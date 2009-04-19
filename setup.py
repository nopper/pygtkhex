#!/usr/bin/env python
#-*- coding:utf-8 -*-
# Copyright (C) 2009 Francesco Piccinno
#
# Author: Francesco Piccinno <stack.box@gmail.com>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

import os
import os.path
import commands

from distutils.core import setup, Extension
from distutils.command.build import build

PYGTKHEX_VERSION = '1.1'
LIBGTK_HEX_VERSION = '1.0'

def pkgconfig(*packages, **kw):
    flag_map = {'-I': 'include_dirs', '-L': 'library_dirs', '-l': 'libraries'}
    for token in commands.getoutput("pkg-config --libs --cflags %s" % ' '.join(packages)).split():
        if flag_map.has_key(token[:2]):
            kw.setdefault(flag_map.get(token[:2]), []).append(token[2:])
        else: # throw others to extra_link_args
            kw.setdefault('extra_link_args', []).append(token)
    for k, v in kw.iteritems(): # remove duplicated
        kw[k] = list(set(v))
    return kw

class pygtkhex_buid(build):
    def run(self):
        if os.name != 'nt':
            self.regen_gtkhex()

        build.run(self)

    def regen_gtkhex(self):
        os.system("pygobject-codegen-2.0 --override gtkhex.override --prefix gtkhex" \
                  " --register /usr/share/pygtk/2.0/defs/gtk-types.defs" \
                  " --register /usr/share/pygtk/2.0/defs/gdk-types.defs" \
                  " --register /usr/share/pygtk/2.0/defs/atk-types.defs" \
                  " gtkhex.defs > gtkhex.c")

if os.name != 'nt':
    deps = pkgconfig('pygtk-2.0 gtk+-2.0 atk')
    deps['include_dirs'].append('src')
    deps['define_macros'] = [
        ('LIBGTKHEX_RELEASE_STRING', '\"%s\"' % LIBGTK_HEX_VERSION)
    ]
else:
    PYDIR = 'C:\\Python25'
    GTKDIR = 'C:\\GTK'
    
    deps = {
        'include_dirs' : [
            'src',
            '%s\\include' % PYDIR,
            '%s\\include\pygtk-2.0' % PYDIR,
            '%s\\include' % GTKDIR,
            '%s\\include\\atk-1.0' % GTKDIR,
            '%s\\include\\cairo' % GTKDIR,
            '%s\\include\\glib-2.0' % GTKDIR,
            '%s\\include\\gtk-2.0' % GTKDIR,
            '%s\\include\\pango-1.0' % GTKDIR,
            '%s\\lib\\glib-2.0\\include' % GTKDIR,
            '%s\\lib\\gtk-2.0\\include' % GTKDIR,
        ],
        'library_dirs' : ['%s\\lib' % GTKDIR],
        'libraries' : [
            'atk-1.0',
            'gdk-win32-2.0',
            'glib-2.0',
            'gobject-2.0',
            'gtk-win32-2.0',
            'pango-1.0',
        ],
        'define_macros' : [('LIBGTKHEX_RELEASE_STRING',
                            '\\"%s\\"' % LIBGTK_HEX_VERSION)],
    }

pygtkhex = Extension(
    'gtkhex',
    [
        'gtkhexmodule.c',
        'gtkhex.c',
        os.path.join('src', 'ghex-marshal.c'),
        os.path.join('src', 'gtkhex.c'),
        os.path.join('src', 'hex-document.c'),
    ],
    **deps
)

setup(
    name = 'PyGtkHex',
    version = PYGTKHEX_VERSION,
    description = 'Python binding of GtkHex widget',
    author = 'Francesco Piccinno',
    author_email = 'stack.box@gmail.com',
    url = 'http://code.google.com/p/pygtkhex/',
    requires = ['pygtk(>=2.2)'],
    ext_modules = [pygtkhex],
    license = 'GPL',
    classifiers = [
        'Developmente Status :: 4 - Beta',
        'Environment :: Desktop',
        'Intended Audience :: Developers',
        'License :: OSI Approved :: GNU General Public License (GPLv2)',
        'Topic :: Software Development :: Libraries :: Python Modules',
        'Operating System :: POSIX',
        'Operating System :: Microsoft :: Windows',
        'Operating System :: MacOS :: MacOS X',
        'Programming Language :: Python',
        'Programming Language :: C',
    ],
    cmdclass = {'build' : pygtkhex_buid}
)

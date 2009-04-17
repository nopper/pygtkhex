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

import gtk
import pango
import gtkhex

def fuffa(b, (v, i)):
    print "Deleting", i
    v.delete_autohighlight(i)
    print "Deleted?", i
box = gtk.VBox()
d = gtkhex.hex_document_new_from_file("examples/high.py")
v = gtkhex.Hex(d)
v.show_offsets(True)
v.set_font("Monospace 9")
idx = d.find_forward('def', 0)
print idx
print d.find_forward('def', idx + 3)
i = v.insert_autohighlight('def', 'yellow')
w = gtk.Window()
w.add(box)
btn = gtk.Button("Remove")
btn.connect('clicked', fuffa, (v, i))
box.pack_start(v)
box.pack_start(btn, False, False)
w.show_all()
gtk.main()

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
f = open("gtkhex.so", "r")
fc = f.read()
f.close()

box = gtk.VBox()
d = gtkhex.hex_document_new_from_file("gtkhex.so")
v = gtkhex.Hex(d)
v.show_offsets(True)
v.set_font("Monospace 9") 
i = v.insert_autohighlight('def', 'yellow')
print type(v.get_byte(8))
print type(d.get_byte(8))
s = d.get_data(0, 20)
print s, type(s), len(s)
print s == fc[0:20]
w = gtk.Window()
w.add(box)
btn = gtk.Button("Remove")
btn.connect('clicked', fuffa, (v, i))
box.pack_start(v)
box.pack_start(btn, False, False)
w.show_all()
gtk.main()

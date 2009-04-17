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
import sys
import random
import unittest
import tempfile

import gtkhex

def random_file():
    """
    Create a temporary file with mktemp and fill it with random data
    """
    tfile = tempfile.NamedTemporaryFile()
    tsize = random.randint(1, 3000)
    buff = ""
    for x in xrange(tsize):
        buff += chr(random.randint(0, 255))
    tfile.write(buff)
    tfile.flush()

    return (tfile, buff)

class TestHexDocument(unittest.TestCase):
    def setUp(self):
        self.file, self.buff = random_file()
        self.doc = gtkhex.hex_document_new_from_file(self.file.name)

    def test_file(self):
        "Test file consinstency"
        f = open(self.file.name, "r")
        tmp = f.read()
        f.close()

        self.assertTrue(tmp == self.buff)
        self.assertTrue(len(tmp) == len(self.buff))

    def test_get_data(self):
        "Test get_data function"
        txt = self.doc.get_data(0, len(self.buff))
        self.assertTrue(len(txt) == len(self.buff))
        self.assertTrue(txt == self.buff)

    def test_random_get_data(self):
        "Test get_data by getting random slices of text"
        start = random.randint(0, len(self.buff) - 1)
        length = random.randint(1, len(self.buff) - 1 - start)

        data = self.doc.get_data(start, length)
        orig = self.buff[start:start + length]

        self.assertTrue(len(data) == len(orig))
        self.assertTrue(orig == data)

    def test_out_get_data(self):
        start = random.randint(0, len(self.buff) - 1)
        data = self.doc.get_data(start, 1)
        byte = self.doc.get_byte(start)
        orig = self.buff[start]

        self.assertTrue(data == byte)
        self.assertTrue(byte == orig)

    def test_out_of_limit(self):
        out = len(self.buff)
        self.assertTrue(self.doc.get_byte(out) is None)

        out += 1000
        self.assertTrue(self.doc.get_byte(out) is None)

        out = -1
        self.assertTrue(self.doc.get_byte(out) is None)

        self.assertTrue(self.doc.get_data(0, 0) == '')
        self.assertRaises(ValueError, gtkhex.Document.get_data, self.doc,
                          0, sys.maxint)
        self.assertRaises(ValueError, gtkhex.Document.get_data, self.doc,
                          -23, -20)

    def test_get_byte(self):
        "Test get_byte function"
        target = random.randint(0, len(self.buff) - 1)
        self.assertTrue(self.doc.get_byte(target) == self.buff[target])

    def test_set_byte(self):
        "Test set_byte function with replace"
        char = chr(random.randint(0, 255))
        offset = random.randint(0, len(self.buff) - 1)
        old = self.doc.get_byte(offset)
        self.doc.set_byte(char, offset, False, False)

        self.assertTrue(self.doc.get_byte(offset) == char)

    def test_set_byte_insert(self):
        "Test set_byte function with insert"
        char = chr(random.randint(0, 255))
        offset = random.randint(0, len(self.buff) - 1)
        old = self.doc.get_byte(offset)
        self.doc.set_byte(char, offset, True, False)

        self.assertTrue(self.doc.get_byte(offset) == char)
        self.assertTrue(self.doc.get_byte(offset + 1) == old)
        self.assertTrue(self.doc.file_size == len(self.buff) + 1)

        buff = self.buff[:offset] + char + self.buff[offset:]
        txt = self.doc.get_data(0, self.doc.file_size)

        self.assertTrue(buff == txt)

        tfile, fname = tempfile.mkstemp()
        self.doc.write_to_file(os.fdopen(tfile, "w+b"))

        f = open(fname, "r")
        out = f.read()
        f.close()
        os.unlink(fname)

        self.assertTrue(out == txt)

    def test_export_html(self):
        "Test the export_html function"
        # Really dummy
        tfile, path = tempfile.mkstemp()
        self.doc.export_html(os.path.dirname(path), os.path.basename(path),
                             0, self.doc.file_size, 20, 20, gtkhex.GROUP_BYTE)
        self.assertTrue(os.system("tidy -qe %s" % path) != 2)
        f = os.fdopen(tfile, "w+b")
        f.close()
        os.unlink(path)

    def test_find_funcs(self):
        "Test find_* funcs"
        start = random.randint(0, len(self.buff) - 1)
        length = random.randint(1, len(self.buff) - 1 - start)
        txt = self.buff[start:start + length]

        self.assertTrue(self.doc.find_forward(txt, 0) == start)
        self.assertTrue(self.doc.find_forward(txt, -1) is None)
        self.assertTrue(self.doc.find_forward(txt, self.doc.file_size) is None)
        self.assertTrue(self.doc.find_forward(txt, self.doc.file_size + 1) is None)

        self.assertTrue(self.doc.find_backward(txt, 0) is None)
        self.assertTrue(self.doc.find_backward(txt, -1) is None)
        self.assertTrue(self.doc.find_backward(txt, self.doc.file_size) == start)
        self.assertTrue(self.doc.find_backward(txt, self.doc.file_size + 1) is None)

    def test_delete_data(self):
        "Test the delete_data function"
        start = random.randint(0, len(self.buff) - 1)
        length = random.randint(1, len(self.buff) - 1 - start)

        self.doc.delete_data(start, length, True)
        self.assertTrue(self.doc.file_size == len(self.buff) - length)
        self.doc.undo()
        self.assertTrue(self.doc.file_size == len(self.buff))
        self.doc.redo()
        self.assertTrue(self.doc.file_size == len(self.buff) - length)

        txt = self.buff[:start] + self.buff[start+length:]
        self.assertTrue(txt == self.doc.get_data(0, self.doc.file_size))

    def test_get_list(self):
        l = gtkhex.hex_document_get_list()
        self.assertTrue(isinstance(l, list))
        self.assertTrue(self.doc in l)

    def test_null_bytes_and_set_data(self):
        pattern = "A\x00AB\x00A\x00B\x00A\x00"
        d = gtkhex.Document()
        d.set_data(0, len(pattern), d.file_size, pattern, False)
        # Check this
        #d.set_data(0, d.file_size, len(pattern), pattern, False)
        txt = d.get_data(0, d.file_size)
        self.assertTrue(txt == pattern)
        self.assertTrue(d.find_forward("A\x00B") == pattern.index("A\x00B"))
        self.assertTrue(d.file_size == len(pattern))

        d.delete_data(0, len(pattern), True)
        
        self.assertRaises(ValueError, gtkhex.Document.get_data, d, -20, d.file_size)
        self.assertTrue(d.get_data(0, d.file_size) == '')
        self.assertTrue(d.file_size == 0)

if __name__ == '__main__':
    unittest.main()

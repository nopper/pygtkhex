#!/bin/sh
svn export . /tmp/exported
cd /tmp/exported
tar -cvvjf ../pygtkhex-$1.tar.bz2 . --exclude contrib
cd ..
md5sum pygtkhex-$1.tar.bz2

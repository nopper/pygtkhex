SUBDIRS = src

gtkhex_defs :=
gtkhex_sources :=
nodist_gtkhex_sources :=
gtkhex_override :=
gtkhex_cflags :=

common_ldflags = -module -avoid-version

pkgpythondir = $(pyexecdir)/gtk-2.0
pkgpyexecdir = $(pyexecdir)/gtk-2.0

pkgpyexec_LTLIBRARIES = gtkhex.la
pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA= pygtkhex-1.0.pc

gtkhex_la_CFLAGS = $(PYGTK_CFLAGS) $(GTK_CFLAGS) $(PYTHON_INCLUDES) -I src
gtkhex_la_LDFLAGS = $(common_ldflags) -export-symbols-regex initgtkhex
gtkhex_la_LIBADD = $(PYGTK_LIBS) src/libgtkhex.la
gtkhex_la_SOURCES = $(gtkhex_sources)
nodist_gtkhex_la_SOURCES = $(nodist_gtkhex_sources)

# Build components
gtkhex_override += gtkhex.override
gtkhex_sources += \
gtkhexmodule.c
nodist_gtkhex_sources += gtkhex.c

gtkhex_defs += gtkhex.defs

webkit_deps := \
gtkhex.override \
gtkhex.defs \
gtkhex.c

gtkhex.c: gtkhex.defs
	$(PYGOBJECT_CODEGEN) --prefix gtkhex \
		--register $(PYGTK_DEFSDIR)/gdk-types.defs \
		--register $(PYGTK_DEFSDIR)/gtk-types.defs \
		--register $(PYGTK_DEFSDIR)/pango-types.defs \
		--override gtkhex.override \
		gtkhex.defs > $@

MAINTAINERCLEANFILES = \
ChangeLog \
aclocal.m4 \
config.h.in \
compile \
config.guess \
config.sub \
configure \
depcomp \
install-sh \
ltmain.sh \
missing

CLEANFILES = \
config.lt \
demos/inspector.pyc \
gtkhex.c \
Makefile.in \
pywebkitgtk-1.0.pc

EXTRA_DIST = \
AUTHORS \
COPYING \
INSTALL \
MAINTAINERS \
NEWS \
README \
examples/inspector.py \
examples/complete.py \
examples/find.py \
examples/getbyte.py \
examples/high.py \
tests/document.py \
$(gtkhex_defs)



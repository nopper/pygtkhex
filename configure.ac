m4_define([pygtkhex_major_version], [1])
m4_define([pygtkhex_minor_version], [1])
m4_define([pygtkhex_micro_version], [0])

m4_define([pygtkhex_version],
          [pygtkhex_major_version.pygtkhex_minor_version.pygtkhex_micro_version])

AC_INIT([pygtkhex],
        [pygtkhex_version],
        [http://code.google.com/p/pygtkhex/])

AC_PREREQ([2.59])
AC_CONFIG_MACRO_DIR([m4])
AC_SUBST(ACLOCAL_AMFLAGS, "-I m4 -I .")

AC_CONFIG_SRCDIR([configure.ac])
AC_CONFIG_HEADERS([config.h])

AC_DEFINE_UNQUOTED(PYGTKHEX_VERSION, pygtkhex_version,
                   [The release version of Python GtkHex.])
AC_DEFINE_UNQUOTED(PYGTKHEX_MAJOR_VERSION, pygtkhex_major_version,
                   [The major version of Python GtkHex.])
AC_DEFINE_UNQUOTED(PYGTKHEX_MINOR_VERSION, pygtkhex_minor_version,
                   [The minor version of Python GtkHex.])
AC_DEFINE_UNQUOTED(PYGTKHEX_MICRO_VERSION, pygtkhex_micro_version,
                   [The micro version of Python GtkHex.])
AM_INIT_AUTOMAKE([foreign subdir-objects])
AM_PROG_CC_C_O
AC_PROG_LIBTOOL
dnl when using libtool 2.x create libtool early, because it's used in configure
m4_ifdef([LT_OUTPUT], [LT_OUTPUT])

dnl check for python
AM_PATH_PYTHON(2.4)
AM_CHECK_PYTHON_HEADERS(,[AC_MSG_ERROR(could not find Python headers)])
py_prefix=`$PYTHON -c "import sys; print sys.prefix"`
PYTHON_INCLUDES="-I${py_prefix}/include/python${PYTHON_VERSION}"

dnl check for dependencies
PKG_CHECK_MODULES(PYGTK, pygtk-2.0 >= 2.2)
AC_SUBST(PYGTK_CFLAGS)
AC_SUBST(PYGTK_LIBS)

dnl python code gen
AC_PATH_PROGS(PYGOBJECT_CODEGEN, pygobject-codegen-2.0 pygtk-codegen-2.0, no)
if test "x$PYGOBJECT_CODEGEN" = xno; then
   AC_MSG_ERROR(could not find pygobject-codegen-2.0 script)
fi

PKG_CHECK_MODULES(GTK, gtk+-2.0 >= 2.4)
AC_SUBST(GTK_CFLAGS)
AC_SUBST(GTK_LIBS)

dnl check for pygtk defsdir
AC_MSG_CHECKING(for pygtk defs)
PYGTK_DEFSDIR=`$PKG_CONFIG --variable=defsdir pygtk-2.0`
AC_SUBST(PYGTK_DEFSDIR)
AC_MSG_RESULT($PYGTK_DEFSDIR)

dnl check for pygtk codegen dir
AC_MSG_CHECKING(for pygtk codegendir)
PYGTK_CODEGENDIR=`$PKG_CONFIG --variable=codegendir pygtk-2.0`
AC_SUBST(PYGTK_CODEGENDIR)
AC_MSG_RESULT($PYGTK_CODEGENDIR)

dnl output
AC_CONFIG_FILES([
Makefile
src/Makefile
pygtkhex-1.0.pc:pygtkhex.pc.in
])

AC_OUTPUT

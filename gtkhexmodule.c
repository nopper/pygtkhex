/*
   gkthexmodule.c - Python bindings for the GTK hex widget.
   Copyright (C) 2009 Francesco Piccinno

   PyGtkHex is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.

   PyGtkHex is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with GHex; see the file COPYING.
   If not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.

   Author: Francesco Piccinno <stack.box@gmail.com>
*/

#include <Python.h>
#include <pygobject.h>
#include <pygtk/pygtk.h>

extern PyMethodDef gtkhex_functions[];

extern PyTypeObject PyChangeData_Type;
extern PyTypeObject PyAutoHighlight_Type;

void gtkhex_register_classes(PyObject *d);

DL_EXPORT(void)
initgtkhex(void)
{
    PyObject *m, *d;

    if (!pygobject_init(-1, -1, -1)) {
        PyErr_Print();
        Py_FatalError ("can't initialise module gobject");
    }

    init_pygtk();

    m = Py_InitModule("gtkhex", gtkhex_functions);
    d = PyModule_GetDict(m);

    gtkhex_register_classes(d);
    gtkhex_add_constants(m, "");

    PyChangeData_Type.ob_type = &PyType_Type;
    PyChangeData_Type.tp_base = &PyBaseObject_Type;

    if (PyType_Ready(&PyChangeData_Type) < 0)
        return;

    Py_INCREF(&PyChangeData_Type);
    PyModule_AddObject(m, "ChangeData", (PyObject *)&PyChangeData_Type);

    PyAutoHighlight_Type.ob_type = &PyType_Type;
    PyAutoHighlight_Type.tp_base = &PyBaseObject_Type;

    if (PyType_Ready(&PyAutoHighlight_Type) < 0)
        return;

    Py_INCREF(&PyAutoHighlight_Type);
    PyModule_AddObject(m, "AutoHighlight", (PyObject *)&PyAutoHighlight_Type);

    if (PyErr_Occurred ()) {
        PyErr_Print();
        Py_FatalError("can't initialise module gtkhex");
    }

}

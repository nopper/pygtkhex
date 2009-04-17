#include <Python.h>
#include <pygobject.h>
#include <pygtk/pygtk.h>

extern PyMethodDef gtkhex_functions[];

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

    if (PyErr_Occurred ()) {
        PyErr_Print();
        Py_FatalError("can't initialise module gtkhex");
    }

}

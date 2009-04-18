/* -- THIS FILE IS GENERATED - DO NOT EDIT *//* -*- Mode: C; c-basic-offset: 4 -*- */

#include <Python.h>



#line 24 "gtkhex.override"
#define NO_IMPORT_PYGOBJECT
#include <pygobject.h>
#include <pygtk/pygtk.h>
#include "gtkhex.h"

#define GTK_TYPE_HEX (gtk_hex_get_type())
#define HEX_TYPE_DOCUMENT (hex_document_get_type())


/* ---------- GtkHex_AutoHighlight ---------- */
typedef struct {
    PyObject_HEAD;
    GtkHex_AutoHighlight *ahl;
} PyAutoHighlight;
staticforward PyTypeObject PyAutoHighlight_Type;

static PyObject *
ahl_new(GtkHex_AutoHighlight *ahl)
{
    PyAutoHighlight *self = NULL;

    self = (PyAutoHighlight *)PyObject_NEW(PyAutoHighlight,
					                       &PyAutoHighlight_Type);
    if (self != NULL) {
        self->ahl = ahl;
    }

    return (PyObject *)self;
}

static void
ahl_dealloc(PyAutoHighlight *self)
{
    self->ahl = NULL;
    PyObject_DEL(self);
}

static PyObject *
ahl_tp_getattr(PyAutoHighlight *self, char *attr)
{
    PyObject *result = NULL;
    PyErr_SetString(PyExc_AttributeError, attr);
    return result;
}

static long
ahl_hash(PyAutoHighlight *self)
{
    return (long)self->ahl;
}

static PyMethodDef ahl_methods[] = {
    { NULL, NULL, 0 }
};

static PyGetSetDef ahl_getsets[] = {
    { NULL, (getter)0, (setter)0, NULL, NULL }
};

static PyTypeObject PyAutoHighlight_Type = {
    PyObject_HEAD_INIT(&PyAutoHighlight_Type)
    0,					/* ob_size */
    "gtkhex.AutoHighlight",			/* tp_name */
    sizeof(PyAutoHighlight),		/* tp_basicsize */
    0,					/* tp_itemsize */
    /* methods */
    (destructor)ahl_dealloc,	/* tp_dealloc */
    (printfunc)0,			/* tp_print */
    (getattrfunc)ahl_tp_getattr,	/* tp_getattr */
    (setattrfunc)0,			/* tp_setattr */
    (cmpfunc)0,	/* tp_compare */
    (reprfunc)0,			/* tp_repr */
    0,					/* tp_as_number */
    0,					/* tp_as_sequence */
    0,					/* tp_as_mapping */
    (hashfunc)ahl_hash,	/* tp_hash */
    (ternaryfunc)0,			/* tp_call */
    (reprfunc)0,			/* tp_str */
    (getattrofunc)0,			/* tp_getattro */
    (setattrofunc)0,			/* tp_setattro */
    0,					/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,			/* tp_flags */
    NULL, /* Documentation string */
    (traverseproc)0,			/* tp_traverse */
    (inquiry)0,				/* tp_clear */
    (richcmpfunc)0,			/* tp_richcompare */
    0,					/* tp_weaklistoffset */
    (getiterfunc)0,			/* tp_iter */
    (iternextfunc)0,			/* tp_iternext */
    ahl_methods,		/* tp_methods */
    0,					/* tp_members */
    ahl_getsets,		/* tp_getset */
    (PyTypeObject *)0,			/* tp_base */
    (PyObject *)0,			/* tp_dict */
    0,					/* tp_descr_get */
    0,					/* tp_descr_set */
    0,					/* tp_dictoffset */
    (initproc)0,			/* tp_init */
    (allocfunc)0,			/* tp_alloc */
    (newfunc)0,				/* tp_new */
    0,					/* tp_free */
    (inquiry)0,				/* tp_is_gc */
    (PyObject *)0,			/* tp_bases */
};

#line 114 "gtkhex.c"


/* ---------- types from other modules ---------- */
static PyTypeObject *_PyGObject_Type;
#define PyGObject_Type (*_PyGObject_Type)
static PyTypeObject *_PyGtkWidget_Type;
#define PyGtkWidget_Type (*_PyGtkWidget_Type)
static PyTypeObject *_PyGtkFixed_Type;
#define PyGtkFixed_Type (*_PyGtkFixed_Type)


/* ---------- forward type declarations ---------- */
PyTypeObject G_GNUC_INTERNAL PyGtkHex_Type;
PyTypeObject G_GNUC_INTERNAL PyHexDocument_Type;

#line 130 "gtkhex.c"



/* ----------- GtkHex ----------- */

#line 143 "gtkhex.override"
static int
_wrap_gtk_hex_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "document", NULL };
    PyGObject *document = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!:GtkHex.__init__", kwlist, &PyHexDocument_Type, &document))
        return -1;
    
    if (document) {
        self->obj = (GObject *)gtk_hex_new(HEX_DOCUMENT(document->obj));
        
        gtk_fixed_set_has_window(GTK_FIXED(self->obj), TRUE);
        
        (HEX_DOCUMENT(document->obj))->views = g_list_append(\
            (HEX_DOCUMENT(document->obj))->views,
            GTK_HEX(self->obj)
        );
    }

    if (!self->obj) {
        PyErr_SetString(PyExc_RuntimeError, "could not create GtkHex object");
        return -1;
    }
    pygobject_register_wrapper((PyObject *)self);
    return 0;
}
#line 164 "gtkhex.c"


static PyObject *
_wrap_gtk_hex_set_cursor(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "index", NULL };
    int index;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:GtkHex.set_cursor", kwlist, &index))
        return NULL;
    
    gtk_hex_set_cursor(GTK_HEX(self->obj), index);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_hex_set_cursor_xy(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "x", "y", NULL };
    int x, y;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"ii:GtkHex.set_cursor_xy", kwlist, &x, &y))
        return NULL;
    
    gtk_hex_set_cursor_xy(GTK_HEX(self->obj), x, y);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_hex_set_nibble(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "lower_nibble", NULL };
    int lower_nibble;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:GtkHex.set_nibble", kwlist, &lower_nibble))
        return NULL;
    
    gtk_hex_set_nibble(GTK_HEX(self->obj), lower_nibble);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_hex_get_cursor(PyGObject *self)
{
    guint ret;

    
    ret = gtk_hex_get_cursor(GTK_HEX(self->obj));
    
    return PyLong_FromUnsignedLong(ret);
}

#line 317 "gtkhex.override"
static PyObject *
_wrap_gtk_hex_get_byte(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = {"offset", NULL};
    PyObject *py_offset = NULL;
    guint offset = 0;
    guchar ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O:GtkHex.get_byte", kwlist, &py_offset))
        return NULL;

    if (py_offset) {
        if (PyLong_Check(py_offset))
            offset = PyLong_AsUnsignedLong(py_offset);
        else if (PyInt_Check(py_offset))
            offset = PyInt_AsLong(py_offset);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'offset' must be an int or a long");
        if (PyErr_Occurred())
            return NULL;
    }
    
    if ((offset >= 0) && (offset < (GTK_HEX(self->obj))->document->file_size)) {

        ret = gtk_hex_get_byte(GTK_HEX(self->obj), offset);
        return PyString_FromFormat("%c", ret);
    }
    
    Py_INCREF(Py_None);
    return Py_None;
}
#line 255 "gtkhex.c"


static PyObject *
_wrap_gtk_hex_set_group_type(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "gt", NULL };
    int gt;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:GtkHex.set_group_type", kwlist, &gt))
        return NULL;
    
    gtk_hex_set_group_type(GTK_HEX(self->obj), gt);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_hex_set_starting_offset(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "offset", NULL };
    int offset;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:GtkHex.set_starting_offset", kwlist, &offset))
        return NULL;
    
    gtk_hex_set_starting_offset(GTK_HEX(self->obj), offset);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_hex_show_offsets(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "show", NULL };
    int show;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:GtkHex.show_offsets", kwlist, &show))
        return NULL;
    
    gtk_hex_show_offsets(GTK_HEX(self->obj), show);
    
    Py_INCREF(Py_None);
    return Py_None;
}

#line 185 "gtkhex.override"
static PyObject *
_wrap_gtk_hex_set_font(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "font_str", NULL };
    char *font_str;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:GtkHex.set_font", kwlist, &font_str))
        return NULL;
    if (font_str) {
        gtk_hex_set_font(GTK_HEX(self->obj), gtk_hex_load_font(font_str),
                         pango_font_description_from_string(font_str));
    }
    
    Py_INCREF(Py_None);
    return Py_None;
}
#line 320 "gtkhex.c"


static PyObject *
_wrap_gtk_hex_set_insert_mode(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "insert", NULL };
    int insert;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:GtkHex.set_insert_mode", kwlist, &insert))
        return NULL;
    
    gtk_hex_set_insert_mode(GTK_HEX(self->obj), insert);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_hex_set_geometry(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "cpl", "vis_lines", NULL };
    int cpl, vis_lines;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"ii:GtkHex.set_geometry", kwlist, &cpl, &vis_lines))
        return NULL;
    
    gtk_hex_set_geometry(GTK_HEX(self->obj), cpl, vis_lines);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_hex_copy_to_clipboard(PyGObject *self)
{
    
    gtk_hex_copy_to_clipboard(GTK_HEX(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_hex_cut_to_clipboard(PyGObject *self)
{
    
    gtk_hex_cut_to_clipboard(GTK_HEX(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_hex_paste_from_clipboard(PyGObject *self)
{
    
    gtk_hex_paste_from_clipboard(GTK_HEX(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_hex_set_selection(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "start", "end", NULL };
    int start, end;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"ii:GtkHex.set_selection", kwlist, &start, &end))
        return NULL;
    
    gtk_hex_set_selection(GTK_HEX(self->obj), start, end);
    
    Py_INCREF(Py_None);
    return Py_None;
}

#line 172 "gtkhex.override"
static PyObject *
_wrap_gtk_hex_get_selection(PyGObject *self)
{
    gint start, end;

    if (gtk_hex_get_selection(GTK_HEX(self->obj), &start, &end))
        return Py_BuildValue("(ii)", start, end);

    Py_INCREF(Py_None);
    return Py_None;
}
#line 410 "gtkhex.c"


static PyObject *
_wrap_gtk_hex_clear_selection(PyGObject *self)
{
    
    gtk_hex_clear_selection(GTK_HEX(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_hex_delete_selection(PyGObject *self)
{
    
    gtk_hex_delete_selection(GTK_HEX(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

#line 203 "gtkhex.override"
static PyObject *
_wrap_gtk_hex_insert_autohighlight(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "search", "colour", NULL };
    gchar *search = NULL, *colour = NULL;
    int search_len;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s#s:GtkHex.insert_autohighlight", kwlist,
            &search, &search_len, &colour))
        return NULL;

    if (search && colour) {
        return ahl_new(gtk_hex_insert_autohighlight(GTK_HEX(self->obj),
                        search, search_len, colour));
    }
    
    Py_INCREF(Py_None);
    return Py_None;
}
#line 453 "gtkhex.c"


#line 224 "gtkhex.override"
static PyObject *
_wrap_gtk_hex_delete_autohighlight(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "ahl", NULL };
    PyAutoHighlight *ahl = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!:GtkHex.delete_autohighlight", kwlist, &PyAutoHighlight_Type, &ahl))
        return NULL;

    if (ahl) {
        if (ahl->ahl) {
            gtk_hex_delete_autohighlight(GTK_HEX(self->obj), ahl->ahl);
            ahl_dealloc(ahl);
        }
        else
            PyErr_SetString(PyExc_ValueError, "Parameter 'ahl' already deleted.");

        if (PyErr_Occurred())
            return NULL;
    }

    Py_INCREF(Py_None);
    return Py_None;
}
#line 481 "gtkhex.c"


static const PyMethodDef _PyGtkHex_methods[] = {
    { "set_cursor", (PyCFunction)_wrap_gtk_hex_set_cursor, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_cursor_xy", (PyCFunction)_wrap_gtk_hex_set_cursor_xy, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_nibble", (PyCFunction)_wrap_gtk_hex_set_nibble, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_cursor", (PyCFunction)_wrap_gtk_hex_get_cursor, METH_NOARGS,
      NULL },
    { "get_byte", (PyCFunction)_wrap_gtk_hex_get_byte, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_group_type", (PyCFunction)_wrap_gtk_hex_set_group_type, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_starting_offset", (PyCFunction)_wrap_gtk_hex_set_starting_offset, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "show_offsets", (PyCFunction)_wrap_gtk_hex_show_offsets, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_font", (PyCFunction)_wrap_gtk_hex_set_font, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_insert_mode", (PyCFunction)_wrap_gtk_hex_set_insert_mode, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_geometry", (PyCFunction)_wrap_gtk_hex_set_geometry, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "copy_to_clipboard", (PyCFunction)_wrap_gtk_hex_copy_to_clipboard, METH_NOARGS,
      NULL },
    { "cut_to_clipboard", (PyCFunction)_wrap_gtk_hex_cut_to_clipboard, METH_NOARGS,
      NULL },
    { "paste_from_clipboard", (PyCFunction)_wrap_gtk_hex_paste_from_clipboard, METH_NOARGS,
      NULL },
    { "set_selection", (PyCFunction)_wrap_gtk_hex_set_selection, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_selection", (PyCFunction)_wrap_gtk_hex_get_selection, METH_NOARGS,
      NULL },
    { "clear_selection", (PyCFunction)_wrap_gtk_hex_clear_selection, METH_NOARGS,
      NULL },
    { "delete_selection", (PyCFunction)_wrap_gtk_hex_delete_selection, METH_NOARGS,
      NULL },
    { "insert_autohighlight", (PyCFunction)_wrap_gtk_hex_insert_autohighlight, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "delete_autohighlight", (PyCFunction)_wrap_gtk_hex_delete_autohighlight, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGtkHex_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gtkhex.Hex",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyGtkHex_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_gtk_hex_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- HexDocument ----------- */

static int
_wrap_hex_document_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char* kwlist[] = { NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     ":gtkhex.Document.__init__",
                                     kwlist))
        return -1;

    pygobject_constructv(self, 0, NULL);
    if (!self->obj) {
        PyErr_SetString(
            PyExc_RuntimeError, 
            "could not create gtkhex.Document object");
        return -1;
    }
    return 0;
}

static PyObject *
_wrap_hex_document_set_data(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "offset", "len", "rep_len", "data", "undoable", NULL };
    PyObject *py_offset = NULL, *py_len = NULL, *py_rep_len = NULL;
    int data_len, undoable;
    guchar *data;
    guint offset = 0, len = 0, rep_len = 0;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"OOOs#i:HexDocument.set_data", kwlist, &py_offset, &py_len, &py_rep_len, &data, &data_len, &undoable))
        return NULL;
    if (py_offset) {
        if (PyLong_Check(py_offset))
            offset = PyLong_AsUnsignedLong(py_offset);
        else if (PyInt_Check(py_offset))
            offset = PyInt_AsLong(py_offset);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'offset' must be an int or a long");
        if (PyErr_Occurred())
            return NULL;
    }
    if (py_len) {
        if (PyLong_Check(py_len))
            len = PyLong_AsUnsignedLong(py_len);
        else if (PyInt_Check(py_len))
            len = PyInt_AsLong(py_len);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'len' must be an int or a long");
        if (PyErr_Occurred())
            return NULL;
    }
    if (py_rep_len) {
        if (PyLong_Check(py_rep_len))
            rep_len = PyLong_AsUnsignedLong(py_rep_len);
        else if (PyInt_Check(py_rep_len))
            rep_len = PyInt_AsLong(py_rep_len);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'rep_len' must be an int or a long");
        if (PyErr_Occurred())
            return NULL;
    }
    
    hex_document_set_data(HEX_DOCUMENT(self->obj), offset, len, rep_len, data, undoable);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hex_document_set_byte(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "val", "offset", "insert", "undoable", NULL };
    char val;
    PyObject *py_offset = NULL;
    int insert, undoable;
    guint offset = 0;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"cOii:HexDocument.set_byte", kwlist, &val, &py_offset, &insert, &undoable))
        return NULL;
    if (py_offset) {
        if (PyLong_Check(py_offset))
            offset = PyLong_AsUnsignedLong(py_offset);
        else if (PyInt_Check(py_offset))
            offset = PyInt_AsLong(py_offset);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'offset' must be an int or a long");
        if (PyErr_Occurred())
            return NULL;
    }
    
    hex_document_set_byte(HEX_DOCUMENT(self->obj), val, offset, insert, undoable);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hex_document_set_nibble(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "val", "offset", "lower_nibble", "insert", "undoable", NULL };
    char val;
    PyObject *py_offset = NULL;
    int lower_nibble, insert, undoable;
    guint offset = 0;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"cOiii:HexDocument.set_nibble", kwlist, &val, &py_offset, &lower_nibble, &insert, &undoable))
        return NULL;
    if (py_offset) {
        if (PyLong_Check(py_offset))
            offset = PyLong_AsUnsignedLong(py_offset);
        else if (PyInt_Check(py_offset))
            offset = PyInt_AsLong(py_offset);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'offset' must be an int or a long");
        if (PyErr_Occurred())
            return NULL;
    }
    
    hex_document_set_nibble(HEX_DOCUMENT(self->obj), val, offset, lower_nibble, insert, undoable);
    
    Py_INCREF(Py_None);
    return Py_None;
}

#line 350 "gtkhex.override"
static PyObject *
_wrap_hex_document_get_byte(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = {"offset", NULL};
    PyObject *py_offset = NULL;
    guint offset = 0;
    guchar ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O:HexDocument.get_byte", kwlist, &py_offset))
        return NULL;

    if (py_offset) {
        if (PyLong_Check(py_offset))
            offset = PyLong_AsUnsignedLong(py_offset);
        else if (PyInt_Check(py_offset))
            offset = PyInt_AsLong(py_offset);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'offset' must be an int or a long");
        if (PyErr_Occurred())
            return NULL;
    }

    if ((offset >= 0) && offset < (HEX_DOCUMENT(self->obj))->file_size) {
        ret = hex_document_get_byte(HEX_DOCUMENT(self->obj), offset);
        return PyString_FromFormat("%c", ret);
    }
    
    Py_INCREF(Py_None);
    return Py_None;
}
#line 732 "gtkhex.c"


#line 382 "gtkhex.override"
static PyObject *
_wrap_hex_document_get_data(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = {"offset", "len", NULL};
    PyObject *py_offset = NULL, *py_len = NULL;
    guint offset = 0, len = 0;
    guchar *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "OO:HexDocument.get_data", kwlist, 
            &py_offset, &py_len))
        return NULL;

    if (py_offset) {
        if (PyLong_Check(py_offset))
            offset = PyLong_AsUnsignedLong(py_offset);
        else if (PyInt_Check(py_offset))
            offset = PyInt_AsLong(py_offset);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'offset' must be an int or a long");
        if (PyErr_Occurred())
            return NULL;
    }

    if (py_len) {
        if (PyLong_Check(py_len))
            len = PyLong_AsUnsignedLong(py_len);
        else if (PyInt_Check(py_len))
            len = PyInt_AsLong(py_len);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'len' must be an int or a long");
        if (PyErr_Occurred())
            return NULL;
    }

    if ((offset >= 0) && offset <= (HEX_DOCUMENT(self->obj))->file_size &&
        (len >= 0) && len <= ((HEX_DOCUMENT(self->obj))->file_size - offset)) {

        ret = hex_document_get_data(HEX_DOCUMENT(self->obj), offset, len);
        if (ret) {
            return PyString_FromStringAndSize(ret, len);
        }
        else {
            return PyString_FromStringAndSize(NULL, 0);
        }
    }

    PyErr_SetString(PyExc_ValueError, "Parameter 'offset' and/or 'len' are incorrect.");
    return NULL;
}
#line 785 "gtkhex.c"


static PyObject *
_wrap_hex_document_delete_data(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "offset", "len", "undoable", NULL };
    PyObject *py_offset = NULL, *py_len = NULL;
    int undoable;
    guint offset = 0, len = 0;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"OOi:HexDocument.delete_data", kwlist, &py_offset, &py_len, &undoable))
        return NULL;
    if (py_offset) {
        if (PyLong_Check(py_offset))
            offset = PyLong_AsUnsignedLong(py_offset);
        else if (PyInt_Check(py_offset))
            offset = PyInt_AsLong(py_offset);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'offset' must be an int or a long");
        if (PyErr_Occurred())
            return NULL;
    }
    if (py_len) {
        if (PyLong_Check(py_len))
            len = PyLong_AsUnsignedLong(py_len);
        else if (PyInt_Check(py_len))
            len = PyInt_AsLong(py_len);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'len' must be an int or a long");
        if (PyErr_Occurred())
            return NULL;
    }
    
    hex_document_delete_data(HEX_DOCUMENT(self->obj), offset, len, undoable);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hex_document_read(PyGObject *self)
{
    int ret;

    
    ret = hex_document_read(HEX_DOCUMENT(self->obj));
    
    return PyInt_FromLong(ret);
}

static PyObject *
_wrap_hex_document_write(PyGObject *self)
{
    int ret;

    
    ret = hex_document_write(HEX_DOCUMENT(self->obj));
    
    return PyInt_FromLong(ret);
}

static PyObject *
_wrap_hex_document_write_to_file(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "file", NULL };
    PyObject *file;
    int ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!:HexDocument.write_to_file", kwlist, &PyFile_Type, &file))
        return NULL;
    
    ret = hex_document_write_to_file(HEX_DOCUMENT(self->obj), PyFile_AsFile(file));
    
    return PyInt_FromLong(ret);
}

static PyObject *
_wrap_hex_document_export_html(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "html_path", "base_name", "start", "end", "cpl", "lpp", "cpw", NULL };
    char *html_path, *base_name;
    PyObject *py_start = NULL, *py_end = NULL, *py_cpl = NULL, *py_lpp = NULL, *py_cpw = NULL;
    int ret;
    guint start = 0, end = 0, cpl = 0, lpp = 0, cpw = 0;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"ssOOOOO:HexDocument.export_html", kwlist, &html_path, &base_name, &py_start, &py_end, &py_cpl, &py_lpp, &py_cpw))
        return NULL;
    if (py_start) {
        if (PyLong_Check(py_start))
            start = PyLong_AsUnsignedLong(py_start);
        else if (PyInt_Check(py_start))
            start = PyInt_AsLong(py_start);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'start' must be an int or a long");
        if (PyErr_Occurred())
            return NULL;
    }
    if (py_end) {
        if (PyLong_Check(py_end))
            end = PyLong_AsUnsignedLong(py_end);
        else if (PyInt_Check(py_end))
            end = PyInt_AsLong(py_end);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'end' must be an int or a long");
        if (PyErr_Occurred())
            return NULL;
    }
    if (py_cpl) {
        if (PyLong_Check(py_cpl))
            cpl = PyLong_AsUnsignedLong(py_cpl);
        else if (PyInt_Check(py_cpl))
            cpl = PyInt_AsLong(py_cpl);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'cpl' must be an int or a long");
        if (PyErr_Occurred())
            return NULL;
    }
    if (py_lpp) {
        if (PyLong_Check(py_lpp))
            lpp = PyLong_AsUnsignedLong(py_lpp);
        else if (PyInt_Check(py_lpp))
            lpp = PyInt_AsLong(py_lpp);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'lpp' must be an int or a long");
        if (PyErr_Occurred())
            return NULL;
    }
    if (py_cpw) {
        if (PyLong_Check(py_cpw))
            cpw = PyLong_AsUnsignedLong(py_cpw);
        else if (PyInt_Check(py_cpw))
            cpw = PyInt_AsLong(py_cpw);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'cpw' must be an int or a long");
        if (PyErr_Occurred())
            return NULL;
    }
    
    ret = hex_document_export_html(HEX_DOCUMENT(self->obj), html_path, base_name, start, end, cpl, lpp, cpw);
    
    return PyInt_FromLong(ret);
}

static PyObject *
_wrap_hex_document_has_changed(PyGObject *self)
{
    int ret;

    
    ret = hex_document_has_changed(HEX_DOCUMENT(self->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_hex_document_set_max_undo(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "max_undo", NULL };
    PyObject *py_max_undo = NULL;
    guint max_undo = 0;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:HexDocument.set_max_undo", kwlist, &py_max_undo))
        return NULL;
    if (py_max_undo) {
        if (PyLong_Check(py_max_undo))
            max_undo = PyLong_AsUnsignedLong(py_max_undo);
        else if (PyInt_Check(py_max_undo))
            max_undo = PyInt_AsLong(py_max_undo);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'max_undo' must be an int or a long");
        if (PyErr_Occurred())
            return NULL;
    }
    
    hex_document_set_max_undo(HEX_DOCUMENT(self->obj), max_undo);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hex_document_undo(PyGObject *self)
{
    int ret;

    
    ret = hex_document_undo(HEX_DOCUMENT(self->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_hex_document_redo(PyGObject *self)
{
    int ret;

    
    ret = hex_document_redo(HEX_DOCUMENT(self->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_hex_document_compare_data(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "s2", "pos", "len", NULL };
    int s2_len, pos, len, ret;
    guchar *s2;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s#ii:HexDocument.compare_data", kwlist, &s2, &s2_len, &pos, &len))
        return NULL;
    
    ret = hex_document_compare_data(HEX_DOCUMENT(self->obj), s2, pos, len);
    
    return PyInt_FromLong(ret);
}

#line 250 "gtkhex.override"
static PyObject *
_wrap_hex_document_find_forward(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = {"what", "start", NULL};
    guchar *what;
    int what_len;
    PyObject *py_start = NULL;
    guint start = 0, found;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "s#|O:HexDocument.find_forward", kwlist, &what, &what_len, &py_start))
        return NULL;
    
    if (py_start) {
        if (PyLong_Check(py_start))
            start = PyLong_AsUnsignedLong(py_start);
        else if (PyInt_Check(py_start))
            start = PyInt_AsLong(py_start);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'start' must be an int or a long");
        if (PyErr_Occurred())
            return NULL;
    }

    if (hex_document_find_forward(HEX_DOCUMENT(self->obj), start, what, what_len, &found))
        return PyLong_FromUnsignedLong(found);
    else
    {
        Py_INCREF(Py_None);
        return Py_None;
    }
}
#line 1038 "gtkhex.c"


#line 283 "gtkhex.override"
static PyObject *
_wrap_hex_document_find_backward(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = {"what", "start", NULL};
    guchar *what;
    int what_len;
    PyObject *py_start = NULL;
    guint start = 0, found;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "s#|O:HexDocument.find_backward", kwlist, &what, &what_len, &py_start))
        return NULL;
    
    if (py_start) {
        if (PyLong_Check(py_start))
            start = PyLong_AsUnsignedLong(py_start);
        else if (PyInt_Check(py_start))
            start = PyInt_AsLong(py_start);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'start' must be an int or a long");
        if (PyErr_Occurred())
            return NULL;
    }

    if (start <= HEX_DOCUMENT(self->obj)->file_size &&
        hex_document_find_backward(HEX_DOCUMENT(self->obj), start, what, what_len, &found))
        return PyLong_FromUnsignedLong(found);
    else
    {
        Py_INCREF(Py_None);
        return Py_None;
    }
}
#line 1074 "gtkhex.c"


static PyObject *
_wrap_hex_document_is_writable(PyGObject *self)
{
    int ret;

    
    ret = hex_document_is_writable(HEX_DOCUMENT(self->obj));
    
    return PyBool_FromLong(ret);

}

static const PyMethodDef _PyHexDocument_methods[] = {
    { "set_data", (PyCFunction)_wrap_hex_document_set_data, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_byte", (PyCFunction)_wrap_hex_document_set_byte, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_nibble", (PyCFunction)_wrap_hex_document_set_nibble, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_byte", (PyCFunction)_wrap_hex_document_get_byte, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_data", (PyCFunction)_wrap_hex_document_get_data, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "delete_data", (PyCFunction)_wrap_hex_document_delete_data, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "read", (PyCFunction)_wrap_hex_document_read, METH_NOARGS,
      NULL },
    { "write", (PyCFunction)_wrap_hex_document_write, METH_NOARGS,
      NULL },
    { "write_to_file", (PyCFunction)_wrap_hex_document_write_to_file, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "export_html", (PyCFunction)_wrap_hex_document_export_html, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "has_changed", (PyCFunction)_wrap_hex_document_has_changed, METH_NOARGS,
      NULL },
    { "set_max_undo", (PyCFunction)_wrap_hex_document_set_max_undo, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "undo", (PyCFunction)_wrap_hex_document_undo, METH_NOARGS,
      NULL },
    { "redo", (PyCFunction)_wrap_hex_document_redo, METH_NOARGS,
      NULL },
    { "compare_data", (PyCFunction)_wrap_hex_document_compare_data, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "find_forward", (PyCFunction)_wrap_hex_document_find_forward, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "find_backward", (PyCFunction)_wrap_hex_document_find_backward, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "is_writable", (PyCFunction)_wrap_hex_document_is_writable, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

static PyObject *
_wrap_hex_document__get_file_name(PyObject *self, void *closure)
{
    const gchar *ret;

    ret = HEX_DOCUMENT(pygobject_get(self))->file_name;
    if (ret)
        return PyString_FromString(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hex_document__get_path_end(PyObject *self, void *closure)
{
    const gchar *ret;

    ret = HEX_DOCUMENT(pygobject_get(self))->path_end;
    if (ret)
        return PyString_FromString(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hex_document__get_gap_size(PyObject *self, void *closure)
{
    int ret;

    ret = HEX_DOCUMENT(pygobject_get(self))->gap_size;
    return PyInt_FromLong(ret);
}

static PyObject *
_wrap_hex_document__get_buffer_size(PyObject *self, void *closure)
{
    guint ret;

    ret = HEX_DOCUMENT(pygobject_get(self))->buffer_size;
    return PyLong_FromUnsignedLong(ret);
}

static PyObject *
_wrap_hex_document__get_file_size(PyObject *self, void *closure)
{
    guint ret;

    ret = HEX_DOCUMENT(pygobject_get(self))->file_size;
    return PyLong_FromUnsignedLong(ret);
}

static const PyGetSetDef hex_document_getsets[] = {
    { "file_name", (getter)_wrap_hex_document__get_file_name, (setter)0 },
    { "path_end", (getter)_wrap_hex_document__get_path_end, (setter)0 },
    { "gap_size", (getter)_wrap_hex_document__get_gap_size, (setter)0 },
    { "buffer_size", (getter)_wrap_hex_document__get_buffer_size, (setter)0 },
    { "file_size", (getter)_wrap_hex_document__get_file_size, (setter)0 },
    { NULL, (getter)0, (setter)0 },
};

PyTypeObject G_GNUC_INTERNAL PyHexDocument_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gtkhex.Document",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyHexDocument_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)hex_document_getsets,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_hex_document_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- functions ----------- */

static PyObject *
_wrap_hex_document_new_from_file(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "name", NULL };
    char *name;
    HexDocument *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:hex_document_new_from_file", kwlist, &name))
        return NULL;
    
    ret = hex_document_new_from_file(name);
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

#line 433 "gtkhex.override"
static PyObject *
_wrap_hex_document_get_list(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    const GList *list;
    PyObject *item, *ret = PyList_New(0);

    for (list = hex_document_get_list(); list != NULL;
         list = list->next) {
        item = pygobject_new((GObject *)HEX_DOCUMENT(list->data));
        if (!item) {
            Py_DECREF(ret);
            Py_INCREF(Py_None);
            return Py_None;
        }

        PyList_Append(ret, item);
        Py_DECREF(item);
    }

    return ret;
}
#line 1276 "gtkhex.c"


const PyMethodDef gtkhex_functions[] = {
    { "hex_document_new_from_file", (PyCFunction)_wrap_hex_document_new_from_file, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "hex_document_get_list", (PyCFunction)_wrap_hex_document_get_list, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};


/* ----------- enums and flags ----------- */

void
gtkhex_add_constants(PyObject *module, const gchar *strip_prefix)
{
#ifdef VERSION
    PyModule_AddStringConstant(module, "__version__", VERSION);
#endif
    PyModule_AddIntConstant(module, (char *) pyg_constant_strip_prefix("HEX_CHANGE_STRING", strip_prefix), HEX_CHANGE_STRING);
    PyModule_AddIntConstant(module, (char *) pyg_constant_strip_prefix("HEX_CHANGE_BYTE", strip_prefix), HEX_CHANGE_BYTE);
    PyModule_AddIntConstant(module, (char *) pyg_constant_strip_prefix("GROUP_BYTE", strip_prefix), GROUP_BYTE);
    PyModule_AddIntConstant(module, (char *) pyg_constant_strip_prefix("GROUP_WORD", strip_prefix), GROUP_WORD);
    PyModule_AddIntConstant(module, (char *) pyg_constant_strip_prefix("GROUP_LONG", strip_prefix), GROUP_LONG);

  if (PyErr_Occurred())
    PyErr_Print();
}

/* initialise stuff extension classes */
void
gtkhex_register_classes(PyObject *d)
{
    PyObject *module;

    if ((module = PyImport_ImportModule("gobject")) != NULL) {
        _PyGObject_Type = (PyTypeObject *)PyObject_GetAttrString(module, "GObject");
        if (_PyGObject_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name GObject from gobject");
            return ;
        }
    } else {
        PyErr_SetString(PyExc_ImportError,
            "could not import gobject");
        return ;
    }
    if ((module = PyImport_ImportModule("gtk")) != NULL) {
        _PyGtkWidget_Type = (PyTypeObject *)PyObject_GetAttrString(module, "Widget");
        if (_PyGtkWidget_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name Widget from gtk");
            return ;
        }
        _PyGtkFixed_Type = (PyTypeObject *)PyObject_GetAttrString(module, "Fixed");
        if (_PyGtkFixed_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name Fixed from gtk");
            return ;
        }
    } else {
        PyErr_SetString(PyExc_ImportError,
            "could not import gtk");
        return ;
    }


#line 1344 "gtkhex.c"
    pygobject_register_class(d, "GtkHex", GTK_TYPE_HEX, &PyGtkHex_Type, Py_BuildValue("(O)", &PyGtkFixed_Type));
    pyg_set_object_has_new_constructor(GTK_TYPE_HEX);
    pygobject_register_class(d, "HexDocument", HEX_TYPE_DOCUMENT, &PyHexDocument_Type, Py_BuildValue("(O)", &PyGObject_Type));
    pyg_set_object_has_new_constructor(HEX_TYPE_DOCUMENT);
}

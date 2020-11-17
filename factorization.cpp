#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include "factorize.h"
#include "bignum/wideint.h"


#ifdef __SIZEOF_INT128__
    using int128_t = __int128_t;
#else
    using int128_t = wideint<128>;
#endif


static PyObject *factorize(PyObject* self, PyObject* args) 
{
    PyObject *py_n1, *py_n2;
    int128_t pq;
    int128_t p, q;
    
    if (!PyArg_ParseTuple(args, "O", &py_n1))
        return NULL;

    _PyLong_AsByteArray((PyLongObject*)py_n1, (uint8_t *)&pq, sizeof(pq), 1, 0);
    
    p = BrentRichard(pq);
    q = pq / p;

    py_n1 = _PyLong_FromByteArray((const uint8_t *)&p, sizeof(p), 1, 0);
    py_n2 = _PyLong_FromByteArray((const uint8_t *)&q, sizeof(q), 1, 0);
    
    return (p < q) ? Py_BuildValue("OO", py_n1, py_n2) : Py_BuildValue("OO", py_n2, py_n1);
   
}


static PyMethodDef methods[] = {
    {"factorize", factorize, METH_VARARGS, "Factorizes the given large integer."},
    {NULL, NULL, 0, NULL}
};


static PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "factorization", 
    "factorize Calculation",
    -1,
    methods
};


PyMODINIT_FUNC PyInit_factorization(void)
{
    return PyModule_Create(&module);
}


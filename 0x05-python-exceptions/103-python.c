#include <Python.h>

/**
 * print_python_list - Prints information about a Python list object
 * @p: Pointer to the Python object
 */
void print_python_list(PyObject *p)
{
    if (!PyList_Check(p))
    {
        printf("[*] Python list info\n  [ERROR] Invalid List Object\n");
        fflush(stdout);
        return;
    }

    Py_ssize_t size = PyList_Size(p);
    Py_ssize_t allocated = ((PyListObject *)p)->allocated;

    printf("[*] Python list info\n[*] Size of the Python List = %zd\n[*] Allocated = %zd\n", size, allocated);
    fflush(stdout);

    for (Py_ssize_t i = 0; i < size; i++)
    {
        PyObject *item = PyList_GetItem(p, i);
        const char *type = Py_TYPE(item)->tp_name;
        printf("Element %zd: %s\n", i, type);
    }

    fflush(stdout);
}

/**
 * print_python_bytes - Prints information about a Python bytes object
 * @p: Pointer to the Python object
 */
void print_python_bytes(PyObject *p)
{
    if (!PyBytes_Check(p))
    {
        printf("[.] bytes object info\n  [ERROR] Invalid Bytes Object\n");
        fflush(stdout);
        return;
    }

    Py_ssize_t size = PyBytes_Size(p);
    printf("[.] bytes object info\n  size: %zd\n  trying string: %s\n", size, PyBytes_AsString(p));
    fflush(stdout);

    printf("  first %zd bytes:", (size < 10) ? size : 10);
    unsigned char *bytes = (unsigned char *)PyBytes_AsString(p);
    for (Py_ssize_t i = 0; i < ((size < 10) ? size : 10); i++)
    {
        printf(" %02x", bytes[i]);
    }
    printf("\n");
    fflush(stdout);
}

/**
 * print_python_float - Prints information about a Python float object
 * @p: Pointer to the Python object
 */
void print_python_float(PyObject *p)
{
    if (!PyFloat_Check(p))
    {
        printf("[.] float object info\n  [ERROR] Invalid Float Object\n");
        fflush(stdout);
        return;
    }

    double value = PyFloat_AsDouble(p);
    printf("[.] float object info\n  value: %f\n", value);
    fflush(stdout);
}

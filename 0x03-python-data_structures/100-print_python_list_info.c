#include <Python.h>
#include <stdio.h>
#include <object.h>
#include <listobject.h>

/**
 * print_python_list_info - print some basic info about Python list
 * @p: python object
 */
void print_python_list_info(PyObject *p)
{
        int size;
        int allocated;
        int i;

        size = Py_SIZE(p);
        allocated = ((PyListObject *)p)->allocated;
        printf("[*] Size of the Python List = %d\n", size);
        printf("[*] Allocated = %d\n", allocated);

        for (i = 0; i < size; i++)
        {
                printf("Element %d: ", i);
                printf("%s\n", ((PyList_GetItem(p, i))->ob_type)->tp_name);
        }
}

#include <Python.h>
#include <stdio.h>

int main() {
    Py_Initialize();

    // Get the array of integers from the user
    int array[100];
    int size;
    int i;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements of the array:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    // Create a Python list and append the array elements
    PyObject* pyArray = PyList_New(0);
    for (i = 0; i < size; i++) {
        PyObject* element = PyLong_FromLong(array[i]);
        PyList_Append(pyArray, element);
        Py_DECREF(element);
    }

    // Set the 'array' variable in the Python environment
    PyDict_SetItemString(PyModule_GetDict(PyImport_AddModule("__main__")), "array", pyArray);

    // Execute Python code to find the maximum element in the array
    PyRun_SimpleString("result = max(array)\n"
                       "print(result)\n");

    // Clean up
    Py_DECREF(pyArray);
    Py_Finalize();

    return 0;
}

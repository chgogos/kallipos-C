#include <Python.h>

int main() {
    Py_Initialize();

    // Execute Python code to find the maximum element in an array
    PyRun_SimpleString("array = [5, 2, 9, 1, 7]\n"
                       "result = max(array)\n"
                       "print(result)\n");

    Py_Finalize();

    return 0;
}

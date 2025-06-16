#include <Python.h>

int main(int argc, char *argv[]) {
  Py_Initialize();

  PyObject *pName = PyUnicode_DecodeFSDefault("fibonacci");
  PyObject *pModule = PyImport_Import(pName);
  Py_DECREF(pName);

  if (pModule != NULL) {
    PyObject *pFunc = PyObject_GetAttrString(pModule, "fibonacci");

    if (pFunc && PyCallable_Check(pFunc)) {
      PyObject *pArgs = PyTuple_Pack(1, PyLong_FromLong(10)); // Αριθμός όρων
      PyObject *pValue = PyObject_CallObject(pFunc, pArgs);
      Py_DECREF(pArgs);

      if (pValue != NULL) {
        if (PyList_Check(pValue)) {
          for (Py_ssize_t i = 0; i < PyList_Size(pValue); i++) {
            PyObject *item = PyList_GetItem(pValue, i);
            if (item) {
              printf("%ld ", PyLong_AsLong(item));
            }
          }
          printf("\n");
        }
        Py_DECREF(pValue);
      } else {
        PyErr_Print();
      }
      Py_DECREF(pFunc);
    } else {
      PyErr_Print();
    }
    Py_DECREF(pModule);
  } else {
    PyErr_Print();
  }

  Py_Finalize();
  return 0;
}

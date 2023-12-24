#include <Python.h>

int main() {
  // Αρχικοποίηση του διερμηνευτή της Python
  Py_Initialize();
  // Εύρεση του Python script στον ίδιο κατάλογο
  PyRun_SimpleString("import sys");
  PyRun_SimpleString("sys.path.append(\".\")");

  // Import του module ch20_script και της συνάρτησης reverse_string
  PyObject *moduleName = PyUnicode_FromString("ch20_script");
  PyObject *module = PyImport_Import(moduleName);
  PyObject *functionName = PyUnicode_FromString("reverse_string");
  PyObject *function = PyObject_GetAttr(module, functionName);

  // Δημιουργία ορισμάτων και κλήση της συνάρτησης Python
  PyObject *args = PyTuple_New(1);
  PyTuple_SetItem(args, 0, PyUnicode_FromString("Hello, world!"));
  PyObject *result = PyObject_CallObject(function, args);

  // Λήψη του ανεστραμμένου λεκτικού από το αποτέλεσμα που επιστρέφει η Python
  const char *reversedString = PyUnicode_AsUTF8(result);
  printf("%s\n", reversedString);

  // Απελευθέρωση μνήμης
  Py_DECREF(moduleName);
  Py_DECREF(module);
  Py_DECREF(functionName);
  Py_DECREF(function);
  Py_DECREF(args);
  Py_DECREF(result);

  // Τερματισμός του διερμηνευτή της Python
  Py_Finalize();

  return 0;
}
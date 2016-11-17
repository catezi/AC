#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <iostream>
//#include <python3.5/Python.h>


//using namespace boost::python;
using namespace std;

int transform(string s) {
    Py_Initialize();
    if (!Py_IsInitialized()) {
        return -1;
    }
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('./')");
    PyObject *pName,*pModule,*pDict,*pFunc,*pArgs;
    pName = PyString_FromString("transform");
    pModule = PyImport_Import(pName);
    if (!pModule) {
        printf("can't find transform.py");
        //getchar();
        return -1;
    }
    pDict = PyModule_GetDict(pModule);
    if (!pDict) {
        return -1;
    }
    pFunc = PyDict_GetItemString(pDict, "string2int");
    if (!pFunc || !PyCallable_Check(pFunc)) {
        printf("can't find function [string2int]");
        //getchar();
        return -1;
    }
    pArgs = PyTuple_New(1);
    PyTuple_SetItem(pArgs, 0, Py_BuildValue("s", s));
    PyObject_CallObject(pFunc, pArgs);
    Py_DECREF(pName);
    Py_DECREF(pArgs);
    Py_DECREF(pModule);
    Py_Finalize();
    return 0;
}

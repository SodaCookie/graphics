#include "graphics.h"
#include <SDL.h>

char *INIT_DOC =
"Initializing the graphics library.";
static PyObject *graphics_init(PyObject *self, PyObject *args){
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0){
		PyErr_SetString(GraphicsError, "SDL was not able to initize");
		return NULL;
	}
	Py_INCREF(Py_None);
	return Py_None;
}

char *SDL_VERSION_DOC =
"Returns the version of SDL being used.";
static PyObject *graphics_get_sdl_version(PyObject *self){
	SDL_version linked;
	SDL_GetVersion(&linked);
	return Py_BuildValue("(iii)", linked.major, linked.minor, linked.patch);
}

// Define Methods and Module
static PyMethodDef graphics_methods[] = {
	{ "init", (PyCFunction) graphics_init, METH_VARARGS, INIT_DOC },
	{ "get_sdl_version", (PyCFunction) graphics_get_sdl_version, METH_NOARGS, SDL_VERSION_DOC },
	{ NULL, NULL, 0, NULL }
};

static PyModuleDef graphics_module = {
	PyModuleDef_HEAD_INIT,
	"graphics",
	"",
	-1,
	graphics_methods
};

PyMODINIT_FUNC PyInit_graphics(void){
	PyObject *m;
	m = PyModule_Create(&graphics_module);
	
	if (m == NULL){
		return NULL;
	}

	GraphicsError = PyErr_NewException("graphics.error", PyExc_RuntimeError, NULL);
	Py_INCREF(GraphicsError);
	PyModule_AddObject(m, "error", GraphicsError);
	return m;
}
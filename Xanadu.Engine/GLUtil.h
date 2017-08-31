#ifndef XANADU_SINGLE_INCLUDE_GLUTIL_H
#define XANADU_SINGLE_INCLUDE_GLUTIL_H

//WIN32 INLCUDE
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

// standard libs
#include <string>
#include <sstream>



#define GLEW_STATIC
// Open GL includes
#include <gl/glew.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <gl/glext.h>
#include <gl/wglew.h>

// link to libraries
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glew32.lib")
#pragma comment(lib, "glu32.lib")



#endif



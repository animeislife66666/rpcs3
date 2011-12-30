#pragma once

//#define USE_GS_FRAME
#ifdef USE_GS_FRAME

#include "Emu/Memory/Memory.h"
#include "Emu/Cell/PPCThread.h"
#include "Ini.h"
#include "wx/glcanvas.h"
#include "GL/gl.h"
#include "GL/glut.h"
#define GL_GLEXT_PROTOTYPES
#include "GL/glext.h"
#include "Utilites/Timer.h"

#pragma comment(lib, "glut32.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "gl.lib")

class GSFrame_GL : public wxFrame
{
public:
	GSFrame_GL(wxWindow* parent);
};

#endif
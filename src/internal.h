#ifndef LUNAVG_INTERNAL_H
#define LUNAVG_INTERNAL_H

#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define LUA_COMPAT_APIINTCASTS
#define NANOVG_GL2_IMPLEMENTATION

#include <GL/glew.h>

#include <lua.h>

#include "lualib.h"
#include "lauxlib.h"
#include "lautoc.h"

#include "nanovg.h"
#include "nanosvg.h"
#include "nanovg_gl.h"

#include "lunavg.h"

int luaopen_lunavg(lua_State *L);

#endif

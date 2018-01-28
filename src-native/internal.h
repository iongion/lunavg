#ifndef LUNAVG_INTERNAL_H
#define LUNAVG_INTERNAL_H

#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define LUNAVG_NAME "lunavg"
#define LUNAVG_VERSION "1.0"

#include "lunavg.h"

int luaopen_lunavg(lua_State *L);

#endif

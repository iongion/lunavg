/* The MIT License (MIT)
 *
 * Copyright (c) 2018 Ionut Stoica
 *
 * Software repository: lunavg, https://github.com/iongion/lunavg
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef LUNAVG_H
#define LUNAVG_H

#define LUNAVG_NAME "LunaVG"
#define LUNAVG_VERSION "1.0"
#define LUA_COMPAT_APIINTCASTS
#define NANOVG_GL2_IMPLEMENTATION

#include <GL/glew.h>

#include <lua.h>

#include "lualib.h"
#include "lauxlib.h"
// #include "lautoc.h"

#include "nanovg.h"
#include "nanosvg.h"
#include "nanovg_gl.h"

#endif

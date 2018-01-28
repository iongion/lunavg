#include "internal.h"

#define NANOVG_MODULE_NAME "NanoVG"
#define NANOVG_MODULE_VERSION "1.0"

#define NANOSVG_MODULE_NAME "NanoSVG"
#define NANOSVG_MODULE_VERSION "1.0"

typedef enum NVGwinding NVGwinding;
typedef enum NVGsolidity NVGsolidity;
typedef enum NVGlineCap NVGlineCap;
typedef enum NVGalign NVGalign;
typedef enum NVGblendFactor NVGblendFactor;
typedef enum NVGcompositeOperation NVGcompositeOperation;
typedef enum NVGimageFlags NVGimageFlags;
typedef enum NVGtexture NVGtexture;

void register_LunaVG_Table(lua_State* L) {
    lua_createtable(L, 0, 0);
    lua_pushstring(L, LUNAVG_NAME);
    lua_setfield(L, -2, "NAME");
    lua_pushstring(L, LUNAVG_VERSION);
    lua_setfield(L, -2, "VERSION");
}

int luaopen_lunavg(lua_State *L)
{
    // register_LunaVG_Table(L);
    /* NVGcolor */
    luaA_struct(L, NVGcolor);
    luaA_struct_member(L, NVGcolor, rgba, float*);
    luaA_struct_member(L, NVGcolor, r, float);
    luaA_struct_member(L, NVGcolor, g, float);
    luaA_struct_member(L, NVGcolor, b, float);
    luaA_struct_member(L, NVGcolor, a, float);
    /* NVGPaint */
    luaA_struct(L, NVGpaint);
    luaA_struct_member(L, NVGpaint, xform, float*);
    luaA_struct_member(L, NVGpaint, extent, float*);
    luaA_struct_member(L, NVGpaint, radius, float);
    luaA_struct_member(L, NVGpaint, feather, float);
    luaA_struct_member(L, NVGpaint, innerColor, NVGcolor);
    luaA_struct_member(L, NVGpaint, outerColor, NVGcolor);

    return 1;
}

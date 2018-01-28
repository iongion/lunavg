#include "internal.h"

#define NANOVG_MODULE_NAME "NanoVG"
#define NANOVG_MODULE_VERSION "1.0"

#define NANOSVG_MODULE_NAME "NanoSVG"
#define NANOSVG_MODULE_VERSION "1.0"

typedef struct {
    int flags;
    struct NVGcontext* context;
} lNanoVG_state_t;

void register_NanoVG_MetaTable(lua_State* L);
void register_NanoSVG_MetaTable(lua_State* L);

/* NanoVG  */
static int lNanoVG_new(lua_State *L)
{
    int flags = (int)luaL_checkint(L, 1);
    lNanoVG_state_t *state = (lNanoVG_state_t *)lua_newuserdata(L, sizeof(*state));
    if (state == NULL) {
        luaL_error(L, "Could not initalize NanoVG");
        return -1;
    }
    state->flags = flags;
    state->context = nvgCreateGL2(flags);
    if (state->context == NULL) {
        luaL_error(L, "Could not initalize NanoVG GL2 context");
        return -1;
    }
    luaL_getmetatable(L, NANOVG_MODULE_NAME);
    return 1;
}
static int lNanoVG_tostring(lua_State *L)
{
    lua_pushfstring(L, NANOVG_MODULE_NAME);
    return 1;
}
static int lNanoVG_destroy(lua_State *L)
{
    lNanoVG_state_t *state;
    state = (lNanoVG_state_t *)luaL_checkudata(L, 1, NANOVG_MODULE_NAME);
    if (state != NULL) {
        nvgDeleteGL2(state->context);
    }
    return 0;
}
static int lNanoVG_beginFrame(lua_State *L)
{
    return 1;
}
static const struct luaL_Reg lNanoVG_methods[] = {
    { "__gc", lNanoVG_destroy },
    { NULL, NULL },
};
static const struct luaL_Reg lNanoVG_functions[] = {
    { "new", lNanoVG_new },
    { "beginFrame", lNanoVG_beginFrame },
    { NULL,  NULL }
};

/* NanoSVG  */
static int lNanoSVG_new(lua_State *L)
{
    /* TODO: complete */
    const lua_Number x = luaL_checknumber(L, 1);
    register_NanoSVG_MetaTable(L);
    return 1;
}
static int lNanoSVG_tostring(lua_State *L)
{
    lua_pushfstring(L, NANOSVG_MODULE_NAME);
    return 1;
}
static int lNanoSVG_dumpVersion(lua_State *L)
{
    lua_pushfstring(L, NANOSVG_MODULE_VERSION);
    return 1;
}
static int lNanoSVG_destroy(lua_State *L)
{
    return 0;
}
static const struct luaL_Reg lNanoSVG_methods[] = {
    { "__gc", lNanoSVG_destroy },
    { "__tostring", lNanoSVG_tostring },
    { NULL, NULL },
};
static const struct luaL_Reg lNanoSVG_functions[] = {
    { "new", lNanoSVG_new },
    { "dumpVersion", lNanoSVG_dumpVersion },
    { NULL,  NULL }
};

void register_LunaVG_Table(lua_State* L) {
    lua_createtable(L, 0, 0);
    lua_pushstring(L, LUNAVG_NAME);
    lua_setfield(L, -2, "NAME");
    lua_pushstring(L, LUNAVG_VERSION);
    lua_setfield(L, -2, "VERSION");
}

void register_NanoVG_MetaTable(lua_State* L) {
    int lib_id, meta_id;
    lua_createtable(L, 0, 0);
    lua_pushstring(L, NANOVG_MODULE_NAME);
    lua_setfield(L, -2, "NAME");
    lua_pushstring(L, NANOVG_MODULE_VERSION);
    lua_setfield(L, -2, "VERSION");
    lib_id = lua_gettop(L);
    luaL_newmetatable(L, NANOVG_MODULE_NAME);
    meta_id = lua_gettop(L);
    luaL_setfuncs(L, lNanoVG_methods, 0);
    luaL_newlib(L, lNanoVG_functions);
    lua_setfield(L, meta_id, "__index");
    luaL_newlib(L, lNanoVG_methods);
    lua_setfield(L, meta_id, "__metatable");
    lua_setmetatable(L, lib_id);
}

void register_NanoSVG_MetaTable(lua_State* L) {
    int lib_id, meta_id;
    lua_createtable(L, 0, 0);
    lua_pushstring(L, NANOSVG_MODULE_NAME);
    lua_setfield(L, -2, "NAME");
    lua_pushstring(L, NANOSVG_MODULE_VERSION);
    lua_setfield(L, -2, "VERSION");
    lib_id = lua_gettop(L);
    luaL_newmetatable(L, NANOSVG_MODULE_NAME);
    meta_id = lua_gettop(L);
    luaL_setfuncs(L, lNanoSVG_methods, 0);
    luaL_newlib(L, lNanoSVG_functions);
    lua_setfield(L, meta_id, "__index");
    luaL_newlib(L, lNanoSVG_methods);
    lua_setfield(L, meta_id, "__metatable");
    lua_setmetatable(L, lib_id);
}

int luaopen_lunavg(lua_State *L)
{
    register_LunaVG_Table(L);

    lua_getmetatable(L, -1);
    register_NanoVG_MetaTable(L);
    lua_setfield(L, -2, "NanoVG");

    lua_getmetatable(L, -1);
    register_NanoSVG_MetaTable(L);
    lua_setfield(L, -2, "NanoSVG");

    return 1;
}

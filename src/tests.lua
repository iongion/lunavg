-- NanoVG = {
--   version = "1.0.1"
-- }
-- NanoVG_mt = { __index = NanoVG }
-- function NanoVG:new(flags)
--   return setmetatable( {flags=flags}, NanoVG_mt)
-- end
-- function NanoVG:dummyVersion()
--   return self.version
-- end
-- 
-- NanoSVG = {}
-- NanoSVG_mt = { __index = NanoVG }
-- function NanoVG:new(flags)
--   return setmetatable( {flags=flags}, NanoVG_mt)
-- end
-- 
-- vg = {
--   NAME = "lunavg",
--   VERSION = "1.0.0",
--   NanoVG = NanoVG,
--   NanoSVG = NanoSVG
-- }
-- 
-- print(vg.VERSION)
-- inst = vg.NanoVG.new(1)
-- print(inst:dummyVersion())
-- function __FILE__() return debug.getinfo(2,'S').source end
-- function __DIR__() return string.gsub(debug.getinfo(2,'S').source, "^@(.+/)[^/]+$", "%1") end
-- function __LINE__() return debug.getinfo(2, 'l').currentline end

-- Usage:
local pprint = require("pprint")
local vg = require("lunavg")

local glfw = require('moonglfw')
local gl = require('moongl')

print(glfw._VERSION)
print(glfw._GLFW_VERSION)
print(glfw.get_version())
print(glfw.get_version_string())

local function error_callback(ec, description)
  io.stderr:write(string.format("Error: %s (%d)\n", description, ec))
end

local function key_callback(window, key, scancode, action)
  print(window, key, scancode, action)
  if key == 'escape' and action == 'press' then
     glfw.set_window_should_close(window, true)
  end
end

glfw.set_error_callback(error_callback)
glfw.window_hint('context version major', 2)
glfw.window_hint('context version minor', 0)

local window = glfw.create_window(640, 480, "Test")
glfw.set_key_callback(window, key_callback)
glfw.make_context_current(window)
-- glfw.version_hint(2, 0, "GLFW_OPENGL_COMPAT_PROFILE")
gl.init()
glfw.swap_interval(1)

pprint(vg.NAME)
pprint(vg.VERSION)
pprint(vg.NanoVG)
pprint(vg.NanoSVG)

inst = vg.NanoSVG.new(384)
pprint(inst)
pprint(vg.NanoSVG.dumpVersion)
vg.NanoSVG.dumpVersion()
-- pprint(inst)
-- pprint(inst)
-- pprint(inst)
-- pprint(inst)

-- pprint(vg.NanoVG.new(1))

-- pprint(NanoVG)
-- pprint(NanoSVG)
-- pprint(NanoSVG.new(1))

collectgarbage()
collectgarbage('stop')
while not glfw.window_should_close(window) do
   local width, height = glfw.get_framebuffer_size(window)
   local ratio = width/height
   gl.viewport(0, 0, width, height)
   gl.clear('color')
   vg.BeginFrame(vg, width, height, ratio);
   vg.EndFrame(vg);
   glfw.swap_buffers(window)
   collectgarbage('step')
   glfw.poll_events()
end

glfw.destroy_window(window)

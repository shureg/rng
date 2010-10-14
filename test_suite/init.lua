#!/usr/bin/env lua

require("rng_lua_swig_wrap")
rng = rng_lua_swig_wrap
g = rng.mtwistGenerator()

sample = function(g,N)
   t = {}
   for i=1,N do t[#t+1] = g() end
   return table.concat(t,' ')
end

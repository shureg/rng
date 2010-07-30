--This is a Lua configuration file for the RNG library
--Currently its only aim is to determine the type of UnitIntervalGenerator 
-- (the object that generates a number in the unit interval) 
-- that will be used by the library's random number generators 
--The library executes Lua chunks prior to and following the execution of this script
--Any script modification must take those wrapping statements into account
--Normally, the only thing that needs to be present here is a
-- statement of the form UIG = rng.<UIGGeneratorType>
-- e.g.
-- UIG = rng.gslPRGenerator()

-- Opening Lua chunk executed by the library:
--  require('rng_lua_swig_wrap')
--  rng = rng_lua_swig_wrap

UIG = rng.mtwistGenerator()

-- Concluding Lua chunk executed by the library:
--  rng.RandomGenerator_get_external_uig(UIG)

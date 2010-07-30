#!/usr/bin/env python

import callback_log_python_swig_wrap as cbl

F = cbl.FileCallbackLog("init.log","test",cbl.TRACE)

import rng_python_swig_wrap as rng

U = rng.UniformGenerator()

print U()

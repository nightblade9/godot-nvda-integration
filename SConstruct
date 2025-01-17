#!/usr/bin/env python

env = SConscript("../SConstruct")

# For the reference:
# - CCFLAGS are compilation flags shared between C and C++
# - CFLAGS are for C-specific compilation flags
# - CXXFLAGS are for C++-specific compilation flags
# - CPPFLAGS are for pre-processor flags
# - CPPDEFINES are for pre-processor defines
# - LINKFLAGS are for linking flags

# tweak this if you want to use different folders, or more folders, to store your source code in.
env.Append(CPPPATH=["src/"])
sources = Glob("src/*.cpp")

if env["arch"] == "x86_64":
    env.Append(LIBS=File("nvdaControllerClient64.lib"))
elif env["arch"] == "x86_32":
    env.Append(LIBS=File("nvdaControllerClient32.lib"))
    
library = env.SharedLibrary(
    "demo/addons/nvda_integration/bin/{}/libgdnvda{}{}".format(env["HOST_ARCH"], env["suffix"], env["SHLIBSUFFIX"]),
    source=sources
)

Default(library)

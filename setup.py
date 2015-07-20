from setuptools import setup, Extension
import os

os.environ["CC"] = "g++"

include_dirs = ["C:\MinGW\include\SDL", "C:\MinGW\include", "C:\Python32\include"]
library_dirs = ["C:\MinGW\lib", "C:\Python32\libs"]
libraries = ["SDL2", "SDL2main"]

setup(name='graphics',
      version='1.0',
      author="Eric Zhang",
      license="MIT",
      packages=["graphics"],
      ext_modules=[Extension("graphics", ["graphics/core/base.cpp"],
                             include_dirs=include_dirs,
                             library_dirs=library_dirs,
                             libraries=libraries,
                             language="C++"),
                   Extension("graphics.display", ["graphics/core/base.cpp"],
                             include_dirs=include_dirs,
                             library_dirs=library_dirs,
                             libraries=libraries,
                             language="C++")
                   ])
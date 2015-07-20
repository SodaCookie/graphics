from setuptools import setup, Extension
import os

os.environ["CC"] = "g++"

include_dirs = []
library_dirs = []

setup(name='graphics',
      version='1.0',
      author="Eric Zhang",
      license="MIT",
      ext_modules=[])
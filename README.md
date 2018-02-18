# Open Motherload

[![Build Status](https://travis-ci.org/Frenzy-Alex/OpenMotherload.svg?branch=master)](https://travis-ci.org/Frenzy-Alex/OpenMotherload)

**Open Motherload (OML)** is an open-source implementation of Motherload game developed by XGen Studios.

**Current Version: PreBeta**

## Requirements
---------------
* [CMake 3.7][CMake] or newer. The executable `cmake` should be on the system path.
* [GCC][GCC] under Linux.

## How to build
---------------
* **Linux**
    * To build on Linux you must have installed the next packages: **xorg-dev** **libopenal-dev** **libgl1-mesa-dev**.
        * **sudo apt-get install xorg-dev libopenal-dev libgl1-mesa-dev** 
    * run ./build.sh for build project or ./clear_build.sh for clear build.
* **Windows**
	* Not Implemented Yet
* **Mac OS X**
	* Not Implemented Yet

## How to generate documentation by doxygen
---------------
* **Linux**
    * To generate docs on Linux you must have installed: **doxygen** and **graphviz** library.
        * **sudo apt-get install doxygen graphviz**
    * run doxygen 

## License
----------
The **Open Motherload** is released under the **[GPLv3][GPLv3]** license (see LICENSE.txt), 
and uses third party libraries that are distributed under their own terms (see LICENSE-3RD-PARTY.txt)

[OpenAL]:https://openal.org/
[OpenGL]:https://www.opengl.org/
[CMake]:https://cmake.org/download/
[GCC]:https://gcc.gnu.org/
[GPLv3]:https://www.gnu.org/licenses/gpl.txt
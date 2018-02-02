#!/bin/bash

if [ ! -d "./Build/CMake/Output/" ];
then
	mkdir ./Build/CMake/Output/
fi

( cd ./Build/CMake/Output && ( exec cmake ../../.. ) && ( exec make -j 4 ) )
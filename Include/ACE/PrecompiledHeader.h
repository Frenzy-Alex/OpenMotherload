/********************************************************************************
 *                                                                              *
 *          Copyright (C) 2017 Oleksandr Lynok. All Rights Reserved.            *
 *                                                                              *
 *                  This file is part of Advanced Crystal Engine.               *
 *                                                                              *
 *      Advanced Crystal Engine is licensed under GNU Lesser General Public     *
 *  License (LGPL), version 3.  See file "LICENSE.txt".                         *
 *                                                                              *
 ********************************************************************************/

#pragma once

#include <ACE/Base/Misc/PlatformDetection.h>

/********************************************************************************
 *  Basic Headers                                                               *
 ********************************************************************************/

#include <climits>
#include <cstdarg>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <typeinfo>

#include <string>

#include <pthread.h>

#include <AL/al.h>
#include <AL/alc.h>
#include <AL/alut.h>

#if ACE_Platform == ACE_Platform_Linux

#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

#endif
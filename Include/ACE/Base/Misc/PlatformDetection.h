/********************************************************************************
 *                                                                              *
 *          Copyright (C) 2018 Oleksandr Lynok. All Rights Reserved.            *
 *                                                                              *
 *                  This file is part of Advanced Crystal Engine.               *
 *                                                                              *
 *      Advanced Crystal Engine is licensed under GNU Lesser General Public     *
 *  License (LGPL), version 3.  See file "LICENSE.txt".                         *
 *                                                                              *
 ********************************************************************************/

#pragma once

/********************************************************************************
 *  Platform Detection                                                          *
 ********************************************************************************/

#define ACE_Platform_Unknown        -1
#define ACE_Platform_Linux          1
#define ACE_Platform_MacOSX         2
#define ACE_Platform_Windows        3

#if __linux__
#   if __ANDROID__
#   else
#       define ACE_Platform     ACE_Platform_Linux
#   endif
#elif __APPLE__
#   if TARGET_OS_MAC
#       define ACE_Platform     ACE_Platform_MacOSX
#   endif
#elif _WIN32_
#   define ACE_Platform     ACE_Platform_Windows
#   if _WIN64
#   else
#   endif
#endif

#ifndef ACE_Platform
#   error Undefined platform
#   define ACE_Platform ACE_Platform_Unknown
#endif  // ACE_Platform

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
 *  Macro                                                                       *
 ********************************************************************************/

//  Safe New & Delete Macro
#define ACE_SafeNew( data, type, ... )                  if( data == nullptr ) { data = new type( __VA_ARGS__ ); }
#define ACE_SafeNewArr( data, type, count )             if( data == nullptr ) { data = new type[count]; }
#define ACE_SafeDelete( data )                          if( data != nullptr ) { delete data; data = nullptr; }
#define ACE_SafeDeleteArr( data )                       if( data != nullptr ) { delete[] data; data = nullptr; }

//  Continue If Macro
#define ACE_BreakIf( expr, ... )                        if( expr ) { __VA_ARGS__; break; }
#define ACE_ContinueIf( expr, ... )                     if( expr ) { __VA_ARGS__; continue; }

//  Return If Macro
#define ACE_ReturnIf( expr, ... )                       if( expr ) { return __VA_ARGS__; }
#define ACE_ReturnTrueIf( expr )                        ACE_ReturnIf( expr, true );
#define ACE_ReturnFalseIf( expr )                       ACE_ReturnIf( expr, false );
#define ACE_ReturnNullptrIf( expr )                     ACE_ReturnIf( expr, nullptr );

#define ACE_NoCopyable( obj )                           obj( const obj& ) = delete

#define ACE_NoMovable( obj )                            obj( obj&& ) = delete;

#define ACE_NoCopyMovable( obj )                        obj( obj&& ) = delete
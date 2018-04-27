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

#include <ACE/Base/Misc/Types.h>

namespace ACE
{
    class ACE_String final
    {
    public:
        /**
         * @brief Default constructor
         */
        ACE_String() noexcept;

        /**
         * @brief Copy constructor
         * @param in_str Source string
         */
        ACE_String( const ACE_String &in_str );

        /**
         * @brief Substring constructor
         * @param in_str Source string
         * @param in_pos Start position
         * @param in_len Length
         */
        ACE_String( const ACE_String &in_str, size in_pos, size in_len );

        /**
         * @brief Move constructor
         * @param in_out_str
         */
        ACE_String( ACE_String &&in_out_str ) noexcept;

        /**
         * @brief
         * @param in_str
         */
        explicit ACE_String( char *in_str );
        explicit ACE_String( char **in_str ) noexcept;

        /**
         * @brief C string copy constructor
         * @param in_str Source string
         */
        ACE_String( const char *in_str );

        /**
         * @brief C string substring constructor
         * @param in_str Source string
         * @param in_pos
         * @param in_len
         */
        ACE_String( const char *in_str, size in_pos, size in_len );

        /**
         * @brief Fill constructor
         * @param in_len Length of new string
         * @param in_char Character to fill the string.
         */
        ACE_String( size in_len, char in_char );

        /**
         * @brief Destructor
         */
        ~ACE_String() noexcept;

        /**
         * @brief Is string empty
         * @return true if string length is 0, false otherwise
         */
        bool IsEmpty() const;

        /**
         * @brief Length of the string
         * @return The number of bytes in the string
         */
        size Length() const;

        /**
         * @brief Resize the string
         * @param in_len New string length
         */
        void Resize( size in_len ) noexcept;

        /**
         * @brief Resize the string
         * @param in_len New string length
         * @param in_char Character to fill the string (in case the string is expanded).
         */
        void Resize( size in_len, char in_char ) noexcept;


        /**
         * @brief Clear the string
         */
        void Clear() noexcept;

        //        char &At( uint in_pos ) noexcept;
        //        const char &At( uint in_pos ) const noexcept;

        /**
         * @brief Get C string
         * @return A pointer to the c string.
         */
        const char *CStr() const noexcept;

        ACE_String SubString( size in_position, size in_length ) const;

        //  Assignment operators
        ACE_String &operator=( const ACE_String &in_str );
        ACE_String &operator+=( const ACE_String &in_str );
        ACE_String &operator+=( const char *in_str );
        ACE_String &operator+=( char in_char );

        //  Arithmetic Operators
        friend ACE_String operator+( const ACE_String &in_lhs, const ACE_String &in_rhs );
        friend ACE_String operator+( const ACE_String &in_lhs, const char *in_rhs );
        friend ACE_String operator+( const char *in_lhs, const ACE_String &in_rhs );

        //  Comparsion Operators
        friend bool operator==( const ACE_String &in_lhs, const ACE_String &in_rhs );
        friend bool operator!=( const ACE_String &in_lhs, const ACE_String &in_rhs );

        //  Member Access Operators
        char &operator[]( uint in_pos ) noexcept;
        const char &operator[]( uint in_pos ) const noexcept;

        //  Static Functions
        static ACE_String Format( const char *in_str, ... );
    private:
        char *m_string;
    };

    template< typename T >
    T ACE_StringTo( const ACE_String &in_str, bool *out_result = nullptr );

    template<>
    bool ACE_StringTo( const ACE_String &in_str, bool *out_result );

    template<>
    int ACE_StringTo( const ACE_String &in_str, bool *out_result );

    template<>
    uint ACE_StringTo( const ACE_String &in_str, bool *out_result );

    ACE_String ACE_ToString( short in_value );
    ACE_String ACE_ToString( ushort in_value );
    ACE_String ACE_ToString( int in_value );
    ACE_String ACE_ToString( uint in_value );
    ACE_String ACE_ToString( long in_value );
    ACE_String ACE_ToString( ulong in_value );
    ACE_String ACE_ToString( float in_value );
    ACE_String ACE_ToString( double in_value );

    template< typename T >
    const ACE_String &ACE_ToString( T in_value );

    template< typename T >
    const char *ACE_ToCString( T in_value );
}

#include <ACE/Base/Containers/String.inl>
/**************************************************************************/
/*! 
    @file     Adafruit_NFCShield_I2C.h
    @author   Adafruit Industries
	@license  BSD (see license.txt)
	
	This is a library for the Adafruit PN532 NFC/RFID shield
	This library works with the Adafruit NFC breakout 
	----> https://www.adafruit.com/products/364
	
	Check out the links above for our tutorials and wiring diagrams 
	These chips use I2C to communicate
	
	Adafruit invests time and resources providing this open source code, 
	please support Adafruit and open-source hardware by purchasing 
	products from Adafruit!

	@section  HISTORY

    v1.3  - Modified to work with I2C
	
	v1.1  - Added full command list
          - Added 'verbose' mode flag to constructor to toggle debug output
          - Changed readPassiveTargetID() to return variable length values
	
*/
/**************************************************************************/

#ifndef Adafruit_NFCShield_I2C_h
#define Adafruit_NFCShield_I2C_h

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 //#include "WProgram.h"
#endif

//#include <Wire.h>
/*
  TwoWire.h - TWI/I2C library for Arduino & Wiring
  Copyright (c) 2006 Nicholas Zambetti.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

  Modified 2012 by Todd Krein (todd@krein.org) to implement repeated starts
*/

#ifndef TwoWire_h
#define TwoWire_h

#include <inttypes.h>
/*
  Stream.h - base class for character-based streams.
  Copyright (c) 2010 David A. Mellis.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

  parsing functions based on TextFinder library by Michael Margolis
*/

#ifndef Stream_h
#define Stream_h

/* Copyright (c) 2004,2005,2007 Joerg Wunsch
   Copyright (c) 2005, Carlos Lamas
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.

   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.

   * Neither the name of the copyright holders nor the names of
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE. */

/* $Id$ */

#ifndef __INTTYPES_H_
#define __INTTYPES_H_

/* Copyright (c) 2002,2004,2005 Marek Michalkiewicz
   Copyright (c) 2005, Carlos Lamas
   Copyright (c) 2005,2007 Joerg Wunsch
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.

   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.

   * Neither the name of the copyright holders nor the names of
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE. */

/* $Id$ */

/*
 * ISO/IEC 9899:1999  7.18 Integer types <stdint.h>
 */

#ifndef __STDINT_H_
#define __STDINT_H_

/** \file */
/** \defgroup avr_stdint <stdint.h>: Standard Integer Types
    \code #include <stdint.h> \endcode

    Use [u]intN_t if you need exactly N bits.

    Since these typedefs are mandated by the C99 standard, they are preferred
    over rolling your own typedefs.  */

/*
 * __USING_MINT8 is defined to 1 if the -mint8 option is in effect.
 */
#if __INT_MAX__ == 127
# define __USING_MINT8 1
#else
# define __USING_MINT8 0
#endif

/* Integer types */

#if defined(__DOXYGEN__)

/* doxygen gets confused by the __attribute__ stuff */

/** \name Exact-width integer types
    Integer types having exactly the specified width */

/*@{*/

/** \ingroup avr_stdint
    8-bit signed type. */

typedef signed char int8_t;

/** \ingroup avr_stdint
    8-bit unsigned type. */

typedef unsigned char uint8_t;

/** \ingroup avr_stdint
    16-bit signed type. */

typedef signed int int16_t;

/** \ingroup avr_stdint
    16-bit unsigned type. */

typedef unsigned int uint16_t;

/** \ingroup avr_stdint
    32-bit signed type. */

typedef signed long int int32_t;

/** \ingroup avr_stdint
    32-bit unsigned type. */

typedef unsigned long int uint32_t;

/** \ingroup avr_stdint
    64-bit signed type.
    \note This type is not available when the compiler
    option -mint8 is in effect. */

typedef signed long long int int64_t;

/** \ingroup avr_stdint
    64-bit unsigned type.
    \note This type is not available when the compiler
    option -mint8 is in effect. */

typedef unsigned long long int uint64_t;

/*@}*/

#else /* !defined(__DOXYGEN__) */

/* actual implementation goes here */

typedef signed int int8_t __attribute__((__mode__(__QI__)));
typedef unsigned int uint8_t __attribute__((__mode__(__QI__)));
typedef signed int int16_t __attribute__ ((__mode__ (__HI__)));
typedef unsigned int uint16_t __attribute__ ((__mode__ (__HI__)));
typedef signed int int32_t __attribute__ ((__mode__ (__SI__)));
typedef unsigned int uint32_t __attribute__ ((__mode__ (__SI__)));
#if !__USING_MINT8
typedef signed int int64_t __attribute__((__mode__(__DI__)));
typedef unsigned int uint64_t __attribute__((__mode__(__DI__)));
#endif

#endif /* defined(__DOXYGEN__) */

/** \name Integer types capable of holding object pointers
    These allow you to declare variables of the same size as a pointer. */

/*@{*/

/** \ingroup avr_stdint
    Signed pointer compatible type. */

typedef int16_t intptr_t;

/** \ingroup avr_stdint
    Unsigned pointer compatible type. */

typedef uint16_t uintptr_t;

/*@}*/

/** \name Minimum-width integer types
   Integer types having at least the specified width */

/*@{*/

/** \ingroup avr_stdint
    signed int with at least 8 bits. */

typedef int8_t   int_least8_t;

/** \ingroup avr_stdint
    unsigned int with at least 8 bits. */

typedef uint8_t  uint_least8_t;

/** \ingroup avr_stdint
    signed int with at least 16 bits. */

typedef int16_t  int_least16_t;

/** \ingroup avr_stdint
    unsigned int with at least 16 bits. */

typedef uint16_t uint_least16_t;

/** \ingroup avr_stdint
    signed int with at least 32 bits. */

typedef int32_t  int_least32_t;

/** \ingroup avr_stdint
    unsigned int with at least 32 bits. */

typedef uint32_t uint_least32_t;

#if !__USING_MINT8 || defined(__DOXYGEN__)
/** \ingroup avr_stdint
    signed int with at least 64 bits.
    \note This type is not available when the compiler
    option -mint8 is in effect. */

typedef int64_t  int_least64_t;

/** \ingroup avr_stdint
    unsigned int with at least 64 bits.
    \note This type is not available when the compiler
    option -mint8 is in effect. */

typedef uint64_t uint_least64_t;
#endif

/*@}*/


/** \name Fastest minimum-width integer types
   Integer types being usually fastest having at least the specified width */

/*@{*/

/** \ingroup avr_stdint
    fastest signed int with at least 8 bits. */

typedef int8_t int_fast8_t;

/** \ingroup avr_stdint
    fastest unsigned int with at least 8 bits. */

typedef uint8_t uint_fast8_t;

/** \ingroup avr_stdint
    fastest signed int with at least 16 bits. */

typedef int16_t int_fast16_t;

/** \ingroup avr_stdint
    fastest unsigned int with at least 16 bits. */

typedef uint16_t uint_fast16_t;

/** \ingroup avr_stdint
    fastest signed int with at least 32 bits. */

typedef int32_t int_fast32_t;

/** \ingroup avr_stdint
    fastest unsigned int with at least 32 bits. */

typedef uint32_t uint_fast32_t;

#if !__USING_MINT8 || defined(__DOXYGEN__)
/** \ingroup avr_stdint
    fastest signed int with at least 64 bits.
    \note This type is not available when the compiler
    option -mint8 is in effect. */

typedef int64_t int_fast64_t;

/** \ingroup avr_stdint
    fastest unsigned int with at least 64 bits.
    \note This type is not available when the compiler
    option -mint8 is in effect. */

typedef uint64_t uint_fast64_t;
#endif

/*@}*/


/** \name Greatest-width integer types
   Types designating integer data capable of representing any value of
   any integer type in the corresponding signed or unsigned category */

/*@{*/

#if __USING_MINT8
typedef int32_t intmax_t;

typedef uint32_t uintmax_t;
#else  /* !__USING_MINT8 */
/** \ingroup avr_stdint
    largest signed int available. */

typedef int64_t intmax_t;

/** \ingroup avr_stdint
    largest unsigned int available. */

typedef uint64_t uintmax_t;
#endif /* __USING_MINT8 */

/*@}*/

/* Helping macro */
#ifndef __CONCAT
#define __CONCATenate(left, right) left ## right
#define __CONCAT(left, right) __CONCATenate(left, right)
#endif

#if !defined(__cplusplus) || defined(__STDC_LIMIT_MACROS)

/** \name Limits of specified-width integer types
   C++ implementations should define these macros only when
   __STDC_LIMIT_MACROS is defined before <stdint.h> is included */

/*@{*/

/** \ingroup avr_stdint
    largest positive value an int8_t can hold. */

#define INT8_MAX 0x7f

/** \ingroup avr_stdint
    smallest negative value an int8_t can hold. */

#define INT8_MIN (-INT8_MAX - 1)

/** \ingroup avr_stdint
    largest value an uint8_t can hold. */

#define UINT8_MAX (__CONCAT(INT8_MAX, U) * 2U + 1U)

#if __USING_MINT8

#define INT16_MAX 0x7fffL
#define INT16_MIN (-INT16_MAX - 1L)
#define UINT16_MAX (__CONCAT(INT16_MAX, U) * 2UL + 1UL)

#define INT32_MAX 0x7fffffffLL
#define INT32_MIN (-INT32_MAX - 1LL)
#define UINT32_MAX (__CONCAT(INT32_MAX, U) * 2ULL + 1ULL)

#else /* !__USING_MINT8 */

/** \ingroup avr_stdint
    largest positive value an int16_t can hold. */

#define INT16_MAX 0x7fff

/** \ingroup avr_stdint
    smallest negative value an int16_t can hold. */

#define INT16_MIN (-INT16_MAX - 1)

/** \ingroup avr_stdint
    largest value an uint16_t can hold. */

#define UINT16_MAX (__CONCAT(INT16_MAX, U) * 2U + 1U)

/** \ingroup avr_stdint
    largest positive value an int32_t can hold. */

#define INT32_MAX 0x7fffffffL

/** \ingroup avr_stdint
    smallest negative value an int32_t can hold. */

#define INT32_MIN (-INT32_MAX - 1L)

/** \ingroup avr_stdint
    largest value an uint32_t can hold. */

#define UINT32_MAX (__CONCAT(INT32_MAX, U) * 2UL + 1UL)

#endif /* __USING_MINT8 */

/** \ingroup avr_stdint
    largest positive value an int64_t can hold. */

#define INT64_MAX 0x7fffffffffffffffLL

/** \ingroup avr_stdint
    smallest negative value an int64_t can hold. */

#define INT64_MIN (-INT64_MAX - 1LL)

/** \ingroup avr_stdint
    largest value an uint64_t can hold. */

#define UINT64_MAX (__CONCAT(INT64_MAX, U) * 2ULL + 1ULL)

/*@}*/

/** \name Limits of minimum-width integer types */
/*@{*/

/** \ingroup avr_stdint
    largest positive value an int_least8_t can hold. */

#define INT_LEAST8_MAX INT8_MAX

/** \ingroup avr_stdint
    smallest negative value an int_least8_t can hold. */

#define INT_LEAST8_MIN INT8_MIN

/** \ingroup avr_stdint
    largest value an uint_least8_t can hold. */

#define UINT_LEAST8_MAX UINT8_MAX

/** \ingroup avr_stdint
    largest positive value an int_least16_t can hold. */

#define INT_LEAST16_MAX INT16_MAX

/** \ingroup avr_stdint
    smallest negative value an int_least16_t can hold. */

#define INT_LEAST16_MIN INT16_MIN

/** \ingroup avr_stdint
    largest value an uint_least16_t can hold. */

#define UINT_LEAST16_MAX UINT16_MAX

/** \ingroup avr_stdint
    largest positive value an int_least32_t can hold. */

#define INT_LEAST32_MAX INT32_MAX

/** \ingroup avr_stdint
    smallest negative value an int_least32_t can hold. */

#define INT_LEAST32_MIN INT32_MIN

/** \ingroup avr_stdint
    largest value an uint_least32_t can hold. */

#define UINT_LEAST32_MAX UINT32_MAX

/** \ingroup avr_stdint
    largest positive value an int_least64_t can hold. */

#define INT_LEAST64_MAX INT64_MAX

/** \ingroup avr_stdint
    smallest negative value an int_least64_t can hold. */

#define INT_LEAST64_MIN INT64_MIN

/** \ingroup avr_stdint
    largest value an uint_least64_t can hold. */

#define UINT_LEAST64_MAX UINT64_MAX

/*@}*/

/** \name Limits of fastest minimum-width integer types */

/*@{*/

/** \ingroup avr_stdint
    largest positive value an int_fast8_t can hold. */

#define INT_FAST8_MAX INT8_MAX

/** \ingroup avr_stdint
    smallest negative value an int_fast8_t can hold. */

#define INT_FAST8_MIN INT8_MIN

/** \ingroup avr_stdint
    largest value an uint_fast8_t can hold. */

#define UINT_FAST8_MAX UINT8_MAX

/** \ingroup avr_stdint
    largest positive value an int_fast16_t can hold. */

#define INT_FAST16_MAX INT16_MAX

/** \ingroup avr_stdint
    smallest negative value an int_fast16_t can hold. */

#define INT_FAST16_MIN INT16_MIN

/** \ingroup avr_stdint
    largest value an uint_fast16_t can hold. */

#define UINT_FAST16_MAX UINT16_MAX

/** \ingroup avr_stdint
    largest positive value an int_fast32_t can hold. */

#define INT_FAST32_MAX INT32_MAX

/** \ingroup avr_stdint
    smallest negative value an int_fast32_t can hold. */

#define INT_FAST32_MIN INT32_MIN

/** \ingroup avr_stdint
    largest value an uint_fast32_t can hold. */

#define UINT_FAST32_MAX UINT32_MAX

/** \ingroup avr_stdint
    largest positive value an int_fast64_t can hold. */

#define INT_FAST64_MAX INT64_MAX

/** \ingroup avr_stdint
    smallest negative value an int_fast64_t can hold. */

#define INT_FAST64_MIN INT64_MIN

/** \ingroup avr_stdint
    largest value an uint_fast64_t can hold. */

#define UINT_FAST64_MAX UINT64_MAX

/*@}*/

/** \name Limits of integer types capable of holding object pointers */

/*@{*/

/** \ingroup avr_stdint
    largest positive value an intptr_t can hold. */

#define INTPTR_MAX INT16_MAX

/** \ingroup avr_stdint
    smallest negative value an intptr_t can hold. */

#define INTPTR_MIN INT16_MIN

/** \ingroup avr_stdint
    largest value an uintptr_t can hold. */

#define UINTPTR_MAX UINT16_MAX

/*@}*/

/** \name Limits of greatest-width integer types */

/*@{*/

/** \ingroup avr_stdint
    largest positive value an intmax_t can hold. */

#define INTMAX_MAX INT64_MAX

/** \ingroup avr_stdint
    smallest negative value an intmax_t can hold. */

#define INTMAX_MIN INT64_MIN

/** \ingroup avr_stdint
    largest value an uintmax_t can hold. */

#define UINTMAX_MAX UINT64_MAX

/*@}*/

/** \name Limits of other integer types
    C++ implementations should define these macros only when
    __STDC_LIMIT_MACROS is defined before <stdint.h> is included */

/*@{*/

/** \ingroup avr_stdint
    largest positive value a ptrdiff_t can hold. */

#define PTRDIFF_MAX INT16_MAX

/** \ingroup avr_stdint
    smallest negative value a ptrdiff_t can hold. */

#define PTRDIFF_MIN INT16_MIN


/* Limits of sig_atomic_t */
/* signal.h is currently not implemented (not avr/signal.h) */

/** \ingroup avr_stdint
    largest positive value a sig_atomic_t can hold. */

#define SIG_ATOMIC_MAX INT8_MAX

/** \ingroup avr_stdint
    smallest negative value a sig_atomic_t can hold. */

#define SIG_ATOMIC_MIN INT8_MIN


/** \ingroup avr_stdint
    largest value a size_t can hold. */

#define SIZE_MAX (__CONCAT(INT16_MAX, U))


/* Limits of wchar_t */
/* wchar.h is currently not implemented */
/* #define WCHAR_MAX */
/* #define WCHAR_MIN */


/* Limits of wint_t */
/* wchar.h is currently not implemented */
/* #define WINT_MAX */
/* #define WINT_MIN */


#endif /* !defined(__cplusplus) || defined(__STDC_LIMIT_MACROS) */

#if !defined(__cplusplus) || defined(__STDC_CONSTANT_MACROS)

/** \name Macros for integer constants
    C++ implementations should define these macros only when
    __STDC_CONSTANT_MACROS is defined before <stdint.h> is included.

    These definitions are valid for integer constants without suffix and
    for macros defined as integer constant without suffix */

/** \ingroup avr_stdint
    define a constant of type int8_t */

#define INT8_C(value) ((int8_t) value)

/** \ingroup avr_stdint
    define a constant of type uint8_t */

#define UINT8_C(value) ((uint8_t) __CONCAT(value, U))

#if __USING_MINT8

#define INT16_C(value) __CONCAT(value, L)
#define UINT16_C(value) __CONCAT(value, UL)

#define INT32_C(value) ((int32_t) __CONCAT(value, LL))
#define UINT32_C(value) ((uint32_t) __CONCAT(value, ULL))

#else /* !__USING_MINT8 */

/** \ingroup avr_stdint
    define a constant of type int16_t */

#define INT16_C(value) value

/** \ingroup avr_stdint
    define a constant of type uint16_t */

#define UINT16_C(value) __CONCAT(value, U)

/** \ingroup avr_stdint
    define a constant of type int32_t */

#define INT32_C(value) __CONCAT(value, L)

/** \ingroup avr_stdint
    define a constant of type uint32_t */

#define UINT32_C(value) __CONCAT(value, UL)

#endif /* __USING_MINT8 */

/** \ingroup avr_stdint
    define a constant of type int64_t */

#define INT64_C(value) __CONCAT(value, LL)

/** \ingroup avr_stdint
    define a constant of type uint64_t */

#define UINT64_C(value) __CONCAT(value, ULL)

/** \ingroup avr_stdint
    define a constant of type intmax_t */

#define INTMAX_C(value) __CONCAT(value, LL)

/** \ingroup avr_stdint
    define a constant of type uintmax_t */

#define UINTMAX_C(value) __CONCAT(value, ULL)

/*@}*/

#endif /* !defined(__cplusplus) || defined(__STDC_LIMIT_MACROS) */


#endif /* _STDINT_H_ */


/** \file */
/** \defgroup avr_inttypes <inttypes.h>: Integer Type conversions
    \code #include <inttypes.h> \endcode

    This header file includes the exact-width integer definitions from
    <tt><stdint.h></tt>, and extends them with additional facilities
    provided by the implementation.

    Currently, the extensions include two additional integer types
    that could hold a "far" pointer (i.e. a code pointer that can
    address more than 64 KB), as well as standard names for all printf
    and scanf formatting options that are supported by the \ref avr_stdio.
    As the library does not support the full range of conversion
    specifiers from ISO 9899:1999, only those conversions that are
    actually implemented will be listed here.

    The idea behind these conversion macros is that, for each of the
    types defined by <stdint.h>, a macro will be supplied that portably
    allows formatting an object of that type in printf() or scanf()
    operations.  Example:

    \code
    #include <inttypes.h>

    uint8_t smallval;
    int32_t longval;
    ...
    printf("The hexadecimal value of smallval is %" PRIx8
           ", the decimal value of longval is %" PRId32 ".\n",
	   smallval, longval);
    \endcode
*/

/** \name Far pointers for memory access >64K */

/*@{*/
/** \ingroup avr_inttypes
    signed integer type that can hold a pointer > 64 KB */
typedef int32_t int_farptr_t;

/** \ingroup avr_inttypes
    unsigned integer type that can hold a pointer > 64 KB */
typedef uint32_t uint_farptr_t;
/*@}*/

#if !defined(__cplusplus) || defined(__STDC_LIMIT_MACROS)


/** \name macros for printf and scanf format specifiers

    For C++, these are only included if __STDC_LIMIT_MACROS
    is defined before including <inttypes.h>.
 */

/*@{*/
/** \ingroup avr_inttypes
    decimal printf format for int8_t */
#define		PRId8			"d"
/** \ingroup avr_inttypes
    decimal printf format for int_least8_t */
#define		PRIdLEAST8		"d"
/** \ingroup avr_inttypes
    decimal printf format for int_fast8_t */
#define		PRIdFAST8		"d"

/** \ingroup avr_inttypes
    integer printf format for int8_t */
#define		PRIi8			"i"
/** \ingroup avr_inttypes
    integer printf format for int_least8_t */
#define		PRIiLEAST8		"i"
/** \ingroup avr_inttypes
    integer printf format for int_fast8_t */
#define		PRIiFAST8		"i"


/** \ingroup avr_inttypes
    decimal printf format for int16_t */
#define		PRId16			"d"
/** \ingroup avr_inttypes
    decimal printf format for int_least16_t */
#define		PRIdLEAST16		"d"
/** \ingroup avr_inttypes
    decimal printf format for int_fast16_t */
#define		PRIdFAST16		"d"

/** \ingroup avr_inttypes
    integer printf format for int16_t */
#define		PRIi16			"i"
/** \ingroup avr_inttypes
    integer printf format for int_least16_t */
#define		PRIiLEAST16		"i"
/** \ingroup avr_inttypes
    integer printf format for int_fast16_t */
#define		PRIiFAST16		"i"


/** \ingroup avr_inttypes
    decimal printf format for int32_t */
#define		PRId32			"ld"
/** \ingroup avr_inttypes
    decimal printf format for int_least32_t */
#define		PRIdLEAST32		"ld"
/** \ingroup avr_inttypes
    decimal printf format for int_fast32_t */
#define		PRIdFAST32		"ld"

/** \ingroup avr_inttypes
    integer printf format for int32_t */
#define		PRIi32			"li"
/** \ingroup avr_inttypes
    integer printf format for int_least32_t */
#define		PRIiLEAST32		"li"
/** \ingroup avr_inttypes
    integer printf format for int_fast32_t */
#define		PRIiFAST32		"li"


#ifdef __avr_libc_does_not_implement_long_long_in_printf_or_scanf

#define		PRId64			"lld"
#define		PRIdLEAST64		"lld"
#define		PRIdFAST64		"lld"

#define		PRIi64			"lli"
#define		PRIiLEAST64		"lli"
#define		PRIiFAST64		"lli"


#define		PRIdMAX			"lld"
#define		PRIiMAX			"lli"

#endif

/** \ingroup avr_inttypes
    decimal printf format for intptr_t */
#define		PRIdPTR			PRId16
/** \ingroup avr_inttypes
    integer printf format for intptr_t */
#define		PRIiPTR			PRIi16

/** \ingroup avr_inttypes
    octal printf format for uint8_t */
#define		PRIo8			"o"
/** \ingroup avr_inttypes
    octal printf format for uint_least8_t */
#define		PRIoLEAST8		"o"
/** \ingroup avr_inttypes
    octal printf format for uint_fast8_t */
#define		PRIoFAST8		"o"

/** \ingroup avr_inttypes
    decimal printf format for uint8_t */
#define		PRIu8			"u"
/** \ingroup avr_inttypes
    decimal printf format for uint_least8_t */
#define		PRIuLEAST8		"u"
/** \ingroup avr_inttypes
    decimal printf format for uint_fast8_t */
#define		PRIuFAST8		"u"

/** \ingroup avr_inttypes
    hexadecimal printf format for uint8_t */
#define		PRIx8			"x"
/** \ingroup avr_inttypes
    hexadecimal printf format for uint_least8_t */
#define		PRIxLEAST8		"x"
/** \ingroup avr_inttypes
    hexadecimal printf format for uint_fast8_t */
#define		PRIxFAST8		"x"

/** \ingroup avr_inttypes
    uppercase hexadecimal printf format for uint8_t */
#define		PRIX8			"X"
/** \ingroup avr_inttypes
    uppercase hexadecimal printf format for uint_least8_t */
#define		PRIXLEAST8		"X"
/** \ingroup avr_inttypes
    uppercase hexadecimal printf format for uint_fast8_t */
#define		PRIXFAST8		"X"


/** \ingroup avr_inttypes
    octal printf format for uint16_t */
#define		PRIo16			"o"
/** \ingroup avr_inttypes
    octal printf format for uint_least16_t */
#define		PRIoLEAST16		"o"
/** \ingroup avr_inttypes
    octal printf format for uint_fast16_t */
#define		PRIoFAST16		"o"

/** \ingroup avr_inttypes
    decimal printf format for uint16_t */
#define		PRIu16			"u"
/** \ingroup avr_inttypes
    decimal printf format for uint_least16_t */
#define		PRIuLEAST16		"u"
/** \ingroup avr_inttypes
    decimal printf format for uint_fast16_t */
#define		PRIuFAST16		"u"

/** \ingroup avr_inttypes
    hexadecimal printf format for uint16_t */
#define		PRIx16			"x"
/** \ingroup avr_inttypes
    hexadecimal printf format for uint_least16_t */
#define		PRIxLEAST16		"x"
/** \ingroup avr_inttypes
    hexadecimal printf format for uint_fast16_t */
#define		PRIxFAST16		"x"

/** \ingroup avr_inttypes
    uppercase hexadecimal printf format for uint16_t */
#define		PRIX16			"X"
/** \ingroup avr_inttypes
    uppercase hexadecimal printf format for uint_least16_t */
#define		PRIXLEAST16		"X"
/** \ingroup avr_inttypes
    uppercase hexadecimal printf format for uint_fast16_t */
#define		PRIXFAST16		"X"


/** \ingroup avr_inttypes
    octal printf format for uint32_t */
#define		PRIo32			"lo"
/** \ingroup avr_inttypes
    octal printf format for uint_least32_t */
#define		PRIoLEAST32		"lo"
/** \ingroup avr_inttypes
    octal printf format for uint_fast32_t */
#define		PRIoFAST32		"lo"

/** \ingroup avr_inttypes
    decimal printf format for uint32_t */
#define		PRIu32			"lu"
/** \ingroup avr_inttypes
    decimal printf format for uint_least32_t */
#define		PRIuLEAST32		"lu"
/** \ingroup avr_inttypes
    decimal printf format for uint_fast32_t */
#define		PRIuFAST32		"lu"

/** \ingroup avr_inttypes
    hexadecimal printf format for uint32_t */
#define		PRIx32			"lx"
/** \ingroup avr_inttypes
    hexadecimal printf format for uint_least32_t */
#define		PRIxLEAST32		"lx"
/** \ingroup avr_inttypes
    hexadecimal printf format for uint_fast32_t */
#define		PRIxFAST32		"lx"

/** \ingroup avr_inttypes
    uppercase hexadecimal printf format for uint32_t */
#define		PRIX32			"lX"
/** \ingroup avr_inttypes
    uppercase hexadecimal printf format for uint_least32_t */
#define		PRIXLEAST32		"lX"
/** \ingroup avr_inttypes
    uppercase hexadecimal printf format for uint_fast32_t */
#define		PRIXFAST32		"lX"


#ifdef __avr_libc_does_not_implement_long_long_in_printf_or_scanf

#define		PRIo64			"llo"
#define		PRIoLEAST64		"llo"
#define		PRIoFAST64		"llo"

#define		PRIu64			"llu"
#define		PRIuLEAST64		"llu"
#define		PRIuFAST64		"llu"

#define		PRIx64			"llx"
#define		PRIxLEAST64		"llx"
#define		PRIxFAST64		"llx"

#define		PRIX64			"llX"
#define		PRIXLEAST64		"llX"
#define		PRIXFAST64		"llX"

#define		PRIoMAX			"llo"
#define		PRIuMAX			"llu"
#define		PRIxMAX			"llx"
#define		PRIXMAX			"llX"

#endif

/** \ingroup avr_inttypes
    octal printf format for uintptr_t */
#define		PRIoPTR			PRIo16
/** \ingroup avr_inttypes
    decimal printf format for uintptr_t */
#define		PRIuPTR			PRIu16
/** \ingroup avr_inttypes
    hexadecimal printf format for uintptr_t */
#define		PRIxPTR			PRIx16
/** \ingroup avr_inttypes
    uppercase hexadecimal printf format for uintptr_t */
#define		PRIXPTR			PRIX16


#ifdef __avr_libc_does_not_implement_hh_in_scanf

#define		SCNd8			"hhd"
#define		SCNdLEAST8		"hhd"
#define		SCNdFAST8		"hhd"

#define		SCNi8			"hhi"
#define		SCNiLEAST8		"hhi"
#define		SCNiFAST8		"hhi"

#endif


/** \ingroup avr_inttypes
    decimal scanf format for int16_t */
#define		SCNd16			"d"
/** \ingroup avr_inttypes
    decimal scanf format for int_least16_t */
#define		SCNdLEAST16		"d"
/** \ingroup avr_inttypes
    decimal scanf format for int_fast16_t */
#define		SCNdFAST16		"d"

/** \ingroup avr_inttypes
    generic-integer scanf format for int16_t */
#define		SCNi16			"i"
/** \ingroup avr_inttypes
    generic-integer scanf format for int_least16_t */
#define		SCNiLEAST16		"i"
/** \ingroup avr_inttypes
    generic-integer scanf format for int_fast16_t */
#define		SCNiFAST16		"i"


/** \ingroup avr_inttypes
    decimal scanf format for int32_t */
#define		SCNd32			"ld"
/** \ingroup avr_inttypes
    decimal scanf format for int_least32_t */
#define		SCNdLEAST32		"ld"
/** \ingroup avr_inttypes
    decimal scanf format for int_fast32_t */
#define		SCNdFAST32		"ld"

/** \ingroup avr_inttypes
    generic-integer scanf format for int32_t */
#define		SCNi32			"li"
/** \ingroup avr_inttypes
    generic-integer scanf format for int_least32_t */
#define		SCNiLEAST32		"li"
/** \ingroup avr_inttypes
    generic-integer scanf format for int_fast32_t */
#define		SCNiFAST32		"li"


#ifdef __avr_libc_does_not_implement_long_long_in_printf_or_scanf

#define		SCNd64			"lld"
#define		SCNdLEAST64		"lld"
#define		SCNdFAST64		"lld"

#define		SCNi64			"lli"
#define		SCNiLEAST64		"lli"
#define		SCNiFAST64		"lli"

#define		SCNdMAX			"lld"
#define		SCNiMAX			"lli"

#endif

/** \ingroup avr_inttypes
    decimal scanf format for intptr_t */
#define		SCNdPTR			SCNd16
/** \ingroup avr_inttypes
    generic-integer scanf format for intptr_t */
#define		SCNiPTR			SCNi16

#ifdef __avr_libc_does_not_implement_hh_in_scanf

#define		SCNo8			"hho"
#define		SCNoLEAST8		"hho"
#define		SCNoFAST8		"hho"

#define		SCNu8			"hhu"
#define		SCNuLEAST8		"hhu"
#define		SCNuFAST8		"hhu"

#define		SCNx8			"hhx"
#define		SCNxLEAST8		"hhx"
#define		SCNxFAST8		"hhx"

#endif

/** \ingroup avr_inttypes
    octal scanf format for uint16_t */
#define		SCNo16			"o"
/** \ingroup avr_inttypes
    octal scanf format for uint_least16_t */
#define		SCNoLEAST16		"o"
/** \ingroup avr_inttypes
    octal scanf format for uint_fast16_t */
#define		SCNoFAST16		"o"

/** \ingroup avr_inttypes
    decimal scanf format for uint16_t */
#define		SCNu16			"u"
/** \ingroup avr_inttypes
    decimal scanf format for uint_least16_t */
#define		SCNuLEAST16		"u"
/** \ingroup avr_inttypes
    decimal scanf format for uint_fast16_t */
#define		SCNuFAST16		"u"

/** \ingroup avr_inttypes
    hexadecimal scanf format for uint16_t */
#define		SCNx16			"x"
/** \ingroup avr_inttypes
    hexadecimal scanf format for uint_least16_t */
#define		SCNxLEAST16		"x"
/** \ingroup avr_inttypes
    hexadecimal scanf format for uint_fast16_t */
#define		SCNxFAST16		"x"


/** \ingroup avr_inttypes
    octal scanf format for uint32_t */
#define		SCNo32			"lo"
/** \ingroup avr_inttypes
    octal scanf format for uint_least32_t */
#define		SCNoLEAST32		"lo"
/** \ingroup avr_inttypes
    octal scanf format for uint_fast32_t */
#define		SCNoFAST32		"lo"

/** \ingroup avr_inttypes
    decimal scanf format for uint32_t */
#define		SCNu32			"lu"
/** \ingroup avr_inttypes
    decimal scanf format for uint_least32_t */
#define		SCNuLEAST32		"lu"
/** \ingroup avr_inttypes
    decimal scanf format for uint_fast32_t */
#define		SCNuFAST32		"lu"

/** \ingroup avr_inttypes
    hexadecimal scanf format for uint32_t */
#define		SCNx32			"lx"
/** \ingroup avr_inttypes
    hexadecimal scanf format for uint_least32_t */
#define		SCNxLEAST32		"lx"
/** \ingroup avr_inttypes
    hexadecimal scanf format for uint_fast32_t */
#define		SCNxFAST32		"lx"


#ifdef __avr_libc_does_not_implement_long_long_in_printf_or_scanf

#define		SCNo64			"llo"
#define		SCNoLEAST64		"llo"
#define		SCNoFAST64		"llo"

#define		SCNu64			"llu"
#define		SCNuLEAST64		"llu"
#define		SCNuFAST64		"llu"

#define		SCNx64			"llx"
#define		SCNxLEAST64		"llx"
#define		SCNxFAST64		"llx"

#define		SCNoMAX			"llo"
#define		SCNuMAX			"llu"
#define		SCNxMAX			"llx"

#endif

/** \ingroup avr_inttypes
    octal scanf format for uintptr_t */
#define		SCNoPTR			SCNo16
/** \ingroup avr_inttypes
    decimal scanf format for uintptr_t */
#define		SCNuPTR			SCNu16
/** \ingroup avr_inttypes
    hexadecimal scanf format for uintptr_t */
#define		SCNxPTR			SCNx16

/*@}*/


#endif	/* !defined(__cplusplus) || defined(__STDC_LIMIT_MACROS) */


#endif /* __INTTYPES_H_ */

/*
  Print.h - Base class that provides print() and println()
  Copyright (c) 2008 David A. Mellis.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef Print_h
#define Print_h

/* Copyright (c) 2004,2005,2007 Joerg Wunsch
   Copyright (c) 2005, Carlos Lamas
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.

   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.

   * Neither the name of the copyright holders nor the names of
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE. */

/* $Id$ */

#ifndef __INTTYPES_H_
#define __INTTYPES_H_

/* Copyright (c) 2002,2004,2005 Marek Michalkiewicz
   Copyright (c) 2005, Carlos Lamas
   Copyright (c) 2005,2007 Joerg Wunsch
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.

   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.

   * Neither the name of the copyright holders nor the names of
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE. */

/* $Id$ */

/*
 * ISO/IEC 9899:1999  7.18 Integer types <stdint.h>
 */

#ifndef __STDINT_H_
#define __STDINT_H_

/** \file */
/** \defgroup avr_stdint <stdint.h>: Standard Integer Types
    \code #include <stdint.h> \endcode

    Use [u]intN_t if you need exactly N bits.

    Since these typedefs are mandated by the C99 standard, they are preferred
    over rolling your own typedefs.  */

/*
 * __USING_MINT8 is defined to 1 if the -mint8 option is in effect.
 */
#if __INT_MAX__ == 127
# define __USING_MINT8 1
#else
# define __USING_MINT8 0
#endif

/* Integer types */

#if defined(__DOXYGEN__)

/* doxygen gets confused by the __attribute__ stuff */

/** \name Exact-width integer types
    Integer types having exactly the specified width */

/*@{*/

/** \ingroup avr_stdint
    8-bit signed type. */

typedef signed char int8_t;

/** \ingroup avr_stdint
    8-bit unsigned type. */

typedef unsigned char uint8_t;

/** \ingroup avr_stdint
    16-bit signed type. */

typedef signed int int16_t;

/** \ingroup avr_stdint
    16-bit unsigned type. */

typedef unsigned int uint16_t;

/** \ingroup avr_stdint
    32-bit signed type. */

typedef signed long int int32_t;

/** \ingroup avr_stdint
    32-bit unsigned type. */

typedef unsigned long int uint32_t;

/** \ingroup avr_stdint
    64-bit signed type.
    \note This type is not available when the compiler
    option -mint8 is in effect. */

typedef signed long long int int64_t;

/** \ingroup avr_stdint
    64-bit unsigned type.
    \note This type is not available when the compiler
    option -mint8 is in effect. */

typedef unsigned long long int uint64_t;

/*@}*/

#else /* !defined(__DOXYGEN__) */

/* actual implementation goes here */

typedef signed int int8_t __attribute__((__mode__(__QI__)));
typedef unsigned int uint8_t __attribute__((__mode__(__QI__)));
typedef signed int int16_t __attribute__ ((__mode__ (__HI__)));
typedef unsigned int uint16_t __attribute__ ((__mode__ (__HI__)));
typedef signed int int32_t __attribute__ ((__mode__ (__SI__)));
typedef unsigned int uint32_t __attribute__ ((__mode__ (__SI__)));
#if !__USING_MINT8
typedef signed int int64_t __attribute__((__mode__(__DI__)));
typedef unsigned int uint64_t __attribute__((__mode__(__DI__)));
#endif

#endif /* defined(__DOXYGEN__) */

/** \name Integer types capable of holding object pointers
    These allow you to declare variables of the same size as a pointer. */

/*@{*/

/** \ingroup avr_stdint
    Signed pointer compatible type. */

typedef int16_t intptr_t;

/** \ingroup avr_stdint
    Unsigned pointer compatible type. */

typedef uint16_t uintptr_t;

/*@}*/

/** \name Minimum-width integer types
   Integer types having at least the specified width */

/*@{*/

/** \ingroup avr_stdint
    signed int with at least 8 bits. */

typedef int8_t   int_least8_t;

/** \ingroup avr_stdint
    unsigned int with at least 8 bits. */

typedef uint8_t  uint_least8_t;

/** \ingroup avr_stdint
    signed int with at least 16 bits. */

typedef int16_t  int_least16_t;

/** \ingroup avr_stdint
    unsigned int with at least 16 bits. */

typedef uint16_t uint_least16_t;

/** \ingroup avr_stdint
    signed int with at least 32 bits. */

typedef int32_t  int_least32_t;

/** \ingroup avr_stdint
    unsigned int with at least 32 bits. */

typedef uint32_t uint_least32_t;

#if !__USING_MINT8 || defined(__DOXYGEN__)
/** \ingroup avr_stdint
    signed int with at least 64 bits.
    \note This type is not available when the compiler
    option -mint8 is in effect. */

typedef int64_t  int_least64_t;

/** \ingroup avr_stdint
    unsigned int with at least 64 bits.
    \note This type is not available when the compiler
    option -mint8 is in effect. */

typedef uint64_t uint_least64_t;
#endif

/*@}*/


/** \name Fastest minimum-width integer types
   Integer types being usually fastest having at least the specified width */

/*@{*/

/** \ingroup avr_stdint
    fastest signed int with at least 8 bits. */

typedef int8_t int_fast8_t;

/** \ingroup avr_stdint
    fastest unsigned int with at least 8 bits. */

typedef uint8_t uint_fast8_t;

/** \ingroup avr_stdint
    fastest signed int with at least 16 bits. */

typedef int16_t int_fast16_t;

/** \ingroup avr_stdint
    fastest unsigned int with at least 16 bits. */

typedef uint16_t uint_fast16_t;

/** \ingroup avr_stdint
    fastest signed int with at least 32 bits. */

typedef int32_t int_fast32_t;

/** \ingroup avr_stdint
    fastest unsigned int with at least 32 bits. */

typedef uint32_t uint_fast32_t;

#if !__USING_MINT8 || defined(__DOXYGEN__)
/** \ingroup avr_stdint
    fastest signed int with at least 64 bits.
    \note This type is not available when the compiler
    option -mint8 is in effect. */

typedef int64_t int_fast64_t;

/** \ingroup avr_stdint
    fastest unsigned int with at least 64 bits.
    \note This type is not available when the compiler
    option -mint8 is in effect. */

typedef uint64_t uint_fast64_t;
#endif

/*@}*/


/** \name Greatest-width integer types
   Types designating integer data capable of representing any value of
   any integer type in the corresponding signed or unsigned category */

/*@{*/

#if __USING_MINT8
typedef int32_t intmax_t;

typedef uint32_t uintmax_t;
#else  /* !__USING_MINT8 */
/** \ingroup avr_stdint
    largest signed int available. */

typedef int64_t intmax_t;

/** \ingroup avr_stdint
    largest unsigned int available. */

typedef uint64_t uintmax_t;
#endif /* __USING_MINT8 */

/*@}*/

/* Helping macro */
#ifndef __CONCAT
#define __CONCATenate(left, right) left ## right
#define __CONCAT(left, right) __CONCATenate(left, right)
#endif

#if !defined(__cplusplus) || defined(__STDC_LIMIT_MACROS)

/** \name Limits of specified-width integer types
   C++ implementations should define these macros only when
   __STDC_LIMIT_MACROS is defined before <stdint.h> is included */

/*@{*/

/** \ingroup avr_stdint
    largest positive value an int8_t can hold. */

#define INT8_MAX 0x7f

/** \ingroup avr_stdint
    smallest negative value an int8_t can hold. */

#define INT8_MIN (-INT8_MAX - 1)

/** \ingroup avr_stdint
    largest value an uint8_t can hold. */

#define UINT8_MAX (__CONCAT(INT8_MAX, U) * 2U + 1U)

#if __USING_MINT8

#define INT16_MAX 0x7fffL
#define INT16_MIN (-INT16_MAX - 1L)
#define UINT16_MAX (__CONCAT(INT16_MAX, U) * 2UL + 1UL)

#define INT32_MAX 0x7fffffffLL
#define INT32_MIN (-INT32_MAX - 1LL)
#define UINT32_MAX (__CONCAT(INT32_MAX, U) * 2ULL + 1ULL)

#else /* !__USING_MINT8 */

/** \ingroup avr_stdint
    largest positive value an int16_t can hold. */

#define INT16_MAX 0x7fff

/** \ingroup avr_stdint
    smallest negative value an int16_t can hold. */

#define INT16_MIN (-INT16_MAX - 1)

/** \ingroup avr_stdint
    largest value an uint16_t can hold. */

#define UINT16_MAX (__CONCAT(INT16_MAX, U) * 2U + 1U)

/** \ingroup avr_stdint
    largest positive value an int32_t can hold. */

#define INT32_MAX 0x7fffffffL

/** \ingroup avr_stdint
    smallest negative value an int32_t can hold. */

#define INT32_MIN (-INT32_MAX - 1L)

/** \ingroup avr_stdint
    largest value an uint32_t can hold. */

#define UINT32_MAX (__CONCAT(INT32_MAX, U) * 2UL + 1UL)

#endif /* __USING_MINT8 */

/** \ingroup avr_stdint
    largest positive value an int64_t can hold. */

#define INT64_MAX 0x7fffffffffffffffLL

/** \ingroup avr_stdint
    smallest negative value an int64_t can hold. */

#define INT64_MIN (-INT64_MAX - 1LL)

/** \ingroup avr_stdint
    largest value an uint64_t can hold. */

#define UINT64_MAX (__CONCAT(INT64_MAX, U) * 2ULL + 1ULL)

/*@}*/

/** \name Limits of minimum-width integer types */
/*@{*/

/** \ingroup avr_stdint
    largest positive value an int_least8_t can hold. */

#define INT_LEAST8_MAX INT8_MAX

/** \ingroup avr_stdint
    smallest negative value an int_least8_t can hold. */

#define INT_LEAST8_MIN INT8_MIN

/** \ingroup avr_stdint
    largest value an uint_least8_t can hold. */

#define UINT_LEAST8_MAX UINT8_MAX

/** \ingroup avr_stdint
    largest positive value an int_least16_t can hold. */

#define INT_LEAST16_MAX INT16_MAX

/** \ingroup avr_stdint
    smallest negative value an int_least16_t can hold. */

#define INT_LEAST16_MIN INT16_MIN

/** \ingroup avr_stdint
    largest value an uint_least16_t can hold. */

#define UINT_LEAST16_MAX UINT16_MAX

/** \ingroup avr_stdint
    largest positive value an int_least32_t can hold. */

#define INT_LEAST32_MAX INT32_MAX

/** \ingroup avr_stdint
    smallest negative value an int_least32_t can hold. */

#define INT_LEAST32_MIN INT32_MIN

/** \ingroup avr_stdint
    largest value an uint_least32_t can hold. */

#define UINT_LEAST32_MAX UINT32_MAX

/** \ingroup avr_stdint
    largest positive value an int_least64_t can hold. */

#define INT_LEAST64_MAX INT64_MAX

/** \ingroup avr_stdint
    smallest negative value an int_least64_t can hold. */

#define INT_LEAST64_MIN INT64_MIN

/** \ingroup avr_stdint
    largest value an uint_least64_t can hold. */

#define UINT_LEAST64_MAX UINT64_MAX

/*@}*/

/** \name Limits of fastest minimum-width integer types */

/*@{*/

/** \ingroup avr_stdint
    largest positive value an int_fast8_t can hold. */

#define INT_FAST8_MAX INT8_MAX

/** \ingroup avr_stdint
    smallest negative value an int_fast8_t can hold. */

#define INT_FAST8_MIN INT8_MIN

/** \ingroup avr_stdint
    largest value an uint_fast8_t can hold. */

#define UINT_FAST8_MAX UINT8_MAX

/** \ingroup avr_stdint
    largest positive value an int_fast16_t can hold. */

#define INT_FAST16_MAX INT16_MAX

/** \ingroup avr_stdint
    smallest negative value an int_fast16_t can hold. */

#define INT_FAST16_MIN INT16_MIN

/** \ingroup avr_stdint
    largest value an uint_fast16_t can hold. */

#define UINT_FAST16_MAX UINT16_MAX

/** \ingroup avr_stdint
    largest positive value an int_fast32_t can hold. */

#define INT_FAST32_MAX INT32_MAX

/** \ingroup avr_stdint
    smallest negative value an int_fast32_t can hold. */

#define INT_FAST32_MIN INT32_MIN

/** \ingroup avr_stdint
    largest value an uint_fast32_t can hold. */

#define UINT_FAST32_MAX UINT32_MAX

/** \ingroup avr_stdint
    largest positive value an int_fast64_t can hold. */

#define INT_FAST64_MAX INT64_MAX

/** \ingroup avr_stdint
    smallest negative value an int_fast64_t can hold. */

#define INT_FAST64_MIN INT64_MIN

/** \ingroup avr_stdint
    largest value an uint_fast64_t can hold. */

#define UINT_FAST64_MAX UINT64_MAX

/*@}*/

/** \name Limits of integer types capable of holding object pointers */

/*@{*/

/** \ingroup avr_stdint
    largest positive value an intptr_t can hold. */

#define INTPTR_MAX INT16_MAX

/** \ingroup avr_stdint
    smallest negative value an intptr_t can hold. */

#define INTPTR_MIN INT16_MIN

/** \ingroup avr_stdint
    largest value an uintptr_t can hold. */

#define UINTPTR_MAX UINT16_MAX

/*@}*/

/** \name Limits of greatest-width integer types */

/*@{*/

/** \ingroup avr_stdint
    largest positive value an intmax_t can hold. */

#define INTMAX_MAX INT64_MAX

/** \ingroup avr_stdint
    smallest negative value an intmax_t can hold. */

#define INTMAX_MIN INT64_MIN

/** \ingroup avr_stdint
    largest value an uintmax_t can hold. */

#define UINTMAX_MAX UINT64_MAX

/*@}*/

/** \name Limits of other integer types
    C++ implementations should define these macros only when
    __STDC_LIMIT_MACROS is defined before <stdint.h> is included */

/*@{*/

/** \ingroup avr_stdint
    largest positive value a ptrdiff_t can hold. */

#define PTRDIFF_MAX INT16_MAX

/** \ingroup avr_stdint
    smallest negative value a ptrdiff_t can hold. */

#define PTRDIFF_MIN INT16_MIN


/* Limits of sig_atomic_t */
/* signal.h is currently not implemented (not avr/signal.h) */

/** \ingroup avr_stdint
    largest positive value a sig_atomic_t can hold. */

#define SIG_ATOMIC_MAX INT8_MAX

/** \ingroup avr_stdint
    smallest negative value a sig_atomic_t can hold. */

#define SIG_ATOMIC_MIN INT8_MIN


/** \ingroup avr_stdint
    largest value a size_t can hold. */

#define SIZE_MAX (__CONCAT(INT16_MAX, U))


/* Limits of wchar_t */
/* wchar.h is currently not implemented */
/* #define WCHAR_MAX */
/* #define WCHAR_MIN */


/* Limits of wint_t */
/* wchar.h is currently not implemented */
/* #define WINT_MAX */
/* #define WINT_MIN */


#endif /* !defined(__cplusplus) || defined(__STDC_LIMIT_MACROS) */

#if !defined(__cplusplus) || defined(__STDC_CONSTANT_MACROS)

/** \name Macros for integer constants
    C++ implementations should define these macros only when
    __STDC_CONSTANT_MACROS is defined before <stdint.h> is included.

    These definitions are valid for integer constants without suffix and
    for macros defined as integer constant without suffix */

/** \ingroup avr_stdint
    define a constant of type int8_t */

#define INT8_C(value) ((int8_t) value)

/** \ingroup avr_stdint
    define a constant of type uint8_t */

#define UINT8_C(value) ((uint8_t) __CONCAT(value, U))

#if __USING_MINT8

#define INT16_C(value) __CONCAT(value, L)
#define UINT16_C(value) __CONCAT(value, UL)

#define INT32_C(value) ((int32_t) __CONCAT(value, LL))
#define UINT32_C(value) ((uint32_t) __CONCAT(value, ULL))

#else /* !__USING_MINT8 */

/** \ingroup avr_stdint
    define a constant of type int16_t */

#define INT16_C(value) value

/** \ingroup avr_stdint
    define a constant of type uint16_t */

#define UINT16_C(value) __CONCAT(value, U)

/** \ingroup avr_stdint
    define a constant of type int32_t */

#define INT32_C(value) __CONCAT(value, L)

/** \ingroup avr_stdint
    define a constant of type uint32_t */

#define UINT32_C(value) __CONCAT(value, UL)

#endif /* __USING_MINT8 */

/** \ingroup avr_stdint
    define a constant of type int64_t */

#define INT64_C(value) __CONCAT(value, LL)

/** \ingroup avr_stdint
    define a constant of type uint64_t */

#define UINT64_C(value) __CONCAT(value, ULL)

/** \ingroup avr_stdint
    define a constant of type intmax_t */

#define INTMAX_C(value) __CONCAT(value, LL)

/** \ingroup avr_stdint
    define a constant of type uintmax_t */

#define UINTMAX_C(value) __CONCAT(value, ULL)

/*@}*/

#endif /* !defined(__cplusplus) || defined(__STDC_LIMIT_MACROS) */


#endif /* _STDINT_H_ */

/** \file */
/** \defgroup avr_inttypes <inttypes.h>: Integer Type conversions
    \code #include <inttypes.h> \endcode

    This header file includes the exact-width integer definitions from
    <tt><stdint.h></tt>, and extends them with additional facilities
    provided by the implementation.

    Currently, the extensions include two additional integer types
    that could hold a "far" pointer (i.e. a code pointer that can
    address more than 64 KB), as well as standard names for all printf
    and scanf formatting options that are supported by the \ref avr_stdio.
    As the library does not support the full range of conversion
    specifiers from ISO 9899:1999, only those conversions that are
    actually implemented will be listed here.

    The idea behind these conversion macros is that, for each of the
    types defined by <stdint.h>, a macro will be supplied that portably
    allows formatting an object of that type in printf() or scanf()
    operations.  Example:

    \code
    #include <inttypes.h>

    uint8_t smallval;
    int32_t longval;
    ...
    printf("The hexadecimal value of smallval is %" PRIx8
           ", the decimal value of longval is %" PRId32 ".\n",
	   smallval, longval);
    \endcode
*/

/** \name Far pointers for memory access >64K */

/*@{*/
/** \ingroup avr_inttypes
    signed integer type that can hold a pointer > 64 KB */
typedef int32_t int_farptr_t;

/** \ingroup avr_inttypes
    unsigned integer type that can hold a pointer > 64 KB */
typedef uint32_t uint_farptr_t;
/*@}*/

#if !defined(__cplusplus) || defined(__STDC_LIMIT_MACROS)


/** \name macros for printf and scanf format specifiers

    For C++, these are only included if __STDC_LIMIT_MACROS
    is defined before including <inttypes.h>.
 */

/*@{*/
/** \ingroup avr_inttypes
    decimal printf format for int8_t */
#define		PRId8			"d"
/** \ingroup avr_inttypes
    decimal printf format for int_least8_t */
#define		PRIdLEAST8		"d"
/** \ingroup avr_inttypes
    decimal printf format for int_fast8_t */
#define		PRIdFAST8		"d"

/** \ingroup avr_inttypes
    integer printf format for int8_t */
#define		PRIi8			"i"
/** \ingroup avr_inttypes
    integer printf format for int_least8_t */
#define		PRIiLEAST8		"i"
/** \ingroup avr_inttypes
    integer printf format for int_fast8_t */
#define		PRIiFAST8		"i"


/** \ingroup avr_inttypes
    decimal printf format for int16_t */
#define		PRId16			"d"
/** \ingroup avr_inttypes
    decimal printf format for int_least16_t */
#define		PRIdLEAST16		"d"
/** \ingroup avr_inttypes
    decimal printf format for int_fast16_t */
#define		PRIdFAST16		"d"

/** \ingroup avr_inttypes
    integer printf format for int16_t */
#define		PRIi16			"i"
/** \ingroup avr_inttypes
    integer printf format for int_least16_t */
#define		PRIiLEAST16		"i"
/** \ingroup avr_inttypes
    integer printf format for int_fast16_t */
#define		PRIiFAST16		"i"


/** \ingroup avr_inttypes
    decimal printf format for int32_t */
#define		PRId32			"ld"
/** \ingroup avr_inttypes
    decimal printf format for int_least32_t */
#define		PRIdLEAST32		"ld"
/** \ingroup avr_inttypes
    decimal printf format for int_fast32_t */
#define		PRIdFAST32		"ld"

/** \ingroup avr_inttypes
    integer printf format for int32_t */
#define		PRIi32			"li"
/** \ingroup avr_inttypes
    integer printf format for int_least32_t */
#define		PRIiLEAST32		"li"
/** \ingroup avr_inttypes
    integer printf format for int_fast32_t */
#define		PRIiFAST32		"li"


#ifdef __avr_libc_does_not_implement_long_long_in_printf_or_scanf

#define		PRId64			"lld"
#define		PRIdLEAST64		"lld"
#define		PRIdFAST64		"lld"

#define		PRIi64			"lli"
#define		PRIiLEAST64		"lli"
#define		PRIiFAST64		"lli"


#define		PRIdMAX			"lld"
#define		PRIiMAX			"lli"

#endif

/** \ingroup avr_inttypes
    decimal printf format for intptr_t */
#define		PRIdPTR			PRId16
/** \ingroup avr_inttypes
    integer printf format for intptr_t */
#define		PRIiPTR			PRIi16

/** \ingroup avr_inttypes
    octal printf format for uint8_t */
#define		PRIo8			"o"
/** \ingroup avr_inttypes
    octal printf format for uint_least8_t */
#define		PRIoLEAST8		"o"
/** \ingroup avr_inttypes
    octal printf format for uint_fast8_t */
#define		PRIoFAST8		"o"

/** \ingroup avr_inttypes
    decimal printf format for uint8_t */
#define		PRIu8			"u"
/** \ingroup avr_inttypes
    decimal printf format for uint_least8_t */
#define		PRIuLEAST8		"u"
/** \ingroup avr_inttypes
    decimal printf format for uint_fast8_t */
#define		PRIuFAST8		"u"

/** \ingroup avr_inttypes
    hexadecimal printf format for uint8_t */
#define		PRIx8			"x"
/** \ingroup avr_inttypes
    hexadecimal printf format for uint_least8_t */
#define		PRIxLEAST8		"x"
/** \ingroup avr_inttypes
    hexadecimal printf format for uint_fast8_t */
#define		PRIxFAST8		"x"

/** \ingroup avr_inttypes
    uppercase hexadecimal printf format for uint8_t */
#define		PRIX8			"X"
/** \ingroup avr_inttypes
    uppercase hexadecimal printf format for uint_least8_t */
#define		PRIXLEAST8		"X"
/** \ingroup avr_inttypes
    uppercase hexadecimal printf format for uint_fast8_t */
#define		PRIXFAST8		"X"


/** \ingroup avr_inttypes
    octal printf format for uint16_t */
#define		PRIo16			"o"
/** \ingroup avr_inttypes
    octal printf format for uint_least16_t */
#define		PRIoLEAST16		"o"
/** \ingroup avr_inttypes
    octal printf format for uint_fast16_t */
#define		PRIoFAST16		"o"

/** \ingroup avr_inttypes
    decimal printf format for uint16_t */
#define		PRIu16			"u"
/** \ingroup avr_inttypes
    decimal printf format for uint_least16_t */
#define		PRIuLEAST16		"u"
/** \ingroup avr_inttypes
    decimal printf format for uint_fast16_t */
#define		PRIuFAST16		"u"

/** \ingroup avr_inttypes
    hexadecimal printf format for uint16_t */
#define		PRIx16			"x"
/** \ingroup avr_inttypes
    hexadecimal printf format for uint_least16_t */
#define		PRIxLEAST16		"x"
/** \ingroup avr_inttypes
    hexadecimal printf format for uint_fast16_t */
#define		PRIxFAST16		"x"

/** \ingroup avr_inttypes
    uppercase hexadecimal printf format for uint16_t */
#define		PRIX16			"X"
/** \ingroup avr_inttypes
    uppercase hexadecimal printf format for uint_least16_t */
#define		PRIXLEAST16		"X"
/** \ingroup avr_inttypes
    uppercase hexadecimal printf format for uint_fast16_t */
#define		PRIXFAST16		"X"


/** \ingroup avr_inttypes
    octal printf format for uint32_t */
#define		PRIo32			"lo"
/** \ingroup avr_inttypes
    octal printf format for uint_least32_t */
#define		PRIoLEAST32		"lo"
/** \ingroup avr_inttypes
    octal printf format for uint_fast32_t */
#define		PRIoFAST32		"lo"

/** \ingroup avr_inttypes
    decimal printf format for uint32_t */
#define		PRIu32			"lu"
/** \ingroup avr_inttypes
    decimal printf format for uint_least32_t */
#define		PRIuLEAST32		"lu"
/** \ingroup avr_inttypes
    decimal printf format for uint_fast32_t */
#define		PRIuFAST32		"lu"

/** \ingroup avr_inttypes
    hexadecimal printf format for uint32_t */
#define		PRIx32			"lx"
/** \ingroup avr_inttypes
    hexadecimal printf format for uint_least32_t */
#define		PRIxLEAST32		"lx"
/** \ingroup avr_inttypes
    hexadecimal printf format for uint_fast32_t */
#define		PRIxFAST32		"lx"

/** \ingroup avr_inttypes
    uppercase hexadecimal printf format for uint32_t */
#define		PRIX32			"lX"
/** \ingroup avr_inttypes
    uppercase hexadecimal printf format for uint_least32_t */
#define		PRIXLEAST32		"lX"
/** \ingroup avr_inttypes
    uppercase hexadecimal printf format for uint_fast32_t */
#define		PRIXFAST32		"lX"


#ifdef __avr_libc_does_not_implement_long_long_in_printf_or_scanf

#define		PRIo64			"llo"
#define		PRIoLEAST64		"llo"
#define		PRIoFAST64		"llo"

#define		PRIu64			"llu"
#define		PRIuLEAST64		"llu"
#define		PRIuFAST64		"llu"

#define		PRIx64			"llx"
#define		PRIxLEAST64		"llx"
#define		PRIxFAST64		"llx"

#define		PRIX64			"llX"
#define		PRIXLEAST64		"llX"
#define		PRIXFAST64		"llX"

#define		PRIoMAX			"llo"
#define		PRIuMAX			"llu"
#define		PRIxMAX			"llx"
#define		PRIXMAX			"llX"

#endif

/** \ingroup avr_inttypes
    octal printf format for uintptr_t */
#define		PRIoPTR			PRIo16
/** \ingroup avr_inttypes
    decimal printf format for uintptr_t */
#define		PRIuPTR			PRIu16
/** \ingroup avr_inttypes
    hexadecimal printf format for uintptr_t */
#define		PRIxPTR			PRIx16
/** \ingroup avr_inttypes
    uppercase hexadecimal printf format for uintptr_t */
#define		PRIXPTR			PRIX16


#ifdef __avr_libc_does_not_implement_hh_in_scanf

#define		SCNd8			"hhd"
#define		SCNdLEAST8		"hhd"
#define		SCNdFAST8		"hhd"

#define		SCNi8			"hhi"
#define		SCNiLEAST8		"hhi"
#define		SCNiFAST8		"hhi"

#endif


/** \ingroup avr_inttypes
    decimal scanf format for int16_t */
#define		SCNd16			"d"
/** \ingroup avr_inttypes
    decimal scanf format for int_least16_t */
#define		SCNdLEAST16		"d"
/** \ingroup avr_inttypes
    decimal scanf format for int_fast16_t */
#define		SCNdFAST16		"d"

/** \ingroup avr_inttypes
    generic-integer scanf format for int16_t */
#define		SCNi16			"i"
/** \ingroup avr_inttypes
    generic-integer scanf format for int_least16_t */
#define		SCNiLEAST16		"i"
/** \ingroup avr_inttypes
    generic-integer scanf format for int_fast16_t */
#define		SCNiFAST16		"i"


/** \ingroup avr_inttypes
    decimal scanf format for int32_t */
#define		SCNd32			"ld"
/** \ingroup avr_inttypes
    decimal scanf format for int_least32_t */
#define		SCNdLEAST32		"ld"
/** \ingroup avr_inttypes
    decimal scanf format for int_fast32_t */
#define		SCNdFAST32		"ld"

/** \ingroup avr_inttypes
    generic-integer scanf format for int32_t */
#define		SCNi32			"li"
/** \ingroup avr_inttypes
    generic-integer scanf format for int_least32_t */
#define		SCNiLEAST32		"li"
/** \ingroup avr_inttypes
    generic-integer scanf format for int_fast32_t */
#define		SCNiFAST32		"li"


#ifdef __avr_libc_does_not_implement_long_long_in_printf_or_scanf

#define		SCNd64			"lld"
#define		SCNdLEAST64		"lld"
#define		SCNdFAST64		"lld"

#define		SCNi64			"lli"
#define		SCNiLEAST64		"lli"
#define		SCNiFAST64		"lli"

#define		SCNdMAX			"lld"
#define		SCNiMAX			"lli"

#endif

/** \ingroup avr_inttypes
    decimal scanf format for intptr_t */
#define		SCNdPTR			SCNd16
/** \ingroup avr_inttypes
    generic-integer scanf format for intptr_t */
#define		SCNiPTR			SCNi16

#ifdef __avr_libc_does_not_implement_hh_in_scanf

#define		SCNo8			"hho"
#define		SCNoLEAST8		"hho"
#define		SCNoFAST8		"hho"

#define		SCNu8			"hhu"
#define		SCNuLEAST8		"hhu"
#define		SCNuFAST8		"hhu"

#define		SCNx8			"hhx"
#define		SCNxLEAST8		"hhx"
#define		SCNxFAST8		"hhx"

#endif

/** \ingroup avr_inttypes
    octal scanf format for uint16_t */
#define		SCNo16			"o"
/** \ingroup avr_inttypes
    octal scanf format for uint_least16_t */
#define		SCNoLEAST16		"o"
/** \ingroup avr_inttypes
    octal scanf format for uint_fast16_t */
#define		SCNoFAST16		"o"

/** \ingroup avr_inttypes
    decimal scanf format for uint16_t */
#define		SCNu16			"u"
/** \ingroup avr_inttypes
    decimal scanf format for uint_least16_t */
#define		SCNuLEAST16		"u"
/** \ingroup avr_inttypes
    decimal scanf format for uint_fast16_t */
#define		SCNuFAST16		"u"

/** \ingroup avr_inttypes
    hexadecimal scanf format for uint16_t */
#define		SCNx16			"x"
/** \ingroup avr_inttypes
    hexadecimal scanf format for uint_least16_t */
#define		SCNxLEAST16		"x"
/** \ingroup avr_inttypes
    hexadecimal scanf format for uint_fast16_t */
#define		SCNxFAST16		"x"


/** \ingroup avr_inttypes
    octal scanf format for uint32_t */
#define		SCNo32			"lo"
/** \ingroup avr_inttypes
    octal scanf format for uint_least32_t */
#define		SCNoLEAST32		"lo"
/** \ingroup avr_inttypes
    octal scanf format for uint_fast32_t */
#define		SCNoFAST32		"lo"

/** \ingroup avr_inttypes
    decimal scanf format for uint32_t */
#define		SCNu32			"lu"
/** \ingroup avr_inttypes
    decimal scanf format for uint_least32_t */
#define		SCNuLEAST32		"lu"
/** \ingroup avr_inttypes
    decimal scanf format for uint_fast32_t */
#define		SCNuFAST32		"lu"

/** \ingroup avr_inttypes
    hexadecimal scanf format for uint32_t */
#define		SCNx32			"lx"
/** \ingroup avr_inttypes
    hexadecimal scanf format for uint_least32_t */
#define		SCNxLEAST32		"lx"
/** \ingroup avr_inttypes
    hexadecimal scanf format for uint_fast32_t */
#define		SCNxFAST32		"lx"


#ifdef __avr_libc_does_not_implement_long_long_in_printf_or_scanf

#define		SCNo64			"llo"
#define		SCNoLEAST64		"llo"
#define		SCNoFAST64		"llo"

#define		SCNu64			"llu"
#define		SCNuLEAST64		"llu"
#define		SCNuFAST64		"llu"

#define		SCNx64			"llx"
#define		SCNxLEAST64		"llx"
#define		SCNxFAST64		"llx"

#define		SCNoMAX			"llo"
#define		SCNuMAX			"llu"
#define		SCNxMAX			"llx"

#endif

/** \ingroup avr_inttypes
    octal scanf format for uintptr_t */
#define		SCNoPTR			SCNo16
/** \ingroup avr_inttypes
    decimal scanf format for uintptr_t */
#define		SCNuPTR			SCNu16
/** \ingroup avr_inttypes
    hexadecimal scanf format for uintptr_t */
#define		SCNxPTR			SCNx16

/*@}*/


#endif	/* !defined(__cplusplus) || defined(__STDC_LIMIT_MACROS) */


#endif /* __INTTYPES_H_ */

/* Copyright (c) 2002, 2005, 2007 Joerg Wunsch
   All rights reserved.

   Portions of documentation Copyright (c) 1990, 1991, 1993
   The Regents of the University of California.

   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.

   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.

   * Neither the name of the copyright holders nor the names of
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE.

  $Id$
*/

#ifndef _STDIO_H_
#define	_STDIO_H_ 1

#ifndef __ASSEMBLER__

#include <inttypes.h>
#include <stdarg.h>

#define __need_NULL
#define __need_size_t
#include <stddef.h>

/** \file */
/** \defgroup avr_stdio <stdio.h>: Standard IO facilities
    \code #include <stdio.h> \endcode

    <h3>Introduction to the Standard IO facilities</h3>

    This file declares the standard IO facilities that are implemented
    in \c avr-libc.  Due to the nature of the underlying hardware,
    only a limited subset of standard IO is implemented.  There is no
    actual file implementation available, so only device IO can be
    performed.  Since there's no operating system, the application
    needs to provide enough details about their devices in order to
    make them usable by the standard IO facilities.

    Due to space constraints, some functionality has not been
    implemented at all (like some of the \c printf conversions that
    have been left out).  Nevertheless, potential users of this
    implementation should be warned: the \c printf and \c scanf families of functions, although
    usually associated with presumably simple things like the
    famous "Hello, world!" program, are actually fairly complex
    which causes their inclusion to eat up a fair amount of code space.
    Also, they are not fast due to the nature of interpreting the
    format string at run-time.  Whenever possible, resorting to the
    (sometimes non-standard) predetermined conversion facilities that are
    offered by avr-libc will usually cost much less in terms of speed
    and code size.

    <h3>Tunable options for code size vs. feature set</h3>

    In order to allow programmers a code size vs. functionality tradeoff,
    the function vfprintf() which is the heart of the printf family can be
    selected in different flavours using linker options.  See the
    documentation of vfprintf() for a detailed description.  The same
    applies to vfscanf() and the \c scanf family of functions.

    <h3>Outline of the chosen API</h3>

    The standard streams \c stdin, \c stdout, and \c stderr are
    provided, but contrary to the C standard, since avr-libc has no
    knowledge about applicable devices, these streams are not already
    pre-initialized at application startup.  Also, since there is no
    notion of "file" whatsoever to avr-libc, there is no function
    \c fopen() that could be used to associate a stream to some device.
    (See \ref stdio_note1 "note 1".)  Instead, the function \c fdevopen()
    is provided to associate a stream to a device, where the device
    needs to provide a function to send a character, to receive a
    character, or both.  There is no differentiation between "text" and
    "binary" streams inside avr-libc.  Character \c \\n is sent
    literally down to the device's \c put() function.  If the device
    requires a carriage return (\c \\r) character to be sent before
    the linefeed, its \c put() routine must implement this (see
    \ref stdio_note2 "note 2").

    As an alternative method to fdevopen(), the macro
    fdev_setup_stream() might be used to setup a user-supplied FILE
    structure.

    It should be noted that the automatic conversion of a newline
    character into a carriage return - newline sequence breaks binary
    transfers.  If binary transfers are desired, no automatic
    conversion should be performed, but instead any string that aims
    to issue a CR-LF sequence must use <tt>"\r\n"</tt> explicitly.

    For convenience, the first call to \c fdevopen() that opens a
    stream for reading will cause the resulting stream to be aliased
    to \c stdin.  Likewise, the first call to \c fdevopen() that opens
    a stream for writing will cause the resulting stream to be aliased
    to both, \c stdout, and \c stderr.  Thus, if the open was done
    with both, read and write intent, all three standard streams will
    be identical.  Note that these aliases are indistinguishable from
    each other, thus calling \c fclose() on such a stream will also
    effectively close all of its aliases (\ref stdio_note3 "note 3").

    It is possible to tie additional user data to a stream, using
    fdev_set_udata().  The backend put and get functions can then
    extract this user data using fdev_get_udata(), and act
    appropriately.  For example, a single put function could be used
    to talk to two different UARTs that way, or the put and get
    functions could keep internal state between calls there.

    <h3>Format strings in flash ROM</h3>

    All the \c printf and \c scanf family functions come in two flavours: the
    standard name, where the format string is expected to be in
    SRAM, as well as a version with the suffix "_P" where the format
    string is expected to reside in the flash ROM.  The macro
    \c PSTR (explained in \ref avr_pgmspace) becomes very handy
    for declaring these format strings.

    \anchor stdio_without_malloc
    <h3>Running stdio without malloc()</h3>

    By default, fdevopen() requires malloc().  As this is often
    not desired in the limited environment of a microcontroller, an
    alternative option is provided to run completely without malloc().

    The macro fdev_setup_stream() is provided to prepare a
    user-supplied FILE buffer for operation with stdio.

    <h4>Example</h4>

    \code
    #include <stdio.h>

    static int uart_putchar(char c, FILE *stream);

    static FILE mystdout = FDEV_SETUP_STREAM(uart_putchar, NULL,
                                             _FDEV_SETUP_WRITE);

    static int
    uart_putchar(char c, FILE *stream)
    {

      if (c == '\n')
        uart_putchar('\r', stream);
      loop_until_bit_is_set(UCSRA, UDRE);
      UDR = c;
      return 0;
    }

    int
    main(void)
    {
      init_uart();
      stdout = &mystdout;
      printf("Hello, world!\n");

      return 0;
    }
    \endcode

    This example uses the initializer form FDEV_SETUP_STREAM() rather
    than the function-like fdev_setup_stream(), so all data
    initialization happens during C start-up.

    If streams initialized that way are no longer needed, they can be
    destroyed by first calling the macro fdev_close(), and then
    destroying the object itself.  No call to fclose() should be
    issued for these streams.  While calling fclose() itself is
    harmless, it will cause an undefined reference to free() and thus
    cause the linker to link the malloc module into the application.

    <h3>Notes</h3>

    \anchor stdio_note1 \par Note 1:
    It might have been possible to implement a device abstraction that
    is compatible with \c fopen() but since this would have required
    to parse a string, and to take all the information needed either
    out of this string, or out of an additional table that would need to be
    provided by the application, this approach was not taken.

    \anchor stdio_note2 \par Note 2:
    This basically follows the Unix approach: if a device such as a
    terminal needs special handling, it is in the domain of the
    terminal device driver to provide this functionality.  Thus, a
    simple function suitable as \c put() for \c fdevopen() that talks
    to a UART interface might look like this:

    \code
    int
    uart_putchar(char c, FILE *stream)
    {

      if (c == '\n')
        uart_putchar('\r');
      loop_until_bit_is_set(UCSRA, UDRE);
      UDR = c;
      return 0;
    }
    \endcode

    \anchor stdio_note3 \par Note 3:
    This implementation has been chosen because the cost of maintaining
    an alias is considerably smaller than the cost of maintaining full
    copies of each stream.  Yet, providing an implementation that offers
    the complete set of standard streams was deemed to be useful.  Not
    only that writing \c printf() instead of <tt>fprintf(mystream, ...)</tt>
    saves typing work, but since avr-gcc needs to resort to pass all
    arguments of variadic functions on the stack (as opposed to passing
    them in registers for functions that take a fixed number of
    parameters), the ability to pass one parameter less by implying
    \c stdin or stdout will also save some execution time.
*/

#if !defined(__DOXYGEN__)

/*
 * This is an internal structure of the library that is subject to be
 * changed without warnings at any time.  Please do *never* reference
 * elements of it beyond by using the official interfaces provided.
 */
struct __file {
	char	*buf;		/* buffer pointer */
	unsigned char unget;	/* ungetc() buffer */
	uint8_t	flags;		/* flags, see below */
#define __SRD	0x0001		/* OK to read */
#define __SWR	0x0002		/* OK to write */
#define __SSTR	0x0004		/* this is an sprintf/snprintf string */
#define __SPGM	0x0008		/* fmt string is in progmem */
#define __SERR	0x0010		/* found error */
#define __SEOF	0x0020		/* found EOF */
#define __SUNGET 0x040		/* ungetc() happened */
#define __SMALLOC 0x80		/* handle is malloc()ed */
#if 0
/* possible future extensions, will require uint16_t flags */
#define __SRW	0x0100		/* open for reading & writing */
#define __SLBF	0x0200		/* line buffered */
#define __SNBF	0x0400		/* unbuffered */
#define __SMBF	0x0800		/* buf is from malloc */
#endif
	int	size;		/* size of buffer */
	int	len;		/* characters read or written so far */
	int	(*put)(char, struct __file *);	/* function to write one char to device */
	int	(*get)(struct __file *);	/* function to read one char from device */
	void	*udata;		/* User defined and accessible data. */
};

#endif /* not __DOXYGEN__ */

/*@{*/
/**
   \c FILE is the opaque structure that is passed around between the
   various standard IO functions.
*/
#define FILE	struct __file

/**
   Stream that will be used as an input stream by the simplified
   functions that don't take a \c stream argument.

   The first stream opened with read intent using \c fdevopen()
   will be assigned to \c stdin.
*/
#define stdin (__iob[0])

/**
   Stream that will be used as an output stream by the simplified
   functions that don't take a \c stream argument.

   The first stream opened with write intent using \c fdevopen()
   will be assigned to both, \c stdin, and \c stderr.
*/
#define stdout (__iob[1])

/**
   Stream destined for error output.  Unless specifically assigned,
   identical to \c stdout.

   If \c stderr should point to another stream, the result of
   another \c fdevopen() must be explicitly assigned to it without
   closing the previous \c stderr (since this would also close
   \c stdout).
*/
#define stderr (__iob[2])

/**
   \c EOF declares the value that is returned by various standard IO
   functions in case of an error.  Since the AVR platform (currently)
   doesn't contain an abstraction for actual files, its origin as
   "end of file" is somewhat meaningless here.
*/
#define EOF	(-1)

/** This macro inserts a pointer to user defined data into a FILE
    stream object.

    The user data can be useful for tracking state in the put and get
    functions supplied to the fdevopen() function. */
#define fdev_set_udata(stream, u) do { (stream)->udata = u; } while(0)

/** This macro retrieves a pointer to user defined data from a FILE
    stream object. */
#define fdev_get_udata(stream) ((stream)->udata)

#if defined(__DOXYGEN__)
/**
   \brief Setup a user-supplied buffer as an stdio stream

   This macro takes a user-supplied buffer \c stream, and sets it up
   as a stream that is valid for stdio operations, similar to one that
   has been obtained dynamically from fdevopen(). The buffer to setup
   must be of type FILE.

   The arguments \c put and \c get are identical to those that need to
   be passed to fdevopen().

   The \c rwflag argument can take one of the values _FDEV_SETUP_READ,
   _FDEV_SETUP_WRITE, or _FDEV_SETUP_RW, for read, write, or read/write
   intent, respectively.

   \note No assignments to the standard streams will be performed by
   fdev_setup_stream().  If standard streams are to be used, these
   need to be assigned by the user.  See also under
   \ref stdio_without_malloc "Running stdio without malloc()".
 */
#define fdev_setup_stream(stream, put, get, rwflag)
#else  /* !DOXYGEN */
#define fdev_setup_stream(stream, p, g, f) \
	do { \
		(stream)->put = p; \
		(stream)->get = g; \
		(stream)->flags = f; \
		(stream)->udata = 0; \
	} while(0)
#endif /* DOXYGEN */

#define _FDEV_SETUP_READ  __SRD	/**< fdev_setup_stream() with read intent */
#define _FDEV_SETUP_WRITE __SWR	/**< fdev_setup_stream() with write intent */
#define _FDEV_SETUP_RW    (__SRD|__SWR)	/**< fdev_setup_stream() with read/write intent */

/**
 * Return code for an error condition during device read.
 *
 * To be used in the get function of fdevopen().
 */
#define _FDEV_ERR (-1)

/**
 * Return code for an end-of-file condition during device read.
 *
 * To be used in the get function of fdevopen().
 */
#define _FDEV_EOF (-2)

#if defined(__DOXYGEN__)
/**
   \brief Initializer for a user-supplied stdio stream

   This macro acts similar to fdev_setup_stream(), but it is to be
   used as the initializer of a variable of type FILE.

   The remaining arguments are to be used as explained in
   fdev_setup_stream().
 */
#define FDEV_SETUP_STREAM(put, get, rwflag)
#else  /* !DOXYGEN */
#define FDEV_SETUP_STREAM(p, g, f) \
	{ \
		.put = p, \
		.get = g, \
		.flags = f, \
		.udata = 0, \
	}
#endif /* DOXYGEN */

#ifdef __cplusplus
extern "C" {
#endif

#if !defined(__DOXYGEN__)
/*
 * Doxygen documentation can be found in fdevopen.c.
 */

extern struct __file *__iob[];

#if defined(__STDIO_FDEVOPEN_COMPAT_12)
/*
 * Declare prototype for the discontinued version of fdevopen() that
 * has been in use up to avr-libc 1.2.x.  The new implementation has
 * some backwards compatibility with the old version.
 */
extern FILE *fdevopen(int (*__put)(char), int (*__get)(void),
                      int __opts __attribute__((unused)));
#else  /* !defined(__STDIO_FDEVOPEN_COMPAT_12) */
/* New prototype for avr-libc 1.4 and above. */
extern FILE *fdevopen(int (*__put)(char, FILE*), int (*__get)(FILE*));
#endif /* defined(__STDIO_FDEVOPEN_COMPAT_12) */

#endif /* not __DOXYGEN__ */

/**
   This function closes \c stream, and disallows and further
   IO to and from it.

   When using fdevopen() to setup the stream, a call to fclose() is
   needed in order to free the internal resources allocated.

   If the stream has been set up using fdev_setup_stream() or
   FDEV_SETUP_STREAM(), use fdev_close() instead.

   It currently always returns 0 (for success).
*/
extern int	fclose(FILE *__stream);

/**
   This macro frees up any library resources that might be associated
   with \c stream.  It should be called if \c stream is no longer
   needed, right before the application is going to destroy the
   \c stream object itself.

   (Currently, this macro evaluates to nothing, but this might change
   in future versions of the library.)
*/
#if defined(__DOXYGEN__)
# define fdev_close()
#else
# define fdev_close() ((void)0)
#endif

/**
   \c vfprintf is the central facility of the \c printf family of
   functions.  It outputs values to \c stream under control of a
   format string passed in \c fmt.  The actual values to print are
   passed as a variable argument list \c ap.

   \c vfprintf returns the number of characters written to \c stream,
   or \c EOF in case of an error.  Currently, this will only happen
   if \c stream has not been opened with write intent.

   The format string is composed of zero or more directives: ordinary
   characters (not \c %), which are copied unchanged to the output
   stream; and conversion specifications, each of which results in
   fetching zero or more subsequent arguments.  Each conversion
   specification is introduced by the \c % character.  The arguments must
   properly correspond (after type promotion) with the conversion
   specifier.  After the \c %, the following appear in sequence:

   - Zero or more of the following flags:
      <ul>
      <li> \c # The value should be converted to an "alternate form".  For
            c, d, i, s, and u conversions, this option has no effect.
            For o conversions, the precision of the number is
            increased to force the first character of the output
            string to a zero (except if a zero value is printed with
            an explicit precision of zero).  For x and X conversions,
            a non-zero result has the string `0x' (or `0X' for X
            conversions) prepended to it.</li>
      <li> \c 0 (zero) Zero padding.  For all conversions, the converted
            value is padded on the left with zeros rather than blanks.
            If a precision is given with a numeric conversion (d, i,
            o, u, i, x, and X), the 0 flag is ignored.</li>
      <li> \c - A negative field width flag; the converted value is to be
            left adjusted on the field boundary.  The converted value
            is padded on the right with blanks, rather than on the
            left with blanks or zeros.  A - overrides a 0 if both are
            given.</li>
      <li> ' ' (space) A blank should be left before a positive number
            produced by a signed conversion (d, or i).</li>
      <li> \c + A sign must always be placed before a number produced by a
            signed conversion.  A + overrides a space if both are
            used.</li>
      </ul>
      
   -   An optional decimal digit string specifying a minimum field width.
       If the converted value has fewer characters than the field width, it
       will be padded with spaces on the left (or right, if the left-adjustment
       flag has been given) to fill out the field width.
   -   An optional precision, in the form of a period . followed by an
       optional digit string.  If the digit string is omitted, the
       precision is taken as zero.  This gives the minimum number of
       digits to appear for d, i, o, u, x, and X conversions, or the
       maximum number of characters to be printed from a string for \c s
       conversions.
   -   An optional \c l or \c h length modifier, that specifies that the
       argument for the d, i, o, u, x, or X conversion is a \c "long int"
       rather than \c int. The \c h is ignored, as \c "short int" is
       equivalent to \c int.
   -   A character that specifies the type of conversion to be applied.

   The conversion specifiers and their meanings are:

   - \c diouxX The int (or appropriate variant) argument is converted
           to signed decimal (d and i), unsigned octal (o), unsigned
           decimal (u), or unsigned hexadecimal (x and X) notation.
           The letters "abcdef" are used for x conversions; the
           letters "ABCDEF" are used for X conversions.  The
           precision, if any, gives the minimum number of digits that
           must appear; if the converted value requires fewer digits,
           it is padded on the left with zeros.
   - \c p  The <tt>void *</tt> argument is taken as an unsigned integer,
           and converted similarly as a <tt>%\#x</tt> command would do.
   - \c c  The \c int argument is converted to an \c "unsigned char", and the
           resulting character is written.
   - \c s  The \c "char *" argument is expected to be a pointer to an array
           of character type (pointer to a string).  Characters from
           the array are written up to (but not including) a
           terminating NUL character; if a precision is specified, no
           more than the number specified are written.  If a precision
           is given, no null character need be present; if the
           precision is not specified, or is greater than the size of
           the array, the array must contain a terminating NUL
           character.
   - \c %  A \c % is written.  No argument is converted.  The complete
           conversion specification is "%%".
   - \c eE The double argument is rounded and converted in the format
           \c "[-]d.ddde±dd" where there is one digit before the
           decimal-point character and the number of digits after it
           is equal to the precision; if the precision is missing, it
           is taken as 6; if the precision is zero, no decimal-point
           character appears.  An \e E conversion uses the letter \c 'E'
           (rather than \c 'e') to introduce the exponent.  The exponent
           always contains two digits; if the value is zero,
           the exponent is 00.
   - \c fF The double argument is rounded and converted to decimal notation
           in the format \c "[-]ddd.ddd", where the number of digits after the
           decimal-point character is equal to the precision specification.
           If the precision is missing, it is taken as 6; if the precision
           is explicitly zero, no decimal-point character appears.  If a
           decimal point appears, at least one digit appears before it.
   - \c gG The double argument is converted in style \c f or \c e (or
           \c F or \c E for \c G conversions).  The precision
           specifies the number of significant digits.  If the
           precision is missing, 6 digits are given; if the precision
           is zero, it is treated as 1.  Style \c e is used if the
           exponent from its conversion is less than -4 or greater
           than or equal to the precision.  Trailing zeros are removed
           from the fractional part of the result; a decimal point
           appears only if it is followed by at least one digit.
   - \c S  Similar to the \c s format, except the pointer is expected to
           point to a program-memory (ROM) string instead of a RAM string.

   In no case does a non-existent or small field width cause truncation of a
   numeric field; if the result of a conversion is wider than the field
   width, the field is expanded to contain the conversion result.

   Since the full implementation of all the mentioned features becomes
   fairly large, three different flavours of vfprintf() can be
   selected using linker options.  The default vfprintf() implements
   all the mentioned functionality except floating point conversions.
   A minimized version of vfprintf() is available that only implements
   the very basic integer and string conversion facilities, but only
   the \c # additional option can be specified using conversion
   flags (these flags are parsed correctly from the format
   specification, but then simply ignored).  This version can be
   requested using the following \ref gcc_minusW "compiler options":

   \code
   -Wl,-u,vfprintf -lprintf_min
   \endcode

   If the full functionality including the floating point conversions
   is required, the following options should be used:

   \code
   -Wl,-u,vfprintf -lprintf_flt -lm
   \endcode

   \par Limitations:
   - The specified width and precision can be at most 255.

   \par Notes:
   - For floating-point conversions, if you link default or minimized
     version of vfprintf(), the symbol \c ? will be output and double
     argument will be skiped. So you output below will not be crashed.
     For default version the width field and the "pad to left" ( symbol
     minus ) option will work in this case.
   - The \c hh length modifier is ignored (\c char argument is
     promouted to \c int). More exactly, this realization does not check
     the number of \c h symbols.
   - But the \c ll length modifier will to abort the output, as this
     realization does not operate \c long \c long arguments.
   - The variable width or precision field (an asterisk \c * symbol)
     is not realized and will to abort the output.

 */

extern int	vfprintf(FILE *__stream, const char *__fmt, va_list __ap);

/**
   Variant of \c vfprintf() that uses a \c fmt string that resides
   in program memory.
*/
extern int	vfprintf_P(FILE *__stream, const char *__fmt, va_list __ap);

/**
   The function \c fputc sends the character \c c (though given as type
   \c int) to \c stream.  It returns the character, or \c EOF in case
   an error occurred.
*/
extern int	fputc(int __c, FILE *__stream);

#if !defined(__DOXYGEN__)

/* putc() function implementation, required by standard */
extern int	putc(int __c, FILE *__stream);

/* putchar() function implementation, required by standard */
extern int	putchar(int __c);

#endif /* not __DOXYGEN__ */

/**
   The macro \c putc used to be a "fast" macro implementation with a
   functionality identical to fputc().  For space constraints, in
   \c avr-libc, it is just an alias for \c fputc.
*/
#define putc(__c, __stream) fputc(__c, __stream)

/**
   The macro \c putchar sends character \c c to \c stdout.
*/
#define putchar(__c) fputc(__c, stdout)

/**
   The function \c printf performs formatted output to stream
   \c stdout.  See \c vfprintf() for details.
*/
extern int	printf(const char *__fmt, ...);

/**
   Variant of \c printf() that uses a \c fmt string that resides
   in program memory.
*/
extern int	printf_P(const char *__fmt, ...);

/**
   The function \c vprintf performs formatted output to stream
   \c stdout, taking a variable argument list as in vfprintf().

   See vfprintf() for details.
*/
extern int	vprintf(const char *__fmt, va_list __ap);

/**
   Variant of \c printf() that sends the formatted characters
   to string \c s.
*/
extern int	sprintf(char *__s, const char *__fmt, ...);

/**
   Variant of \c sprintf() that uses a \c fmt string that resides
   in program memory.
*/
extern int	sprintf_P(char *__s, const char *__fmt, ...);

/**
   Like \c sprintf(), but instead of assuming \c s to be of infinite
   size, no more than \c n characters (including the trailing NUL
   character) will be converted to \c s.

   Returns the number of characters that would have been written to
   \c s if there were enough space.
*/
extern int	snprintf(char *__s, size_t __n, const char *__fmt, ...);

/**
   Variant of \c snprintf() that uses a \c fmt string that resides
   in program memory.
*/
extern int	snprintf_P(char *__s, size_t __n, const char *__fmt, ...);

/**
   Like \c sprintf() but takes a variable argument list for the
   arguments.
*/
extern int	vsprintf(char *__s, const char *__fmt, va_list ap);

/**
   Variant of \c vsprintf() that uses a \c fmt string that resides
   in program memory.
*/
extern int	vsprintf_P(char *__s, const char *__fmt, va_list ap);

/**
   Like \c vsprintf(), but instead of assuming \c s to be of infinite
   size, no more than \c n characters (including the trailing NUL
   character) will be converted to \c s.

   Returns the number of characters that would have been written to
   \c s if there were enough space.
*/
extern int	vsnprintf(char *__s, size_t __n, const char *__fmt, va_list ap);

/**
   Variant of \c vsnprintf() that uses a \c fmt string that resides
   in program memory.
*/
extern int	vsnprintf_P(char *__s, size_t __n, const char *__fmt, va_list ap);
/**
   The function \c fprintf performs formatted output to \c stream.
   See \c vfprintf() for details.
*/
extern int	fprintf(FILE *__stream, const char *__fmt, ...);

/**
   Variant of \c fprintf() that uses a \c fmt string that resides
   in program memory.
*/
extern int	fprintf_P(FILE *__stream, const char *__fmt, ...);

/**
   Write the string pointed to by \c str to stream \c stream.

   Returns 0 on success and EOF on error.
*/
extern int	fputs(const char *__str, FILE *__stream);

/**
   Variant of fputs() where \c str resides in program memory.
*/
extern int	fputs_P(const char *__str, FILE *__stream);

/**
   Write the string pointed to by \c str, and a trailing newline
   character, to \c stdout.
*/
extern int	puts(const char *__str);

/**
   Variant of puts() where \c str resides in program memory.
*/
extern int	puts_P(const char *__str);

/**
   Write \c nmemb objects, \c size bytes each, to \c stream.
   The first byte of the first object is referenced by \c ptr.

   Returns the number of objects successfully written, i. e.
   \c nmemb unless an output error occured.
 */
extern size_t	fwrite(const void *__ptr, size_t __size, size_t __nmemb,
		       FILE *__stream);

/**
   The function \c fgetc reads a character from \c stream.  It returns
   the character, or \c EOF in case end-of-file was encountered or an
   error occurred.  The routines feof() or ferror() must be used to
   distinguish between both situations.
*/
extern int	fgetc(FILE *__stream);

#if !defined(__DOXYGEN__)

/* getc() function implementation, required by standard */
extern int	getc(FILE *__stream);

/* getchar() function implementation, required by standard */
extern int	getchar(void);

#endif /* not __DOXYGEN__ */

/**
   The macro \c getc used to be a "fast" macro implementation with a
   functionality identical to fgetc().  For space constraints, in
   \c avr-libc, it is just an alias for \c fgetc.
*/
#define getc(__stream) fgetc(__stream)

/**
   The macro \c getchar reads a character from \c stdin.  Return
   values and error handling is identical to fgetc().
*/
#define getchar() fgetc(stdin)

/**
   The ungetc() function pushes the character \c c (converted to an
   unsigned char) back onto the input stream pointed to by \c stream.
   The pushed-back character will be returned by a subsequent read on
   the stream.

   Currently, only a single character can be pushed back onto the
   stream.
   
   The ungetc() function returns the character pushed back after the
   conversion, or \c EOF if the operation fails.  If the value of the
   argument \c c character equals \c EOF, the operation will fail and
   the stream will remain unchanged.
*/
extern int	ungetc(int __c, FILE *__stream);

/**
   Read at most <tt>size - 1</tt> bytes from \c stream, until a
   newline character was encountered, and store the characters in the
   buffer pointed to by \c str.  Unless an error was encountered while
   reading, the string will then be terminated with a \c NUL
   character.

   If an error was encountered, the function returns NULL and sets the
   error flag of \c stream, which can be tested using ferror().
   Otherwise, a pointer to the string will be returned.  */
extern char	*fgets(char *__str, int __size, FILE *__stream);

/**
   Similar to fgets() except that it will operate on stream \c stdin,
   and the trailing newline (if any) will not be stored in the string.
   It is the caller's responsibility to provide enough storage to hold
   the characters read.  */
extern char	*gets(char *__str);

/**
   Read \c nmemb objects, \c size bytes each, from \c stream,
   to the buffer pointed to by \c ptr.

   Returns the number of objects successfully read, i. e.
   \c nmemb unless an input error occured or end-of-file was
   encountered.  feof() and ferror() must be used to distinguish
   between these two conditions.
 */
extern size_t	fread(void *__ptr, size_t __size, size_t __nmemb,
		      FILE *__stream);

/**
   Clear the error and end-of-file flags of \c stream.
 */
extern void	clearerr(FILE *__stream);

#if !defined(__DOXYGEN__)
/* fast inlined version of clearerr() */
#define clearerror(s) do { (s)->flags &= ~(__SERR | __SEOF); } while(0)
#endif /* !defined(__DOXYGEN__) */

/**
   Test the end-of-file flag of \c stream.  This flag can only be cleared
   by a call to clearerr().
 */
extern int	feof(FILE *__stream);

#if !defined(__DOXYGEN__)
/* fast inlined version of feof() */
#define feof(s) ((s)->flags & __SEOF)
#endif /* !defined(__DOXYGEN__) */

/**
   Test the error flag of \c stream.  This flag can only be cleared
   by a call to clearerr().
 */
extern int	ferror(FILE *__stream);

#if !defined(__DOXYGEN__)
/* fast inlined version of ferror() */
#define ferror(s) ((s)->flags & __SERR)
#endif /* !defined(__DOXYGEN__) */

extern int	vfscanf(FILE *__stream, const char *__fmt, va_list __ap);

/**
   Variant of vfscanf() using a \c fmt string in program memory.
 */
extern int	vfscanf_P(FILE *__stream, const char *__fmt, va_list __ap);

/**
   The function \c fscanf performs formatted input, reading the
   input data from \c stream.

   See vfscanf() for details.
 */
extern int	fscanf(FILE *__stream, const char *__fmt, ...);

/**
   Variant of fscanf() using a \c fmt string in program memory.
 */
extern int	fscanf_P(FILE *__stream, const char *__fmt, ...);

/**
   The function \c scanf performs formatted input from stream \c stdin.

   See vfscanf() for details.
 */
extern int	scanf(const char *__fmt, ...);

/**
   Variant of scanf() where \c fmt resides in program memory.
 */
extern int	scanf_P(const char *__fmt, ...);

/**
   The function \c vscanf performs formatted input from stream
   \c stdin, taking a variable argument list as in vfscanf().

   See vfscanf() for details.
*/
extern int	vscanf(const char *__fmt, va_list __ap);

/**
   The function \c sscanf performs formatted input, reading the
   input data from the buffer pointed to by \c buf.

   See vfscanf() for details.
 */
extern int	sscanf(const char *__buf, const char *__fmt, ...);

/**
   Variant of sscanf() using a \c fmt string in program memory.
 */
extern int	sscanf_P(const char *__buf, const char *__fmt, ...);

#if defined(__DOXYGEN__)
/**
   Flush \c stream.

   This is a null operation provided for source-code compatibility
   only, as the standard IO implementation currently does not perform
   any buffering.
 */
extern int	fflush(FILE *stream);
#else
static __inline__ int fflush(FILE *stream __attribute__((unused)))
{
	return 0;
}
#endif

#ifdef __cplusplus
}
#endif

/*@}*/

/*
 * The following constants are currently not used by avr-libc's
 * stdio subsystem.  They are defined here since the gcc build
 * environment expects them to be here.
 */
#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2

#endif /* __ASSEMBLER */

#endif /* _STDLIB_H_ */


/*
  WString.h - String library for Wiring & Arduino
  ...mostly rewritten by Paul Stoffregen...
  Copyright (c) 2009-10 Hernando Barragan.  All right reserved.
  Copyright 2011, Paul Stoffregen, paul@pjrc.com

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef String_class_h
#define String_class_h
#ifdef __cplusplus

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <avr/pgmspace.h>

// When compiling programs with this class, the following gcc parameters
// dramatically increase performance and memory (RAM) efficiency, typically
// with little or no increase in code size.
//     -felide-constructors
//     -std=c++0x

class __FlashStringHelper;
#define F(string_literal) (reinterpret_cast<const __FlashStringHelper *>(PSTR(string_literal)))

// An inherited class for holding the result of a concatenation.  These
// result objects are assumed to be writable by subsequent concatenations.
class StringSumHelper;

// The string class
class String
{
	// use a function pointer to allow for "if (s)" without the
	// complications of an operator bool(). for more information, see:
	// http://www.artima.com/cppsource/safebool.html
	typedef void (String::*StringIfHelperType)() const;
	void StringIfHelper() const {}

public:
	// constructors
	// creates a copy of the initial value.
	// if the initial value is null or invalid, or if memory allocation
	// fails, the string will be marked as invalid (i.e. "if (s)" will
	// be false).
	String(const char *cstr = "");
	String(const String &str);
	String(const __FlashStringHelper *str);
	#ifdef __GXX_EXPERIMENTAL_CXX0X__
	String(String &&rval);
	String(StringSumHelper &&rval);
	#endif
	explicit String(char c);
	explicit String(unsigned char, unsigned char base=10);
	explicit String(int, unsigned char base=10);
	explicit String(unsigned int, unsigned char base=10);
	explicit String(long, unsigned char base=10);
	explicit String(unsigned long, unsigned char base=10);
	explicit String(float, unsigned char decimalPlaces=2);
	explicit String(double, unsigned char decimalPlaces=2);
	~String(void);

	// memory management
	// return true on success, false on failure (in which case, the string
	// is left unchanged).  reserve(0), if successful, will validate an
	// invalid string (i.e., "if (s)" will be true afterwards)
	unsigned char reserve(unsigned int size);
	inline unsigned int length(void) const {return len;}

	// creates a copy of the assigned value.  if the value is null or
	// invalid, or if the memory allocation fails, the string will be 
	// marked as invalid ("if (s)" will be false).
	String & operator = (const String &rhs);
	String & operator = (const char *cstr);
	String & operator = (const __FlashStringHelper *str);
	#ifdef __GXX_EXPERIMENTAL_CXX0X__
	String & operator = (String &&rval);
	String & operator = (StringSumHelper &&rval);
	#endif

	// concatenate (works w/ built-in types)
	
	// returns true on success, false on failure (in which case, the string
	// is left unchanged).  if the argument is null or invalid, the 
	// concatenation is considered unsucessful.  
	unsigned char concat(const String &str);
	unsigned char concat(const char *cstr);
	unsigned char concat(char c);
	unsigned char concat(unsigned char c);
	unsigned char concat(int num);
	unsigned char concat(unsigned int num);
	unsigned char concat(long num);
	unsigned char concat(unsigned long num);
	unsigned char concat(float num);
	unsigned char concat(double num);
	unsigned char concat(const __FlashStringHelper * str);
	
	// if there's not enough memory for the concatenated value, the string
	// will be left unchanged (but this isn't signalled in any way)
	String & operator += (const String &rhs)	{concat(rhs); return (*this);}
	String & operator += (const char *cstr)		{concat(cstr); return (*this);}
	String & operator += (char c)			{concat(c); return (*this);}
	String & operator += (unsigned char num)		{concat(num); return (*this);}
	String & operator += (int num)			{concat(num); return (*this);}
	String & operator += (unsigned int num)		{concat(num); return (*this);}
	String & operator += (long num)			{concat(num); return (*this);}
	String & operator += (unsigned long num)	{concat(num); return (*this);}
	String & operator += (float num)		{concat(num); return (*this);}
	String & operator += (double num)		{concat(num); return (*this);}
	String & operator += (const __FlashStringHelper *str){concat(str); return (*this);}

	friend StringSumHelper & operator + (const StringSumHelper &lhs, const String &rhs);
	friend StringSumHelper & operator + (const StringSumHelper &lhs, const char *cstr);
	friend StringSumHelper & operator + (const StringSumHelper &lhs, char c);
	friend StringSumHelper & operator + (const StringSumHelper &lhs, unsigned char num);
	friend StringSumHelper & operator + (const StringSumHelper &lhs, int num);
	friend StringSumHelper & operator + (const StringSumHelper &lhs, unsigned int num);
	friend StringSumHelper & operator + (const StringSumHelper &lhs, long num);
	friend StringSumHelper & operator + (const StringSumHelper &lhs, unsigned long num);
	friend StringSumHelper & operator + (const StringSumHelper &lhs, float num);
	friend StringSumHelper & operator + (const StringSumHelper &lhs, double num);
	friend StringSumHelper & operator + (const StringSumHelper &lhs, const __FlashStringHelper *rhs);

	// comparison (only works w/ Strings and "strings")
	operator StringIfHelperType() const { return buffer ? &String::StringIfHelper : 0; }
	int compareTo(const String &s) const;
	unsigned char equals(const String &s) const;
	unsigned char equals(const char *cstr) const;
	unsigned char operator == (const String &rhs) const {return equals(rhs);}
	unsigned char operator == (const char *cstr) const {return equals(cstr);}
	unsigned char operator != (const String &rhs) const {return !equals(rhs);}
	unsigned char operator != (const char *cstr) const {return !equals(cstr);}
	unsigned char operator <  (const String &rhs) const;
	unsigned char operator >  (const String &rhs) const;
	unsigned char operator <= (const String &rhs) const;
	unsigned char operator >= (const String &rhs) const;
	unsigned char equalsIgnoreCase(const String &s) const;
	unsigned char startsWith( const String &prefix) const;
	unsigned char startsWith(const String &prefix, unsigned int offset) const;
	unsigned char endsWith(const String &suffix) const;

	// character acccess
	char charAt(unsigned int index) const;
	void setCharAt(unsigned int index, char c);
	char operator [] (unsigned int index) const;
	char& operator [] (unsigned int index);
	void getBytes(unsigned char *buf, unsigned int bufsize, unsigned int index=0) const;
	void toCharArray(char *buf, unsigned int bufsize, unsigned int index=0) const
		{getBytes((unsigned char *)buf, bufsize, index);}
	const char * c_str() const { return buffer; }

	// search
	int indexOf( char ch ) const;
	int indexOf( char ch, unsigned int fromIndex ) const;
	int indexOf( const String &str ) const;
	int indexOf( const String &str, unsigned int fromIndex ) const;
	int lastIndexOf( char ch ) const;
	int lastIndexOf( char ch, unsigned int fromIndex ) const;
	int lastIndexOf( const String &str ) const;
	int lastIndexOf( const String &str, unsigned int fromIndex ) const;
	String substring( unsigned int beginIndex ) const { return substring(beginIndex, len); };
	String substring( unsigned int beginIndex, unsigned int endIndex ) const;

	// modification
	void replace(char find, char replace);
	void replace(const String& find, const String& replace);
	void remove(unsigned int index);
	void remove(unsigned int index, unsigned int count);
	void toLowerCase(void);
	void toUpperCase(void);
	void trim(void);

	// parsing/conversion
	long toInt(void) const;
	float toFloat(void) const;

protected:
	char *buffer;	        // the actual char array
	unsigned int capacity;  // the array length minus one (for the '\0')
	unsigned int len;       // the String length (not counting the '\0')
protected:
	void init(void);
	void invalidate(void);
	unsigned char changeBuffer(unsigned int maxStrLen);
	unsigned char concat(const char *cstr, unsigned int length);

	// copy and move
	String & copy(const char *cstr, unsigned int length);
	String & copy(const __FlashStringHelper *pstr, unsigned int length);
	#ifdef __GXX_EXPERIMENTAL_CXX0X__
	void move(String &rhs);
	#endif
};

class StringSumHelper : public String
{
public:
	StringSumHelper(const String &s) : String(s) {}
	StringSumHelper(const char *p) : String(p) {}
	StringSumHelper(char c) : String(c) {}
	StringSumHelper(unsigned char num) : String(num) {}
	StringSumHelper(int num) : String(num) {}
	StringSumHelper(unsigned int num) : String(num) {}
	StringSumHelper(long num) : String(num) {}
	StringSumHelper(unsigned long num) : String(num) {}
	StringSumHelper(float num) : String(num) {}
	StringSumHelper(double num) : String(num) {}
};

#endif  // __cplusplus
#endif  // String_class_h

/*
  Printable.h - Interface class that allows printing of complex types
  Copyright (c) 2011 Adrian McEwen.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef Printable_h
#define Printable_h

#include <stdlib.h>

class Print;

/** The Printable class provides a way for new classes to allow themselves to be printed.
    By deriving from Printable and implementing the printTo method, it will then be possible
    for users to print out instances of this class by passing them into the usual
    Print::print and Print::println methods.
*/

class Printable
{
  public:
    virtual size_t printTo(Print& p) const = 0;
};

#endif


#define DEC 10
#define HEX 16
#define OCT 8
#define BIN 2

class Print
{
  private:
    int write_error;
    size_t printNumber(unsigned long, uint8_t);
    size_t printFloat(double, uint8_t);
  protected:
    void setWriteError(int err = 1) { write_error = err; }
  public:
    Print() : write_error(0) {}
  
    int getWriteError() { return write_error; }
    void clearWriteError() { setWriteError(0); }
  
    virtual size_t write(uint8_t) = 0;
    size_t write(const char *str) {
      if (str == NULL) return 0;
      return write((const uint8_t *)str, strlen(str));
    }
    virtual size_t write(const uint8_t *buffer, size_t size);
    size_t write(const char *buffer, size_t size) {
      return write((const uint8_t *)buffer, size);
    }
    
    size_t print(const __FlashStringHelper *);
    size_t print(const String &);
    size_t print(const char[]);
    size_t print(char);
    size_t print(unsigned char, int = DEC);
    size_t print(int, int = DEC);
    size_t print(unsigned int, int = DEC);
    size_t print(long, int = DEC);
    size_t print(unsigned long, int = DEC);
    size_t print(double, int = 2);
    size_t print(const Printable&);

    size_t println(const __FlashStringHelper *);
    size_t println(const String &s);
    size_t println(const char[]);
    size_t println(char);
    size_t println(unsigned char, int = DEC);
    size_t println(int, int = DEC);
    size_t println(unsigned int, int = DEC);
    size_t println(long, int = DEC);
    size_t println(unsigned long, int = DEC);
    size_t println(double, int = 2);
    size_t println(const Printable&);
    size_t println(void);
};

#endif


// compatability macros for testing
/*
#define   getInt()            parseInt()
#define   getInt(skipChar)    parseInt(skipchar)
#define   getFloat()          parseFloat()
#define   getFloat(skipChar)  parseFloat(skipChar)
#define   getString( pre_string, post_string, buffer, length)
readBytesBetween( pre_string, terminator, buffer, length)
*/

class Stream : public Print
{
  protected:
    unsigned long _timeout;      // number of milliseconds to wait for the next char before aborting timed read
    unsigned long _startMillis;  // used for timeout measurement
    int timedRead();    // private method to read stream with timeout
    int timedPeek();    // private method to peek stream with timeout
    int peekNextDigit(); // returns the next numeric digit in the stream or -1 if timeout

  public:
    virtual int available() = 0;
    virtual int read() = 0;
    virtual int peek() = 0;
    virtual void flush() = 0;

    Stream() {_timeout=1000;}

// parsing methods

  void setTimeout(unsigned long timeout);  // sets maximum milliseconds to wait for stream data, default is 1 second

  bool find(char *target);   // reads data from the stream until the target string is found
  bool find(uint8_t *target) { return find ((char *)target); }
  // returns true if target string is found, false if timed out (see setTimeout)

  bool find(char *target, size_t length);   // reads data from the stream until the target string of given length is found
  bool find(uint8_t *target, size_t length) { return find ((char *)target, length); }
  // returns true if target string is found, false if timed out

  bool findUntil(char *target, char *terminator);   // as find but search ends if the terminator string is found
  bool findUntil(uint8_t *target, char *terminator) { return findUntil((char *)target, terminator); }

  bool findUntil(char *target, size_t targetLen, char *terminate, size_t termLen);   // as above but search ends if the terminate string is found
  bool findUntil(uint8_t *target, size_t targetLen, char *terminate, size_t termLen) {return findUntil((char *)target, targetLen, terminate, termLen); }


  long parseInt(); // returns the first valid (long) integer value from the current position.
  // initial characters that are not digits (or the minus sign) are skipped
  // integer is terminated by the first character that is not a digit.

  float parseFloat();               // float version of parseInt

  size_t readBytes( char *buffer, size_t length); // read chars from stream into buffer
  size_t readBytes( uint8_t *buffer, size_t length) { return readBytes((char *)buffer, length); }
  // terminates if length characters have been read or timeout (see setTimeout)
  // returns the number of characters placed in the buffer (0 means no valid data found)

  size_t readBytesUntil( char terminator, char *buffer, size_t length); // as readBytes with terminator character
  size_t readBytesUntil( char terminator, uint8_t *buffer, size_t length) { return readBytesUntil(terminator, (char *)buffer, length); }
  // terminates if length characters have been read, timeout, or if the terminator character  detected
  // returns the number of characters placed in the buffer (0 means no valid data found)

  // Arduino String functions to be added here
  String readString();
  String readStringUntil(char terminator);

  protected:
  long parseInt(char skipChar); // as above but the given skipChar is ignored
  // as above but the given skipChar is ignored
  // this allows format characters (typically commas) in values to be ignored

  float parseFloat(char skipChar);  // as above but the given skipChar is ignored

  struct MultiTarget {
    const char *str;  // string you're searching for
    size_t len;       // length of string you're searching for
    size_t index;     // index used by the search routine.
  };

  // This allows you to search for an arbitrary number of strings.
  // Returns index of the target that is found first or -1 if timeout occurs.
  int findMulti(struct MultiTarget *targets, int tCount);
};


#endif


#define BUFFER_LENGTH 32

class TwoWire : public Stream
{
  private:
    static uint8_t rxBuffer[];
    static uint8_t rxBufferIndex;
    static uint8_t rxBufferLength;

    static uint8_t txAddress;
    static uint8_t txBuffer[];
    static uint8_t txBufferIndex;
    static uint8_t txBufferLength;

    static uint8_t transmitting;
    static void (*user_onRequest)(void);
    static void (*user_onReceive)(int);
    static void onRequestService(void);
    static void onReceiveService(uint8_t*, int);
  public:
    TwoWire();
    void begin();
    void begin(uint8_t);
    void begin(int);
    void setClock(uint32_t);
    void beginTransmission(uint8_t);
    void beginTransmission(int);
    uint8_t endTransmission(void);
    uint8_t endTransmission(uint8_t);
    uint8_t requestFrom(uint8_t, uint8_t);
    uint8_t requestFrom(uint8_t, uint8_t, uint8_t);
    uint8_t requestFrom(int, int);
    uint8_t requestFrom(int, int, int);
    virtual size_t write(uint8_t);
    virtual size_t write(const uint8_t *, size_t);
    virtual int available(void);
    virtual int read(void);
    virtual int peek(void);
    virtual void flush(void);
    void onReceive( void (*)(int) );
    void onRequest( void (*)(void) );

    inline size_t write(unsigned long n) { return write((uint8_t)n); }
    inline size_t write(long n) { return write((uint8_t)n); }
    inline size_t write(unsigned int n) { return write((uint8_t)n); }
    inline size_t write(int n) { return write((uint8_t)n); }
    using Print::write;
};

extern TwoWire Wire;

#endif



#define PN532_PREAMBLE                      (0x00)
#define PN532_STARTCODE1                    (0x00)
#define PN532_STARTCODE2                    (0xFF)
#define PN532_POSTAMBLE                     (0x00)

#define PN532_HOSTTOPN532                   (0xD4)
#define PN532_PN532TOHOST                   (0xD5)

// PN532 Commands
#define PN532_COMMAND_DIAGNOSE              (0x00)
#define PN532_COMMAND_GETFIRMWAREVERSION    (0x02)
#define PN532_COMMAND_GETGENERALSTATUS      (0x04)
#define PN532_COMMAND_READREGISTER          (0x06)
#define PN532_COMMAND_WRITEREGISTER         (0x08)
#define PN532_COMMAND_READGPIO              (0x0C)
#define PN532_COMMAND_WRITEGPIO             (0x0E)
#define PN532_COMMAND_SETSERIALBAUDRATE     (0x10)
#define PN532_COMMAND_SETPARAMETERS         (0x12)
#define PN532_COMMAND_SAMCONFIGURATION      (0x14)
#define PN532_COMMAND_POWERDOWN             (0x16)
#define PN532_COMMAND_RFCONFIGURATION       (0x32)
#define PN532_COMMAND_RFREGULATIONTEST      (0x58)
#define PN532_COMMAND_INJUMPFORDEP          (0x56)
#define PN532_COMMAND_INJUMPFORPSL          (0x46)
#define PN532_COMMAND_INLISTPASSIVETARGET   (0x4A)
#define PN532_COMMAND_INATR                 (0x50)
#define PN532_COMMAND_INPSL                 (0x4E)
#define PN532_COMMAND_INDATAEXCHANGE        (0x40)
#define PN532_COMMAND_INCOMMUNICATETHRU     (0x42)
#define PN532_COMMAND_INDESELECT            (0x44)
#define PN532_COMMAND_INRELEASE             (0x52)
#define PN532_COMMAND_INSELECT              (0x54)
#define PN532_COMMAND_INAUTOPOLL            (0x60)
#define PN532_COMMAND_TGINITASTARGET        (0x8C)
#define PN532_COMMAND_TGSETGENERALBYTES     (0x92)
#define PN532_COMMAND_TGGETDATA             (0x86)
#define PN532_COMMAND_TGSETDATA             (0x8E)
#define PN532_COMMAND_TGSETMETADATA         (0x94)
#define PN532_COMMAND_TGGETINITIATORCOMMAND (0x88)
#define PN532_COMMAND_TGRESPONSETOINITIATOR (0x90)
#define PN532_COMMAND_TGGETTARGETSTATUS     (0x8A)

#define PN532_RESPONSE_INDATAEXCHANGE       (0x41)
#define PN532_RESPONSE_INLISTPASSIVETARGET  (0x4B)


#define PN532_WAKEUP                        (0x55)

#define PN532_SPI_STATREAD                  (0x02)
#define PN532_SPI_DATAWRITE                 (0x01)
#define PN532_SPI_DATAREAD                  (0x03)
#define PN532_SPI_READY                     (0x01)

#define PN532_I2C_ADDRESS                   (0x48 >> 1)
#define PN532_I2C_READBIT                   (0x01)
#define PN532_I2C_BUSY                      (0x00)
#define PN532_I2C_READY                     (0x01)
#define PN532_I2C_READYTIMEOUT              (20)

#define PN532_MIFARE_ISO14443A              (0x00)

// Mifare Commands
#define MIFARE_CMD_AUTH_A                   (0x60)
#define MIFARE_CMD_AUTH_B                   (0x61)
#define MIFARE_CMD_READ                     (0x30)
#define MIFARE_CMD_WRITE                    (0xA0)
#define MIFARE_CMD_TRANSFER                 (0xB0)
#define MIFARE_CMD_DECREMENT                (0xC0)
#define MIFARE_CMD_INCREMENT                (0xC1)
#define MIFARE_CMD_STORE                    (0xC2)

// Prefixes for NDEF Records (to identify record type)
#define NDEF_URIPREFIX_NONE                 (0x00)
#define NDEF_URIPREFIX_HTTP_WWWDOT          (0x01)
#define NDEF_URIPREFIX_HTTPS_WWWDOT         (0x02)
#define NDEF_URIPREFIX_HTTP                 (0x03)
#define NDEF_URIPREFIX_HTTPS                (0x04)
#define NDEF_URIPREFIX_TEL                  (0x05)
#define NDEF_URIPREFIX_MAILTO               (0x06)
#define NDEF_URIPREFIX_FTP_ANONAT           (0x07)
#define NDEF_URIPREFIX_FTP_FTPDOT           (0x08)
#define NDEF_URIPREFIX_FTPS                 (0x09)
#define NDEF_URIPREFIX_SFTP                 (0x0A)
#define NDEF_URIPREFIX_SMB                  (0x0B)
#define NDEF_URIPREFIX_NFS                  (0x0C)
#define NDEF_URIPREFIX_FTP                  (0x0D)
#define NDEF_URIPREFIX_DAV                  (0x0E)
#define NDEF_URIPREFIX_NEWS                 (0x0F)
#define NDEF_URIPREFIX_TELNET               (0x10)
#define NDEF_URIPREFIX_IMAP                 (0x11)
#define NDEF_URIPREFIX_RTSP                 (0x12)
#define NDEF_URIPREFIX_URN                  (0x13)
#define NDEF_URIPREFIX_POP                  (0x14)
#define NDEF_URIPREFIX_SIP                  (0x15)
#define NDEF_URIPREFIX_SIPS                 (0x16)
#define NDEF_URIPREFIX_TFTP                 (0x17)
#define NDEF_URIPREFIX_BTSPP                (0x18)
#define NDEF_URIPREFIX_BTL2CAP              (0x19)
#define NDEF_URIPREFIX_BTGOEP               (0x1A)
#define NDEF_URIPREFIX_TCPOBEX              (0x1B)
#define NDEF_URIPREFIX_IRDAOBEX             (0x1C)
#define NDEF_URIPREFIX_FILE                 (0x1D)
#define NDEF_URIPREFIX_URN_EPC_ID           (0x1E)
#define NDEF_URIPREFIX_URN_EPC_TAG          (0x1F)
#define NDEF_URIPREFIX_URN_EPC_PAT          (0x20)
#define NDEF_URIPREFIX_URN_EPC_RAW          (0x21)
#define NDEF_URIPREFIX_URN_EPC              (0x22)
#define NDEF_URIPREFIX_URN_NFC              (0x23)

#define PN532_GPIO_VALIDATIONBIT            (0x80)
#define PN532_GPIO_P30                      (0)
#define PN532_GPIO_P31                      (1)
#define PN532_GPIO_P32                      (2)
#define PN532_GPIO_P33                      (3)
#define PN532_GPIO_P34                      (4)
#define PN532_GPIO_P35                      (5)

class Adafruit_NFCShield_I2C{
 public:
  Adafruit_NFCShield_I2C(uint8_t irq, uint8_t reset);
  void begin(void);
  
  // Generic PN532 functions
  boolean SAMConfig(void);
  uint32_t getFirmwareVersion(void);
  boolean sendCommandCheckAck(uint8_t *cmd, uint8_t cmdlen, uint16_t timeout = 1000);  
  boolean writeGPIO(uint8_t pinstate);
  uint8_t readGPIO(void);
  boolean setPassiveActivationRetries(uint8_t maxRetries);
  
  // ISO14443A functions
  boolean inListPassiveTarget();
  boolean readPassiveTargetID(uint8_t cardbaudrate, uint8_t * uid, uint8_t * uidLength, uint16_t timeout = 0); //timeout 0 means no timeout - will block forever.

  boolean inDataExchange(uint8_t * send, uint8_t sendLength, uint8_t * response, uint8_t * responseLength);
  
  // Mifare Classic functions
  bool mifareclassic_IsFirstBlock (uint32_t uiBlock);
  bool mifareclassic_IsTrailerBlock (uint32_t uiBlock);
  uint8_t mifareclassic_AuthenticateBlock (uint8_t * uid, uint8_t uidLen, uint32_t blockNumber, uint8_t keyNumber, uint8_t * keyData);
  uint8_t mifareclassic_ReadDataBlock (uint8_t blockNumber, uint8_t * data);
  uint8_t mifareclassic_WriteDataBlock (uint8_t blockNumber, uint8_t * data);
  uint8_t mifareclassic_FormatNDEF (void);
  uint8_t mifareclassic_WriteNDEFURI (uint8_t sectorNumber, uint8_t uriIdentifier, const char * url);
  
  // Mifare Ultralight functions
  uint8_t mifareultralight_ReadPage (uint8_t page, uint8_t * buffer);
  
  // Help functions to display formatted text
  static void PrintHex(const byte * data, const uint32_t numBytes);
  static void PrintHexChar(const byte * pbtData, const uint32_t numBytes);

 private:
  uint8_t _irq, _reset;
  uint8_t _uid[7];  // ISO14443A uid
  uint8_t _uidLen;  // uid len
  uint8_t _key[6];  // Mifare Classic key
  uint8_t inListedTag; // Tg number of inlisted tag.

  boolean readackframe(void);
  uint8_t wirereadstatus(void);
  void    wirereaddata(uint8_t* buff, uint8_t n);
  void    wiresendcommand(uint8_t* cmd, uint8_t cmdlen);
  boolean waitUntilReady(uint16_t timeout);
};

#endif

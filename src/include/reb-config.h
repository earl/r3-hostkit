/***********************************************************************
**
**  REBOL 3.0 "Invasion"
**  Copyright 2010 REBOL Technologies
**  All rights reserved.
**
************************************************************************
**
**  Title: General build configuration
**  Date:  1-Dec-2009
**  File:  reb-config.h
**
**  Note: This is the first file included.
**
***********************************************************************/

//* Common *************************************************************

#define INT_64_MODE				// 64 bit integer datatype
#define THREADED				// enable threads


//* MS Windows 32 ******************************************************

#ifdef TO_WIN32					// Win32/Intel

#define	WIN32_LEAN_AND_MEAN		// trim down the Win32 headers
#define ENDIAN_LITTLE			// uses little endian byte order
#define OS_WIDE_CHAR			// OS uses WIDE_CHAR API
#define OS_CRLF TRUE			// uses CRLF as line terminator
#define OS_DIR_SEP '\\'			// file path separator (Thanks Bill.)
#define HAS_ASYNC_DNS			// supports it
#define ATOI					// supports it
#define ATOI64					// supports it
#define ITOA64					// supports it
#define HAS_ECVT				// supports ecvt()
#define FINITE _finite			// name used for it
#define INLINE __inline			// name used for it

#ifdef THREADED
#define THREAD __declspec(thread)
#endif

// Used when we build REBOL as a DLL:
#define API_EXPORT __declspec(dllexport)
#define API_IMPORT __declspec(dllimport)

// Use non-standard int64 declarations:
#if (defined(_MSC_VER) && (_MSC_VER <= 1200))
#define ODD_INT_64
#else
#define HAS_LONG_DOUBLE
#endif

// Disable various warnings
#pragma warning(disable : 4201)		// nameless unions
#pragma warning(disable : 4100)		// unreferenced formal parameter
#pragma warning(disable : 4127)		// conditional expression is constant
//#pragma warning(disable : 4057)
//#pragma warning(disable : 4701)

#else

//* Non Windows ********************************************************

#define MIN_OS					// not all devices are working
#define NO_GRAPHICS				// no graphics yet
#define FINITE finite
#define INLINE
#define API_EXPORT __attribute__((visibility("default")))
#define API_IMPORT
#endif

#ifdef TO_LINUX					// Linux/Intel
#define ENDIAN_LITTLE
#define HAS_ECVT
#define HAS_LONG_DOUBLE
#endif

#ifdef TO_LINUX_PPC				// Linux/PPC
#define ENDIAN_BIG
#define HAS_ECVT
#define HAS_LONG_DOUBLE
#endif

#ifdef TO_OSXI					// OSX/Intel
#define ENDIAN_LITTLE
#define HAS_ECVT
#define HAS_LONG_DOUBLE
#endif

#ifdef TO_OSX					// OSX/PPC
#define ENDIAN_BIG
#define HAS_ECVT
#define HAS_LL_CONSTS
#define OLD_COMPILER
#endif

#ifdef TO_FREEBSD
#define ENDIAN_LITTLE
#define HAS_LONG_DOUBLE
#endif

#ifdef TO_OPENBSD
#define ENDIAN_LITTLE
#define HAS_LL_CONSTS
#define HAS_ECVT
#endif

#ifdef TO_OBSD					// OpenBSD
#define COPY_STR(d,s,m) strlcpy(d,s,m)
#define JOIN_STR(d,s,m) strlcat(d,s,m)
#endif

//* Defaults ***********************************************************

#ifdef HAS_LONG_DOUBLE
#define HAS_LL_CONSTS
#endif

#ifndef THREAD
#define THREAD
#endif

#ifndef OS_DIR_SEP
#define OS_DIR_SEP '/'			// rest of the world uses it
#endif

#ifndef OS_CRLF
#define OS_CRLF FALSE
#endif

#ifdef REBOL_ONLY
#define REBOL_API				// REBOL stand-alone test version
#else
#ifdef REBOL_EXPORTS
#define REBOL_API API_EXPORT	// for REBOL library build
#else
#define REBOL_API API_IMPORT	// for host files when DLL used
#endif
#endif // REBOL_ONLY

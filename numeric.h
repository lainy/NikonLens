/*
 * numeric.h
 *
 *  Created: 8/2/2013 04:21:01
 *
 *  Lain A.
 *  code@hacktheinter.net
 *  http://hacktheinter.net
 *
 *  Copyright (c) 2013 Lain A.
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *  THE SOFTWARE.
 */

#ifndef NUMERIC_H_
#define NUMERIC_H_

#include <inttypes.h>

///////////////////////////////////////////////////////////////////////////////
//! \addtogroup util Misc. utilities
//@{

//! \name Shorter numeric typedefs.
//@{
typedef unsigned int uint; //!< Unsigned integer
typedef  uint8_t  u8;      //!< 8-bit unsigned integer
typedef uint16_t u16;      //!< 16-bit unsigned integer
typedef uint32_t u32;      //!< 32-bit unsigned integer
typedef uint64_t u64;      //!< 64-bit unsigned integer
typedef   int8_t  s8;      //!< 8-bit signed integer
typedef  int16_t s16;      //!< 16-bit signed integer
typedef  int32_t s32;      //!< 32-bit signed integer
typedef  int64_t s64;      //!< 64-bit signed integer
//@}

//@}

#endif /* NUMERIC_H_ */

// eof

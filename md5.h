/* MD5 for GNU make
Copyright (C) 2013-2015 Free Software Foundation, Inc.
This file is part of GNU Make.

GNU Make is free software; you can redistribute it and/or modify it under the
terms of the GNU General Public License as published by the Free Software
Foundation; either version 3 of the License, or (at your option) any later
version.

GNU Make is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program.  If not, see <http://www.gnu.org/licenses/>.  */

#ifndef MAKE_MD5_H
#define MAKE_MD5_H
#include <stddef.h>


 // Block size defined by algorithm;
#define kBlockSize  ((int)64)

/* struct for computing Message Digest version 5 checksums */
typedef struct  CMD5_t
  {
    uint32_t       m_Buf[4];
    int64_t        m_Bits; // must be a 64-bit count
    unsigned char  m_In[kBlockSize];
    int            m_Finalized;
  } CMD5;

/* create a new CMD5 */
CMD5* CMD5New(void);
/* Update state to reflect the concatenation of another buffer full of bytes. */
void CMD5Update(CMD5* ptr,const char* buf, size_t length);
/* // Final wrapup - pad to kBlockSize-byte boundary with the bit pattern */
void CMD5Finalize(CMD5* ptr,unsigned char digest[16]);

#endif

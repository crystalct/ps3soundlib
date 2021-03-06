/*
	mangle: support defines for preprocessed assembler

	copyright 1995-2007 by the mpg123 project - free software under the terms of the LGPL 2.1
	see COPYING and AUTHORS files in distribution or http://mpg123.org

	This once started out as mangle.h from MPlayer, but you can't really call it derived work... the small part that in principle stems from MPlayer also being not very special (once you decided to use such a header at all, it's quite obvious material).
*/

#ifndef __MANGLE_H
#define __MANGLE_H

#include "config.h"

#ifdef CCALIGN
#define MOVUAPS movaps
#else
#define MOVUAPS movups
#endif

#ifdef ASMALIGN_EXP
#define ALIGN4  .align 2
#define ALIGN8  .align 3
#define ALIGN16 .align 4
#define ALIGN32 .align 5
#else
#define ALIGN4  .align 4
#define ALIGN8  .align 8
#define ALIGN16 .align 16
#define ALIGN32 .align 32
#endif

/* Feel free to add more to the list, eg. a.out IMO */
#if defined(__CYGWIN__) || defined(__MINGW32__) || defined(__OS2__) || \
   (defined(__OpenBSD__) && !defined(__ELF__)) || defined(__APPLE__)
#define MANGLE(a) "_" #a
#define ASM_NAME(a) _##a
#define ASM_VALUE(a) $_##a
#else
#define MANGLE(a) #a
#define ASM_NAME(a) a
#define ASM_VALUE(a) "$" #a
#endif

#if defined(__CYGWIN__) || defined(__MINGW32__) || defined(__APPLE__)
#define COMM(a,b,c) .comm a,b
#else
#define COMM(a,b,c) .comm a,b,c
#endif
/* more hacks for macosx; no .bss ... */
#ifdef __APPLE__
#define BSS .data
#else
#define BSS .bss
#endif
#endif /* !__MANGLE_H */


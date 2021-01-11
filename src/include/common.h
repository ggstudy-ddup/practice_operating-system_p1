/*
 * common.h
 * defines some common functions needed for the incomplete OS
 *  
 */
#ifndef __INCLUDE_COMMON_H__
#define __INCLUDE_COMMON_H__

#include <define.h>

/* Video */
#define VID_MEM_BEG 0xB8000
#define VID_YROWS  25
#define VID_XLINES 80
word *vid_pos = VID_MEM_BEG;

 #endif /* !__INCLUDE_COMMON_H__ */


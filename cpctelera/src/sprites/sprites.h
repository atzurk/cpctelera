//-----------------------------LICENSE NOTICE------------------------------------
//  This file is part of CPCtelera: An Amstrad CPC Game Engine
//  Copyright (C) 2014-2015 ronaldo / Fremos / Cheesetea / ByteRealms (@FranGallegoBR)
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//-------------------------------------------------------------------------------

//#####################################################################
//### MODULE: Sprites                                               ###
//#####################################################################
//### This module contains several functions and routines to manage ###
//### sprites and video memory in an Amstrad CPC environment.       ###
//#####################################################################
//

#ifndef CPCT_SPRITES_H
#define CPCT_SPRITES_H

#include <types.h>

// Standard memory management functions
extern void cpct_memset    (void *array, u8 value, u16 size);

// Functions to transform firmware colours for a group of pixels into a byte in screen pixel format
extern   u8 cpct_px2byteM0 (u8 px0, u8 px1);
extern   u8 cpct_px2byteM1 (u8 px0, u8 px1, u8 px2, u8 px3);

// Sprite and box drawing functions
extern void cpct_drawSpriteAligned2x8  (void *sprite, void* memory);
extern void cpct_drawSpriteAligned4x8  (void *sprite, void* memory);
extern void cpct_drawSpriteAligned2x8_f(void *sprite, void* memory);
extern void cpct_drawSpriteAligned4x8_f(void *sprite, void* memory);
extern void cpct_drawSprite            (void *sprite, void* memory, u8 width, u8 height);
extern void cpct_drawSpriteMasked      (void *sprite, void* memory, u8 width, u8 height);
extern void cpct_drawSolidBox          (void *memory, u8 colour_pattern, u8 width, u8 height);

// Functions to modify video memory location
extern void cpct_setVideoMemoryPage    (  i8 page_codified_in_6LSb);
extern void cpct_setVideoMemoryOffset  (  i8 offset);

// Useful constants with some typical video memory pages
#define cpct_pageC0 0x30
#define cpct_page80	0x20
#define cpct_page40	0x10
#define cpct_page00 0x00

// Calculate mempage value for cpct_setVideoMemoryPage
#define cpct_memPage6(A) ((A) >> 2)

#endif

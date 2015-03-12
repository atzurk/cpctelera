//-----------------------------LICENSE NOTICE------------------------------------
//  This file is part of CPCtelera: An Amstrad CPC Game Engine
//  Copyright (C) 2015 ronaldo / Fremos / Cheesetea / ByteRealms (@FranGallegoBR)
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
//------------------------------------------------------------------------------

#include <cpctelera.h>
#include "demo.song"

void main(void) {
   unsigned char playing = 1, color = 1;
   char* video_pos = (char*) 0xC000;

   cpct_disableFirmware();
   cpct_setVideoMode(2);

   cpct_arkosPlayer_init(molusk_song);
   while (1) {
      __asm
            ld   b, #0xF5
            in   a,(c)
            rra
            jr  nc, .-3
      __endasm;

      if (playing) {
         cpct_arkosPlayer_play();
         cpct_drawROMCharM2(video_pos, color, '#');
         if (++video_pos >= (char*)0xC7CF) {
            video_pos = (char*)0xC000;
            color ^= 1;
         }
      }

      cpct_scanKeyboardFast();
      if (cpct_isKeyPressed(Key_Space)) {
         if (playing)
            cpct_arkosPlayer_stop();
         playing ^= 1;
      }
   }
}

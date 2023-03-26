/*
 *   UXAV - Easy, fast WAV files player in Terminal
 *   Copyright (C) 2023 SolindekDev
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "uxav_play_alsa.h"
#include <uxav_wav_encoder.h>
#include <uxav_wav_header.h>

#include <uxav_main.h>
#include <uxav_io.h>

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int 
main(int argc, char** argv) 
{
    USE(*argv++);

    if (argc < 2) 
    {
        printf("Expected more arguments, example usage of uxav: uxav <filename.wav>\n");
        return EXIT_FAILURE;
    }

    FILE* f = fopen(*argv, "r");
    if (f == NULL) 
    {
        printf("File \"%s\" doesn't exists\n", *argv);
        return EXIT_FAILURE;
    }

    unsigned char* file_bytes = uxav_io_read_bytes(*argv); 
    wav_header_t* wav_header  = uxav_encode_wav(file_bytes);

    if (memcmp(wav_header->wav_header_info->riff_magic, RIFF_MAGIC, 4) != 0)
    {
        printf("This file isn't WAV\n");
        return EXIT_FAILURE;
    } 

    if (uxav_play_sound(wav_header) == 1) return EXIT_FAILURE;

    return EXIT_SUCCESS;
}
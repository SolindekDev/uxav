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

#include <uxav_main.h>
#include <uxav_io.h>

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

unsigned char*
uxav_io_read_bytes(const char* filename)
{
    FILE* f = fopen(filename, "rb");

    fseek(f, 0, SEEK_END);
    long int res = ftell(f);
    fseek(f, 0, SEEK_SET);

    unsigned char* bytes = malloc((sizeof(unsigned char) * res));
    char c = 'A';

    for (long int i = 0; i < res; i++) {
        c = fgetc(f);
        bytes[i] = c;
    }
  
    fclose(f);
    return bytes;
}
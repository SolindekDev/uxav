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

#ifndef __UXAV_WAV_ENCODER_H__
#define __UXAV_WAV_ENCODER_H__

#include "uxav_wav_header.h"

wav_header_t* uxav_encode_wav(unsigned char* bytes);

void uxav_print_wav_info(wav_header_t* wav_header);

long uxav_get_file_length_ms(wav_header_t* wav_header);
double uxav_get_file_length_sec(wav_header_t* wav_header);

#endif /* __UXAV_WAV_ENCODER_H__ */
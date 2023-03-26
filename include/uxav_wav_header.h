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

#ifndef __UXAV_WAV_HEADER_H__
#define __UXAV_WAV_HEADER_H__

static const unsigned char RIFF_MAGIC[4] = { 'R', 'I', 'F', 'F' };

typedef struct wav_header_info_t {
    unsigned char  riff_magic[4];
    unsigned int   file_size;
    unsigned char  file_header[4];
    unsigned char  format_chunk[4];
    unsigned int   length_format_data;
    unsigned short type_format;
    unsigned short channels_number;
    unsigned int   sample_rate;
    unsigned int   bytes_sec;
    unsigned short block_align;
    unsigned short bits_per_sample;
    unsigned char  data_start[4];
    unsigned int   data_section_length;
} wav_header_info_t;

typedef struct wav_header_t {
    wav_header_info_t* wav_header_info;
    unsigned char*     data_section;
} wav_header_t;

#endif /* __UXAV_WAV_HEADER_H__ */
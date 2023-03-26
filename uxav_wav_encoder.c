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

#include <uxav_wav_encoder.h>
#include <uxav_wav_header.h>

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

wav_header_t*
uxav_encode_wav(unsigned char* bytes)
{
    wav_header_t* wav_header_info = (wav_header_t*)malloc(sizeof(wav_header_t));

    wav_header_info->wav_header_info = (wav_header_info_t*)bytes;
    wav_header_info->data_section    = ((unsigned char*)(bytes + sizeof(wav_header_info_t)));

    return wav_header_info;
}

void
uxav_print_wav_info(wav_header_t* wav_header) 
{
    printf("RIFF Magic: %.4s\n",       wav_header->wav_header_info->riff_magic);    
    printf("File size: %d\n",          wav_header->wav_header_info->file_size);    
    printf("File header: %.4s\n",      wav_header->wav_header_info->file_header);    
    printf("File chunk: %.4s\n",       wav_header->wav_header_info->format_chunk);    
    printf("Length format data: %d\n", wav_header->wav_header_info->length_format_data);    
    printf("Type format: %d\n",        wav_header->wav_header_info->type_format);    
    printf("Channels number: %d\n",    wav_header->wav_header_info->channels_number);    
    printf("Sample rate: %d\n",        wav_header->wav_header_info->sample_rate);    
    printf("Bytes sec: %d\n",          wav_header->wav_header_info->bytes_sec);    
    printf("Block align: %d\n",        wav_header->wav_header_info->block_align);    
    printf("Bits per sample: %d\n",    wav_header->wav_header_info->bits_per_sample);   
    printf("Data start: %.4s\n",       wav_header->wav_header_info->data_start);    
    printf("Data section start: %d\n", wav_header->wav_header_info->data_section_length);    
}

long 
uxav_get_file_length_ms(wav_header_t* wav_header)
{
    return (wav_header->wav_header_info->data_section_length / wav_header->wav_header_info->bytes_sec) * 1000;
}

double 
uxav_get_file_length_sec(wav_header_t* wav_header)
{
    return wav_header->wav_header_info->data_section_length / wav_header->wav_header_info->bytes_sec;
}

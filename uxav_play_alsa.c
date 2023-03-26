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

#include <unistd.h>
#include <uxav_wav_encoder.h>
#include <uxav_wav_header.h>
#include <uxav_play_alsa.h>

#include <uxav_main.h>

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <alsa/asoundlib.h>
#include <alsa/pcm.h>

#define alloca(x)  __builtin_alloca(x)

snd_pcm_t*
uxav_open_device()
{
    snd_pcm_t *pcm;
    snd_pcm_open(&pcm, "default", SND_PCM_STREAM_PLAYBACK, 0);

    return pcm;
}

void
uxav_configure_device(snd_pcm_t* pcm, unsigned int channels, unsigned int rate)
{
    snd_pcm_hw_params_t *hw_params;
    snd_pcm_hw_params_alloca(&hw_params);

    snd_pcm_hw_params_any(pcm, hw_params);
    snd_pcm_hw_params_set_access(pcm, hw_params, SND_PCM_ACCESS_RW_INTERLEAVED);
    snd_pcm_hw_params_set_format(pcm, hw_params, SND_PCM_FORMAT_S16_LE);
    snd_pcm_hw_params_set_channels(pcm, hw_params, channels);
    snd_pcm_hw_params_set_rate(pcm, hw_params, rate, 0);

    snd_pcm_hw_params(pcm, hw_params);
}

int 
uxav_play_sound(wav_header_t* wav_header)
{
    snd_pcm_t* pcm = uxav_open_device();
    uxav_configure_device(pcm, wav_header->wav_header_info->channels_number,
                          wav_header->wav_header_info->sample_rate);

    snd_pcm_writei(pcm, wav_header->data_section, wav_header->wav_header_info->data_section_length / sizeof(unsigned short));

    snd_pcm_drain(pcm);
    snd_pcm_close(pcm);

    return 0;
}

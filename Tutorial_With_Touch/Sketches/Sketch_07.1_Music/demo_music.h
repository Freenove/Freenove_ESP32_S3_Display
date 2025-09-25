
#ifndef DEMO_MUSIC_H
#define DEMO_MUSIC_H

#include "FS.h"
#include "Audio.h"
extern Audio audio;

bool demo_music(void);
const char * demo_music_get_title(uint32_t track_id);
void demo_music_play(uint32_t track_id);
void demo_music_pause(void);

#endif /*LV_DEMO_MUSIC_H*/

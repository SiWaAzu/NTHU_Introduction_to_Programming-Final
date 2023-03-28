#include <iostream>
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void draw_ribbon_scene(ALLEGRO_FONT* font_pirulen_16,ALLEGRO_FONT* font_pirulen_20,
const int SCREEN_W,const int SCREEN_H,ALLEGRO_BITMAP* talk_bg);

void ribbon_back_to_FIND(int keycode);


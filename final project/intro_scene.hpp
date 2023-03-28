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

void draw_intro_scene(ALLEGRO_FONT* font_pirulen_24,ALLEGRO_BITMAP* intro_bg,const int SCREEN_W,const int SCREEN_H);
void back_to_MENU(int keycode);


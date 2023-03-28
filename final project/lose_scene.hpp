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

void draw_lose_scene(ALLEGRO_BITMAP* lose_bg,const int SCREEN_H,const int SCREEN_W,ALLEGRO_FONT* font_pirulen_16);
void lose_click_but(int btn, int x, int y,int mouse_x,int mouse_y);

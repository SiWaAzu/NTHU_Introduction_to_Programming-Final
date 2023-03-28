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


void draw_find_scene(ALLEGRO_BITMAP* findscene_bg,const int SCREEN_W,const int SCREEN_H,
					ALLEGRO_BITMAP* img_talk,ALLEGRO_BITMAP* item_box,
					ALLEGRO_BITMAP* Ribbon,int ribbon_flag,
					ALLEGRO_BITMAP* door_key,int key_flag,
					ALLEGRO_BITMAP* Kinfe,int kinfe_flag);
void find_click_but(int btn, int x, int y,int mouse_x,int mouse_y,ALLEGRO_BITMAP* img_talk,const int SCREEN_W,const int SCREEN_H,ALLEGRO_FONT* font_pirulen_16);

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


void draw_run_scene(ALLEGRO_BITMAP* runscene_bg,ALLEGRO_FONT* font_pirulen_24,
const int SCREEN_W,const int SCREEN_H,ALLEGRO_BITMAP* img_window,ALLEGRO_BITMAP* item_box,
ALLEGRO_BITMAP* img_book1,ALLEGRO_BITMAP* img_book2,ALLEGRO_BITMAP* img_paperpile,ALLEGRO_BITMAP* img_hp);

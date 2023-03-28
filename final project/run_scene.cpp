#include "run_scene.hpp"
#include "game_iniation.hpp"
void draw_run_scene(ALLEGRO_BITMAP* runscene_bg,ALLEGRO_FONT* font_pirulen_24,
const int SCREEN_W,const int SCREEN_H,ALLEGRO_BITMAP* img_window,ALLEGRO_BITMAP* item_box
,ALLEGRO_BITMAP* img_book1,ALLEGRO_BITMAP* img_book2,ALLEGRO_BITMAP* img_paperpile,ALLEGRO_BITMAP* img_hp)

{
	al_draw_bitmap(runscene_bg, 0, 0, 0);
    //al_draw_text(font_pirulen_24, al_map_rgb(255,255,255), SCREEN_W / 2+300, SCREEN_H -100, ALLEGRO_ALIGN_CENTER, "item");
    //al_draw_bitmap(img_window,850,300, 0);
	//al_draw_bitmap(img_window,600,300, 1);
	//al_draw_bitmap(img_window,350,300, 1);
	//al_draw_bitmap(img_window,350,300, 1);
	al_draw_bitmap(item_box,650,613,0);
	al_draw_bitmap(img_book1,160,517,0);
	al_draw_bitmap(img_book2,600,537,0);
	al_draw_bitmap(img_paperpile,380,565,0);
	al_draw_bitmap(img_book1,850,517,0);
	al_draw_bitmap(img_hp,20,50,0);
	al_draw_bitmap(img_hp,90,50,0);
	al_draw_bitmap(img_hp,160,50,0);
	
	
}


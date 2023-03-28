#include "END2.hpp"
#include "game_iniation.hpp"

void draw_end2_scene(ALLEGRO_BITMAP* END2_pic,const int SCREEN_H,const int SCREEN_W,ALLEGRO_FONT* font_pirulen_16)
{
	al_draw_bitmap(END2_pic, 0, 0, 0);
        al_draw_rectangle(150,SCREEN_H/2+300,300,SCREEN_H/2+300,al_map_rgb(105, 105 ,105), 40);
		al_draw_textf(font_pirulen_16, al_map_rgb(0,0,0), 170, SCREEN_H/2+290, ALLEGRO_ALIGN_LEFT,"back");
}

void END2_click_but(int btn, int x, int y,int mouse_x,int mouse_y)
{
	if (btn == 1)
		{
			change_flag (4);
			if (pnt(mouse_x, mouse_y, 130, 664, 189,50 ))
                game_change_scene(SCENE_MENU);
		}
}

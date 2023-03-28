#include "lose_scene.hpp"

#include "game_iniation.hpp"

void draw_lose_scene(ALLEGRO_BITMAP* lose_bg,const int SCREEN_H,const int SCREEN_W,ALLEGRO_FONT* font_pirulen_16)
{
	al_draw_bitmap(lose_bg, 0, 0, 0);
        al_draw_rectangle(150,SCREEN_H/2+300,400,SCREEN_H/2+300,al_map_rgb(105, 105 ,105), 40);
		al_draw_textf(font_pirulen_16, al_map_rgb(0,0,0), 170, SCREEN_H/2+290, ALLEGRO_ALIGN_LEFT,"again and again");
}

void lose_click_but(int btn, int x, int y,int mouse_x,int mouse_y)
{
	if (btn == 1)
		{
			if (pnt(mouse_x, mouse_y, 132, 663,417-132,40 ))
                game_change_scene(SCENE_MENU);
		}
}

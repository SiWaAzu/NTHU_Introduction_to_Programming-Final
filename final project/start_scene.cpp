#include "start_scene.hpp"
#include "game_iniation.hpp"

void draw_start_scene(ALLEGRO_BITMAP* startscene_bg,const int SCREEN_H,const int SCREEN_W,ALLEGRO_FONT* font_pirulen_16)
{
	al_draw_bitmap(startscene_bg, 0, 0, 0);
        //al_draw_rectangle(150,SCREEN_H/2+300,300,SCREEN_H/2+300,al_map_rgb(105, 105 ,105), 40);
        al_draw_rectangle(150,SCREEN_H/2+230,300,SCREEN_H/2+230,al_map_rgb(105, 105 ,105), 40);
        al_draw_rectangle(150,SCREEN_H/2+160,300,SCREEN_H/2+160,al_map_rgb(105, 105 ,105), 40);
		al_draw_textf(font_pirulen_16, al_map_rgb(0,0,0), 140, SCREEN_H/2+150, ALLEGRO_ALIGN_LEFT," Intoduction");
		al_draw_textf(font_pirulen_16, al_map_rgb(0,0,0), 140, SCREEN_H/2+220, ALLEGRO_ALIGN_LEFT," Start Game");
		//al_draw_textf(font_pirulen_16, al_map_rgb(0,0,0), 170, SCREEN_H/2+290, ALLEGRO_ALIGN_LEFT,"Settting");
}

void MENU_click_but(int btn, int x, int y,int mouse_x,int mouse_y)
{
	if (btn == 1)
		{
			if (pnt(mouse_x, mouse_y, 130, 524, 189,50 ))
				game_change_scene(SCENE_INTRO);
            else if (pnt(mouse_x, mouse_y, 130, 594, 189,50 ))
                game_change_scene(SCENE_RUN);
           // else if (pnt(mouse_x, mouse_y, 130, 664, 189,50 ))
             //   game_change_scene(SCENE_SETTINGS);
		}
}



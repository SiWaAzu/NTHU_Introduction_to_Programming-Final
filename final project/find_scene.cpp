#include "run_scene.hpp"
#include "game_iniation.hpp"
#include "talk_scene.hpp"
#include "find_scene.hpp"
#include "ribbon_scene.hpp"
#include "log.hpp"
void draw_find_scene(ALLEGRO_BITMAP* findscene_bg,const int SCREEN_W,
					const int SCREEN_H,ALLEGRO_BITMAP* img_talk,ALLEGRO_BITMAP* item_box,
					ALLEGRO_BITMAP* Ribbon,int ribbon_flag,
					ALLEGRO_BITMAP* door_key,int key_flag,
					ALLEGRO_BITMAP* Kinfe,int kinfe_flag)
{
	al_draw_bitmap(findscene_bg, 0, 0, 0);
	al_draw_bitmap(item_box,650,613,0);
	if (ribbon_flag==1) al_draw_bitmap(Ribbon,655,635,0);
	if (key_flag==1) al_draw_bitmap(door_key,750,635,0);
	if (kinfe_flag==1) al_draw_bitmap(Kinfe,850,635,0);
//	al_draw_bitmap(img_talk, 200, 300, 0);
}

void find_click_but(int btn, int x, int y,int mouse_x,int mouse_y,ALLEGRO_BITMAP* img_talk,const int SCREEN_W,const int SCREEN_H,ALLEGRO_FONT* font_pirulen_16)
{
		if (btn == 1)
		{
			
			if (pnt(mouse_x, mouse_y, 334, 294, 50,50 )||pnt(mouse_x, mouse_y, 367, 480, 50,50 )||pnt(mouse_x, mouse_y, 408, 463, 50,50 )) //flower//paperfile//bluebook
			{
				game_change_scene(SCENE_TALK);
			}
			if(pnt(mouse_x, mouse_y, 894, 288, 50,50  )||pnt(mouse_x, mouse_y, 656, 417, 50,50 )||pnt(mouse_x, mouse_y, 301, 514, 50,50 ))//candle
			{
				game_change_scene(SCENE_TALK);
			}
			if(pnt(mouse_x, mouse_y, 910, 421, 50,50  )) //bed
			{
				game_change_scene(SCENE_RIBBON);
			}		
			if(pnt(mouse_x, mouse_y, 574, 511, 50,50 )) //green book
			{
				game_change_scene(SCENE_KEY);
			}
			if(pnt(mouse_x, mouse_y, 204 , 589 , 50,50  )) 
			{
				game_change_scene(SCENE_KNIFE);
			}
				
		}
	
}

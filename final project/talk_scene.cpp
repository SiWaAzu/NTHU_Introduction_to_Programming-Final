#include "intro_scene.hpp"
#include "game_iniation.hpp"
#include "find_scene.hpp"
#include "talk_scene.hpp"
#include "log.hpp"
void draw_talk_scene(ALLEGRO_FONT* font_pirulen_16,ALLEGRO_FONT* font_pirulen_20,
const int SCREEN_W,const int SCREEN_H,ALLEGRO_BITMAP* talk_bg)
{
	al_draw_bitmap(talk_bg, 0, 0, 0);
    al_draw_text(font_pirulen_16, al_map_rgb(255, 255, 255), SCREEN_W-500, SCREEN_H - 50, 0, "Press enter key to get back");
	al_draw_text(font_pirulen_20, al_map_rgb(0, 0, 0), SCREEN_W/2-313, SCREEN_H/2-15,0, "seems like there is nothing special here");
	
	
}

void back_to_FIND(int keycode)
{
	if (keycode == ALLEGRO_KEY_ENTER)
	game_change_scene(SCENE_FIND);
} 

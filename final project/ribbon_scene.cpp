#include "intro_scene.hpp"
#include "game_iniation.hpp"
#include "find_scene.hpp"
#include "ribbon_scene.hpp"
#include "log.hpp"

void draw_ribbon_scene(ALLEGRO_FONT* font_pirulen_16,ALLEGRO_FONT* font_pirulen_20,
const int SCREEN_W,const int SCREEN_H,ALLEGRO_BITMAP* talk_bg)
{
	al_draw_bitmap(talk_bg, 0, 0, 0);
    al_draw_text(font_pirulen_16, al_map_rgb(255, 255, 255), SCREEN_W-500, SCREEN_H - 50, 0, "Press enter key to get back");
	al_draw_text(font_pirulen_20, al_map_rgb(0, 0, 0), SCREEN_W/2-350, SCREEN_H/2-30,0, "perhaps what you believe in are just fantsy");
	al_draw_text(font_pirulen_20, al_map_rgb(0, 0, 0), SCREEN_W/2-75, SCREEN_H/2-7,0, "perhaps......");
	
}

void ribbon_back_to_FIND(int keycode)
{
	change_flag (1);
	if (keycode == ALLEGRO_KEY_ENTER)
	game_change_scene(SCENE_FIND);
} 

#include "intro_scene.hpp"
#include "game_iniation.hpp"

void draw_intro_scene(ALLEGRO_FONT* font_pirulen_24,ALLEGRO_BITMAP* intro_bg,const int SCREEN_W,const int SCREEN_H)
{
	al_draw_bitmap(intro_bg, 0, 0, 0);
    al_draw_text(font_pirulen_24, al_map_rgb(0, 0, 0), SCREEN_W-600, SCREEN_H - 50, 0, "Press enter key to get back");
}

void back_to_MENU(int keycode)
{
	if (keycode == ALLEGRO_KEY_ENTER)
	game_change_scene(SCENE_MENU);
} 

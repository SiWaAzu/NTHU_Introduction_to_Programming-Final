#include "enemy.hpp"
#include "game_iniation.hpp"
void show_enemy(ALLEGRO_BITMAP* img_enemy,MovableObject enemy)
{
	enemy.img=img_enemy;
	
	enemy.y=450;
	draw_movable_object(enemy);
}

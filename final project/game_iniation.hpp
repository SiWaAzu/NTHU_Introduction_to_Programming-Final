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

// Frame rate (frame per second)
const int FPS = 60;
// Display (screen) width.
const int SCREEN_W =1024;
// Display (screen) height.
const int SCREEN_H =768;
// At most 4 audios can be played at a time.
const int RESERVE_SAMPLES = 6;
// Same as:
// const int SCENE_MENU = 1;
// const int SCENE_START = 2;
enum {
	SCENE_MENU = 1,
	SCENE_INTRO = 2
	// [HACKATHON 3-7]
	// TODO: Declare a new scene id.
	 , SCENE_SETTINGS = 3
	 , SCENE_LOSE = 4
	 , SCENE_WIN = 5
	 , SCENE_RUN = 6
	 , SCENE_FIND= 7
	 ,SCENE_TALK=8
	 ,SCENE_RIBBON=9
	 ,SCENE_KNIFE=10
	 ,SCENE_KEY=11
	 ,SCENE_END1=12
	 ,SCENE_END2=13
	 ,SCENE_END3=14
};

/* Input states */

// The active scene id.
int active_scene;
// Keyboard state, whether the key is down or not.
bool key_state[ALLEGRO_KEY_MAX];
// Mouse state, whether the key is down or not.
// 1 is for left, 2 is for right, 3 is for middle.
bool *mouse_state;
// Mouse position.
int mouse_x, mouse_y;
//item flag
int ribbon_flag;
int key_flag;
int kinfe_flag;

int hp_flag;
// TODO: More variables to store input states such as joysticks, ...

/* Variables for allegro basic routines. */

ALLEGRO_DISPLAY* game_display;
ALLEGRO_EVENT_QUEUE* game_event_queue;
ALLEGRO_TIMER* game_update_timer;

/* Shared resources*/

ALLEGRO_FONT* font_pirulen_32;
ALLEGRO_FONT* font_pirulen_24;
ALLEGRO_FONT* font_pirulen_20;
ALLEGRO_FONT* font_pirulen_16;
// TODO: More shared resources or data that needed to be accessed
// across different scenes.

/* Menu Scene resources*/
ALLEGRO_BITMAP* main_img_background;


/* Start Scene resources*/
ALLEGRO_BITMAP* img_block;
ALLEGRO_BITMAP* img_hp;
ALLEGRO_BITMAP* img_enemy;
ALLEGRO_BITMAP* startscene_bg;
ALLEGRO_BITMAP* runscene_bg;
ALLEGRO_SAMPLE* main_bgm;
ALLEGRO_SAMPLE_ID main_bgm_id;
ALLEGRO_SAMPLE* start_bgm;
ALLEGRO_SAMPLE_ID start_bgm_id;
ALLEGRO_SAMPLE* find_bgm;
ALLEGRO_SAMPLE_ID find_bgm_id;
ALLEGRO_SAMPLE* end_bgm;
ALLEGRO_SAMPLE_ID end_bgm_id;
ALLEGRO_SAMPLE* runscene_bgm;
ALLEGRO_SAMPLE_ID runscene_bgm_id;
ALLEGRO_SAMPLE* talk_bgm;
ALLEGRO_SAMPLE_ID talk_bgm_id;
ALLEGRO_SAMPLE* lose_bgm;
ALLEGRO_SAMPLE_ID lose_bgm_id;
ALLEGRO_SAMPLE* intro_bgm;
ALLEGRO_SAMPLE_ID intro_bgm_id;
ALLEGRO_SAMPLE* hurt_se;
ALLEGRO_SAMPLE_ID hurt_se_id;
ALLEGRO_SAMPLE* laugh_se;
ALLEGRO_SAMPLE_ID laugh_se_id;

ALLEGRO_BITMAP* img_win;
ALLEGRO_BITMAP* img_char1;
ALLEGRO_BITMAP* img_char2;
ALLEGRO_BITMAP* img_window;
ALLEGRO_BITMAP* intro_bg;
ALLEGRO_BITMAP* findscene_bg;
ALLEGRO_BITMAP* talk_bg;
ALLEGRO_BITMAP* img_talk;
ALLEGRO_BITMAP* item_box;

ALLEGRO_BITMAP* Ribbon;
ALLEGRO_BITMAP* door_key;
ALLEGRO_BITMAP* Kinfe;

ALLEGRO_BITMAP* img_paperpile;
ALLEGRO_BITMAP* img_book1;
ALLEGRO_BITMAP* img_book2;

ALLEGRO_BITMAP* END1_pic;
ALLEGRO_BITMAP* END2_pic;
ALLEGRO_BITMAP* END3_pic;
ALLEGRO_BITMAP* lose_bg;
typedef struct {
	//?The center coordinate of the image.
	float x, y;
	//?The width and height of the object.
	float w, h;
	//?The velocity in x, y axes.
	float vx, vy;
	//?Should we draw this object on the screen.
	bool hidden;
	//?The pointer to the object? image.
	ALLEGRO_BITMAP* img;
} MovableObject;

void draw_movable_object(MovableObject obj);

MovableObject char1;
MovableObject enemy;
MovableObject block;

// Initialize allegro5 library
void allegro5_init(void);
// Initialize variables and resources.
// Allows the game to perform any initialization it needs before
// starting to run.
void game_init(void);
// Process events inside the event queue using an infinity loop.
void game_start_event_loop(void);
// Run game logic such as updating the world, checking for collision,
// switching scenes and so on.
// This is called when the game should update its logic.
void game_update(void);
// Draw to display.
// This is called when the game should draw itself.
void game_draw(void);
// Release resources.
// Free the pointers we allocated.
void game_destroy(void);
// Function to change from one scene to another.
void game_change_scene(int next_scene);
// Load resized bitmap and check if failed.
ALLEGRO_BITMAP *load_bitmap_resized(const char *filename, int w, int h);
// [HACKATHON 3-2]
// TODO: Declare a function.
// Determines whether the point (px, py) is in rect (x, y, w, h).
// Uncomment the code below.
bool pnt_in_rect(int px, int py, int x, int y, int w, int h);
bool pnt(int px, int py, int x, int y, int w, int h);

/* Event callbacks. */
void on_key_down(int keycode);
void on_mouse_down(int btn, int x, int y);

void change_flag (int item);
void pass_to_stopper (MovableObject char1);
void pass_to_char (MovableObject char1);

#include "game_iniation.hpp"
#include "start_scene.hpp"
#include "intro_scene.hpp"
#include "run_scene.hpp"
#include "log.hpp"
#include "start_scene.hpp"
#include "find_scene.hpp"
#include "talk_scene.hpp"
#include "ribbon_scene.hpp"
#include "knife_scene.hpp"
#include "key_scene.hpp"
#include "END1.hpp"
#include "END2.hpp"
#include "END3.hpp"
#include "lose_scene.hpp"
void allegro5_init(void) {
	if (!al_init())
		game_abort("failed to initialize allegro");

	// Initialize add-ons.
	if (!al_init_primitives_addon())
		game_abort("failed to initialize primitives add-on");
	al_init_font_addon();
	if (!al_init_ttf_addon())
		game_abort("failed to initialize ttf add-on");
	if (!al_init_image_addon())
		game_abort("failed to initialize image add-on");
	if (!al_install_audio())
		game_abort("failed to initialize audio add-on");
	if (!al_init_acodec_addon())
		game_abort("failed to initialize audio codec add-on");
	if (!al_reserve_samples(RESERVE_SAMPLES))
		game_abort("failed to reserve samples");
	if (!al_install_keyboard())
		game_abort("failed to install keyboard");
	if (!al_install_mouse())
		game_abort("failed to install mouse");
	// TODO: Initialize other addons such as video, ...

	// Setup game display.
	game_display = al_create_display(SCREEN_W, SCREEN_H);
	if (!game_display)
		game_abort("failed to create display");
	al_set_window_title(game_display, "Where have you been?");

	// Setup update timer.
	game_update_timer = al_create_timer(1.0f / FPS);
	if (!game_update_timer)
		game_abort("failed to create timer");

	// Setup event queue.
	game_event_queue = al_create_event_queue();
	if (!game_event_queue)
		game_abort("failed to create event queue");

	// Malloc mouse buttons state according to button counts.
	const unsigned m_buttons = al_get_mouse_num_buttons();
	game_log("There are total %u supported mouse buttons", m_buttons);
	// mouse_state[0] will not be used.
	mouse_state = (bool*)malloc((m_buttons + 1) * sizeof(bool));
	memset(mouse_state, false, (m_buttons + 1) * sizeof(bool));

	// Register display, timer, keyboard, mouse events to the event queue.
	al_register_event_source(game_event_queue, al_get_display_event_source(game_display));
	al_register_event_source(game_event_queue, al_get_timer_event_source(game_update_timer));
	al_register_event_source(game_event_queue, al_get_keyboard_event_source());
	al_register_event_source(game_event_queue, al_get_mouse_event_source());
	// TODO: Register other event sources such as timer, video, ...

	// Start the timer to update and draw the game.
	al_start_timer(game_update_timer);
}

void game_init(void) {
	/* Shared resources*/
	font_pirulen_32 = al_load_font("pirulen.ttf", 32, 0);
	if (!font_pirulen_32)
		game_abort("failed to load font: pirulen.ttf with size 32");

	font_pirulen_24 = al_load_font("pirulen.ttf", 24, 0);
	if (!font_pirulen_24)
		game_abort("failed to load font: pirulen.ttf with size 24");

    font_pirulen_16 = al_load_font("pirulen.ttf", 16, 0);
	if (!font_pirulen_16)
		game_abort("failed to load font: pirulen.ttf with size 16");
		
	font_pirulen_20 = al_load_font("pirulen.ttf", 20, 0);
	if (!font_pirulen_20)
		game_abort("failed to load font: pirulen.ttf with size 20");



	/* Start Scene resources*/
	 main_bgm = al_load_sample("startscene.ogg");
	if (!main_bgm)
		game_abort("failed to load audio: startscene.ogg");


    runscene_bgm = al_load_sample("runscene.ogg");
	if (!runscene_bgm)
		game_abort("failed to load audio: runscene.ogg");

    find_bgm=al_load_sample("find.ogg");
	if (!find_bgm)
		game_abort("failed to load audio: find.ogg");
		
	laugh_se=al_load_sample("laugh.ogg");
	if (!laugh_se)
		game_abort("failed to load audio: laugh.ogg");
	hurt_se=al_load_sample("yamete.ogg");
	if (!hurt_se)
		game_abort("failed to load audio: yamete.ogg");	
		
	lose_bgm=al_load_sample("lose.ogg");
	if (!lose_bgm)
		game_abort("failed to load audio: lose.ogg");
		
	end_bgm	=al_load_sample("end.ogg");
	if (!end_bgm)
		game_abort("failed to load audio: end.ogg");
		
	talk_bgm=al_load_sample("paper.ogg");
	if (!talk_bgm)
		game_abort("failed to load audio: paper.ogg");
	
	intro_bgm=al_load_sample("notice.ogg");
	if (!intro_bgm)
		game_abort("failed to load audio: notice.ogg");


	// Change to first scene.
	game_change_scene(SCENE_MENU);
	img_window = load_bitmap_resized("window.png", 120, 120);
	if (!img_window)
		game_abort("failed to load image: window.png");

    startscene_bg = load_bitmap_resized("startscene.png", SCREEN_W, SCREEN_H);
	if (!startscene_bg)
		game_abort("failed to load image: startscene.png");

    runscene_bg = load_bitmap_resized("runscene.png", SCREEN_W, SCREEN_H);
	if (!runscene_bg)
		game_abort("failed to load image: runscene.png");

    img_char1=load_bitmap_resized("char1.png", 60, 80);
	if (!img_char1)
		game_abort("failed to load image: char1.png");

    img_char2=load_bitmap_resized("char2.png", 60, 80);
	if (!img_char2)
		game_abort("failed to load image: char2.png");

    intro_bg=load_bitmap_resized("tutorial.png", SCREEN_W, SCREEN_H);
	if (!intro_bg)
		game_abort("failed to load image: tutorial.png");
		
	findscene_bg=load_bitmap_resized("background2.png", SCREEN_W, SCREEN_H);
	if (!findscene_bg)
		game_abort("failed to load image: background2.png");
		
	img_talk=al_load_bitmap("talk.png");
	if (!img_talk)
		game_abort("failed to load image: talk.png");
		
talk_bg=al_load_bitmap("talk_bg.png");
	if (!talk_bg)
		game_abort("failed to load image: talk_bg.png");
		
	item_box=al_load_bitmap("item_place.png");
	if (!item_box)
		game_abort("failed to load image: item_place.png");
		
	Ribbon=al_load_bitmap("bow2.png");
	if (!Ribbon)
		game_abort("failed to load image: bow2.png");
		
	door_key=al_load_bitmap("key.png");
	if (!door_key)
		game_abort("failed to load image: key.png");
	
	Kinfe=al_load_bitmap("Sprite-0005.png");
	if (!Kinfe)
		game_abort("failed to load image: Sprite-0005.png");
	
	img_paperpile=al_load_bitmap("paperpile.png");
	if (!img_paperpile)
		game_abort("failed to load image: paperpile.png");
	
	img_book1=al_load_bitmap("book1.png");
	if (!img_book1)
		game_abort("failed to load image: book1.png");
	
	img_book2=al_load_bitmap("book2.png");
	if (!img_book2)
		game_abort("failed to load image: book2.png");
		
	img_enemy=al_load_bitmap("enemy.png");
	if (!img_enemy)
		game_abort("failed to load image: enemy.png");	
		
	END1_pic=al_load_bitmap("end1.png");
	if (!END1_pic)
		game_abort("failed to load image: end1.png");
		
	END2_pic=al_load_bitmap("end2.png");
	if (!END2_pic)
		game_abort("failed to load image: end2.png");	
		
  	END3_pic=al_load_bitmap("end3.png");
	if (!END3_pic)
		game_abort("failed to load image: END3.png");
	
	img_hp=al_load_bitmap("hp.png");
	if (!img_hp)
		game_abort("failed to load image: hp.png");
	
	img_block=al_load_bitmap("black.png");
	if (!img_block)
		game_abort("failed to load image: black.png");
	
	lose_bg=al_load_bitmap("lose.png");
	if (!lose_bg)
		game_abort("failed to load image: lose.png");
}

void game_start_event_loop(void) {
	bool done = false;
	ALLEGRO_EVENT event;
	int redraws = 0;
	while (!done) {
		al_wait_for_event(game_event_queue, &event);
		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			// Event for clicking the window close button.
			game_log("Window close button clicked");
			done = true;
		} else if (event.type == ALLEGRO_EVENT_TIMER) {
			// Event for redrawing the display.
			if (event.timer.source == game_update_timer)
				// The redraw timer has ticked.
				redraws++;
		} else if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
			// Event for keyboard key down.
			game_log("Key with keycode %d down", event.keyboard.keycode);
			key_state[event.keyboard.keycode] = true;
			on_key_down(event.keyboard.keycode);
		} else if (event.type == ALLEGRO_EVENT_KEY_UP) {
			// Event for keyboard key up.
			game_log("Key with keycode %d up", event.keyboard.keycode);
			key_state[event.keyboard.keycode] = false;
		} else if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			// Event for mouse key down.
			game_log("Mouse button %d down at (%d, %d)", event.mouse.button, event.mouse.x, event.mouse.y);
			mouse_state[event.mouse.button] = true;
			on_mouse_down(event.mouse.button, event.mouse.x, event.mouse.y);
		} else if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			// Event for mouse key up.
			game_log("Mouse button %d up at (%d, %d)", event.mouse.button, event.mouse.x, event.mouse.y);
			mouse_state[event.mouse.button] = false;
		} else if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
			if (event.mouse.dx != 0 || event.mouse.dy != 0) {
				// Event for mouse move.
				game_log("Mouse move to (%d, %d)", event.mouse.x, event.mouse.y);
				mouse_x = event.mouse.x;
				mouse_y = event.mouse.y;
			} else if (event.mouse.dz != 0) {
				// Event for mouse scroll.
				game_log("Mouse scroll at (%d, %d) with delta %d", event.mouse.x, event.mouse.y, event.mouse.dz);
			}
		}
		// TODO: Process more events and call callbacks by adding more
		// entries inside Scene.

		// Redraw
		if (redraws > 0 && al_is_event_queue_empty(game_event_queue)) {
			if (redraws > 1)
				game_log("%d frame(s) dropped", redraws - 1);
			// Update and draw the next frame.
			game_update();
			game_draw();
			redraws = 0;
		}
	}
}

void game_update(void) {


	if (active_scene == SCENE_RUN) {
        //character
		float gravity =2;
		
        char1.vx = char1.vy = 0;
        enemy.vx =1;
        if(enemy.x<SCREEN_W/2-100)  enemy.vy =-0.15;
        if(enemy.x>SCREEN_W/2-100) enemy.vy =0.3;
        if(enemy.x>SCREEN_W) 
        {
        	enemy.x=-150;
        	enemy.y=450;
		}
		if ((key_state[ALLEGRO_KEY_SPACE]|| key_state[ALLEGRO_KEY_UP])&&char1.y==515 )
		{
			char1.vy -= 35;
		}

		if (key_state[ALLEGRO_KEY_LEFT] )
        {
            char1.img=img_char2;
            char1.vx -= 2;
        }
		if (key_state[ALLEGRO_KEY_RIGHT] )
        {
            char1.img=img_char1;
            char1.vx += 2;
        }
        if(char1.y+char1.h/2 < 515)
            char1.vy+=gravity;
		// 0.71 is (1/sqrt(2)).
		char1.y += char1.vy * 4 * (char1.vx ? 0.71f : 1);
		char1.x += char1.vx * 4 * (char1.vy ? 0.71f : 1);
		enemy.x += enemy.vx * 4 * (enemy.vy ? 0.71f : 1);
		enemy.y += enemy.vy * 4 * (enemy.vx ? 0.71f : 1);
		
		if (char1.x-char1.w/2 < 0)
			char1.x = char1.w/2;
		if (char1.x+char1.w/2 > SCREEN_W)
            game_change_scene(SCENE_FIND);
        if (char1.y+char1.h/2 > 515)
            char1.y = 515;
        if (char1.y+char1.h/2 <139)
            char1.y = 515;
            
        if(char1.y==515&&char1.x>=135&&char1.x<=210){
			if(char1.img==img_char1) char1.x=135;
			if(char1.img==img_char2) char1.x=210;
			char1.vx=0;
		 } 
		if(char1.y==515&&char1.x>=350&&char1.x<=405){
			if(char1.img==img_char1) char1.x=350;
			if(char1.img==img_char2) char1.x=405;
			char1.vx=0;
		 }
		 if(char1.y==515&&char1.x>=570&&char1.x<=630){
			if(char1.img==img_char1) char1.x=570;
			if(char1.img==img_char2) char1.x=630;
			char1.vx=0;
		 }
		 if(char1.y==515&&char1.x>=825&&char1.x<=875){
			if(char1.img==img_char1) char1.x=825;
			if(char1.img==img_char2) char1.x=875;
			char1.vx=0;
		 } 
		 
		 if(char1.x>=enemy.x+30&&char1.x<=enemy.x+33) 
		 {
		 	hp_flag--;
		 	al_play_sample(hurt_se, 1.2, 0.0, 1.1, ALLEGRO_PLAYMODE_ONCE, &hurt_se_id);
		 	
		 }
		 if(hp_flag==2)block.x=160;
		if(hp_flag==1)block.x=90;
		 if(hp_flag==0) game_change_scene(SCENE_LOSE);
	}
	else if(active_scene==SCENE_FIND) {
        //character
        
        char1.vx = char1.vy = 0;

		if (key_state[ALLEGRO_KEY_LEFT] )
        {
            char1.img=img_char2;
            char1.vx -= 2;
        }
		if (key_state[ALLEGRO_KEY_RIGHT] )
        {
            char1.img=img_char1;
            char1.vx += 2;
            
        }
        if(char1.y+char1.h/2 < 515)
           // char1.vy+=gravity;
		// 0.71 is (1/sqrt(2)).
		char1.y += char1.vy * 4 * (char1.vx ? 0.71f : 1);
		char1.x += char1.vx * 4 * (char1.vy ? 0.71f : 1);

		if (char1.x-char1.w/2 < 0)
			game_change_scene(SCENE_RUN);
			
		if (char1.x+char1.w/2 > SCREEN_W)
            {
            	if (key_flag==1 && ribbon_flag!=1 && kinfe_flag!=1) game_change_scene(SCENE_END1);
            	else if (key_flag==1 && ribbon_flag!=1 && kinfe_flag==1) game_change_scene(SCENE_END2);
            	else if (key_flag==1 && ribbon_flag==1) game_change_scene(SCENE_END3);
			}
        if (char1.y+char1.h/2 > 515)
            char1.y = 515;
        if (char1.y+char1.h/2 <139)
            char1.y = 515;
            
	}
	
	


}


void game_draw(void) {


	if (active_scene == SCENE_MENU)
    {
      draw_start_scene(startscene_bg ,SCREEN_H,SCREEN_W,font_pirulen_16);
    }
    else if (active_scene == SCENE_INTRO)
    {
        draw_intro_scene(font_pirulen_24,intro_bg,SCREEN_W,SCREEN_H);
    }


	// [HACKATHON 3-9]
	// TODO: If active_scene is SCENE_SETTINGS.
	// Draw anything you want, or simply clear the display.
	else if (active_scene == SCENE_SETTINGS) {
		al_clear_to_color(al_map_rgb(0, 0, 0));

		al_draw_text(font_pirulen_24, al_map_rgb(255, 255, 255), 20, SCREEN_H - 50, 0, "Press enter key to get back");
	}

    else if(active_scene == SCENE_RUN)
    {
        //background setting
		draw_run_scene(runscene_bg,font_pirulen_24,SCREEN_W,SCREEN_H,img_window,item_box,img_book1,
		img_book2,img_paperpile,img_hp);
        //character
        draw_movable_object(char1);
        draw_movable_object(enemy);
		draw_movable_object(block);
    }

    else if (active_scene == SCENE_FIND)
    {
        draw_find_scene(findscene_bg,  SCREEN_W,  SCREEN_H,img_talk,item_box,
						Ribbon,ribbon_flag,
						door_key,key_flag,
						Kinfe,kinfe_flag);
        draw_movable_object(char1);
    }
    
    else if (active_scene == SCENE_TALK)
    {
  	  draw_talk_scene(font_pirulen_16, font_pirulen_20, SCREEN_W,  SCREEN_H,talk_bg);
    }
    
    else if (active_scene == SCENE_RIBBON)
    {
  	  draw_ribbon_scene(font_pirulen_16, font_pirulen_20, SCREEN_W,  SCREEN_H,talk_bg);
    }
    else if (active_scene == SCENE_KNIFE)
    {
  	  draw_knife_scene(font_pirulen_16, font_pirulen_20, SCREEN_W,  SCREEN_H,talk_bg);
    }
    else if (active_scene == SCENE_KEY)
    {
  	  draw_key_scene(font_pirulen_16, font_pirulen_20, SCREEN_W,  SCREEN_H,talk_bg);
    }
    
    else if (active_scene==SCENE_END1)
    {
    	draw_end1_scene(END1_pic,SCREEN_H,SCREEN_W,font_pirulen_16);
	}
	
	else if (active_scene == SCENE_END2)
	{
		draw_end2_scene(END2_pic,SCREEN_H,SCREEN_W,font_pirulen_16);
	}
	
	else if (active_scene == SCENE_END3)
	{
		draw_end3_scene(END3_pic,SCREEN_H,SCREEN_W,font_pirulen_16);
	}
	else if (active_scene == SCENE_LOSE)
	{
		draw_lose_scene(lose_bg,SCREEN_H,SCREEN_W,font_pirulen_16);
	}
	
	
	al_flip_display();
}

void game_destroy(void) {
	// Destroy everything you have created.
	// Free the memories allocated by malloc or allegro functions.
	// Destroy shared resources.
	al_destroy_font(font_pirulen_32);
	al_destroy_font(font_pirulen_24);

	/* Menu Scene resources*/
	al_destroy_bitmap(main_img_background);
	al_destroy_sample(main_bgm);
	al_destroy_sample(start_bgm);
	al_destroy_timer(game_update_timer);
	al_destroy_event_queue(game_event_queue);
	al_destroy_display(game_display);
	free(mouse_state);
}

void game_change_scene(int next_scene) {
	game_log("Change scene from %d to %d", active_scene, next_scene);
	// TODO: Destroy resources initialized when creating scene.
	if (active_scene == SCENE_MENU) {
		al_stop_sample(&main_bgm_id);
		game_log("stop audio (bgm)");
	}
	else if (active_scene == SCENE_RUN) {
        al_stop_sample(&runscene_bgm_id);
		game_log("stop audio (bgm)");
	}
	else if (active_scene == SCENE_FIND) {
        al_stop_sample(&find_bgm_id);
		game_log("stop audio (bgm)");
	}
	else if (active_scene == SCENE_RIBBON||active_scene == SCENE_KNIFE||active_scene == SCENE_KEY) {
        al_stop_sample(&laugh_se_id);
		game_log("stop audio (bgm)");
	}
	else if (active_scene == SCENE_TALK) {
        al_stop_sample(&talk_bgm_id);
		game_log("stop audio (bgm)");
	}
	else if (active_scene == SCENE_LOSE) {
        al_stop_sample(&lose_bgm_id);
		game_log("stop audio (bgm)");
	}
	else if (active_scene == SCENE_END1||active_scene == SCENE_END2||active_scene == SCENE_END3) {
        al_stop_sample(&end_bgm_id);
		game_log("stop audio (bgm)");
	}
	else if (active_scene == SCENE_INTRO) {
        al_stop_sample(&intro_bgm_id);
		game_log("stop audio (bgm)");
	}
	

	active_scene = next_scene;
	// TODO: Allocate resources before entering scene.
	if (active_scene == SCENE_MENU) {
		if (!al_play_sample(main_bgm, 1, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, &main_bgm_id))
			game_abort("failed to play audio (bgm)");
			hp_flag=3;
	}
	if(active_scene == SCENE_RUN)
    {
        if (!al_play_sample(runscene_bgm, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, &runscene_bgm_id))
			game_abort("failed to play audio (bgm)");
        char1.img=img_char1;
        char1.x=0;
        char1.y=515;
        enemy.img=img_enemy;
        enemy.x=-300;
        enemy.y=450;
        
        block.img=img_block;
        block.x=500;block.y=50;
    }
    if(active_scene == SCENE_FIND)
    {
        if (!al_play_sample(find_bgm, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, &find_bgm_id))
			game_abort("failed to play audio (bgm)");
        char1.img=img_char1;
        char1.x=0;
        char1.y=515;
		 
    }
    
    if(active_scene == SCENE_RIBBON)
    {
       if (!al_play_sample(laugh_se, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, &laugh_se_id))
			game_abort("failed to play audio (bgm)");
		 
    }
     if(active_scene == SCENE_KNIFE)
    {
       if (!al_play_sample(laugh_se, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, &laugh_se_id))
			game_abort("failed to play audio (bgm)");
		 
    }
     if(active_scene == SCENE_KEY)
    {
       if (!al_play_sample(laugh_se, 1.5, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, &laugh_se_id))
			game_abort("failed to play audio (bgm)");
		 
    }
	if(active_scene == SCENE_LOSE)
    {
       if (!al_play_sample(lose_bgm, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, &lose_bgm_id))
			game_abort("failed to play audio (bgm)");
		 
    }
    if(active_scene  == SCENE_END1||active_scene == SCENE_END2||active_scene == SCENE_END3)
    {
       if (!al_play_sample(end_bgm, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, &end_bgm_id))
			game_abort("failed to play audio (bgm)");
		 
    }
    if(active_scene == SCENE_TALK)
    {
       if (!al_play_sample(talk_bgm, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, &talk_bgm_id))
			game_abort("failed to play audio (bgm)");
		 
    }
    if(active_scene == SCENE_INTRO)
    {
       if (!al_play_sample(intro_bgm, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, &intro_bgm_id))
			game_abort("failed to play audio (bgm)");
		 
    }
		

}

void change_flag (int item)
{
	if (item==1)	ribbon_flag=1;
	else if (item==2)	key_flag=1;
	else if (item==3)	kinfe_flag=1;
	else if (item==4)
	{
		ribbon_flag=0;
		key_flag=0;
		kinfe_flag=0;
	}
}

void on_key_down(int keycode)
{
	if (active_scene == SCENE_SETTINGS)
    {
		if (keycode == ALLEGRO_KEY_ENTER)
			game_change_scene(SCENE_MENU);
	}
	if (active_scene == SCENE_INTRO)
	{
        back_to_MENU(keycode);
	}
	if (active_scene == SCENE_TALK)
	{
        if (keycode == ALLEGRO_KEY_ENTER)
		{
			back_to_FIND(keycode);
		}
	}
	if (active_scene == SCENE_RIBBON)
	{
        if (keycode == ALLEGRO_KEY_ENTER)
		{
			ribbon_back_to_FIND(keycode);
		}
	}
	if (active_scene == SCENE_KEY)
	{
        if (keycode == ALLEGRO_KEY_ENTER)
		{
			key_back_to_FIND(keycode);
		}
	}
	if (active_scene == SCENE_KNIFE)
	{
        if (keycode == ALLEGRO_KEY_ENTER)
		{
			knife_back_to_FIND(keycode);
		}
	}
	

}

void on_mouse_down(int btn, int x, int y) {
	// [HACKATHON 3-8]
	// TODO: When settings clicked, switch to settings scene.
	// Uncomment and fill in the code below.
	if (active_scene == SCENE_MENU)
    {
		MENU_click_but(btn,x,y,mouse_x,mouse_y);
	}
	
	else if (active_scene == SCENE_FIND)
    {
    	find_click_but( btn,  x,  y, mouse_x, mouse_y,img_talk,  SCREEN_W,  SCREEN_H,font_pirulen_16);
	}
	
	else if (active_scene==SCENE_END1)
	{
		END1_click_but(btn, x,y,mouse_x,mouse_y);
	}
	
	else if (active_scene==SCENE_END2)
	{
		END2_click_but(btn, x,y,mouse_x,mouse_y);
	}
	
	else if (active_scene==SCENE_END3)
	{
		END3_click_but(btn, x,y,mouse_x,mouse_y);
	}
	else if (active_scene==SCENE_LOSE)
	{
		lose_click_but(btn, x,y,mouse_x,mouse_y);
	}
}

void draw_movable_object(MovableObject obj) {
	if (obj.hidden)
		return;
	al_draw_bitmap(obj.img, round(obj.x - obj.w / 2), round(obj.y - obj.h / 2), 0);
}

ALLEGRO_BITMAP *load_bitmap_resized(const char *filename, int w, int h) {
	ALLEGRO_BITMAP* loaded_bmp = al_load_bitmap(filename);
	if (!loaded_bmp)
		game_abort("failed to load image: %s", filename);
	ALLEGRO_BITMAP *resized_bmp = al_create_bitmap(w, h);
	ALLEGRO_BITMAP *prev_target = al_get_target_bitmap();

	if (!resized_bmp)
		game_abort("failed to create bitmap when creating resized image: %s", filename);
	al_set_target_bitmap(resized_bmp);
	al_draw_scaled_bitmap(loaded_bmp, 0, 0,
		al_get_bitmap_width(loaded_bmp),
		al_get_bitmap_height(loaded_bmp),
		0, 0, w, h, 0);
	al_set_target_bitmap(prev_target);
	al_destroy_bitmap(loaded_bmp);

	game_log("resized image: %s", filename);

	return resized_bmp;
}


bool pnt(int px, int py, int x, int y, int w, int h) {
    if(px<=x+w&&px>=x&&py<=y+h&&py>=y)
        return true;
	else
        return false;
}


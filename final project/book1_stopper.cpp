

void pass_to_stopper (MovableObject char1)
{
	player_x=char1.x;
	player_y=char1.y;
	player_vx=char1.vx;
	player_vy=char1.vy;
}

void stops()
{
	if(player_x==x-w)
	{
		player_x=x-w;
		player_vx=0;
		pass_to_char (char1);
	}   
}
void pass_to_char (MovableObject char1)
{
	char1.x=player_x;
	char1.y=player_y;
	char1.vx=player_vx;
	char1.vy=player_vy;
}


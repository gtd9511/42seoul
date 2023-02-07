
#include "cub3d.h"

void raycasting(t_game *game)
{
	double posX = 22, posY = 12;
	double dirX = -1, dirY = 0;
	double planeX = 0, planeY = 0.66;

	double time = 0;
	double oldTime = 0;

	while(1)
	{
		 for(int x = 0; x < 1920; x++)
		{
			//calculate ray position and direction
			double cameraX = 2 * x / 1920 - 1; //x-coordinate in camera space
			double rayDirX = dirX + planeX * cameraX;
			double rayDirY = dirY + planeY * cameraX;

			int mapX = (int)game->player.x;
			int mapY = (int)game->player.y;

			//length of ray from current position to next x or y-side
			double sideDistX;
			double sideDistY;

			//length of ray from one x or y-side to next x or y-side
			double deltaDistX = fabs(1 / rayDirX);
			double deltaDistY = fabs(1 / rayDirY);
			double perpWallDist;

			//what direction to step in x or y-direction (either +1 or -1)
			int stepX;
			int stepY;

			int hit = 0; //was there a wall hit?
			int side; //was a NS or a EW wall hit?

	//calculate step and initial sideDist
			if (rayDirX < 0)
			{
				stepX = -1;
				sideDistX = (posX - mapX) * deltaDistX;
			}
			else
			{
				stepX = 1;
				sideDistX = (mapX + 1.0 - posX) * deltaDistX;
			}
			if (rayDirY < 0)
			{
				stepY = -1;
				sideDistY = (posY - mapY) * deltaDistY;
			}
			else
			{
				stepY = 1;
				sideDistY = (mapY + 1.0 - posY) * deltaDistY;
			}
			while (hit == 0)
			{
				//jump to next map square, OR in x-direction, OR in y-direction
				if (sideDistX < sideDistY)
				{
					sideDistX += deltaDistX;
					mapX += stepX;
					side = 0;
				}
				else
				{
				sideDistY += deltaDistY;
					mapY += stepY;
					side = 1;
					}
				//Check if ray has hit a wall
				if (game->map[mapX][mapY] > 0)
					hit = 1;
			}
			//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
			if (side == 0)
				perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
			else
				perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;

			int lineHeight = (int)(1080 / perpWallDist);

			//calculate lowest and highest pixel to fill in current stripe
			int drawStart = -lineHeight / 2 + 1080 / 2;
			if(drawStart < 0)drawStart = 0;
			int drawEnd = lineHeight / 2 + 1080 / 2;
			if(drawEnd >= 1080)drawEnd = 1080 - 1;

			t_rgb color;
			switch(game->map[mapX][mapY])
			{
				case 1:  color.r = 255, color.g =  0, color.b = 0;  break; //red
				case 2:  color.r = 0, color.g =  255, color.b = 0;  break; //green
				case 3:  color.r = 0, color.g =  0, color.b = 255;   break; //blue
				case 4:  color.r = 255, color.g =  255, color.b = 255;  break; //white
				default: color.r = 0, color.g =  255, color.b = 255; break; //yellow
			}
			//give x and y sides different brightness
			if (side == 1)
			{
				color.r = color.r / 2;
				color.b = color.b / 2;
				color.g = color.g / 2;
			}
			//draw the pixels of the stripe as a vertical line
			//verLine(x, drawStart, drawEnd, color); 수직선
		}
	oldTime = time;
//	time = getTicks();
//	double frameTime = (time - oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds
//	print(1.0 / frameTime); //FPS counter
//	redraw();
//	cls();

	//speed modifiers
//	double moveSpeed = frameTime * 5.0; //the constant value is in squares/second
//	double rotSpeed = frameTime * 3.0; //the constant value is in radians/second
//	readKeys();

/*
	//move forward if no wall in front of you


	if (keyDown(KEY_W))
	{
		if(game->map[(int)(posX + dirX * moveSpeed)][(int)posY] == false) posX += dirX * moveSpeed;
		if(game->map[(int)(posX)][(int)(posY + dirY * moveSpeed)] == false) posY += dirY * moveSpeed;
	}
	//move backwards if no wall behind you
	if (keyDown(KEY_S))
	{
		if(game->map[(int)(posX - dirX * moveSpeed)][(int)(posY)] == false) posX -= dirX * moveSpeed;
		if(game->map[(int)(posX)][(int)(posY - dirY * moveSpeed)] == false) posY -= dirY * moveSpeed;
	}

	//rotate to the right
	if (keyDown(SDLK_RIGHT))
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = dirX;
		dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
		dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
		double oldPlaneX = planeX;
		planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
		planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
	}
	//rotate to the left
	if (keyDown(SDLK_LEFT))
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = dirX;
		dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
		dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
		double oldPlaneX = planeX;
		planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
		planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
	}
	*/
	}
}


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int		WEIGHT;
int		HEIGHT;
char	BG;
char	**TAB;

typedef struct draw {
	char	r;
	float	x1;
	float	y1;
	float	x2;
	float	y2;
	float	w;
	float	h;
	char	c;
}Draw;

int	is_in_rect(int x, int y, Draw el)
{
	if ((x - el.x1 < 1.0f) || (el.x2 - x < 1.0f) ||
		(y - el.y1 < 1.0f) || (el.y2 - y < 1.0f))
		return (1);
	return (0);
}

int	err_msg(FILE *fd, int err)
{
	if (err == 2 && (err = 1))
		write(1, "Error: Operation file corrupted\n", 32);
	else if (err == 1)
		write(1, "Error: argument\n", 16);
	else
	{
		for (int i = 0; i < HEIGHT; i++) {
			write(1, TAB[i], WEIGHT);
			write(1, "\n", 1);
		}
	}
	if (fd)
		fclose(fd);
	if (TAB)
	{
		for (int i = 0; i < HEIGHT; i++) {
			free(TAB[i]);
		}
		free(TAB);
	}
	return (err);
}

int	main(int ac, char **av)
{
	FILE	*fd;
	int		res;
	Draw	el;

	fd = NULL;
	if (ac != 2)
		return (err_msg(fd, 1));
	if ((fd = fopen(av[1], "r")))
	{
		if ((res = fscanf(fd, "%d %d %c", &WEIGHT, &HEIGHT, &BG)) == 3)
		{
			if (WEIGHT > 0 && WEIGHT <= 300 && HEIGHT > 0 && HEIGHT <= 300)
			{
				TAB = malloc(HEIGHT * sizeof(char *));
				for (int i = 0; i < HEIGHT; i++) {
					TAB[i] = malloc(WEIGHT * sizeof(char));
					memset(TAB[i], BG, WEIGHT);
				}
				while (1)
				{
					res = fscanf(fd, "\n%c %f %f %f %f %c", &el.r, &el.x1, &el.y1, &el.w, &el.h, &el.c);
					if (res == EOF)
						return (err_msg(fd, 0));
					else if (res != 6 || el.w <= 0 || el.h <= 0 || (el.r != 'r' && el.r != 'R'))
						break ;
					el.x2 = el.x1 + el.w;
					el.y2 = el.y1 + el.h;
					for (int line = 0; line < HEIGHT; line++) {
						for (int col = 0; col < WEIGHT; col++) {
							if (line >= el.y1 && el.y2 >= line && col >= el.x1 && el.x2 >= col)
							{
								if ((el.r == 'R') || (el.r == 'r' && is_in_rect(col, line, el)))
									TAB[line][col] = el.c;
							}
						}
					}
				}
			}
		}
	}
	return (err_msg(fd, 2));
}

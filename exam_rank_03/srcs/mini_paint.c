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
	char	t;
	float	x;
	float	y;
	float	r;
	char	c;
}Draw;

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
		for (int j = 0; j < HEIGHT; j++) {
			free(TAB[j]);
		}
		free(TAB);
	}
	return (err);
}

int	main(int ac, char **av)
{
	FILE	*fd;
	float	sqr;
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
					res = fscanf(fd, "\n%c %f %f %f %c", &el.t, &el.x, &el.y, &el.r, &el.c);
					if (res == EOF)
						return (err_msg(fd, 0));
					else if (res != 5 || el.r <= 0 || (el.t != 'C' && el.t != 'c'))
						break ;
					for (int line = 0; line < HEIGHT; line++) {
						for (int col = 0; col < WEIGHT; col++) {
							sqr = sqrtf(powf(line - el.y, 2.0) + powf(col - el.x, 2.0));
							if (sqr <= el.r)
							{
								if ((el.t == 'C') || (el.t == 'c' && el.r - sqr < 1.0f))
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

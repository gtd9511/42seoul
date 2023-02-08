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
	char	c
}Draw;

int	is_in_rect(int x, int y, Draw el)
{
	if ((x - el.x1 < 1.0f) || (el.x2 - x < 1.0f)) ||
		(y - el.y1 < 1.0f) || (el.y2 - y < 1.0f)
		return (1);
	return (0);
}

int	err_msg(FILE *fd, int err)
{
	if (err == 2)
}

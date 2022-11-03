#include "minitalk.h"
#include <stdlib.h>
int	main(void)
{
	int	pid;
	char				*pid_str;

	pid = getpid();
	pid_str = ft_itoa(pid);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	write(1, pid_str, ft_strlen(pid_str));
	write(1, "\n", 1);
}

void	display_nbr(int n, int fd)
{
	char	*decimal;

	decimal = "0123456789";
	if (n >= 10)
		display_nbr(n / 10, fd);
	write(fd, decimal + (n % 10), 1);
}

size_t	ft_strlen(const char *s)
{
	size_t	c;

	c = 0;
	while (*s != '\0')
	{
		c++;
		s++;
	}
	return (c);
}


void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	display_nbr(n, fd);
}


int					ft_minus(int *n);
long unsigned int	ft_numlen(int n);

char	*ft_itoa(int n)
{
	char				*str;
	long unsigned int	str_len;
	int					sign;

	sign = ft_minus(&n);
	if (sign < 0)
		return ((char *)ft_strdup("-2147483648"));
	str_len = ft_numlen(n);
	str = (char *)malloc(sizeof(char) * (str_len + sign + 1));
	if (str == NULL)
		return (NULL);
	str[str_len + sign] = '\0';
	while (str_len-- > 0)
	{
		str[str_len + sign] = '0' + n % 10;
		n /= 10;
	}
	if (sign)
		str[0] = '-';
	return (str);
}

int	ft_minus(int *n)
{
	if (*n < 0)
	{
		if (*n <= -2147483648)
			return (-1);
		*n *= -1;
		return (1);
	}
	return (0);
}

long unsigned int	ft_numlen(int n)
{
	long unsigned int	n_len;

	n_len = 0;
	while (n)
	{
		n /= 10;
		n_len++;
	}
	if (!n_len)
		return (1);
	return (n_len);
}

char	*ft_strdup(const char *s1)
{
	char	*dst;
	int		i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	dst = (char *)malloc(sizeof(char) * (i + 1));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

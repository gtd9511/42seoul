#include "./megaphone.hpp"

void ft_put_error()
{
	std::cout << "error: cannot print";
}

bool is_print(char c)
{
	if (32 <= c && c<= 127)
		return true;
	return false;
}

void print_str(std::string str)
{
	int	i = -1;
	while(str[++i] != '\0')
	{
		if (is_print(str[i]))
		{
			if ('a' <= str[i] && str[i] <= 'z')
				str[i] = str[i] - 32;
		}
		else
			ft_put_error();
		std::cout << str[i];
	}
}

int main(int argc, char **argv)
{
	int j = 0;
	if(argc == 1)
		std::cout <<"* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else
	{
		while(++j < argc)
			print_str(argv[j]);
		std::cout << std::endl;
	}
	return (0);
}
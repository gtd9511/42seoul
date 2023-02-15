#include <stdio.h>

void	*ft_print_memory(void *addr, unsigned int size);

int main()
{
	char str[] = "Bonjour les aminches\t\n\tc  est fou\ttout\tce qu on peut faire avec\t\n\tprint_memory\n\n\n\tlol.lol\n \0";
//	char str[] = "Hello World!";
	ft_print_memory(str, sizeof(str) - 1);
	printf("%p\n", str);
}

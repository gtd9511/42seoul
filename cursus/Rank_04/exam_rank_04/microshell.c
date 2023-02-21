#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int ft_putstr_fd2(char *str1, char *str2)
{
	while (*str1)
		write(2, str1++, 1);
	if (str2)
		while (*str2)
			write(2, str2++, 1);
	write(2, "\n", 1);
	return (1);
}

int ft_execute(char *argv[], int i, int temp_fd, char *env[])
{
	argv[i] = NULL;
	dup2(temp_fd, STDIN_FILENO);
	close(temp_fd);
	execve(argv[0], argv, env);
	return (ft_putstr_fd2("error: cannot execute ", argv[0]));
}

int main(int argc, char *argv[], char *env[])
{
	int i;
	int fd[2];
	int temp_fd;
	(void)argc;

	i = 0;
	temp_fd = dup(STDIN_FILENO);
	while (argv[i] && argv[i + 1])
	{
		argv = &argv[i + 1];
		i = 0;
		while (argv[i] && strcmp(argv[i], ";") && strcmp(argv[i], "|"))
			i++;
		if (strcmp(argv[0], "cd") == 0)
		{
			if (i != 2)
				ft_putstr_fd2("error: cd: bad arguments", NULL);
			else if (chdir(argv[1]) != 0)
				ft_putstr_fd2("error: cd: cannot change directory to ", argv[1]);
		}
		else if (i != 0 && (argv[i] == NULL || strcmp(argv[i], ";") == 0))
		{
			if (fork() == 0)
			{
				if (ft_execute(argv, i, temp_fd, env))
					return (1);
			}
			else
			{
				close(temp_fd);
				while(waitpid(-1, NULL, WUNTRACED) != -1)
					;
				temp_fd = dup(STDIN_FILENO);
			}
		}
		else if (i != 0 && strcmp(argv[i], "|") == 0)
		{
			pipe(fd);
			if (fork() == 0)
			{
				dup2(fd[1], STDOUT_FILENO);
				close(fd[0]);
				close(fd[1]);
				if (ft_execute(argv, i, temp_fd, env))
					return (1);
			}
			else
			{
				close(fd[1]);
				close(temp_fd);
				temp_fd = fd[0];
			}
		}
	}
	close(temp_fd);
	return (0);
}

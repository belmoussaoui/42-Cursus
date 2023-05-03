#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

static void perr(char *string)
{
	while (*string)
		write(2, string++, 1);
}

void cd(char **argv, int i)
{
	if (i != 2)
		perr("error: cd: bad arguments");
	else if (chdir(argv[1]) != 0)
	{
		perr("error: cd: cannot change directory to ");
		perr(argv[1]);
		perr("\n");
	}
}

int ft_execute(char **argv, char **envp, int i, int tmp_fd)
{
	argv[i] = NULL;
	dup2(tmp_fd, STDIN_FILENO);
	close(tmp_fd);
	execve(argv[0], argv, envp);
	perr("error: cannot execute");
	return (1);
}

static int exec(char **argv, char **envp, int i, int tmp_fd)
{
	if (fork() == 0)
	{
		if (ft_execute(argv, envp, i, tmp_fd))
			return (1);
	}
	else
	{
		close(tmp_fd);
		while (waitpid(-1, NULL, WUNTRACED) != -1)
			;
		tmp_fd = dup(STDIN_FILENO);
	}
	return (0);
}

static int pipex(char **argv, char **envp, int i, int* tmp_fd)
{
	int fd[2];
	pipe(fd);
	if (fork() == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		if (ft_execute(argv, envp, i, *tmp_fd))
			return (1);
	}
	else
	{
		close(fd[1]);
		close(*tmp_fd);
		*tmp_fd = fd[0];
	}
	return (1);
}

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	int tmp_fd = dup(STDIN_FILENO);
	while (*argv && *(argv + 1))
	{
		argv++;
		int i = 0;
		while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
			i++;
		if (strcmp(*argv, "cd") == 0)
			cd(argv, i);
		else if (i > 0)
		{
			if (argv[i] == NULL || strcmp(argv[i], ";") == 0)
				exec(argv, envp, i, tmp_fd);
			else if (strcmp(argv[i], "|") == 0)
				pipex(argv, envp, i, &tmp_fd);
		}
		argv += i;
	}
	close(tmp_fd);
	return (0);
}

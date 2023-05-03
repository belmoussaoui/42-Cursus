#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

void perror2(char *message) {
	while (*message) {
		write(2, message, 1);
		message++;
	}
}

#include <stdio.h>
void cd(char **argv, int i)
{
	if (i != 2)
		perror2("bad");
	else if (chdir(argv[1]) != 0)
		perror2("error");
	printf("%s\n", argv[1]);
}

void exec(char **argv, char **envp, int i, int tmp_fd) {
	argv[i] = NULL;
	dup2(tmp_fd, STDIN_FILENO);
	close(tmp_fd);
	execve(argv[0], argv, envp);
	perror2("error");
}

void execute(char **argv, char **envp, int i, int tmp_fd) {
	if (fork() == 0) {
		exec(argv, envp, i, tmp_fd);
	} else {
		close(tmp_fd);
		while(waitpid(-1, NULL, WUNTRACED) != -1) ;
		tmp_fd = dup(STDIN_FILENO);
	}
}

void pipex(char **argv, char **envp, int i, int *tmp_fd) {
	int fd[2];
	pipe(fd);
	if (fork() == 0) {
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		exec(argv, envp, i, *tmp_fd);
	} else {
		close(fd[1]);
		close(*tmp_fd);
		*tmp_fd = fd[0];
	}
}

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	int tmp_fd = dup(STDIN_FILENO);
	while (argv[0] && argv[1])
	{
		int i = 0;
		argv++;
		while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
			i++;
		if (argv[0] && strcmp(argv[0], "cd") == 0)
			cd(argv, i);
		else if (i > 0) {
			if (argv[i] == NULL || strcmp(argv[i], ";") == 0)
				execute(argv, envp, i, tmp_fd);
			else if (strcmp(argv[i], "|") == 0)
				pipex(argv, envp, i, &tmp_fd);
		}
		argv += i;
	}
	close(tmp_fd);
	return (1);
}
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

int get_argc (const char *cmdline)
{	
	int i = 0;
	int argc = 1;	

	for(i = 0;cmdline[i] != '\0';i++)
	{
		if((cmdline[i] == ' ') || (cmdline[i] == '\n'))	
			argc++;
	}
	argc = argc + 2;

	return argc;
}
		
int * get_sizes (const char *cmdline)
{
	int i, j, c;
	i = j = c = 0;
	int n = get_argc(cmdline);
	int *sizetable = malloc(n * sizeof(int *));
	
	for(i = 0;cmdline[i] != '\0';i++)
	{
		if((cmdline[i] == ' ') || (cmdline[i] == '\n'))	
		{
			sizetable[c] = j;
			if(cmdline[i] != '\n')
			{			
				c++;
				j = 0;
			}		
		}
		else
			j++;
	}
	sizetable[c + 1] = 1;

	return sizetable;
}

char **allocate_argv(const char *cmdline)
{	
	int rows = get_argc(cmdline);	
	int *sizes = get_sizes(cmdline);
	char **argv = malloc(rows * sizeof(char *));

	int i = 0;
	for(i = 0;i < rows;i++)
		argv[i] = malloc(sizes[i] * sizeof(char *));

	free(sizes);

	return argv;
}

char **parse_cmdline (const char *cmdline)
{ 
	int i, j, c;
	i = j = c = 0;
	char **args = allocate_argv(cmdline);
	
	for(i = 0;cmdline[i] != '\0';i++)
	{
		if((cmdline[i] == ' ') || (cmdline[i] == '\n'))	
		{
			args[c][j] = '\0';
			if(cmdline[i] != '\n')
			{			
				c++;
				j = 0;
			}	
		}
		else
		{
			args[c][j] = cmdline[i];
			j++;
		}
	}
	args[c + 1][0] = '\0';
	
	return args;
}

void exec (char **args)
{
	int status, exec_return;
	pid_t pid = fork();

	if (pid == 0)
	{	
		exec_return = execv(args[0], args);
		if(exec_return == - 1)
			perror(args[0]);			
	}
	else if (pid > 0)	
	{
		pid = waitpid(pid, &status, 0);
		if(pid  == -1)
		{
			perror("waitpid");
			exit(1);
		}
	}
	else
	{
		perror("fork");
		exit(1);
	}
}

int  main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char **args;

	while((read = getline(&line, &len, stdin)) != -1) 
	{		
		args = parse_cmdline(line);
		exec(args);
	}
		
	free(line);
	free(args);

	return 0;	
}

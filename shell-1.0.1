//--------------------------------------------
// NAME: Ivo Stratev
// CLASS: XIb
// NUMBER: 16
// PROBLEM: #2
// FILE NAME: shell.c
// FILE PURPOSE:
// This program is simple-shell (pipelines and other functions of real shell/bash aren't implemnted.
// But this shell does the basic role of Terminal, it runs programs while interpretate command lines from stdin.
// This implementation relais only to 4 functions: fork(), execv(), waitpid() and perror().
// And it has it's own parse function that does not relais on functions like: strtok() or any other prebuild ones.
//---------------------------------------------

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

//--------------------------------------------
// FUNCTION: get_argument_counter
// Returns argc (for the same argv produce from parse_cmdline()) in order to allocate rigth number of bytes.
// PARAMETERS:
// cmdline: used for producing argc (from it).
//----------------------------------------------
int get_argument_counter (const char *cmdline);
//--------------------------------------------
// FUNCTION: get_sizes
// Returns array containing the number of bytes for each argument from the arguments vector (the same one produced by parse_cmdline()).
// PARAMETERS:
// cmdline: used for producing byte size of each argument for producing argv (from it).
//----------------------------------------------
int *get_sizes (const char *cmdline);
//--------------------------------------------
// FUNCTION: allocate_argv
// Allocates memory for argv (for the same argv produce from parse_cmdline())
// PARAMETERS:
// cmdline: used for memory allocation for each argument for producing argv (from it).
//----------------------------------------------
char **allocate_argv (const char *cmdline);
//--------------------------------------------
// FUNCTION: parse_cmdline
// Parses command line and producing argv from it.
// PARAMETERS:
// cmdline: used for producing argv in order to execute programs with execv().
//----------------------------------------------
char **parse_cmdline (const char *cmdline);
//--------------------------------------------
// FUNCTION: exec
// Creates diffrent processes.
// PARAMETERS:
// args: used for executing programs with execv().
//----------------------------------------------
void exec (char **args);

//--------------------------------------------
// FUNCTION: main
// Reads command lines and executes programs from parsing those lines.
// PARAMETERS:
// none.
//----------------------------------------------
int  main (void)
{
	int size = 9, index = 0, flag = 0;	//Define size, flag and index and inicializate them with their starting values.
        char **args, *command_line = malloc(size * sizeof(char *)), byte;	//Define args, command_line and byte and alocate memory for command_line.  
       	while((byte = getchar()) != EOF)	//Lopp while end of file of stdin isn't reached and read it byte by byte.
	{	
		command_line[index] = byte;	//Buffer read byte in command_line.
		index++;	//Increment index (possition in command_line).
		if(index > size)	//And if possition isn't in command_line range reallocate command_line(giving it 3 more bytes space).
		{
			size += 3;	//Increment size with 3.
			command_line = realloc(command_line, size * sizeof(char *));	//Realloacte command_line with current size + 3.
		}
		if(byte != '\n')	//Protect against /n/n... chain by setting flag in 1.
			flag = 1;	//Set flag.				
		if((byte == '\n') && (flag == 1))	//If read byte is new line and flag is 1 than terminate futer string, pass buffered memmory for parsing it, try to execute command from that string and reset index in order to start fresh if there are more command lines. 
		{
			command_line[index] = '\0';	//Terminate futer string.
			args = parse_cmdline(command_line);	//Parse that string.
			exec(args);	//Execute the command line.
			index = 0;	//Reset index.
			flag = 0;	//Reset flag.
		}
	}
               
        free(args);     //Free all memory used by args, since it's no longer needed.
        free(command_line);     //Free all memory used by line, since it's no longer needed.
 
        return 0;       //Return 0 to indicate succesfull program execution.   
}
 
int get_argument_counter (const char *cmdline)
{      
        int index = 0, argument_counter = 0;    //Define index and argument_counter and inicializate them with 0; index is used to iterate througth passed argument (c-string) and argument_counter is used to return number of potencial argument in futer string parsing.    
 
        for(index = 0;cmdline[index] != '\0';index++)   //Iterate throuth argument and increment argument_counter when end of potencial argument is reached.
        {
                if(((cmdline[index] == ' ') || (cmdline[index] == '\n')) && (cmdline[index - 1] != ' ')) //If potencial argument is reached increment argument_counter.
                        argument_counter++;     //Increment argument_counter if potencial argument is reached.
        }
 
        return argument_counter;        //Return agument_counter to indicate how much memory is need to be allocated.
}
               
int *get_sizes (const char *cmdline)
{
        int position = 0, counter = 0, index = 0, *sizes_holder = malloc(get_argument_counter(cmdline) * sizeof(int *));        //Defines postition (used to iterate throut command line), counter (used to hold current future argument's size) and index (used to bound counter's value with future position in argument vector configuration) and inicializate them with 0s; And defines aray of ints (as pointer in order to avoid return of local varible address) (sizes_holder) and allocate memory (result returned from get_argument_counter() mul with size of int).
       
        for(position = 0;cmdline[position] != '\0';position++)  //Iterates throuth command line and saves the rigth future number of bytes needed for each arguments.
        {
                if((cmdline[position] == ' ') || (cmdline[position] == '\n'))  //If current symbol from command line is end of argument save it, reset counter and increment index.
                {
                        sizes_holder[index] = counter;  //Save current argument (index)'s length in bytes.
                        if((cmdline[position] != '\n') && (cmdline[position - 1] != ' '))   //If end of command line isn't reached yet and previus byte ins't space than increment index and reset counter.
                        {                      
                                index++;        //Increment index.
                                counter = 0;    //Reset counter.
                        }              
                }
                else    //Else increment counter.
                        counter++;      //Increment counter.
        }
 
        return sizes_holder;    //Return array containing all sizes in bytes for each future argument.
}
 
char **allocate_argv (const char *cmdline)
{      
        int index = 0, rows = get_argument_counter(cmdline), *sizes = get_sizes(cmdline);       //Defines index(position in argument vector) and inicializate it with 0, rows (number of blocks need for all arguments) and inicializate it with result from get_argument_counter() and sizes (array of sizes of all arguments and inicializate it with result from performing get_sizes().    
        char **argv = malloc(rows * sizeof(char *));    //Defines argument vector and allocates memory for number of arguments.
 
        for(index = 0;index < rows;index++)     //Iterate throuth argument vector's "rows" and allocate memory for the future argument in this "row".
                argv[index] = malloc(sizes[index] * sizeof(char *)); //Allocate memory for the future argument on it's place in argument vector.
 
        free(sizes);    //Free memory used by sizes, since it's no longer needed.
 
        return argv;    //Return argv (only the memory alocated for it).
}
 
char **parse_cmdline (const char *cmdline)
{
        int position = 0, counter = 0, index = 0;       //Defines postition (used to iterate throut command line), counter (used to hold current future argument's size) and index (used to bound counter's value with future position in argument vector configuration) and inicializate them with 0s
        char **args = allocate_argv(cmdline);   //Defines and allocates memory for arguments vector.
       
        for(position = 0;cmdline[position] != '\0';position++)  //Iterates throuth command line and forms the argument vecotor from parsing command line.
        {
                if((cmdline[position] == ' ') || (cmdline[position] == '\n'))   //If end of argument is reached increment index, reset counter and terminate curent argument.
                {
                        if((cmdline[position] != '\n') && (cmdline[position - 1] != ' '))   //If end of command line isn't reached yet and previus byte ins't space than increment index and reset counter.
                        {                      
                                index++;        //Incremnt index.
                                counter = 0;    //Reset counter.
                        }
                        args[index][counter] = '\0';    //Terminate current argument.
                }
                else    //Else current argument with current position in it recives the value of current position in command line.
                {
                        args[index][counter] = cmdline[position];       //Current argument with current position in it recives the value of current position in command line.
                        counter++;      //Increment counter;
                }
        }
        args[index + 1] = NULL; //Last argument is set to NULL to indicate end of arguments chain.
       
        return args;    //Return formed arguments vector.
}
 
void exec (char **args)
{
        int status;     //Defines holder of status from waiting child procces to execute normaly.
        pid_t pid = fork();     //Defines and inicializate Pid (process id) with result from fork()ing current parent process.
 
        if (pid == 0)   //If current process is child, since pid is 0, which means it's safe to use execv(), which "overtakes" the process where it's used.
        {      
                if((execv(args[0], args)) == - 1)       //If execv() returns value (returns only on error occurency) print the error massage.
                        perror(args[0]);        //Print the error massage.             
        }
        else if (pid > 0)       //Else if current process is parent wait childe process to end (or terminate).     
        {
                if((waitpid(pid, &status, 0))  == -1)   //Wait the childe process and if waitpid() fails (error ocurres) pritn the error and terminate that process.
                {
                        perror("waitpid(2)");   //Print the error massage.
                        exit(1);        //Terminate the process.
                }
        }
        else    //Else fork failed (error ocurred), print proper error massage and exit() (terminate parent process.
        {
                perror("fork(2)");      //Print the error massage.     
                exit(1);        //Exit() (terminate parent process.    
        }
}

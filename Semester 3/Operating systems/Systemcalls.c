/*
Develop a C program to implement the Process system calls (fork(), exec(), wait(), 
create process, terminate process).
*/

#include <stdio.h>      // printf()
#include <stdlib.h>     // exit()
#include <sys/types.h>  // pid_t
#include <sys/wait.h>   // wait()
#include <unistd.h>     // fork(), exec()

int main(int argc, char **argv) {
    pid_t pid;

    // Create a new process using fork
    pid = fork();

    if (pid < 0) {
        // Error in forking
        printf("Error in forking..\n");
        exit(EXIT_FAILURE);
    } 
    else if (pid == 0) {
        // Child process
        printf("It is the child process with PID: %d\n", getpid());
        
        // Execute a new program (e.g., "ls") using exec
        char *args[] = {"ls", "-l", NULL}; // Arguments for the new program
        execvp(args[0], args); // Replace the child process with "ls"
        
        // If execvp fails
        printf("Error in exec\n");
        exit(EXIT_FAILURE);
    } 
    else {
        // Parent process
        printf("It is the parent process with PID: %d\n", getpid());
        
        int status;
        wait(&status); // Wait for the child process to complete
        printf("Child process reaped with exit status: %d\n", WEXITSTATUS(status));
    }

    return 0;
}

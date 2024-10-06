#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

/*
    Develop a C program which demonstrates inter-process communication
    between a reader process and a writer process. Use mkfifo, open, read, write
    and close APIs in your program.
*/

int main() {
    int fd;
    /* Create the FIFO (named pipe) */
    char *myfifo = "/tmp/myfifo";
    mkfifo(myfifo, 0666); // Create FIFO with read and write permissions

    printf("Run Reader process to read the FIFO File\n");

    fd = open(myfifo, O_WRONLY); // Open FIFO for writing
    write(fd, "Hi", sizeof("Hi")); // Write "Hi" to the FIFO

    close(fd); // Close the FIFO
    unlink(myfifo); // Remove the FIFO
    return 0;
}

/*
    Instructions for Execution:
    1. Compile the Program:
       Open a terminal and navigate to the directory where you saved the file.
       Compile the program using the following command:
       gcc writer.c -o writer

    2. Run the Writer Process:
       Open a terminal window and run the writer process:
       ./writer

    Expected Output:
    When you run the program, you will see:
    - In the writer terminal, it will display:
      Run Reader process to read the FIFO File
      (It will wait for input from the reader process.)
    
    Important Notes:
    - Make sure the FIFO file is not already created or being used by another process before running the program.
    - You may need to adjust permissions or paths depending on your operating system and user permissions.
    - This example uses a fixed message "Hi", but you can modify the writer to read user input if desired.
*/

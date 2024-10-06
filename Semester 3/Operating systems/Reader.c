/*
    Develop a C program which demonstrates inter-process communication
    between a reader process and a writer process. Use mkfifo, open, read, write
    and close APIs in your program.
*/
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

#define MAX_BUF 1024

int main() {
    int fd;
    char *myfifo = "/tmp/myfifo"; // FIFO file path
    char buf[MAX_BUF]; // Buffer to store the read message

    /* Open, read, and display the message from the FIFO */
    fd = open(myfifo, O_RDONLY); // Open FIFO for reading
    read(fd, buf, MAX_BUF); // Read from the FIFO
    printf("Writer: %s\n", buf); // Print the message received from the writer

    close(fd); // Close the FIFO
    return 0;
}

/*
    Instructions for Execution:
    1. Compile the Program:
       Open a terminal and navigate to the directory where you saved the file.
       Compile the program using the following command:
       gcc reader.c -o reader

    2. Run the Reader Process:
       Open a terminal window and run the reader process first:
       ./reader

    3. Run the Writer Process:
       Open another terminal window and run the writer process:
       ./writer

    Expected Output:
    When you run the programs as described:
    1. In the reader terminal, you will see:
       (It will wait for input from the writer process.)

    2. In the writer terminal, you will see:
       (No output, it just writes "Hi" to the FIFO.)

    3. After running the writer process, the reader terminal will display:
       Writer: Hi

    Important Notes:
    - Make sure the FIFO file is not already created or being used by another process before running the programs.
    - You may need to adjust permissions or paths depending on your operating system and user permissions.
    - This example uses a fixed message "Hi", but you can modify the writer to read user input if desired.
*/

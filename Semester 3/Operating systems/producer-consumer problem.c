/*
Implement a Producer-Consumer problem using a circular buffer.
The program allows the user to produce and consume items in the buffer.
*/

#include <stdio.h>

void main() {
    int buffer[10], bufsize, in, out, produce, consume, choice = 0;
    in = 0;
    out = 0;
    bufsize = 10; // Size of the circular buffer

    while (choice != 3) {
        printf("\n1. Produce\t2. Consume\t3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: // Produce
                if ((in + 1) % bufsize == out) {
                    printf("\nBuffer is Full"); // Check if buffer is full
                } else {
                    printf("\nEnter the value: ");
                    scanf("%d", &produce); // Get value from user
                    buffer[in] = produce; // Place value in buffer
                    in = (in + 1) % bufsize; // Update 'in' index circularly
                }
                break;
                
            case 2: // Consume
                if (in == out) {
                    printf("\nBuffer is Empty"); // Check if buffer is empty
                } else {
                    consume = buffer[out]; // Get value from buffer
                    printf("\nThe consumed value is %d", consume);
                    out = (out + 1) % bufsize; // Update 'out' index circularly
                }
                break;
        }
    }
}

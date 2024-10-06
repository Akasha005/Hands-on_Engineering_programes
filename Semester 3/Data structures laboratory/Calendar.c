/*
1. Develop a Program in C for the following:
   a) Declare a calendar as an array of 7 elements (A dynamically Created array) to represent 7 days of a
      week. Each Element of the array is a structure having three fields. The first field is the name of the
      Day (A dynamically allocated String), The second field is the date of the Day (A integer), the third
      field is the description of the activity for a particular day (A dynamically allocated String).
   b) Write functions create(), read(), and display(); to create the calendar, to read the data from the
      keyboard and to print the week's activity details report on screen.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NUM_DAYS_IN_WEEK 7

// Structure to represent a day
typedef struct {
    char *acDayName;   // Dynamically allocated string for the day name
    int iDate;         // Date of the day
    char *acActivity;  // Dynamically allocated string for the activity description
} DAYTYPE;

DAYTYPE *create();              // Function to create a calendar
void read(DAYTYPE *calendar);    // Function to read data from the user
void display(DAYTYPE *calendar); // Function to display the week's activity details
void freeCalendar(DAYTYPE *calendar); // Function to free dynamically allocated memory

int main() {
    // Create the calendar
    DAYTYPE *weeklyCalendar = create();
    
    // Read data from the keyboard
    read(weeklyCalendar);
    
    // Display the week's activity details
    display(weeklyCalendar);
    
    // Free allocated memory
    freeCalendar(weeklyCalendar);
    
    return 0;
}

// Function to create a dynamically allocated calendar with 7 days
DAYTYPE *create() {
    DAYTYPE *calendar = (DAYTYPE *)malloc(NUM_DAYS_IN_WEEK * sizeof(DAYTYPE));
    for (int i = 0; i < NUM_DAYS_IN_WEEK; i++) {
        calendar[i].acDayName = NULL;
        calendar[i].iDate = 0;
        calendar[i].acActivity = NULL;
    }
    return calendar;
}

// Function to read the day name, date, and activity from the user for each day
void read(DAYTYPE *calendar) {
    char cChoice;
    for (int i = 0; i < NUM_DAYS_IN_WEEK; i++) {
        printf("Do you want to enter details for day %d [Y/N]: ", i + 1);
        scanf(" %c", &cChoice); getchar(); // Space before %c to consume any newline characters
        
        if (tolower(cChoice) == 'n') {
            continue;
        }
        
        // Read Day Name
        printf("Day Name: ");
        char nameBuffer[50];
        scanf("%s", nameBuffer);
        calendar[i].acDayName = strdup(nameBuffer); // Dynamically allocate and copy the string
        
        // Read Date
        printf("Date: ");
        scanf("%d", &calendar[i].iDate);
        
        // Read Activity
        printf("Activity: ");
        char activityBuffer[100];
        scanf(" %[^\n]", activityBuffer); // Read the entire line, including spaces
        calendar[i].acActivity = strdup(activityBuffer);
        
        getchar(); // Remove trailing newline character in input buffer
    }
}

// Function to display the week's activity details
void display(DAYTYPE *calendar) {
    printf("\nWeek's Activity Details:\n");
    for (int i = 0; i < NUM_DAYS_IN_WEEK; i++) {
        printf("Day %d:\n", i + 1);
        if (calendar[i].iDate == 0) {
            printf("No Activity\n\n");
            continue;
        }
        
        printf(" Day Name: %s\n", calendar[i].acDayName);
        printf(" Date: %d\n", calendar[i].iDate);
        printf(" Activity: %s\n\n", calendar[i].acActivity);
    }
}

// Function to free dynamically allocated memory for the calendar
void freeCalendar(DAYTYPE *calendar) {
    for (int i = 0; i < NUM_DAYS_IN_WEEK; i++) {
        free(calendar[i].acDayName);
        free(calendar[i].acActivity);
    }
    free(calendar);
}

/*
   Develop a Program in C for the following operations on Strings:
   a. Read a main String (STR), a Pattern String (PAT), and a Replace String (REP).
   b. Perform a Pattern Matching Operation: Find and replace all occurrences of PAT in STR with REP if PAT exists in STR. 
      Report suitable messages in case PAT does not exist in STR.
   c. Support the program with functions for each of the above operations. Do not use built-in functions.
*/

#include <stdio.h>

void findAndReplace(char str[], char pat[], char rep[], char ans[]);

int main() {
    char str[100], pat[100], rep[100], ans[200]; // ans array size should be large enough to store final result

    // Reading inputs
    printf("Enter the main string (STR): ");
    gets(str);

    printf("\nEnter the pattern string (PAT): ");
    gets(pat);

    printf("\nEnter the replacement string (REP): ");
    gets(rep);

    // Perform pattern matching and replacement
    findAndReplace(str, pat, rep, ans);
    
    return 0;
}

// Function to find and replace all occurrences of 'pat' in 'str' with 'rep'
void findAndReplace(char str[], char pat[], char rep[], char ans[]) {
    int i, j, c, m, k;
    int flag = 0;  // To check if the pattern exists or not
    
    i = m = c = j = 0;
    
    // Loop through the main string (STR)
    while (str[c] != '\0') {
        // Pattern matching
        if (str[m] == pat[i]) {
            i++;
            m++;
            
            // If the entire pattern is matched
            if (pat[i] == '\0') {
                printf("\nPattern '%s' is found at position %d", pat, c + 1);
                
                // Replace with REP string
                for (k = 0; rep[k] != '\0'; k++, j++) {
                    ans[j] = rep[k];
                }
                
                // Reset pattern index and move the main string pointer
                i = 0;
                c = m;
                flag = 1; // Pattern found
                
            }
        } else {
            // If there is a mismatch, copy the character from STR to ANS
            ans[j] = str[c];
            j++;
            c++;
            m = c;
            i = 0;
        }
    }

    // Terminate the resulting string
    ans[j] = '\0';

    // If no pattern was found, print a message
    if (flag == 0) {
        printf("\nPattern '%s' was not found in the string '%s'.", pat, str);
    } else {
        // If pattern was found, display the resulting string
        printf("\nThe resulting string is: %s", ans);
    }
}

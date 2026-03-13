#include "debug.h"
#include "debug.c"
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int main() {
    srand(time(NULL));
    char level[MAX_AMT];
    bool debug_check = true;
    int level_num;

    while (debug_check) {
        printf("Enter a debug level(0-4): ");
        fgets(level,MAX_AMT,stdin);
        if (level[strlen(level) - 1] != '\n') { // Checks if number is too long
            clear_input_buffer();
            printf("Error: Input too long!\n");
        }
        level[strlen(level) - 1] = '\0';
        if (sscanf(level, "%d", &level_num) == 1) { //Checks that the number is within range
            if (level_num < 0 || level_num > 4) {
                printf("Please enter the debug level within the given range (0-4).\n");
            } else {
                set_debug_level(level_num);
                debug_check = false;
            }
        } else { // If the user enters something other than a number
            printf("Error: Please enter a number.\n");
        }
    } // Define messages
    char message1[MAX_LEN] = "This is the %dst message.\n";
    char message2[MAX_LEN] = "Message no.%d here.\n";
    char message3[MAX_LEN] = "Hello, isn't %d wonderful?\n";
    char message4[MAX_LEN] = "This is happening for the %dth time..\n";
    char message5[MAX_LEN] = "Lucky number %d!\n";

    for (int i = 1; i <= 5; i++) { // Call dprintf 5 times
        int random_debug_level = rand() % 5;
        switch (i) {
            case 1:
                dprintf(random_debug_level, message1, i);
                break;
            case 2:
                dprintf(random_debug_level, message2, i);
                break;
            case 3:
                dprintf(random_debug_level, message3, i);
                break;
            case 4:
                dprintf(random_debug_level, message4, i);
                break;
            case 5:
                dprintf(random_debug_level, message5, i);
                break;
            default:
                break;
        }
    }
    return 0;
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

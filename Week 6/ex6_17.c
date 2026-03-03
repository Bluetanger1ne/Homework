#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define PASSPHRASE_SIZE 32
#define PASSWORD_SIZE 64

bool password_generator(char *password, int size, const char *passphrase);

void remove_linefeed(char *string);

char random_character(int min, int max);

void clear_input_buffer();

int main() {
    srand(time(NULL));
    char password[PASSWORD_SIZE];
    char passphrase[PASSPHRASE_SIZE];
    bool running = true;

    // ask user to enter a password
    while (running != false) {
        printf("Please enter a word to make a password with, or \"stop\" to quit: ");

        if (fgets(passphrase, PASSPHRASE_SIZE, stdin) != NULL) {
            if (passphrase[strlen(passphrase) - 1] != '\n') { // Check if input is too long ( No newline). If so, do this.
                clear_input_buffer();  // Clear input buffer
                printf("Error: Input too long!\n");
                continue;
            }
            // remove the line feed
            remove_linefeed(passphrase);
        }
        if (strcmp(passphrase, "stop") == 0) {
            // check for the termination word
            running = false;
        } else if (sscanf(passphrase, "%s", passphrase) == 1) { // If conditions are satisfied, generate and print the password.
            if (password_generator(password, PASSWORD_SIZE, passphrase)) {
                printf("Your password is: %s\n", password);
            }
        } else {
            // Input is not valid
            printf("Invalid input. Try again. \n");
        }
    }

    return 0;
}


bool password_generator(char *password, int size, const char *passphrase) {
    int index = 0;
    int required_size = (int) (strlen(passphrase) * 2) + 2;
    if (size < required_size) { // check if the generated password is too large
        return false;
    }
    password[index++] = random_character(33, 126); // Make first character a random printable character

    for (int i = 0; passphrase[i] != '\0'; i++) { // Generate a random printable character and modify the original string according to the rules
        password[index++] = passphrase[i];
        password[index++] = random_character(33, 126);
    }
    password[index] = '\0';

    return true;
}

void remove_linefeed(char *string) {
    if (string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }
}

char random_character(int min, int max) {
    int random = rand() % (max - min + 1) + min;
    return (char) random;
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
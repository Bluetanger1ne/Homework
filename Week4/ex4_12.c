#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 120

int count_words(const char* str, const char *word);

int main() {
    char sentence[MAX_SIZE];
    char word[MAX_SIZE];
    int running = 1;

    do {
        printf("\nPlease enter a string:");
        fgets(sentence,MAX_SIZE,stdin);
        if (sentence[strlen(sentence) - 1] == '\n') {
            // Removing the new line
            sentence[strlen(sentence) - 1] = '\0'; // Replacing it with \0
        }
        printf("\nPlease enter a word you wish to search for: \n");
        fgets(word,MAX_SIZE,stdin);
        if (word[strlen(word) - 1] == '\n') {
            // Removing the new line
            word[strlen(word) - 1] = '\0'; // Replacing it with \0
        }
        if (strcmp(word, "stop") == 0 || strcmp(word, "Stop") == 0 || strcmp(word, "STOP") == 0)  {
            running = 0; // Checking if the user enters the word 'stop' in (almost) any iteration.
        }
        if (running != 0) {
            int total_amount = count_words(sentence,word);
            printf("That word appeared %d time(s) in the sentence.\n",total_amount);
        }

    } while (running != 0);
    return 0;
}


int count_words(const char* str, const char *word) {
    int count = 0;
    const char *ptr = str; // Using pointer arithmetic to keep track of each word found within the sentence.

    while ((ptr = strstr(ptr, word))) {
        ptr += strlen(word); // If the word is found, jump over the section where it was found, and add one to the total count.
        count++;
    }

    return count;

}
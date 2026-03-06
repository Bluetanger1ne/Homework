#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 80

void remove_linefeed(char * string);

typedef struct node {
    int number;
    struct node *next;
} nnode;

void add(struct node **phead, int num);

int main() {
    bool running = true;
    int value = 0;
    char input[MAX_SIZE];
    nnode * head = NULL;

    while (running != false) {
        printf("Please enter a number, or \"end\" to quit: ");
        if (fgets(input, MAX_SIZE, stdin) != NULL) {
            remove_linefeed(input);

            if (strcmp(input,"end") == 0) { // Check if the entered string was "end"
                running = false;

            } else if (sscanf(input,"%d",&value) == 1) {
                // Add node to linked list
                add(&head,value);

            } else { // Input is not valid
                printf("Invalid input. Try again. \n");
            }
        }


        }
        nnode * pn = head;
        //int count1 = 0;
        while (pn != NULL) {
            printf("%d\n",pn->number);
            pn=pn->next;
            //count1++;
        }

        //int count2 = 0;
        pn = head;
        while (pn != NULL) {
            head = pn->next;
            free(pn);
            //count2++;
            pn=head;
    }
    //printf("Numbers added:%d\nNumbers deleted: %d",count1,count2);

    return 0;

}

void remove_linefeed(char * string) {
    if (string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }
}

void add(struct node **phead, int num) {
    // Allocate memory for new node
    nnode * new = (nnode*)malloc(sizeof(nnode));

    if(*phead == NULL) { // empty list
        *phead = new;
    }
    else {
        nnode *this = *phead;
        while (this->next != NULL) {
            this = this->next;
        }
        this->next = new;
    }
    new->number=num;
    new->next = NULL;
}

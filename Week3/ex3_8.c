#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 15


void print_numbers(const int *array, int count);

int main() {
    int array[SIZE] = {};
    srand(time(NULL));
    for (int i=0;i<SIZE;i++) {
        int value = rand();
        array[i] = value;
    }
    print_numbers(array,SIZE);
}

void print_numbers(const int *array, int count) {
    for (int i = 0; i < count;i++) {
        printf("%8d\n",array[i]);
    }
}
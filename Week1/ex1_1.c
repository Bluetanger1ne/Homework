#include <stdio.h>

float money(void);
float bus_cost(void);
float taxi_cost(void);

int main(void) {
    float your_money = 0;
    your_money = money();

    float buscost = 0;
    buscost= bus_cost();

    float taxicost = 0;
    taxicost = taxi_cost();
    printf("You have: $%.2f\n" , your_money);
    printf("A bus ticket costs: $%.2f\n"  , buscost);
    printf("A taxi costs: $%.2f\n" , taxicost);
    return 0;
}

float bus_cost() {
    float bus;
    printf("How much does a bus ticket cost?: ");
    scanf("%f", &bus);
    return bus;
}
float taxi_cost() {
    float taxi;
    printf("How much does a taxi ride cost?: ");
    scanf("%f", &taxi);
    return taxi;
}
float money() {
    float cash;
    printf("How much money do you have?: ");
    scanf("%f", &cash);
    return cash;
}
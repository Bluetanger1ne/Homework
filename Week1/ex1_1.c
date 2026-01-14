#include <stdio.h>

float money(void);
float bus_cost(void);
float taxi_cost(void);
int choice(void);

int main(void) {
    float your_money = 0;
    float buscost = 0;
    float taxicost = 0;

    buscost= bus_cost();
    taxicost = taxi_cost();
    your_money = money();


    while (your_money >= buscost || your_money >= taxicost) {
        int select = 0;
        printf("Do you want to travel by \n 1) Bus ($%.2f)\n 2) Taxi ($%.2f)\n",buscost,taxicost);
        select = choice();
        switch (select) {
            case 1:
                if (your_money >= buscost) {
                    printf("You chose bus.\n");
                    your_money -= buscost;
                    printf("You have: $%.2f left. \n" , your_money);
                    break;
                }
                if (your_money <= buscost) {
                    printf("You chose bus.\n");
                    printf("You don't have enough money for that. \n");
                    printf("You have: $%.2f left. \n" , your_money);
                    break;
                }
            case 2:
                if (your_money >= taxicost) {
                    printf("You chose taxi.\n");
                    your_money -= taxicost;
                    printf("You have: $%.2f left. \n" , your_money);
                    break;
                }
                if (your_money <= taxicost) {
                    printf("You chose taxi.\n");
                    printf("You don't have enough money for that. \n");
                    printf("You have: $%.2f left. \n" , your_money);
                    break;
                }
            default:
                printf("Please enter a valid number\n");
                break;
        }
    }
    printf("You don't have enough money, take a walk. Bye\n");
    return 0;
}
int choice() {
    int var = 0;
    printf("Enter your selection: ");
    scanf("%d", &var);
    return var;
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
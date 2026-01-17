#include <stdio.h>
#define ARRAY_LENGTH 12

float taxrate();

float incomelim();

float extratax();


int main(void) {
    float income[ARRAY_LENGTH] = {};
    float tax[ARRAY_LENGTH] = {};
    float value;
    float total = 0;

    float tax_percent = taxrate();
    float income_lim = incomelim();
    float extra_tax = extratax();

    for (int i = 0; i < ARRAY_LENGTH; i++) {
        printf("Please enter your income for month %d: ", i + 1);
        scanf("%f", &value);
        income[i] = value;

        if (total + income[i] <= income_lim) { //If the entire amount is under the income limit
            tax[i] = income[i] * tax_percent / 100;
        } else if (total >= income_lim) {     //If the entire amount is over the income limit
            tax[i] = income[i] * extra_tax / 100;
        } else {                              //If the part of the amount is over the income limit and part of it is under
            float under_lim = income_lim - total;
            float over_lim = value - under_lim;
            tax[i] = (under_lim * tax_percent / 100) + (over_lim * extra_tax / 100);
        }
        total += value;
    }

    printf("%7s", "Month");
    printf("%15s", "income");
    printf("%15s", "tax");
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        printf("\n %6d %14.2f %14.2f", i + 1, income[i], tax[i]);
    }

    return 0;
}

float taxrate() {
    float tax_percent;
    printf("Please enter your tax rate: ");
    scanf("%f", &tax_percent);
    return tax_percent;
}

float incomelim() {
    float income_lim;
    printf("Please enter your income limit: ");
    scanf("%f", &income_lim);
    return income_lim;
}

float extratax() {
    float extra_tax;
    printf("Please enter your excess tax rate: ");
    scanf("%f", &extra_tax);

    return extra_tax;
}

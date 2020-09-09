#include <stdio.h>
#include <stdlib.h>

float income;
float deduction;

float getInput(float income, float deduction ) {
    float uInput = -1;
    // use do-while loop to gurantee one execution
    while (uInput != 0) {
        printf(" Enter the next amount : ");
        scanf("%f", &uInput);

        if(uInput > 0) {
            income = income + uInput;
        }
    }
    return 1; 
}

int main (void) {
    getInput(income, deduction); 

    printf(" Income %f :  \n ", income);
}

/*
// global variables
float income, deduction, taxableIncome, taxOwed;
char group;

float getInput(float *income, float *deduction)
{
    float uInput = 0;
    // use do-while loop to gurantee one execution
    do
    {
        printf(" Enter the next amount : ");
        scanf("%f", &uInput);

        if (uInput > 0)
        {
            *income = *income + uInput;
        }
        else
        {
            // we need to convert the negative deduction value to positive.....because we are going to subtract income - deduction in the next methodd
            *deduction = *deduction + abs(uInput);
        }
    } while (uInput != 0);

    return 1;
}


int main(void) {
    getInput(&income, &deduction); 
}

*/ 
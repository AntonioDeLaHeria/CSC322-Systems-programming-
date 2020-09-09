#include <stdio.h>
#include<stdlib.h> 

// global variables
float income ,  deduction , taxableIncome , taxOwed;
char group; 


float getInput(float *income, float *deduction) {
    float uInput = 0; 
    // use do-while loop to gurantee one execution 
    do {
        printf(" Enter the next amount : ");
        scanf("%f",&uInput); 

        if ( uInput > 0 ) {
            *income = *income + uInput; 
        } else {
            // we need to convert the negative deduction value to positive.....because we are going to subtract income - deduction in the next methodd
            *deduction = *deduction + abs(uInput);
        }
    } 
    while (uInput != 0);

    return 1; 
}

// compute taxable income 
float computeTaxableIncome (float income, float deduction) {
    float taxableIncome; 
    taxableIncome = income - deduction;

    if ( taxableIncome <= 0) {
        return 0.0;
    } 
    return taxableIncome; 
}

// need to find out where the client lands on the tax bracket
char taxGroup(float taxableIncome ) {
    if( taxableIncome >= 500000) {
        return 'S';
    } 
    else if (taxableIncome >= 200000) {
        return 'Q';
    }
    else if (taxableIncome >= 100000) {
        return 'M';
    }
    else if (taxableIncome >= 50000) {
        return 'A'; 
    }
    else if (taxableIncome >= 20000) {
        return 'R';
    }
    else {
        return 'P'; 
    }

    return group;

}
// calculate the tax rate for the group 
float computeTaxOwed( char group ) {
    if ( group == 'S' || group == 'Q') {
        taxOwed = 0.25 * taxableIncome; 
    } 
    else if ( group == 'M') {
        taxOwed = 0.10 * taxableIncome; 
    }
    else if ( group == 'A' || group == 'R') {
        taxOwed = 0.3 * taxableIncome; 
    }
    else if (group == 'P') {
        taxOwed = 0.0; 
    }
    else {
        printf (" There was an error. "); 
    }

    // max you will pay in taxes 
    if (taxOwed > 50000) {
        taxOwed = 50000;
    }
    return taxOwed; 
}

// will print out my data....
void display()
{
    printf(" \n Income   =   %f \n ", income);
    printf(" \n Deductions   = %f \n ", deduction);
    printf(" \n Taxable Income  = %f  \n ", taxableIncome);
    printf(" \n taxable group   = %c  \n ", group);
    printf(" \n Tax Owed    = %f \n " , taxOwed);
}

int main (void) {
    getInput(&income,&deduction);
    // the income that will be taxed 
    taxableIncome = computeTaxableIncome(income, deduction);

    // tax bracket that you belong too 
    group = taxGroup(taxableIncome);

    //tax rate that you will pay 
    taxOwed = computeTaxOwed(group); 
    
    display();

}
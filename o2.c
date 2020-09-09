#include <stdio.h>

#define FEET_PRESS 33.0 
#define MAXPARTIALPRESSUREOXYGEN 1.4
#define CONTINGENCYPARTIALPRESSURE 1.6


int main (void) {
    // find out how deep the dive in ft..int
    // get the 02 pressure from the user and feet
    int depth = 0; 
    int o2 = 0;

    printf(" Enter depth and percentage o2   : ");  
    scanf(" %d  %d", &depth, &o2);
    
    // compute the am bient pressure = depth / FEET.PRESS + 1  
    float ambPress; 
    ambPress = (float) (depth / FEET_PRESS) + 1;
    printf(" \n Ambient Pressure    : %f \n ", ambPress);

    // compute the partial pressure of o2 =  (oxygen / 100) x ambPress....
    float partialPressure; 
    partialPressure = ((float) o2) / 100 * ambPress; 
    printf(" \n o2(partial pressure)     : %f \n ", partialPressure);

    // compute the the oxygren pressure group...from A to Z...letters repretsent the partial pressure group
    char oxygenGroup;
    oxygenGroup = (char)(((int)(partialPressure * 10))  + 65);
    // print the letter the group belongs too 
    printf ("\n o2 group  : %c \n ", oxygenGroup); 



    if ( partialPressure > MAXPARTIALPRESSUREOXYGEN) {
        printf("\n Exceeds maximal pressure:\t   true \n " );
    } else {
        printf (" \n Exceeds maximal pressure:\t  false \n "); 
    }

    if (partialPressure > CONTINGENCYPARTIALPRESSURE ) {
        printf(" Exceeds contigency o2 pressure : true \n ");
    } else {
        printf( " \n Exceeds contigency o2 pressure : false \n "); 
    }

    return 1; 


    
    
} 







#include <stdio.h>
#include <stdlib.h> 

// integer pointer 
int ptr; 

// array of 5 integers 
int arr[5]; 

// array of five pointers to int 
int *ptrArray[5]; 


void Intialization() {
    // intialize the int arr to five random integers 
    for ( int i = 0; i < 5; i++) {
        arr[i] = rand(); 
    }
    // initalize ptrArray to point to arr
    for ( int i = 0; i < 5; i++) {
        // pointing to the int array
        ptrArray[i] = arr[i]; 
    }
}

void printArray() {
    for ( int i = 0 ; i < 5; i++) {
        printf("  %d \n  %d \n ",i,arr[i]); 
    }
}

// function to print ptrArray 

void printPointer() {
    for ( int i = 0 ; i < 5; i++) {
        // need to access the ptrArray[i]
        printf( " %d \n %d \n ", i, *(ptrArray + i )); 
    }
}

void swap ( int *xp , int *yp) {
    int temp; 
    temp = *xp;
    *xp = *yp; 
    *yp = temp;  

}

void bubbleSortArray() {
    int temp; 
    // this for loop is for walking through the array
    for ( int i = 0; i < 5 - 1 ; i++) {
        // this for loop is for comparison
        for ( int j = 0; j < 5 - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j]; 
                arr[j] = arr[j+1];
                arr[j+1] = temp; 
            }
        }
    }
}

void bubbleSortPoint() {
    for ( int i = 0; i < 5 - 1; i++) {
        for ( int j = 0; j < 5 - i - 1; j++) {
            // accessing the element the ptrArray[j] and ptrArray[j+1] is pointing to
            if(*(ptrArray + j) > *(ptrArray + j + 1 )) {
                swap(ptrArray + j, ptrArray + j + 1); 
            }

        }
    }
}

int main (void) {
    Intialization(); 
    printf(" ---Initalized array of integers ---- \n");
    printArray(); 

    bubbleSortPoint();
    printf(" ----- Sorted array of pointers ----- \n"); 
    printPointer();


    bubbleSortArray(); 
    printf("---- sorted array of integers ------ \n");
    printArray();

    printf(" -----Array of pointers ----- \n ");
    printPointer();
}



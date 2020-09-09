#include <stdio.h> 
#include <stdlib.h> 
#include<string.h> 

typedef char String[128]; 

typedef enum {mammal, insect, bird, fish} TypeofSpecie; 

typedef struct {
    TypeofSpecie type;
    double size;
    String name; 
} Animal; 

TypeofSpecie getType(String type) {
    if (!strcmp(type, "mammal"))
    {
        return mammal;
    }
    else if (!strcmp(type, "insect"))
    {
        return insect;
    }
    else if (!strcmp(type, "bird"))
    {
        return bird;
    }
    else if (!strcmp(type, "fish"))
    {
        return fish;
    }
    else
    {
        printf("Wrong Animal Type.\n");
        exit(1);
    }
}


int enterAnimalInfo( Animal *temp) {
    String type; 

    printf(" Enter animal information (\"exit\" to exit: \n" ); 
    
    printf(" What is the name : "); 
    // store in Animal *temp -> name "->" for pointers
    scanf( "%s" ,temp->name); 

    // check to see if the user exit...if not continue
    if(!strcmp(temp->name,"exit")) {
        return 0; 
    }

    // need to store at the address at temp->size
    printf( "WHat is the size: " ); 
    scanf("%s" , &temp->size); 

    // Use type String  --- to find my enum type {}
    printf("What is the type: "); 
    scanf("%s" ,type);

    // I have a specified TypeSpecie enum{} so the user can't just put whichever..
    temp->type = getType(type); 

    return 1; 

}

char *getString(TypeofSpecie type)
{
    switch (type)
    {
    case mammal:
        return "mammal";
    case insect:
        return "insect";
    case bird:
        return "bird";
    case fish:
        return "fish";
    default:
        return "error";
    }
}

void print(Animal **temp, int size) {
    printf(" The follwing new species were found: \n ");
    // trasnfer teh data..temporary at the specfic index
    Animal *tempDirectory; 
    for ( int i = 0; i < size; i++) {
        tempDirectory = * ( temp + i); 
        printf(" %-20s has a size of %5.2f and is a %s \n" ,tempDirectory->name,tempDirectory->size, getString(tempDirectory->type));
    }
}



int main (void) {
    // initial array of size 1...index[0]
    int size = 1; 
    int index = -1; 

    // malloc() for an inital array of size 1... array of type Animal
    Animal ** discover = malloc(sizeof(Animal*)); 

    while(1) {
        // create a temp ptrArray....this array needs to be of Animal type...keep data integrity
        Animal * temp = malloc(sizeof(Animal*)); 
    
        // check if nothing is in *temp 
        if ( temp == NULL) {
            printf(" Can't allocate "); 
            return - 1; 
        }
        
        if (++index >= size ) {
            // keep track of size
            size = size * 2;
            // need to resize **discover to hold the new data entry and keep existing data...realloc()
            discover = realloc(discover, size * sizeof(Animal*)); 
                if (*discover == NULL) {
                    printf(" cant't allocate ");
                    exit (-1); 
                }
        }

        if(!enterAnimalInfo(temp)) {
            break;
        } else {
            *(discover + index ) = temp; 
        }

    }
    print(discover, index); 

    return 0; 

    
}




// prompts the user to enter a setnence....capture the setence need typedef 

#include<stdio.h>
#include<stdlib.h> 

// char phraseArray [1000 index]...indexed from 0 to 999....string of characters....global variable 
char phrase [1000] = "";

// function needs to output the string without whitespaces
void outputWithoutWhitespace()
{
    // create a temp array to store the string without whitespace
    char tempArr[1000] = "";
    // need index to keep track of tempArr
    int j = 0;
    // need index to keep track of phrase array
    int i;

    for (i = 0; i < 1000; i++)
    {
        // if phrase[i] is not a whitespace store the index value at tempArr...if it is a whitespace goes back to for loop tp increment i
        if (phrase[i] != ' ')
        {
            tempArr[j] = phrase[i];
            j = j + 1;
        }
    }
    printf(" String with no whitespace: %s ", tempArr);
}

int main(void) {
    printf(" Enter a sentence or phrase: \n");
    // capturing the input as a string...storing into the char aray phrase
    fgets(phrase, sizeof(phrase), stdin);
    // output the string...stdout(printf)
    printf("You entered :  %s ", phrase);
    int numChars = getNumOfChars();
    printf(" The number of characters: %d \n ", numChars);
    outputWithoutWhitespace();
    
}



/*
    function needs to output the number of characters in the string
        return: numnber of characters in the user string....use for loop
*/
int getNumOfChars() {
    // program already has the string in the phrase array....because it's a global variable 
    int i ; 
    for ( int i = 0; i < 1000; i++) {
        if (phrase[i] == '\0') {
            return i - 1; 
        }   
    }
    return 0; 
}






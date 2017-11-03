/***
*
*   HexCalc
*   This program will take a user input decimal interger and output the hexadecimal conversion of said interger.
*
*   Made by Tyler Christensen
***/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getUserInput();

char convertHex(int decInput, char *pHex);

int main(){
    int i;
    char *hexOut;
    hexOut = malloc(sizeof(char) * 8);

    //ask for user input
    i = getUserInput();
    while (i == 0){
        printf("\nTry again.\n");
        i = getUserInput();
    }
    
    //convert user input into hexadecimal
    convertHex(i, hexOut);

    //display user input
    printf("\nThe hexadecimal conversion of %d is: %s", i, hexOut);

    free(hexOut);

    return 0;
}

int getUserInput(){
    char *pInt;
    pInt = malloc(sizeof(int) * 8);
    int userInt;

    printf("Enter a non-zero interger: ");
    fgets(pInt, 10, stdin);

    if(atoi(pInt) != 0){
        userInt = atoi(pInt);
    }else{
        printf("\n\nIntergers are whole numbers....\n");
        userInt = 0;
    }

    free(pInt);

    return userInt;
}

char convertHex(int decInput, char *pHex){
    char *result;
    result = malloc(sizeof(char) * 8);

    //calculations
    itoa(decInput, result, 16);
    strcpy(pHex, result);

    free(result);
}
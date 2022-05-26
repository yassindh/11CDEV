//
// Created by Yassin on 26/05/2022.
//


#include <stdio.h>
#include "Fonction.h"

void userChoice()
{
    printf("Select a direction (N, S, E, W).\n Cancel the previous move(B).\n");
    printf("Erase the chain (R).\n Restart the level (X).\n");
    printf("Select another chain (C)\n");
}

void printGrid(char **level){
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            printf("%c ", level[i][j]);
        }
        printf("\n");
    }
}
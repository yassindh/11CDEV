//
// Created by Yassin on 26/05/2022.
//


#include <stdio.h>
#include <stdbool.h>
#include "Fonction.h"
#include "Level.h"

void userChoice()
{
    printf("Select a direction (N, S, E, W).\n Cancel the previous move(B).\n");
    printf("Erase the chain (R).\n Restart the level (X).\n");
    printf("Select another chain (C)\n");
}

void printGrid(levelt level){
    for(int i=0; i<level.height; i++) {
        for(int j=0; j<level.width; j++) {
            printf("%c ", level.grid[i][j]);
        }
        printf("\n");
    }
}

void findStart(levelt level){
    for(int i=0; i<level.height; i++) {
        for(int j=0; j<level.width; j++) {
            if(level.grid[i][j] == 'x'){
                positionx = i;
                positiony = j;
            }
        }
    }
}

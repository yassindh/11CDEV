//
// Created by Yassin on 26/05/2022.
//


#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include <stdlib.h>
#include "Fonction.h"
#include "Level.h"
#include "constVar.h"

void userChoice(){
    printf("Select a direction (N, S, E, W).\n Cancel the previous move(B).\n");
    printf("Erase the chain (R).\n Restart the level (X).\n");
    printf("Select another chain (C)\n");
}

void printGrid(levelt level){
    for(int i=0; i<level.height; i++) {
        for(int j=0; j<level.width; j++) {
            if (level.grid[i][j].state == -1){
                colorChain(12,0);
                printf("%c ", 'x');
                colorChain(15,0);
            }
            else if (level.grid[i][j].state == 0){
                printf("%c ", ' ');
            }
            else if (level.grid[i][j].state == 1 && level.grid[i][j].place == 1){
                colorChain(12,0);
                printf("%c ", '1');
                colorChain(15,0);
            }
            else if (level.grid[i][j].state == 1){
                printf("%c ", '1');
            }
        }
        printf("\n");
    }
}

int findStart(levelt *level, int startPos[][2]){
    int index = 0 ;
    for(int i=0; i<level->height; i++) {
        for(int j=0; j<level->width; j++) {
            if(level->grid[i][j].state == -1){
                startPos[index][0] = j ;
                startPos[index][1] = i ;
                level->grid[i][j].place = index + 1;
                index ++;
            }
        }
    }
    return index;
}

bool again(levelt level){
    for(int i=0; i<level.height; i++) {
        for(int j=0; j<level.width; j++) {
            if (level.grid[i][j].place == 0 && level.grid[i][j].state != 0){
                return true;
            }
        }
    }
    return false;
}


void colorChain(int t,int f){
    HANDLE H= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,f*16+t);
}

void eraseChain(levelt *level, int chain){
    for(int i=0; i<level->height; i++) {
        for(int j=0; j<level->width; j++) {
            if(level->grid[i][j].place == chain +1){
                level->grid[i][j].place = 0;
                level->grid[i][j].PreviousDir = 0 ;
            }
        }
    }
}

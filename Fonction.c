#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include "Fonction.h"
#include "Level.h"

void userChoice(){
    printf("Select a direction (N, S, E, W).\n Cancel the previous move(B).\n");
    printf("Erase the chain (R).\n Restart the level (X).\n");
    printf("Select another chain (C)\n");
}

void printGrid(levelt level){
    for(int i=0; i<level.height; i++) {
        for(int j=0; j<level.width; j++) {
            if (level.grid[i][j].state == -1){
                colorChain(level.grid[i][j].place,0);
                printf(" x ");
            }
            else if (level.grid[i][j].state == 0){
                printf("   ");
            }
            else if (level.grid[i][j].state > 0){
                colorChain(level.grid[i][j].place == 0 ? 15 : level.grid[i][j].place,0);
                printf(" %d ",level.grid[i][j].state);
                colorChain(15,0);
            }
            else {
                colorChain(15,0);
                printf(" %d ", level.grid[i][j].state);
            }
        }
        printf("\n");
    }
    userChoice();
}

int findStart(levelt *level, int startPos[][2]){
    int index = 0 ;
    for(int i=0; i<level->height; i++) {
        for(int j=0; j<level->width; j++) {
            if(level->grid[i][j].state == -1){
                startPos[index][0] = i ;
                startPos[index][1] = j ;
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

bool possible( cases currentCase, cases nextCase){
    return nextCase.place == 0 && nextCase.state != 0 && currentCase.state <= nextCase.state ;
}

void colorChain(int t,int f){
    HANDLE H= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,f*16+t);
}

void eraseChain(levelt *level, int chain, char direction, int startPos[][2]) {
    if (direction == Erase) {
        for (int i = 0; i < level->height; i++) {
            for (int j = 0; j < level->width; j++) {
                if (level->grid[i][j].place == chain + 1 && level->grid[i][j].state != -1) {
                    level->grid[i][j].place = 0;
                    level->grid[i][j].PreviousDir = 0;
                }
                else if(level->grid[i][j].place == chain + 1 && level->grid[i][j].state == -1){
                    startPos[chain][0] = i;
                    startPos[chain][1] = j;
                }
            }
        }
    }
}
void resetLevel(levelt *level,int startPos[][2], char direction,levelt test[],int indexLevel){
    if (direction == Reset){
        *level = test[indexLevel];
        findStart(level,startPos);
    }
}

void changeChain(char direction, int *chain, int numberChain) {
    if (direction == OtherChain) {
        if (*chain == numberChain - 1) {
            *chain = 0;
        } else {
            (*chain)++;
        }
    }
}

void prevMouve(levelt *level, int startPos[][2], int chain, char direction){
    if(direction == PreviousMove){
        if (level->grid[startPos[chain][0]][startPos[chain][1]].PreviousDir == East.direction && level->grid[startPos[chain][0]][startPos[chain][1]].place == chain + 1){
            level->grid[startPos[chain][0]][startPos[chain][1]].place = 0;
            startPos[chain][1] -= East.action;
        }
        else if (level->grid[startPos[chain][0]][startPos[chain][1]].PreviousDir == West.direction && level->grid[startPos[chain][0]][startPos[chain][1]].place == chain + 1){
            level->grid[startPos[chain][0]][startPos[chain][1]].place = 0;
            startPos[chain][1] -= West.action;
        }
        else if (level->grid[startPos[chain][0]][startPos[chain][1]].PreviousDir == South.direction && level->grid[startPos[chain][0]][startPos[chain][1]].place == chain + 1){
            level->grid[startPos[chain][0]][startPos[chain][1]].place = 0;
            startPos[chain][0] -= South.action;
        }
        else if (level->grid[startPos[chain][0]][startPos[chain][1]].PreviousDir == North.direction && level->grid[startPos[chain][0]][startPos[chain][1]].place == 1){
            level->grid[startPos[chain][0]][startPos[chain][1]].place = 0;
            startPos[chain][0] -= North.action;
        }
    }
}

void mouv(levelt *level, char direction, int chain, int startPos[][2]){
    if (direction == East.direction && possible(level->grid[startPos[chain][0]][startPos[chain][1]],level->grid[startPos[chain][0]][startPos[chain][1]+1])){
        startPos[chain][1] += East.action;
        level->grid[startPos[chain][0]][startPos[chain][1]].PreviousDir = East.direction;
        level->grid[startPos[chain][0]][startPos[chain][1]].place = chain + 1;
    }
    else if(direction == South.direction && possible(level->grid[startPos[chain][0]][startPos[chain][1]],level->grid[startPos[chain][0]+1][startPos[chain][1]])){
        startPos[chain][0] += South.action;
        level->grid[startPos[chain][0]][startPos[chain][1]].PreviousDir = South.direction;
        level->grid[startPos[chain][0]][startPos[chain][1]].place = chain + 1;
    }
    else if(direction == North.direction && possible(level->grid[startPos[chain][0]][startPos[chain][1]],level->grid[startPos[chain][0]-1][startPos[chain][1]])){
        startPos[chain][0] += North.action;
        level->grid[startPos[chain][0]][startPos[chain][1]].PreviousDir = North.direction;
        level->grid[startPos[chain][0]][startPos[chain][1]].place = chain + 1;
    }
    else if(direction == West.direction && possible(level->grid[startPos[chain][0]][startPos[chain][1]],level->grid[startPos[chain][0]][startPos[chain][1]-1])){
        startPos[chain][1] += West.action;
        level->grid[startPos[chain][0]][startPos[chain][1]].PreviousDir = West.direction;
        level->grid[startPos[chain][0]][startPos[chain][1]].place = chain + 1;
    }
}


#include <stdio.h>
#include "Level.h"
#include "Fonction.h"
#include "constVar.h"



int main()
{
    char previousCase;
    char direction[2];
    int startPos[10][2];
    int chain = 0 ;
    levelt levelt;
    levelt = level10;
    printGrid(levelt);
    userChoice();
    int numberChain = findStart(&levelt, startPos);
    while(again(levelt)){
        scanf("%s", direction);
        if (direction[0] == East.direction && possible(levelt.grid[startPos[chain][0]][startPos[chain][1]],levelt.grid[startPos[chain][0]][startPos[chain][1]+1])){
            startPos[chain][1] += East.action;
            levelt.grid[startPos[chain][0]][startPos[chain][1]].PreviousDir = East.direction;
            levelt.grid[startPos[chain][0]][startPos[chain][1]].place = chain + 1;
        }
        else if(direction[0] == South.direction && possible(levelt.grid[startPos[chain][0]][startPos[chain][1]],levelt.grid[startPos[chain][0]+1][startPos[chain][1]])){
            startPos[chain][0] += South.action;
            levelt.grid[startPos[chain][0]][startPos[chain][1]].PreviousDir = South.direction;
            levelt.grid[startPos[chain][0]][startPos[chain][1]].place = chain + 1;
        }
        else if(direction[0] == North.direction && possible(levelt.grid[startPos[chain][0]][startPos[chain][1]],levelt.grid[startPos[chain][0]-1][startPos[chain][1]])){
            startPos[chain][0] += North.action;
            levelt.grid[startPos[chain][0]][startPos[chain][1]].PreviousDir = North.direction;
            levelt.grid[startPos[chain][0]][startPos[chain][1]].place = chain + 1;
        }
        else if(direction[0] == West.direction && possible(levelt.grid[startPos[chain][0]][startPos[chain][1]],levelt.grid[startPos[chain][0]][startPos[chain][1]-1])){
            startPos[chain][1] += West.action;
            levelt.grid[startPos[chain][0]][startPos[chain][1]].PreviousDir = West.direction;
            levelt.grid[startPos[chain][0]][startPos[chain][1]].place = chain + 1;
        }
        char previousDirection = direction[0];
        if(direction[0] == Reset){
            levelt = level21;
            findStart(&levelt,startPos);
        }
        if(direction[0] == PreviousMove){
            if (levelt.grid[startPos[chain][0]][startPos[chain][1]].PreviousDir == East.direction && levelt.grid[startPos[chain][0]][startPos[chain][1]].place == chain + 1){
                levelt.grid[startPos[chain][0]][startPos[chain][1]].place = 0;
                startPos[chain][1] -= East.action;
            }
            else if (levelt.grid[startPos[chain][0]][startPos[chain][1]].PreviousDir == West.direction && levelt.grid[startPos[chain][0]][startPos[chain][1]].place == chain + 1){
                levelt.grid[startPos[chain][0]][startPos[chain][1]].place = 0;
                startPos[chain][1] -= West.action;
            }
            else if (levelt.grid[startPos[chain][0]][startPos[chain][1]].PreviousDir == South.direction && levelt.grid[startPos[chain][0]][startPos[chain][1]].place == chain + 1){
                levelt.grid[startPos[chain][0]][startPos[chain][1]].place = 0;
                startPos[chain][0] -= South.action;
            }
            else if (levelt.grid[startPos[chain][0]][startPos[chain][1]].PreviousDir == North.direction && levelt.grid[startPos[chain][0]][startPos[chain][1]].place == 1){
                levelt.grid[startPos[chain][0]][startPos[chain][1]].place = 0;
                startPos[chain][0] -= North.action;
            }
        }
        if (direction[0] == OtherChain){
            if (chain == numberChain-1){
                chain = 0;
            }
            else{
                chain++;
            }
        }
        if (direction[0] == Erase){
            eraseChain(&levelt,chain);
            findStart(&levelt,startPos);
        }
        printGrid(levelt);
    }
    return 0;
}

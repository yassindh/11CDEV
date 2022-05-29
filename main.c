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
    levelt levelt10;
    levelt10 = level21;
    printGrid(levelt10);
    userChoice();
    int numberChain = findStart(&levelt10, startPos);
    while(again(levelt10)){
        scanf("%s", direction);
        if (direction[0] == East.direction && possible(levelt10.grid[startPos[chain][0]][startPos[chain][1]],levelt10.grid[startPos[chain][0]][startPos[chain][1]+1])){
            startPos[chain][1] += East.action;
            levelt10.grid[startPos[chain][0]][startPos[chain][1]].PreviousDir = East.direction;
            levelt10.grid[startPos[chain][0]][startPos[chain][1]].place = 1;
        }
        else if(direction[0] == South.direction && possible(levelt10.grid[startPos[chain][0]][startPos[chain][1]],levelt10.grid[startPos[chain][0]+1][startPos[chain][1]])){
            startPos[chain][0] += South.action;
            levelt10.grid[startPos[chain][0]][startPos[chain][1]].PreviousDir = South.direction;
            levelt10.grid[startPos[chain][0]][startPos[chain][1]].place = 1;
        }
        else if(direction[0] == North.direction && possible(levelt10.grid[startPos[chain][0]][startPos[chain][1]],levelt10.grid[startPos[chain][0]-1][startPos[chain][1]])){
            startPos[chain][0] += North.action;
            levelt10.grid[startPos[chain][0]][startPos[chain][1]].PreviousDir = North.direction;
            levelt10.grid[startPos[chain][0]][startPos[chain][1]].place = 1;
        }
        else if(direction[0] == West.direction && possible(levelt10.grid[startPos[chain][0]][startPos[chain][1]],levelt10.grid[startPos[chain][0]][startPos[chain][1]-1])){
            startPos[chain][1] += West.action;
            levelt10.grid[startPos[chain][0]][startPos[chain][1]].PreviousDir = West.direction;
            levelt10.grid[startPos[chain][0]][startPos[chain][1]].place = 1;
        }
        char previousDirection = direction[0];
        if(direction[0] == Reset){
            levelt10 = level21;
            findStart(&levelt10,startPos);
        }
        if(direction[0] == PreviousMove){
            if (levelt10.grid[startPos[chain][0]][startPos[chain][1]].PreviousDir == East.direction && levelt10.grid[startPos[chain][0]][startPos[chain][1]].place == 1){
                levelt10.grid[startPos[chain][0]][startPos[chain][1]].place = 0;
                startPos[chain][1] -= East.action;
            }
            else if (levelt10.grid[startPos[chain][0]][startPos[chain][1]].PreviousDir == West.direction && levelt10.grid[startPos[chain][0]][startPos[chain][1]].place == 1){
                levelt10.grid[startPos[chain][0]][startPos[chain][1]].place = 0;
                startPos[chain][1] -= West.action;
            }
            else if (levelt10.grid[startPos[chain][0]][startPos[chain][1]].PreviousDir == South.direction && levelt10.grid[startPos[chain][0]][startPos[chain][1]].place == 1){
                levelt10.grid[startPos[chain][0]][startPos[chain][1]].place = 0;
                startPos[chain][0] -= South.action;
            }
            else if (levelt10.grid[startPos[chain][0]][startPos[chain][1]].PreviousDir == North.direction && levelt10.grid[startPos[chain][0]][startPos[chain][1]].place == 1){
                levelt10.grid[startPos[chain][0]][startPos[chain][1]].place = 0;
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
        printGrid(levelt10);

        }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Level.h"
#include "Fonction.h"



int main()
{
    char direction[2];
    printGrid(level2);
    userChoice();
    findStart(level2);
    while(again(level2)){
        printf(" une direction: \n");
        scanf("%s", direction);
        if (direction[0] == East && level2.grid[positionx][positiony+1].state == 1) {
            positiony += 1;
            level2.grid[positionx][positiony].place = 1;
        }
        else if(direction[0] == South && level2.grid[positionx+1][positiony].state == 1){
            positionx += 1;
            level2.grid[positionx][positiony].place = 1;
        }
        else if(direction[0] == North && level2.grid[positionx-1][positiony].state == 1){
            positionx -= 1;
            level2.grid[positionx][positiony].place = 1;
        }
        else if(direction[0] == West && level2.grid[positionx][positiony-1].state ==  1){
            positiony -= 1;
            level2.grid[positionx][positiony].place = 1;
        }
        printGrid(level2);
    }


    return 0;
}

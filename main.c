#include <stdio.h>
#include "Level.h"
#include "Fonction.h"
#include <stdlib.h>


int main() {
    levelt test[] = {level10,level9};
    int indexLevel = 0;
    char direction[2];
    int startPos[10][2];
    int chain = 0;
    levelt leveltemp;
    leveltemp = test[indexLevel];
    findStart(&leveltemp, startPos);
    printGrid(leveltemp);
    int numberChain = findStart(&leveltemp, startPos);
    while(indexLevel<= 30){
        while (again(leveltemp)) {
            scanf("%s", direction);
            mouv(&leveltemp, direction[0], chain, startPos);
            resetLevel(&leveltemp, startPos, direction[0], test, indexLevel);
            prevMouve(&leveltemp, startPos, chain, direction[0]);
            changeChain(direction[0], &chain, numberChain);
            eraseChain(&leveltemp, chain, direction[0], startPos);
            system("cls");
            printGrid(leveltemp);
        }
    indexLevel++;
    }
    return 0;
}
#include <stdio.h>
#include "Fonction.h"
#include "Level.h"
#include <stdlib.h>


int main() {
    levelt test[] = {level1, level2,level3,level4,level5,level6,level7,level8,level9,level10,level11,level12,level13,level14,level15,level16,level17,level18,level19,level20,level21,level22,level23,level24,level25,level26,level27,level28,level29,level30};
    int indexLevel = 0;
    char direction[2];
    int startPos[10][2];
    int chain = 0;
    levelt leveltemp;
    while(indexLevel< 30){
        leveltemp = test[indexLevel];
        findStart(&leveltemp, startPos);
        printGrid(leveltemp);
        int numberChain = findStart(&leveltemp, startPos);
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
    system("cls");
    indexLevel++;
    }
    return 0;
}
//
// Created by Yassin on 26/05/2022.
//

#ifndef INC_1CDEV_FONCTION_H
#define INC_1CDEV_FONCTION_H
#include <stdbool.h>
#include "Level.h"
void userChoice();
void printGrid(levelt level);
int findStart(levelt *level, int startPos[][2]);
bool again(levelt level);
void colorChain(int t,int f);
bool possible( cases currentCase, cases nextCase);
void eraseChain(levelt *level, int chain);
#endif //INC_1CDEV_FONCTION_H

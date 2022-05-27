//
// Created by Yassin on 26/05/2022.
//

#ifndef INC_1CDEV_FONCTION_H
#define INC_1CDEV_FONCTION_H
#include <stdbool.h>
#include "Level.h"
void userChoice();
void printGrid(levelt level);
void findStart(levelt level);
bool again(levelt level);
void colorChain(int t,int f);
bool possible(levelt level, int i, int j);
#endif //INC_1CDEV_FONCTION_H

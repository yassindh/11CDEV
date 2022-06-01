#ifndef INC_1CDEV_FONCTION_H
#define INC_1CDEV_FONCTION_H
#define Reset 'x'
#define PreviousMove 'b'
#define Erase 'r'
#define OtherChain 'c'
#include <stdbool.h>
#include "Level.h"
void userChoice();
void printGrid(levelt level);
int findStart(levelt *level, int startPos[][2]);
bool again(levelt level);
void colorChain(int t,int f);
bool possible( cases currentCase, cases nextCase);
void eraseChain(levelt *level, int chain, char direction, int startPos[][2]);
void resetLevel(levelt *level,int startPos[][2], char direction,levelt test[],int indexLevel);
void changeChain(char direction, int *chain, int numberChain);
void prevMouve(levelt *level, int startPos[][2], int chain, char direction);
void mouv(levelt *level, char direction, int chain, int startPos[][2]);
#endif //INC_1CDEV_FONCTION_H
//
// Created by Yassin on 26/05/2022.
//

#include <stdbool.h>
#ifndef INC_1CDEV_LEVEL_H
#define INC_1CDEV_LEVEL_H

typedef struct {
    int state;
    int place;
    char PreviousDir;
}cases;

typedef struct {
    cases grid[10][10];
    int width;
    int height;
}levelt;

typedef struct{
    char direction;
    int action;
}cardinal;


extern levelt level1;
extern levelt level2;
extern int positionx;
extern int positiony;

#endif //INC_1CDEV_LEVEL_H

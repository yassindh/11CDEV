//
// Created by Yassin on 26/05/2022.
//

#include <stdbool.h>
#ifndef INC_1CDEV_LEVEL_H
#define INC_1CDEV_LEVEL_H
#define East 'e'
#define North 'n'
#define South 's'
#define West 'w'
#define Reset 'x'

typedef struct {
    int state;
    int place;
}cases;

typedef struct {
    cases grid[10][10];
    int width;
    int height;
}levelt;


extern levelt level1;
extern levelt level2;
extern int positionx;
extern int positiony;

#endif //INC_1CDEV_LEVEL_H

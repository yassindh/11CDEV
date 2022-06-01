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

extern levelt level2;
extern levelt level9;
extern levelt level10;
extern cardinal South;
extern cardinal North;
extern cardinal West;
extern cardinal East;
#endif //INC_1CDEV_LEVEL_H

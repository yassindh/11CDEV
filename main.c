#include <stdio.h>


void userChoice()
{
    printf("Select a direction (N, S, E, W).\n Cancel the previous move(B).\n");
    printf("Erase the chain (R).\n Restart the level (X).\n");
    printf("Select another chain (C)\n");

}

int main()
{
    char direction;
    char arr[5][5] = {{'x','1','1','1',' '},
                     {' ',' ',' ','1',' '},
                     {' ','1','1','1',' '},
                     {' ','1',' ',' ','1'},
                     {' ','1','1','1','1'}
    };
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
    userChoice();
    int positionx = 0;
    int positiony = 0;
    char East = 'e';
    char West = 'w';
    char North = 'n';
    char South = 's';
    for(int k=0; k<30; ++k){
        printf(" une direction: \n");
        scanf("%c", &direction);
        if (direction == East && arr[positionx][positiony+1] == '1') {
            positiony += 1;
            arr[positionx][positiony] = '*';
        }
        else if(direction == South && arr[positionx+1][positiony] == '1'){
            positionx += 1;
            arr[positionx][positiony] = '*';
        }
        else if(direction == North && arr[positionx-1][positiony] == '1'){
            positionx -= 1;
            arr[positionx][positiony] = '*';
        }
        else if(direction == West && arr[positionx][positiony-1] == '1'){
            positiony -= 1;
            arr[positionx][positiony] = '*';
        }
        for(int i=0; i<5; i++) {
            for(int j=0; j<5; j++) {
                printf("%c ", arr[i][j]);
            }
            printf("\n");
        }
    }


    return 0;
}

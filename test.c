#include <stdio.h>

typedef struct
{
   int posisiR;
   int posisiC; /* data */
}square;

square board[8][8];

board [1][1] = {2,3};

int main()
{
    printf("%d %d",&board[1][1].posisiR,&board[1][1].posisiC);
}
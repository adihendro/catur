#include <stdio.h>

typedef struct
{
   int posisiR;
   int posisiC; /* data */
}square;

int main()
{
square board[8][8];
board[1][1].posisiC = 5;
    printf("%d %d\n",board[1][1].posisiC,board[1][1].posisiR);
}
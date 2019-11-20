#include "boolean.h"
#include "tipe_bentukan.h"

boolean adaorang(papan *board[10][10], int y, int x){
    return((*board[x][y]).nama != ' ');
}
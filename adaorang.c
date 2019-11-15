#include "boolean.h"
#include "tipe_bentukan.h"
#include "listlinier.h"

boolean adaorang(papan board[10][10], int y, int x){
    if (board[x][y].nama != ' '){
        return true;
    } else {
        return false;
    }
}
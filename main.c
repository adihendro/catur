#include <stdio.h>
#include "fungsi.h"
#include "tipe_bentukan.h"

int main(){
    papan board[10][10];

    start();
    PrintPapan(board);

    printf("Masukkan command: ");
    scanf("%s",command);

    switch (command){
    case "MOVE":
        /* code */
        break;
    default:
        //command salah
        break;
    }


    return 0;
}
#include <stdio.h>
#include <string.h>
#include "tipe_bentukan.h"

#include "start.c"
#include "inisialisasi.c"
#include "print_papan.c"
#include "listlinier.c"
#include "listposisi.c"
#include "stack.c"
#include "queue.c"
#include "move.c"


int main(){
    // for(i=1;i<=8;i++){
    //     for(j=1;j<=8;j++){
    //         board[i][j].nama = ' ';
    //     }
    // }

    // board[1][1].nama = 'P';
    // board[1][1].player = 1;

    // board[1][2].nama = 'P';
    // board[1][2].player = 2;

    // board[1][3].nama = ' ';
    // board[1][3].player = 1;

    // board[2][1].nama = ' ';
    // board[2][1].player = 1;

    board[6][1].nama = ' ';
    // board[2][3].player = 1;
    
    board[6][2].nama = ' ';
    // board[3][1].player = 2;

    board[6][3].nama = ' ';
    // board[3][2].player = 2;

    board[5][2].nama = ' ';
    // board[3][3].player = 1;




    //GAME START 
    start();
    inisialisasi();

    papan *board2[10][10];
    for(int i=0;i<=10;i++){
        for(int j=0;j<=10;j++){
            board2[i][j] = &board[i][j];
        }
    }


    do{
        PrintPapan(board2);

        do{
            go=false;
            printf("Masukkan command: ");
            scanf("%s",command);
            if((strcmp(command,"MOVE") == 0) || (strcmp(command,"SPECIAL_MOVE") == 0) ||
            (strcmp(command,"UNDO") == 0) || (strcmp(command,"SAVE") == 0)){
                go=true;
            } else{
                printf("Command salah!\n\n");
            }
        } while(!go);

    
        if(strcmp(command,"MOVE") == 0){
            move(board2, &history, &termakan, &poin_putih, &poin_hitam, &list_ada_putih, &list_ada_hitam, giliransiapa);
        }
        else if(strcmp(command,"SPECIAL_MOVE") == 0){
        
        }
        else if(strcmp(command,"UNDO") == 0){
            
        }
        else if(strcmp(command,"SAVE") == 0){
            
        }

        printf("\n\n");
    } while(1);


    return 0;
}

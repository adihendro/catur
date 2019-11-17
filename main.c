#include <stdio.h>
#include <string.h>
#include "fungsi.h"

#include "start.c"
#include "print_papan.c"
#include "listlinier.c"
#include "listposisi.c"
#include "stack.c"
#include "queue.c"


int main(){
    // F.nama = 'K';
    // F.poin = 1; //putih
    // F.player = 1;
    // F.posisiR = 2;
    // F.posisiC = 2;

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

    // board[2][3].nama = 'Q';
    // board[2][3].player = 1;
    
    // board[3][1].nama = 'P';
    // board[3][1].player = 2;

    // board[3][2].nama = ' ';
    // board[3][2].player = 2;

    // board[3][3].nama = ' ';
    // board[3][3].player = 1;

    CreateEmpty_stack(&history);
    CreateEmpty_stack(&termakan);
    CreateEmpty_list(&list_ada_putih);
    CreateEmpty_list(&list_ada_hitam);
    CreateEmpty_queue(&giliransiapa, 1);
    poin_putih=0;
    poin_hitam=0;




    //GAME START
    start();

    do{
        printf("Your choice: ");
        scanf("%d",&choice);
        if(!(choice==1 || choice==2 || choice==3))
            printf("WRONG! It's must be a number from 1-3!\n\n");
    } while(!(choice==1 || choice==2 || choice==3));

    printf("\n\n\n");
    PrintPapan(board);

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

    papan *board2[10][10];
    for(int i=0;i<=10;i++){
        for(int j=0;j<=10;j++){
            board2[i][j] = &board[i][j];
        }
    }

    if(strcmp(command,"MOVE") == 0){
        move(board2, &history, &termakan, &poin_putih, &poin_hitam, &list_ada_putih, &list_ada_hitam, giliransiapa);
    }



    return 0;
}

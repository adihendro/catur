#include <stdio.h>
#include "tipe_bentukan.h"
#include "stack.h"
#include "ada_orang.c"

void specialmove(piece P)
{
    if(canCastle())
    {
        Castling();
    }

    promotion(P);
}

piece promotion(piece P)
{
    int n;

    if(((P.posisiR == 2) && (P.player == 1)) || ((P.posisiR == 7) && (P.player == 2)))
    {
        printf("\nPion telah mencapai ujung\n");
        printf("Terjadi special move promosi\n");
        
        printf("   1. Queen (Q)\n");
        printf("   2. Bishop (B)\n");
        printf("   3. Knight (N)\n");
        printf("   4. Rook (R)\n");

        printf("Masukkan nomor perwira yang hendak dipilih: ");
        
        do{
            scanf("%d", &n);
        } while(n<1 || n>4);

        if(n == 1){
            P.nama = 'Q';
            P.poin = 8;
        } else if (n == 2){
            P.nama = 'B';
            P.poin = 4;
        } else if(n == 3){
            P.nama = 'N';
            P.poin = 2;
        } else if(n == 4){
            P.nama = 'R';
            P.poin = 4;
        }
    }
    return P;
}

void enPassant(piece P, stack* history)
{
  //  if (TOP(history) = );

}
/*

boolean HasMoved(piece P, stack history)
{
    int counter = 1;
    boolean Moved = false;

    infotype_stack X;
    
    while ((!Moved) && (counter < (history.T[(history).TOP].turn))){   
        X = (history).T[(history).TOP];
        history.TOP--;
    
        if (X.nama == P.nama){
            Moved = true;
        }

       counter++;
    }

    return Moved;
}

void Castling(piece Raja, piece Benteng , stack history, papan* board[10][10])
{
    if (!(HasMoved(Raja,history)))
    {
        if (((*board[Raja.posisiR][Raja.posisiC+2]).nama == ' ') && ((*board[Raja.posisiR][Raja.posisiC+1]).nama == ' ') && (!(HasMoved(Benteng, history))))
        {
            (*board[Raja.posisiR][Raja.posisiC+2]).nama == ' ';
        }
    }
*/
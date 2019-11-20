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

void promotion(piece P)
{
    int n = 0;

    if((P.posisiR == 8) && (P.player == 2)){
        printf("1. Queen (Q)");
        printf("2. Bishop (B)");
        printf("3. Knight (N)");
        printf("4. Rook (R)");

        printf("Masukkan nomor perwira yang hendak dipilih: ");
        
        while(n < 1 && n > 4)
            scanf("%d", &n);
        

        if((n == 1)){
            P.nama = "Q";
            P.poin = 8;
        } else if (n==2){
            P.nama = "B";
            P.poin = 4;
        } else if(n == 3){
            P.nama = "N";
            P.poin = 2;
        } else if(n == 4){
            P.nama = "R";
            P.poin = 4;
        }
    }

    else if((P.posisiR == 1) && (P.player == 1))
    {
        printf("1. Queen (Q)");
        printf("2. Bishop (B)");
        printf("3. Knight (N)");
        printf("4. Rook (R)");

        printf("Masukkan nomor perwira yang hendak dipilih: ");
        
        while(n < 1 && n>4)
            scanf("%d", &n);
        

        if((n == 1)){
            P.nama = "Q";
            P.poin = 8;
        } else if (n==2){
            P.nama = "B";
            P.poin = 4;
        } else if(n == 3){
            P.nama = "N";
            P.poin = 2;
        } else if(n == 4){
            P.nama = "R";
            P.poin = 4;
        }
    }
}

void enPassant(piece P, stack* history)
{
  //  if (TOP(history) = );

}


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

#include <stdio.h>
#include <stdlib.h>
#include "tipe_bentukan.h"
#include "stack.h"
#include "threaten.c"
#include "move.c"

piece board[10][10];

void specialmove()
{
    if(canCastle)
    {
        Castling()
    }

void promotion(piece P)
{
    int n = 0;

    if((P.posisiR == 8) && (P.player == 2))
    {
        printf("1. Queen (Q)");
        printf("2. Bishop (B)");
        printf("3. Knight (N)");
        printf("4. Rook (R)");

        printf("Masukkan nomor perwira yang hendak dipilih: ");
        
        while(n < 1 && n > 4)
        {
            scanf("%d", &n);
        }
        

        if((n == 1))
        {
            P.nama = "Q";
            P.poin = 8;
        }

        else if (n==2)
        {
            P.nama = "B";
            P.poin = 4;
        }

        else if(n == 3)
        {
            P.nama = "N";
            P.poin = 2;
        }

        else if(n == 4)
        {
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
        {
            scanf("%d", &n);
        }
        

        if((n == 1))
        {
            P.nama = "Q";
            P.poin = 8;
        }

        else if (n==2)
        {
            P.nama = "B";
            P.poin = 4;
        }

        else if(n == 3)
        {
            P.nama = "N";
            P.poin = 2;
        }

        else if(n == 4)
        {
            P.nama = "R";
            P.poin = 4;
        }
    }
}



#include "headerCekSemuaGerak.h"
#include <stdio.h>

piece board[10][10];
piece bidak;

void ConstructBoard(char nama, int player, int poin, int posisiR, int posisiC)
{
    board[posisiR][posisiC].nama = nama;
    board[posisiR][posisiC].player = player;
    board[posisiR][posisiC].poin = poin;
    board[posisiR][posisiC].posisiC = posisiC;
    board[posisiR][posisiR].posisiR = posisiR;
}

void ConstructBidak(piece bidak, char nama, int player, int poin, int posisiR, int posisiC)
{
    bidak.nama = nama;
    bidak.player = player;
    bidak.poin = poin;
    bidak.posisiC = posisiC;
    bidak.posisiR = posisiR;
}


int main()
{
    piece bidak;
    
    ConstructBidak(bidak,"P",1,1,7,3);

    ConstructBoard("P",1,1,7,1);
    ConstructBoard("P",1,1,7,2);
    ConstructBoard(" ",1,1,7,4);

    if(Timur(bidak).nama == " ")
    {
        printf("Kosong");
    }


   


    return 0;
}
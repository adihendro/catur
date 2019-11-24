#include "tipe_bentukan.h"

boolean isskak(list lawan, list kawan, papan *board[10][10], address_list *K, address_list *P1, int *jml);

//kalau bidak ini pindah apakah bakal jadi skak?
boolean jadi_skak(list lawan, list kawan, papan *board[10][10], piece F, int posisiR, int posisiC){
    papan board3[10][10];
    papan *board4[10][10];
     
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            board3[i][j] = *board[i][j];
        }
    }

    //kotak asal piece dikosongin 
    board3[F.posisiR][F.posisiC].nama = ' ';
    board3[F.posisiR][F.posisiC].player = 0;

    //piece "dipindahkan"
    board3[posisiR][posisiC].nama = F.nama;
    board3[posisiR][posisiC].player = F.player;

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            board4[i][j] = &board3[i][j];
        }
    }

    return (isskak(lawan, kawan, board4, &K, &P1, &jml));
}
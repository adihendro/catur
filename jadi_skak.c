#include "tipe_bentukan.h"

boolean isskak(list lawan, list kawan, papan *board[10][10], address_list *K, address_list *P1, int *jml);

//kalau bidak ini pindah apakah bakal jadi skak?
boolean jadi_skak(list lawan, list kawan, papan *board[10][10], piece F, int posisiR, int posisiC){
    address_list P, P1, P2, K1;
    boolean jadi;
    int tempR, tempC;
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

    if(F.nama == 'K'){ //kalau bidaknya king
        K1 = First(kawan);
        while ((K1!=Nil_list) && (Info(K1).nama!='K'))
            K1 = Next(K1);
            //K1 udah menunjuk ke alamat King
        tempC = Info(K1).posisiC;
        tempR = Info(K1).posisiR;
        Info(K1).posisiC = posisiC;
        Info(K1).posisiR = posisiR;
    }

    if(adaorang(lawan, posisiC, posisiR, &P1, &P2)){ //kalau di kotak itu ada musuh
        P = Next(P1);
        DelAfter(&lawan, &P, P1); // hapus bidak lawan dari list linier lawan 

        jadi = isskak(lawan, kawan, board4, &K, &P1, &jml);
        InsertAfter(&lawan, P, P1);

    } else{
        jadi = isskak(lawan, kawan, board4, &K, &P1, &jml);
    }

    if(F.nama == 'K'){ //kalau bidaknya king
        Info(K1).posisiC = tempC;
        Info(K1).posisiR = tempR;
    }

    return jadi;
}
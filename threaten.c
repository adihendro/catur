#include "listlinier.h"
#include "listposisi.h"
#include "tipe_bentukan.h"

boolean isthreaten(list lawan, int x, int y, papan *board[10][10]){ //mengefound apakah suatu spot berbahaya untuk raja
    list_posisi dftr_posisi;
    address_posisi R;
    address_list P; 
    boolean found = false;
    P = First(lawan);
    CreateEmpty_posisi(&dftr_posisi);
    while (P!=Nil_list && found!=false){
        ceksemuagerak(Info(P), board, dftr_posisi);
        R = First(dftr_posisi);
        while (R!=Nil_list && found!=false){
            if((Info(R).posisiC==x)&&(Info(R).posisiR==y)){
                found = true;
            }
            R = Next(R);
        }
        P=Next(P);
    }
    return found;
}

boolean skak(list lawan, list kawan, papan *board[10][10]){
    address_list K;
    K = First(kawan);
    while (Info(K).nama!='K'||K!=Nil_list){
        K = Next(K);
    }
    return (isthreaten(lawan, Info(K).posisiC, Info(K).posisiR, board));
}

boolean skakmat(list kawan, list lawan, papan *board[10][10]){
    int i;
    int j;
    address_list K;
    boolean cek = false;
    K = First(kawan);
    for (i=-1;i<=1;i++){
        for (j=-1;j<=1;j++){

        }
    }
}
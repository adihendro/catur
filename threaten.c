#include "listlinier.h"
#include "listposisi.h"

boolean isthreaten(list lawan, list_posisi daftar_posisi, int x, int y, papan board[10][10]){ //mengecek apakah suatu spot berbahaya untuk raja
    address_list P; 
    address_posisi R;
    boolean cek = false;
    P = First(lawan);
    CreateEmpty_posisi(&daftar_posisi);
    while (P!=Nil && cek!=false){
        ceksemuagerak(Info(P), board, daftar_posisi);
        R = First(daftar_posisi);
        while (R!=Nil && cek!=false){
            if((Info(R).posisiC==x)&&(Info(R).posisiR==y)){
                cek = true;
            }
            R = Next(R);
        }
        P=Next(P);
    }
    return cek;
}


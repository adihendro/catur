#include "listlinier.h"
#include "listposisi.h"
#include "tipe_bentukan.h"

boolean isthreaten(list lawan, list_posisi daftar_posisi, int x, int y, papan board[10][10]){ 
    //mengefound apakah suatu spot berbahaya untuk raja
    address_list P; 
    address_posisi R;
    boolean found = false;
    P = First(lawan);
    CreateEmpty_posisi(&daftar_posisi);
    while (P!=Nil_list && found!=false){
        ceksemuagerak(Info(P), board, daftar_posisi);
        R = First(daftar_posisi);
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


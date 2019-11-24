#include "tipe_bentukan.h"

boolean isthreaten(list lawan, int x, int y, papan *board[10][10], address_list *P1, int *jml){ 
    //mengefound apakah suatu spot berbahaya untuk raja
    list_posisi dftr_posisi;
    address_posisi R;
    address_list P;
    boolean found = false;
    (*jml)=0; //inisialisasi awal jml
    P = First(lawan);

    while (P!=Nil_list && (*jml)<=1){
        CreateEmpty_posisi(&dftr_posisi);
        ceksemuagerak(Info(P), board, &dftr_posisi); //menyimpan semua gerakan yang mungkin dari bidak lawan
        R = First(dftr_posisi);

        while (R!=Nil_list && (*jml)<=1){
            if((Info(R).posisiC==x)&&(Info(R).posisiR==y)){
                found = true;
                (*jml)++;
                *P1 = P;
            }
            R = Next(R);
        }

        P = Next(P);
    }
    return found;
}

boolean isskak(list lawan, list kawan, papan *board[10][10], address_list *K, address_list *P1, int *jml){
    *K = First(kawan);
    while ((*K!=Nil_list) && (Info(*K).nama!='K')){
        *K = Next(*K);
    }
    return (isthreaten(lawan, Info(*K).posisiC, Info(*K).posisiR, board, P1, jml));
}













/*

boolean isthreaten(list lawan, int x, int y, papan *board[10][10]){ //mengefound apakah suatu spot berbahaya untuk raja
    list_posisi list_jalur_ancaman;
    address_posisi R;
    address_list P;
    boolean found = false;
    P = First(lawan);
    while (P!=Nil_list && !found){
        CreateEmpty_posisi(&dftr_posisi);
        ceksemuagerak(Info(P), board, &dftr_posisi); //menyimpan semua gerakan yang mungkin dari bidak lawan
        R = First(dftr_posisi);
        while (R!=Nil_list && !found){
            if((Info(R).posisiC==x)&&(Info(R).posisiR==y)){
                found = true;
            }
            R = Next(R);
        }
        P=Next(P);
    }
    return found;
}









boolean skakmat(list kawan, list lawan, papan *board[10][10]){
    address_list K;
    address_list P;
    list_posisi posisi_raja;
    boolean cek = true;
    K = First(kawan);
    while (Info(K).nama!='K' && K!=Nil_list){
        K = Next(K);
    }
    CreateEmpty_posisi(&posisi_raja);
    ceksemuagerak(Info(K), board, &posisi_raja);
    P = First(posisi_raja);
    while (cek && P!=Nil_list){
        if (isthreaten(lawan, Info(P).posisiC, Info(P).posisiR, board)){
            P = Next(P);
        } else {
            cek = false;
        }
    }
    return cek;
}
*/
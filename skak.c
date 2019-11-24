#include "tipe_bentukan.h"
#include "threaten.c"


void cekskak(){
    if(!isskak(lawan, kawan, board)){ //raja tidak skak
        ceksemuagerak(Info(P), board, &dftr_posisi);
        if(IsEmpty_list(dftr_posisi)){ //raja ga bisa gerak
            cekbisagerak();
            ceksemuagerak()
            if(IsEmpty_list(dftr_posisi)){  //bidak temen ga bisa gerak
                //stalemate
            }
        }
        //cek jangan ada yg skak

    } else{ //raja lagi skak
        ceksemuagerak(Info(P), board, &dftr_posisi); //cek semua gerakan raja
        if(IsEmpty_list(dftr_posisi)){ //raja ga bisa gerak
            //bidak temen bisa makan/nutupin?
        }

    }
}


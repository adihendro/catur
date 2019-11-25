#include "tipe_bentukan.h"

#include "threaten.c"

void gerakaman(list kawan, list lawan, papan *board[10][10], list *list_bisa_gerak, int *jml_bs_grk, boolean *endgame){
    address_list P, R, R1;
    address_posisi Q, PrecQ;
    // lihat bidak yang masih ada di papan dari list linier dan memasukkan ke list_bisa_gerak
    P = First(kawan);
    CreateEmpty_list(list_bisa_gerak);
    *jml_bs_grk = 0;
    while (P != Nil_list) {
        if (cekbisagerak(Info(P), board)) { //Info(P) == piece
            InsVFirst(list_bisa_gerak, Info(P)); //dari list kawan dimasukkin ke list_bisa_gerak

            R = First(*list_bisa_gerak); //list_linier yg bisa gerak dari kawan
            
            CreateEmpty_posisi(&Gerakan(R));
            ceksemuagerak(Info(R), board, &Gerakan(R));

            Q = First(Gerakan(R)); //list_posisi gerakan yang bisa dilakukan piece kawan
            PrecQ = Q;

            while (Q != Nil_list){ //cek semua gerakan bidak tersebut, bikin skak atau tidak
                if(jadi_skak(lawan, kawan, board, Info(R), Info(Q).posisiR, Info(Q).posisiC)){

                    if(Q == First(Gerakan(R))){ //jika elemen gerakan pertama
                        DelFirst_posisi(&Gerakan(R),&Q);
                    } else{ //bukan elemen gerakan pertama
                        DelAfter_posisi(&Gerakan(R),&Q,PrecQ);
                    }
                }
                PrecQ = Q;
                Q = Next(Q);
            }

            if(IsEmpty_posisi(Gerakan(R))){ //kalo bidak tsb ga bisa gerak karena bikin skak
                DelFirst(list_bisa_gerak, &R1); //maka didelete
                (*jml_bs_grk)--;
            }

            (*jml_bs_grk)++;
        }
        P = Next(P);
    }
    if(IsEmpty_list(*list_bisa_gerak)){ //kalo ga ada bidak yg bisa gerak
        //berarti STALEMATE atau CHECKMATE
        *endgame = true;
    } else{
        *endgame = false;
    }

}


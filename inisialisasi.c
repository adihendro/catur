#include "tipe_bentukan.h"

piece bidak;
list L;

void construct(char nama, int player, int poin, int posisiR, int posisiC, list *L){
    bidak.nama = nama;
    bidak.player = player;
    bidak.poin = poin;
    bidak.posisiR = posisiR;
    bidak.posisiC = posisiC;
    InsVFirst(L,bidak);
}

void inisialisasi(){
    CreateEmpty_stack(&history);
    CreateEmpty_stack(&termakan);
    CreateEmpty_list(&list_ada_putih);
    CreateEmpty_list(&list_ada_hitam);
    CreateEmpty_queue(&giliransiapa, 2);
    Add (&giliransiapa, 1); //giliran pertama putih (1)
    poin_putih=0;
    poin_hitam=0;

    construct('P', 1, 1, 7, 2, &list_ada_putih); //pion putih


    construct('Q', 2, 8, 1, 4, &list_ada_hitam); //ratu hitam






    printf("\n\n\n");
}
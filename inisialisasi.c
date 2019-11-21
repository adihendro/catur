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
    CreateEmpty_queue(&giliran, 2);
    Add(&giliran, 1); //giliran pertama putih (1)
    poin_putih=0;
    poin_hitam=0;

    construct('P', 1, 1, 7, 1, &list_ada_putih); //pion putih
    construct('P', 1, 1, 7, 2, &list_ada_putih); //pion putih
    construct('P', 1, 1, 7, 3, &list_ada_putih); //pion putih
    construct('P', 1, 1, 7, 4, &list_ada_putih); //pion putih
    construct('P', 1, 1, 7, 5, &list_ada_putih); //pion putih
    construct('P', 1, 1, 7, 6, &list_ada_putih); //pion putih
    construct('P', 1, 1, 7, 7, &list_ada_putih); //pion putih
    construct('P', 1, 1, 7, 8, &list_ada_putih); //pion putih

    construct('K', 1, 10, 8, 5, &list_ada_putih); //raja putih
    construct('Q', 1, 8, 8, 4, &list_ada_putih); //ratu putih
    construct('B', 1, 4, 8, 3, &list_ada_putih); //menteri putih
    construct('B', 1, 4, 8, 6, &list_ada_putih); //menteri putih
    construct('R', 1, 4, 8, 1, &list_ada_putih); //benteng putih
    construct('R', 1, 4, 8, 8, &list_ada_putih); //benteng putih
    construct('N', 1, 2, 8, 2, &list_ada_putih); //kuda putih
    construct('N', 1, 2, 8, 7, &list_ada_putih); //kuda putih


    construct('P', 2, 1, 2, 1, &list_ada_hitam); //pion hitam
    construct('P', 2, 1, 2, 2, &list_ada_hitam); //pion hitam
    construct('P', 2, 1, 2, 3, &list_ada_hitam); //pion hitam
    construct('P', 2, 1, 2, 4, &list_ada_hitam); //pion hitam
    construct('P', 2, 1, 2, 5, &list_ada_hitam); //pion hitam
    construct('P', 2, 1, 2, 6, &list_ada_hitam); //pion hitam
    construct('P', 2, 1, 2, 7, &list_ada_hitam); //pion hitam
    construct('P', 2, 1, 2, 8, &list_ada_hitam); //pion hitam

    construct('K', 2, 10, 1, 5, &list_ada_hitam); //raja hitam
    construct('Q', 2, 8, 1, 4, &list_ada_hitam); //ratu hitam
    construct('B', 2, 4, 1, 3, &list_ada_hitam); //menteri hitam
    construct('B', 2, 4, 1, 6, &list_ada_hitam); //menteri hitam
    construct('R', 2, 4, 1, 1, &list_ada_hitam); //benteng hitam
    construct('R', 2, 4, 1, 8, &list_ada_hitam); //benteng hitam
    construct('N', 2, 2, 1, 2, &list_ada_hitam); //kuda hitam
    construct('N', 2, 2, 1, 7, &list_ada_hitam); //kuda hitam

}


void updateboard(papan *board[10][10], list list_ada_putih, list list_ada_hitam){
    for(i=0;i<=9;i=i+9){
        for(j=0;j<=9;j++){
            (*board[i][j]).nama = '*';
        }
    }
    for(i=0;i<=9;i=i+9){
        for(j=1;j<=8;j++){
            (*board[j][i]).nama = '*';
        }
    }

    for(i=1;i<=8;i++){
        for(j=1;j<=8;j++){
            (*board[i][j]).nama = ' ';
        }
    }

    address_list P;
    P = First(list_ada_putih);
    while(P != Nil_list) {
        (*board[Info(P).posisiR][Info(P).posisiC]).nama = Info(P).nama;
        (*board[Info(P).posisiR][Info(P).posisiC]).player = Info(P).player;
        P = Next(P);
    }
    P = First(list_ada_hitam);
    while(P != Nil_list) {
        (*board[Info(P).posisiR][Info(P).posisiC]).nama = Info(P).nama;
        (*board[Info(P).posisiR][Info(P).posisiC]).player = Info(P).player;
        P = Next(P);
    }
}
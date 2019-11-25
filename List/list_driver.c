#include "..//ProgramUtama//tipe_bentukan.h"
#include "listlinier.c"

piece bidak;

//fungsi buat ngebentuk isi list
void construct(char nama, int player, int poin, int posisiR, int posisiC, list *L){
    bidak.nama = nama;
    bidak.player = player;
    bidak.poin = poin;
    bidak.posisiR = posisiR;
    bidak.posisiC = posisiC;
    InsVFirst(L,bidak);
}

//driver list
int main(){
    //deklarasi awal list dan address
    list list_ada_putih, list_ada_hitam;
    address_list P;

    //buat list kosong
    CreateEmpty_list(&list_ada_putih);
    CreateEmpty_list(&list_ada_hitam);

    //cek kosong atau ga
    if(IsEmpty_list(list_ada_hitam))
        printf("kosong\n\n");
    else
        printf("ada isinya\n\n");


    //isi ke list
    construct('P', 1, 1, 7, 1, &list_ada_putih); //pion putih
    construct('K', 1, 10, 8, 5, &list_ada_putih); //raja putih
    construct('Q', 1, 8, 8, 4, &list_ada_putih); //ratu putih
    construct('B', 1, 4, 8, 6, &list_ada_putih); //menteri putih

    construct('P', 2, 1, 2, 8, &list_ada_hitam); //pion hitam
    construct('K', 2, 10, 1, 5, &list_ada_hitam); //raja hitam
    construct('Q', 2, 8, 1, 4, &list_ada_hitam); //ratu hitam
    construct('B', 2, 4, 1, 6, &list_ada_hitam); //menteri hitam
    construct('R', 2, 4, 1, 1, &list_ada_hitam); //benteng hitam

    //cek kosong atau ga
    if(IsEmpty_list(list_ada_hitam))
        printf("kosong\n");
    else
        printf("ada isinya\n");

    //lihat jumlah elemen list
    printf("jumlah elemen %d\n\n", NbElmt (list_ada_hitam));

    //print isi list
    P = First(list_ada_putih);
    while(P != Nil_list){
        printf("Nama piece %c, pemain %d, poin %d.\n", Info(P).nama, Info(P).player, Info(P).poin);
        P = Next(P);
    }

    //hapus elemen terakhir
    DelLast (&list_ada_putih, &P);

    //terus diinvers
    InversList (&list_ada_putih);

    printf("\n");

    //print isi list
    P = First(list_ada_putih);
    while(P != Nil_list){
        printf("Nama piece %c, pemain %d, poin %d.\n", Info(P).nama, Info(P).player, Info(P).poin);
        P = Next(P);
    }


    return 0;
}
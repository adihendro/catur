#include <stdio.h>

#include "fungsi.h"
#include "print_semua.c"

// #include "cek_semua_gerak.c"
// #include "cek_bisa_gerak.c"


void move(papan *board[10][10], stack *history, stack *termakan, int *poin_putih, int *poin_hitam, list *list_ada_putih, list *list_ada_hitam, queue giliransiapa) {
    // papan board2[10][10];
    // stack history2;
    // stack termakan2;
    // termakan2 = *termakan;
    // history2 = *history;
    // for(int i=0;i<=10;i++){
    //     for(int j=0;j<=10;j++){
    //         board2[i][j] = *board[i][j];
    //     }
    // }

    // cek giliran hitam atau putih untuk menentukan list linier yang akan diakses, cek dari queue
    list kawan; //list piece apa yg ada di papan
    list lawan;
    int poin;

    CreateEmpty_list(&kawan);
    if (Head(giliransiapa) == 1) { //putih
        kawan = *list_ada_putih; //piece yg masih ada di papan
        lawan = *list_ada_hitam;
        poin = *poin_putih;
    }
    else { //giliransiapa == 2, hitam
        kawan = *list_ada_hitam;
        lawan = *list_ada_putih;
        poin = *poin_hitam;
    }
    
    // lihat bidak yang masih ada di papan dari list linier dan memasukkan ke list_bisa_gerak
    list list_bisa_gerak; //ditunjuk pake R
    CreateEmpty_list(&list_bisa_gerak);
    address_list P;
    P = First(kawan);
    while (P != Nil_list) {
        if (cekbisagerak(Info(P), board)) { //Info(P) == piece
            InsVLast(&list_bisa_gerak, Info(P)); //reborn tambahin reborn
        }
    }
        
    // tampilkan bidak yang dapat bergerak
    address_list R;
    R = First(list_bisa_gerak);
    int i = 1;  
    printf("Daftar bidak yang bisa bergerak:\n");
    while (R != Nil_list) {
        printf("  %d. ", i);
        i++;
        PrintNamaBidak(Info(R).nama);
        printf(" (");
        PrintKolom(Info(R).posisiC);
        printf(",");
        PrintBaris(Info(R).posisiR);
        printf(")\n");
        R = Next(R);
    }

    // user input nomor bidak yang ingin digerakkan
    printf("Pilih bidak yang ingin digerakkan: ");
    int input_nomor_bidak;
    scanf("%d",&input_nomor_bidak);
    // cari list linier dengan indeks ke input_nomor_bidak
    R = First(list_bisa_gerak);
    i = 1;
    while (i < input_nomor_bidak) {
        R = Next(R);
        i++;
    } // R sudah menunjukkan address bidak yang ingin diganti posisinya
    

    // pertama-tama buat list posisi yang mungkin dijalani
    list_posisi daftar_posisi;
    CreateEmpty_posisi(&daftar_posisi);
    // cari semua posisi tujuan yang mungkin dari bidak itu dan masukkan ke daftar_posisi
    ceksemuagerak(Info(R), board, &daftar_posisi); //Info(R) == piece
    
    // print daftar pilihan posisi yang mungkin
    address_posisi Q;
    i = 1;
    Q = First(daftar_posisi);
    while(Q != Nil_list) {
        printf("  %d. (", i);
        i++;
        PrintKolom(Info(Q).posisiC);
        printf(", ");
        PrintBaris(Info(R).posisiR);
        printf(")\n");
        Q = Next(Q);
    }

    // user memilih posisi tujuan bidak
    int input_pilihan_posisi;
    printf("Pilih posisi tujuan bidak: ");
    scanf("%d",&input_pilihan_posisi);
    i = 1;
    // Q akan pergi ke bidak yang dimaksud
    Q = First(daftar_posisi);
    while (i < input_pilihan_posisi){
        Q = Next(Q);
        i++;
    }
    // Q sudah menunjukkan pilihan posisi bidak yang ingin dituju


    // lakukan fungsi swap
    infotype_stack X;
    
    if (adaorang(lawan, board, Info(Q).posisiC, Info(Q).posisiR)) { //cek apakah ada bidak lawan
        address_list A, A1;
        A1 = Search(lawan, Info(Q).posisiC, Info(Q).posisiR); //address sebelum bidak lawan yang termakan
        A = Next(A1); //address bidak lawan yang termakan
        poin += Info(A).poin;

        //stack
        X.nama = Info_stack(A).nama;
        X.player = (Head(giliransiapa) % 2) + 1;
        // X.turn = turn;
        X.posisiR = Info_stack(Q).posisiR;
        X.posisiC = Info_stack(Q).posisiC;
        Push(termakan, X); //masukkan ke stack termakan

        //list
        DelAfter(&lawan, &A, A1); // hapus bidak lawan dari list linier lawan 
    }

    int tempR;
    int tempC;
    Parent(R)=P;
    // simpan nilai awal pada temp
    tempR = Info(Parent(R)).posisiR; //R adalah bidak yang ingin digerakkan
    tempC = Info(Parent(R)).posisiC;
    // update nilai awal menjadi nilai akhir
    Info(Parent(R)).posisiR = Info(Q).posisiR;
    Info(Parent(R)).posisiC = Info(Q).posisiC;

    // update stack dengan posisi bidak terbaru
    X.nama = Info(R).nama;
    X.player = Head(giliransiapa);
    // X.turn = turn;
    X.posisiR = tempR;
    X.posisiC = tempC;

    Push(history, X);


    // simpan kembali datanya ke variabel global
    if (Head(giliransiapa) == 1) { //putih
        *list_ada_putih = kawan;
        *list_ada_hitam = lawan;
        *poin_putih = poin;
    }
    else { //giliransiapa == 2, hitam
        *list_ada_hitam = kawan;
        *list_ada_putih = lawan;
        *poin_hitam = poin;
    }
    // *board = board2;
    // *history = history2;
    // *termakan = termakan2;
 
}


int main(){
    move(board, &history, &termakan, &poin_putih, &poin_hitam, &list_ada_putih, &list_ada_hitam, giliransiapa);
    return 0;
}
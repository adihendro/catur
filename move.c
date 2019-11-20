#include <stdio.h>
#include "tipe_bentukan.h"

#include "print_semua.c"
#include "ada_orang.c"
#include "cek_semua_gerak.c"
#include "cek_bisa_gerak.c"


void move(papan *board[10][10], stack *history, stack *termakan, int *poin_putih, int *poin_hitam, list *list_ada_putih, list *list_ada_hitam, queue *giliran) {
    // cek giliran hitam atau putih untuk menentukan list linier yang akan diakses, cek dari queue
    list kawan; //list piece apa yg ada di papan
    list lawan;
    int poin;
    static int turn = 0;

    CreateEmpty_list(&kawan);
    if (InfoTail(*giliran) == 1) { //putih
        kawan = *list_ada_putih; //piece yg masih ada di papan
        lawan = *list_ada_hitam;
        poin = *poin_putih;
    }
    else { //giliran == 2, hitam
        kawan = *list_ada_hitam;
        lawan = *list_ada_putih;
        poin = *poin_hitam;
    }
    
    // lihat bidak yang masih ada di papan dari list linier dan memasukkan ke list_bisa_gerak
    list list_bisa_gerak; //akan ditunjuk pake R
    CreateEmpty_list(&list_bisa_gerak);
    address_list P;
    P = First(kawan);

    while (P != Nil_list) {
        if (cekbisagerak(Info(P), board)) { //Info(P) == piece
            InsVLast(&list_bisa_gerak, Info(P)); //dari list kawan dimasukkin ke list_bisa_gerak
        }
        P = Next(P);
    }
        
    // tampilkan bidak yang dapat bergerak
    InversList(&list_bisa_gerak);
    address_list R;
    R = First(list_bisa_gerak);
    int i = 1;  
    printf("Daftar bidak yang bisa bergerak:\n");
    while (R != Nil_list) {
        printf("   %d. ", i);
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
    
    P = First(kawan);
    while((Info(P).posisiC != Info(R).posisiC) || (Info(P).posisiR != Info(R).posisiR)){
        P = Next(P);
    } // P sudah menunjukkan address bidak dari list_ada


    // pertama-tama buat list posisi yang mungkin dijalani
    list_posisi daftar_posisi;
    CreateEmpty_posisi(&daftar_posisi);

    // cari semua posisi tujuan yang mungkin dari bidak itu dan masukkan ke daftar_posisi
    ceksemuagerak(Info(R), board, &daftar_posisi); //Info(R) == piece
    
    // print daftar pilihan posisi yang mungkin
    address_posisi Q;
    i = 1;
    Q = First(daftar_posisi);
    printf("Daftar posisi tujuan ");
    PrintNamaBidak(Info(R).nama);
    printf(" yang mungkin:\n");
    while(Q != Nil_list) {
        printf("   %d. (", i);
        i++;
        PrintKolom(Info(Q).posisiC);
        printf(",");
        PrintBaris(Info(Q).posisiR);
        printf(")\n");
        Q = Next(Q);
    }

    // user memilih posisi tujuan bidak
    printf("Pilih posisi tujuan bidak: ");
    int input_pilihan_posisi;
    scanf("%d",&input_pilihan_posisi);
    // Q akan pergi ke bidak yang dimaksud
    Q = First(daftar_posisi);
    i = 1;
    while (i < input_pilihan_posisi){
        Q = Next(Q);
        i++;
    } // Q sudah menunjukkan pilihan posisi bidak yang ingin dituju


    //piece promotion
    if(Info(R).nama == 'P'){
        if (InfoTail(*giliran) == 1){ //putih
            if(Info(R).posisiR == 2){
                promotion(P);
            }
    }


    // lakukan fungsi swap
    infotype_stack X;
    
    if (adaorang(board, Info(Q).posisiC, Info(Q).posisiR)) { //cek apakah ada bidak lawan
        printf("MUSUHH\n");
        address_list A, A1;
        A1 = Search(lawan, Info(Q).posisiC, Info(Q).posisiR); //address sebelum bidak lawan yang termakan
        A = Next(A1); //address bidak lawan yang termakan
        poin += Info(A).poin;

        //stack
        X.nama = Info(A).nama;
        X.player = (InfoTail(*giliran) % 2) + 1; //lawan
        X.turn = turn;
        X.posisiR_lama = Info(R).posisiR;
        X.posisiC_lama = Info(R).posisiC;
        X.posisiR_baru = Info(Q).posisiR;
        X.posisiC_baru = Info(Q).posisiC;
        Push(termakan, X); //masukkan ke stack termakan

        //list
        DelAfter(&lawan, &A, A1); // hapus bidak lawan dari list linier lawan 
    }


    // update nilai awal di list_ada menjadi nilai akhir
    Info(P).posisiR = Info(Q).posisiR;
    Info(P).posisiC = Info(Q).posisiC;

    // update stack dengan posisi bidak terbaru
    X.nama = Info(R).nama;
    X.player = InfoTail(*giliran);
    X.turn = turn;
    X.posisiR_lama = Info(R).posisiR;
    X.posisiC_lama = Info(R).posisiC;
    X.posisiR_baru = Info(Q).posisiR;
    X.posisiC_baru = Info(Q).posisiC;
    Push(history, X);

    turn++;

    printf("Bidak ");
    PrintNamaBidak(Info(R).nama);
    printf(" telah berpindah dari (");
    PrintKolom(Info(R).posisiC);
    printf(",");
    PrintBaris(Info(R).posisiR);
    printf(") ke (");
    PrintKolom(Info(Q).posisiC);
    printf(",");
    PrintBaris(Info(Q).posisiR);
    printf(")\n");


    // simpan kembali datanya ke variabel global
    if (InfoTail(*giliran) == 1) { //putih
        *list_ada_putih = kawan;
        *list_ada_hitam = lawan;
        *poin_putih = poin;
        Add(giliran, 2);
    }
    else { //giliran == 2, hitam
        *list_ada_hitam = kawan;
        *list_ada_putih = lawan;
        *poin_hitam = poin;
        Add(giliran, 1);
    }
    
}
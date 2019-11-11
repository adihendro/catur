#include <stdio.h>
#include "cek_bisa_gerak.c"
#include "cekSemuaGerak.c"

void move(piece *board, stack *history, stack *termakan, int *poin_putih, int *poin_hitam, List *list_ada_putih, List *list_ada_hitam, Queue giliransiapa);

void move(piece *board, stack *history, stack *termakan, int *poin_putih, int *poin_hitam, List *list_ada_putih, List *list_ada_hitam, Queue giliransiapa) {
    piece board2;
    stack history2;
    stack termakan2;
    termakan2 = *termakan;
    history2 = *history;
    board2 = *board;
    // cek giliran hitam atau putih untuk menentukan list linier yang akan diakses, cek dari queue
    list giliran;
    list lawan;
    int poin;
    CreateEmpty(&giliran);
    if (Head(giliransiapa) == 1) {
        giliran = *list_ada_putih;
        lawan = *list_ada_hitam;
        poin = *poin_putih;
    }
    else {
        giliran = *list_ada_hitam;
        lawan = *list_ada_putih;
        poin = *poin_hitam;
    }
    // lihat bidak yang masih ada di papan dari list linier dan memasukkan ke list_bisa_gerak
    list list_bisa_gerak;
    CreateEmpty(&list_bisa_gerak);
    address P;
    P = First(giliran);
    while (P != Nil) {
        if (cekbisagerak(Info(P).nama , board2)) {
            InsVLast_reborn(&list_bisa_gerak , Info(P)); //reborn tambahin reborn
        }
    }
        
    // tampilkan bidak yang dapat bergerak
    address R;
    R = First(list_bisa_gerak);
    int i = 1;
    printf("Daftar bidak yang bisa bergerak:\n");
    while (R != Nil) {
        printf("  %d. ", i);
        i++;
        PrintNamaBidak(Info(R).nama);
        printf(" (");
        PrintKolom(Info(R).posisiC);
        printf(",%d)\n",Info(R).posisiR)
    }

    // di sini user input nomor bidak yang ingin dia gerakkan
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
    CreateEmpty(&daftar_posisi);
    // cari semua posisi tujuan yang mungkin dari bidak itu dan masukkan ke daftar_posisi
    ceksemuagerak(Info(R).nama , &daftar_posisi);
    
    // print daftar pilihan posisi yang mungkin
    // address Q;
    // i = 1;
    // Q = First(daftar_posisi);
    // while(Q != Nil) {
    //     printf("  %d. (", i);
    //     i++;
    //     PrintKolom(Info(Q).posisiC);
    //     printf(",%d)\n",Info(Q).posisiR)
    // }

    // user memilih posisi tujuan bidak
    int inputan_pilihan_posisi;
    printf("Pilih posisi tujuan bidak: ");
    scanf("%d",inputan_pilihan_posisi);
    address Q;
    i = 1;
    // Q akan pergi ke bidak yang dimaksud
    Q = First(daftar_posisi);
    while (i < inputan_pilihan_posisi) {
        Q = Next(Q);
        i++;
    }

    // Q sudah menunjukkan pilihan posisi bidak yang ingin dituju
    // lakukan fungsi swap
    infotype_stack X;
    if (adaorang(*board , Info(Q).posisiC , Info(Q).posisiR)) { //cek apakah ada bidak lawan
        address A;
        A = Search_reborn(lawan , Info(Q).posisiC , Info(Q).posisiR); //address bidak lawan yang termakan
        poin = poin + Info(A).poin;
        X.nama = Info(A).nama;
        X.player = (Head(giliransiapa) % 2) + 1;
        X.turn = turn;
        X.posisiR = Info(Q).posisiR;
        X.posisiC = Info(Q).posisiC;
        Push_reborn(&termakan , X); //masukkan ke stack termakan
        DelP_reborn(&lawan , Info(Q).posisiC , Info(Q).posisiR); // hapus bidak lawan dari list linier lawan 
    }
    int tempR;
    int tempC;
    // simpan nilai awal pada temp
    tempR = Info(Parent(R)).posisiR;
    tempC = Info(Parent(R)).posisiC;
    // update nilai awal menjadi nilai akhir
    Info(Parent(R)).posisiR = Info(Q).posisiR;
    Info(Parent(R)).posisiC = Info(Q).posisiC;
    // update stack dengan posisi bidak terbaru
    X.nama = Info(R).nama;
    X.player = Head(giliransiapa);
    X.turn = turn;
    X.posisiR = tempR;
    X.posisiC = tempC;
    Push_reborn(&history2 , X);

    // simpan kembali datanya ke variabel global
    if (Head(giliransiapa) == 1) {
        *list_ada_putih = giliran;
        *list_ada_hitam = lawan;
        *poin_putih = poin;
    }
    else {
        *list_ada_hitam = giliran;
        *list_ada_putih = lawan;
        *poin_hitam = poin;
    }
    *board = board2;
    *history = history2;
    *termakan = termakan2;
}

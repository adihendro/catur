#include "tipe_bentukan.h"

#include "print_semua.c"
#include "ada_orang.c"
#include "cek_semua_gerak.c"
#include "cek_bisa_gerak.c"

piece promotion(piece P, boolean *ispromoted);

void move(papan *board[10][10], stack *history, stack *termakan, int *poin_putih, int *poin_hitam, list *list_ada_putih, list *list_ada_hitam, queue *giliran, int turn) {
    // cek giliran hitam atau putih untuk menentukan list linier yang akan diakses, cek dari queue
    list kawan; //list piece apa yg ada di papan 
    list lawan;
    int poin;
    infotype_stack X;
    boolean ispromoted = false;
    boolean istwosteps = false;
    boolean enpassant = false;

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
    int jml_bs_grk = 0;
    P = First(kawan);
    while (P != Nil_list) {
        if (cekbisagerak(Info(P), board)) { //Info(P) == piece
            InsVLast(&list_bisa_gerak, Info(P)); //dari list kawan dimasukkin ke list_bisa_gerak
            jml_bs_grk ++;
        }
        P = Next(P);
    }
    // tampilkan bidak yang dapat bergerak
    InversList(&list_bisa_gerak);
    address_list R;
    R = First(list_bisa_gerak);
    int i = 1;  
    printf("\033[1;33m");
    printf("Daftar bidak yang bisa bergerak:\n");
    printf("\033[0m"); 
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
    int input1;
    int input2;
    int input_nomor_bidak;

    do{    //buat input yg baru diubah jadi ascii
        choice = (char*) malloc (sizeof(100));
        printf("\033[1;36m");
        printf("Pilih bidak yang ingin digerakkan: ");
        printf("\033[0m"); 
        scanf("%s",choice);
        stringToInt(choice, &input1);
        input_nomor_bidak = atoi(choice);
        if((!(49<=input1 && input1<=57)) || (input_nomor_bidak>jml_bs_grk))
            printf("Wrong input! Choose from the corresponding numbers above!\n\n");
    } while((!(49<=input1 && input1<=57)) || (input_nomor_bidak>jml_bs_grk));

    // cari list linier dengan indeks ke input_nomor_bidak
    R = First(list_bisa_gerak);
    i = 1;
    while (i < input_nomor_bidak) {
        R = Next(R);
        i++;
    } // R sudah menunjukkan address bidak yang ingin diganti posisinya
    
    P = First(kawan);
    while((Info(P).posisiC != Info(R).posisiC) || (Info(P).posisiR != Info(R).posisiR))
        P = Next(P);
    // P sudah menunjukkan address bidak dari list_ada


    // pertama-tama buat list posisi yang mungkin dijalani
    list_posisi daftar_posisi;
    CreateEmpty_posisi(&daftar_posisi);

    // cari semua posisi tujuan yang mungkin dari bidak itu dan masukkan ke daftar_posisi
    ceksemuagerak(Info(R), board, &daftar_posisi); //Info(R) == piece
    
    // print daftar pilihan posisi yang mungkin
    address_posisi Q;
    i = 1;
    Q = First(daftar_posisi);
    printf("\033[1;33m");
    printf("Daftar posisi tujuan ");
    PrintNamaBidak(Info(R).nama);
    printf(" yang mungkin:\n");
    printf("\033[0m");
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
    printf("\033[1;36m");
    printf("Pilih posisi tujuan bidak: ");
    printf("\033[0m");
    int input_pilihan_posisi;
    scanf("%d",&input_pilihan_posisi);
    // Q akan pergi ke bidak yang dimaksud
    Q = First(daftar_posisi);
    i = 1;
    while (i < input_pilihan_posisi){
        Q = Next(Q);
        i++;
    } // Q sudah menunjukkan pilihan posisi bidak yang ingin dituju


    if(Info(R).nama == 'P'){  //Info(R).nama selalu huruf kapital
        //piece promotion?
        Info(P)=Info(R)=promotion(Info(P), &ispromoted);
        //piece bisa en passant?
        if(abs(Info(R).posisiR-Info(Q).posisiR) == 2) //pion jalan dua kotak
            istwosteps=true;
    }
    X.promotion = ispromoted;
    X.twosteps = istwosteps;
    X.enpassant = enpassant;



    // lakukan fungsi swap
    if (adaorang(lawan, Info(Q).posisiC, Info(Q).posisiR)) { //cek apakah ada bidak lawan
        address_list A, A1;
        A1 = Search(lawan, Info(Q).posisiC, Info(Q).posisiR); //address sebelum bidak lawan yang termakan
        A = Next(A1); //address bidak lawan yang termakan
        poin += Info(A).poin;

        //stack
        X.nama = Info(A).nama; //bidak lawan yg termakan
        X.player = (InfoTail(*giliran) % 2) + 1; //lawan
        X.poin = Info(A).poin;
        X.turn = turn;
        X.posisiR_lama = X.posisiR_baru = Info(Q).posisiR;
        X.posisiC_lama = X.posisiC_baru = Info(Q).posisiC;
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
    X.poin = Info(R).poin;
    X.turn = turn;
    X.posisiR_lama = Info(R).posisiR;
    X.posisiC_lama = Info(R).posisiC;
    X.posisiR_baru = Info(Q).posisiR;
    X.posisiC_baru = Info(Q).posisiC;
    Push(history, X); //masukkan ke stack history

    printf("\nBidak ");
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




piece promotion(piece P, boolean *ispromoted)
{
    int n;
    *ispromoted = false;

    if(((P.posisiR == 2) && (P.player == 1)) || ((P.posisiR == 7) && (P.player == 2)))
    {
        printf("\nPion telah mencapai ujung\n");
        printf("Terjadi special move promosi\n");
        
        printf("   1. Ratu\n");
        printf("   2. Menteri\n");
        printf("   3. Kuda\n");
        printf("   4. Benteng\n");
        
        
        //printing
        int X;
        do{    
            choice = (char*) malloc (sizeof(100));
            printf("Masukkan nomor perwira yang hendak dipilih: ");
            scanf("%s",choice);
            stringToInt(choice,&X);
            n = atoi(choice);
            if(!(X==49 || X==50 || X==51 || X==52))//49 adalah ascii untuk 1, 50=2, 51=3, 52=4
                printf("Wrong input! It's must be a number from 1-4!\n\n");
        } while(!(X==49 || X==50 || X==51 || X==52));

        if(n == 1){
            P.nama = 'Q';
            P.poin = 8;
        } else if (n == 2){
            P.nama = 'B';
            P.poin = 4;
        } else if(n == 3){
            P.nama = 'N';
            P.poin = 2;
        } else if(n == 4){
            P.nama = 'R';
            P.poin = 4;
        }

        *ispromoted = true;
    }
    return P;
}
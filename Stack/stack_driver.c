#include <stdio.h>
#include <stdlib.h>
#include "..//ProgramUtama//tipe_bentukan.h"
#include "stack.c"
#include "..//List//listlinier.c"



int main () {
    // membuat stack kosong terlebih dahulu
    stack contoh_stack;
    CreateEmpty_stack(&contoh_stack);
    // cek apakah fungsi CreateEmpty_stack dan IsEmpty_stack selaras
    if (IsEmpty_stack(contoh_stack)) {
        printf("contoh_stack kosong\n");
    }
    else {
        printf("ternyata contoh_stack tidak kosong\n");
    }
    // memasukkan sebuah infotype_stack ke dalam stack
    infotype_stack masukan_stack;
    // berikan nilai masukan_stack
    masukan_stack.nama = 'P';
    masukan_stack.player = 1;
    masukan_stack.poin = 1;
    masukan_stack.turn = 3;
    masukan_stack.posisiR_lama = 7;
    masukan_stack.posisiC_lama = 2;
    masukan_stack.posisiR_baru = 5;
    masukan_stack.posisiC_baru = 2;
    masukan_stack.promotion = 0;
    masukan_stack.twosteps = 1;
    masukan_stack.enpassant = 0;
    Push(&contoh_stack,masukan_stack);
    printf("Contoh masukan : P,1,1,3,7,2,5,2,0,1,0\n");
    // sekarang kita akan Pop isi stack tersebut
    infotype_stack keluaran_stack;
    int to_int;
    int temp_input;
    printf("Keluaran : ");
    Pop(&contoh_stack,&keluaran_stack);
    printf("%c,",keluaran_stack.nama);
    printf("%d,",keluaran_stack.player);
    printf("%d,",keluaran_stack.poin);
    printf("%d,",keluaran_stack.turn);
    printf("%d,",keluaran_stack.posisiR_lama);
    printf("%d,",keluaran_stack.posisiC_lama);
    printf("%d,",keluaran_stack.posisiR_baru);
    printf("%d,",keluaran_stack.posisiC_baru);
    printf("%d,",keluaran_stack.promotion);
    printf("%d,",keluaran_stack.twosteps);
    printf("%d,",keluaran_stack.enpassant);
    printf("\n");
    return 0;
}
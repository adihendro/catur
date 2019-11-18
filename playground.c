// nama : nyoman kevin cahyadi giri
// nim : 18218001
// tanggal : 03 Oktober 2019
// topik : mesin kata
// deskripsi : menghitung biaya telegram

#include <stdio.h>
#include "mesin_kata.h"

void swap_skor(int skor[10] , int index_baru) {
    int temp;
    temp = skor[index_baru];
    skor[index_baru] = skor[index_baru + 1];
    skor[index_baru + 1] = temp;
}

void swap_nama(char nama[10][3], int index_baru) {
    char temp;
    int q;
    for (q = 1 ; q <= 3 ; q++) {
        temp = nama[index_baru][q];
        nama[index_baru][q] = nama[index_baru + 1][q];
        nama[index_baru + 1][q] = temp;
    }
}

int main () {
    int skor[3] = {2,3,1};
    int i;
    for (i = 0 ; i <= 2 ; i++) {
        printf("%d",skor[i]);
    }
    swap_skor(skor , 0);
    for (i = 0 ; i <= 2 ; i++) {
        printf("%d",skor[i]);
    }
}



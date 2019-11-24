#include <stdio.h>

int main () {
    printf("Apakah kamu mau kembali sekarang ? (Y/n)\n");
    char pilihannya;
    scanf("%c", &pilihannya);
    if (pilihannya != 'y' && (pilihannya != 'Y')) {
        while (pilihannya != 'y' && (pilihannya != 'Y')) {
            printf("Baiklah, silahkan melihat leaderboards dulu.\n\nJika sudah siap kembali tekan Y");
            scanf("%c", &pilihannya);
        }
    } 
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "urut_leaderboards_for_driver.c"

int main () {
    char str[50];
	char CC;
	static FILE *pita;
    boolean EOP;
    EOP = false;
	strcpy(str,"..//save_file//leaderboards.txt");
    pita = fopen(str,"r");
    int retval;
    retval = fscanf(pita,"%c",&CC);
    printf("Yang tertulis pada file leaderboards.txt : ");
	while (CC != ';') {
        printf("%c",CC);
        retval = fscanf(pita,"%c",&CC);
    }
    printf(";");
	printf("\n");
    fclose(pita);
    // masukkan nama pemain yang menang dan skornya
    char nama_pemenang[4];
    int skor_pemenang;
    printf("masukkan nama pemenang : ");
    scanf("%s", nama_pemenang);
    printf("masukkan skor pemenang : ");
    scanf("%d",&skor_pemenang);
	int i;
    for (i = 0; i <= 2 ; i++) {
        nama[0][i+1] = nama_pemenang[i];
    }
    skor[0] = skor_pemenang;
    // sekarang tampilkan leaderboards
    tampilkan_leaderboards();
	return 0;
}
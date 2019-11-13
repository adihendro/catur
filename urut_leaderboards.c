#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    char str[50];
	char CC;
	static FILE *pita;
	strcpy(str,"leaderboards.txt");
    pita = fopen(str,"r");
    int retval;
    char nama[10][20]; //ada 10 nama, maks 20 karakter per nama
    int skor[10];
    retval = fscanf(pita,"%c",&CC);
    int i;
    int j;
    i = 1;
    j = 1;
	while (CC != ';') {
        while (CC != '|') {
            nama[i][j] = CC;
            j++;
            retval = fscanf(pita,"%c",&CC);
        }
        while (CC != '%') {
            skor[i] = skor
        }
    }
	printf("\n");
	
	return 0;
}
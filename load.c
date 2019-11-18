#include "listlinier.h"

int main () {
    char str[50];
	char CC;
	static FILE *pita;
    list A; // list yang dimaksud
    CreateEmpty(&A); // buat gampang overwritenya
	strcpy(str,"contohList.txt");
    pita = fopen(str,"r");
    int retval;
    retval = fscanf(pita,"%c",&CC);
    while (CC != '|') {
        printf("%c",CC);
        retval = fscanf(pita,"%c",&CC);
    }
    printf("\n");
    fclose(pita);
    pita = fopen(str,"r");
    retval = fscanf(pita,"%c",&CC);
    int temp;
	while (CC != '|') {
        if (CC != ' ') {
            temp = CC - '0'; // karena disimpan dalam ascii jadi harus dicasting
            InsVLast(&A,temp);
        }
        retval = fscanf(pita,"%c",&CC);
    }
    address P;
    P = First(A);
    while (P != Nil) {
        printf("%d ",Info(P));
        P = Next(P);
    }
	printf("\n");
	
	return 0;
}
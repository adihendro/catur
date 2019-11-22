#include <stdio.h>
#include <string.h>

int main () {
    char gg[50];
    int i;
    char CC;
    for (i = 0; i <= 40 ; i++) {
        printf("%c",gg[i]);
    }
    printf("\n");
    strcpy(gg,"nyoba.txt");
    for (i = 0; i <= 49 ; i++) {
        printf("%c",gg[i]);
    }
    printf("\n");
    FILE *pita;
    pita = fopen(gg,"r");
    for (i = 1 ; i <= 20 ; i++) {
        fscanf(pita,"%c",&CC);
        printf("%c",CC);
    }
    fclose(pita);
    strcpy(gg,"nyoba2.txt");
    for (i = 0; i <= 49 ; i++) {
        printf("%c",gg[i]);
    }
    printf("\n");
    
    return 0;
}
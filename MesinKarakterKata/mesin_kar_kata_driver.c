#include <stdio.h>
#include <stdlib.h>
#include "mesin_kata.c"
#include <string.h>

int main () {
    char str[50]; // formatnya N|1|2|8|7|;
    char CC;
    static FILE *pita;
    int i;
    strcpy(str,"test_for_driver.txt");
    START(str);
    // print isi dari test_for_driver mengguankan mesin karakter
    EOP = false;
    printf("Isi dari test_for_driver.txt : ");
    while (!EOP) {
        CC = GetCC();
        printf("%c",CC);
        ADV();
    }
    printf(";\n");
    // mengeprint nama-nama yang ada pada test_for_driver dengan mesin kata
    EOP = false;
    int j = 0;
    START(str);
    while (!EOP) {
        j++;
        ADVKATA();
        printf("nama orang ke-%d : ",j);
        for (i = 1; i <= CKata.Length; i++) {
            printf("%c",CKata.TabKata[i]);
        }
        printf("\n");
        ADV(); // untuk memindahkan jendela dari | ke karakter selanjutnya
    }
    return 0;
}
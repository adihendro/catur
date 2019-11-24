#include <stdio.h>
#include "mesin_kata.c"
// #include "mesin_kar.c"
#include <string.h>
#include "tipe_bentukan.h"

int main () {
	char str[50]; // formatnya N(nama)|1(player)|2(turn)|8(R_lama)|7(C_lama)|6(R_baru)|5(C_baru)|;
	char CC;
	static FILE *pita;
	int count = 0;
    int i;
    i = 0;
    int to_int;
    infotype_list temp_list;
    int temp_input;
    int l;
	strcpy(str,"save_file//history.txt");
    START(str);
	while (!IsEOP()) {
        CC = GetCC();
        printf("%c",CC);
        if (CC != '|') {
            i++;
            if ((i % 5) == 1) {
                temp_list.nama = CC;
            }
            else if ((i % 5) == 2) {
                to_int = CC - '0';
                temp_list.player = to_int;
            }
            else if ((i % 5) == 3) {
                ADVKATA();
                temp_input = 0;
                for (l = 1 ; l <= CKata.Length ; l++) {
                    to_int = CKata.TabKata[l] - '0';
                    temp_input = 10*temp_input + to_int;
                }
                temp_list.poin = temp_input;
            }
            else if ((i % 5) == 4) {
                to_int = CC - '0';
                temp_list.posisiR = to_int;
            }
            else {
                to_int = CC - '0';
                temp_list.posisiC = to_int;
            }
        }
        ADV();
    }
    printf("\n");
	printf("%c\n",temp_list.nama);
    printf("%d\n",temp_list.player);
    printf("%d\n",temp_list.poin);
    printf("%d\n",temp_list.posisiR);
    printf("%d\n",temp_list.posisiC);
    printf("\n");
	
	return 0;
};
    

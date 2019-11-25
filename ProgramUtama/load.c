#include "..//ProgramUtama//tipe_bentukan.h"

#include "..//MesinKarakterKata//mesin_kata.c"

void load (list *list_ada_putih , list *list_ada_hitam , int *poin_putih , int *poin_hitam , queue *giliran , stack *history , stack *termakan, char *putih_1, char *putih_2, char *putih_3, char *hitam_1, char *hitam_2, char *hitam_3, int *turn) {
    
    // load list_ada_putih
    char str[50]; // formatnya N|1|2|8|7|;
    char CC;
    static FILE *pita;
    int count = 0;
    int i;
    i = 0;
    int to_int;
    infotype_list temp_list;
    int temp_input;
    int l;
    strcpy(str,"..//save_file//list_ada_putih.txt");
    START(str);
    while (!IsEOP()) {
        CC = GetCC();
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
                InsVLast(list_ada_putih,temp_list);
            }
        }
        ADV();
    }
    
    

    // load list_ada_hitam
    i = 0;
    strcpy(str,"..//save_file//list_ada_hitam.txt");
    START(str);
    while (!IsEOP()) {
        CC = GetCC();
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
                InsVLast(list_ada_hitam,temp_list);
            }
        }
        ADV();
    }
    
    // load poin_putih , poin_hitam , giliran , turn
    // int poin_putih = 0;
    // int poin_hitam = 0;
    int giliran_siapa;
    strcpy(str,"..//save_file//poin.txt");
    STARTKATA(str); // window di |
    temp_input = 0;
    for (l = 1 ; l <= CKata.Length ; l++) {
        to_int = CKata.TabKata[l] - '0';
        temp_input = 10*temp_input + to_int;
    }
    *poin_putih = temp_input;
    ADV(); // window di 6
    ADVKATA(); // window di |
    temp_input = 0;
    for (l = 1 ; l <= CKata.Length ; l++) {
        to_int = CKata.TabKata[l] - '0';
        temp_input = 10*temp_input + to_int;
    }
    *poin_hitam = temp_input;
    ADV(); // window di 1
    CC = GetCC();
    to_int = CC - '0';
    giliran_siapa = to_int;
    if (giliran_siapa == 1) {
        Add(giliran, 1);
    }
    else {
        Add(giliran, 2);
    }
    ADV();
    ADV();
    ADVKATA(); // window di |
    temp_input = 0;
    for (l = 1 ; l <= CKata.Length ; l++) {
        to_int = CKata.TabKata[l] - '0';
        temp_input = 10*temp_input + to_int;
    }
    *turn = temp_input;
    ADV();
    

    // load stack history
    i = 0;
    int b;
    b = 0;
    infotype_stack temp_infostack;
    strcpy(str,"..//save_file//history.txt");
    START(str);
    while (!IsEOP()) {
        CC = GetCC();
        if (CC != '|') {
            i++;
            if ((i % 11) == 1) {
                temp_infostack.nama = CC;
            }
            else if ((i % 11) == 2) {
                to_int = CC - '0';
                temp_infostack.player = to_int;
            }
            else if ((i % 11) == 3) {
                ADVKATA();
                temp_input = 0;
                for (l = 1 ; l <= CKata.Length ; l++) {
                    to_int = CKata.TabKata[l] - '0';
                    temp_input = 10*temp_input + to_int;
                }
                temp_infostack.poin = temp_input;
            }
            else if ((i % 11) == 4) {
                ADVKATA();
                temp_input = 0;
                for (l = 1 ; l <= CKata.Length ; l++) {
                    to_int = CKata.TabKata[l] - '0';
                    temp_input = 10*temp_input + to_int;
                }
                temp_infostack.turn = temp_input;
            }
            else if ((i % 11) == 5) {
                to_int = CC - '0';
                temp_infostack.posisiR_lama = to_int;
            }
            else if ((i % 11) == 6) {
                to_int = CC - '0';
                temp_infostack.posisiC_lama = to_int;
            }
            else if ((i % 11) == 7) {
                to_int = CC - '0';
                temp_infostack.posisiR_baru = to_int;
            }
            else if ((i % 11) == 8) {
                to_int = CC - '0';
                temp_infostack.posisiC_baru = to_int;
            }
            else if ((i % 11) == 9) {
                to_int = CC - '0';
                temp_infostack.promotion = to_int;
            }
            else if ((i % 11) == 10) {
                to_int = CC - '0';
                temp_infostack.twosteps = to_int;
            }
            else { // saat habis dibagi 11
                to_int = CC - '0';
                temp_infostack.enpassant = to_int;
                Push(history,temp_infostack);
            }
        }
        ADV();
    }


    // load stack termakan
    i = 0;
    // infotype_stack temp_infostack;
    strcpy(str,"..//save_file//termakan.txt");
    START(str);
    while (!IsEOP()) {
        CC = GetCC();
        if (CC != '|') {
            i++;
            if ((i % 11) == 1) {
                temp_infostack.nama = CC;
            }
            else if ((i % 11) == 2) {
                to_int = CC - '0';
                temp_infostack.player = to_int;
            }
            else if ((i % 11) == 3) {
                ADVKATA();
                temp_input = 0;
                for (l = 1 ; l <= CKata.Length ; l++) {
                    to_int = CKata.TabKata[l] - '0';
                    temp_input = 10*temp_input + to_int;
                }
                temp_infostack.poin = temp_input;
            }
            else if ((i % 11) == 4) {
                ADVKATA();
                temp_input = 0;
                for (l = 1 ; l <= CKata.Length ; l++) {
                    to_int = CKata.TabKata[l] - '0';
                    temp_input = 10*temp_input + to_int;
                }
                temp_infostack.turn = temp_input;
            }
            else if ((i % 11) == 5) {
                to_int = CC - '0';
                temp_infostack.posisiR_lama = to_int;
            }
            else if ((i % 11) == 6) {
                to_int = CC - '0';
                temp_infostack.posisiC_lama = to_int;
            }
            else if ((i % 11) == 7) {
                to_int = CC - '0';
                temp_infostack.posisiR_baru = to_int;
            }
            else if ((i % 11) == 8) {
                to_int = CC - '0';
                temp_infostack.posisiC_baru = to_int;
            }
            else if ((i % 11) == 9) {
                to_int = CC - '0';
                temp_infostack.promotion = to_int;
            }
            else if ((i % 11) == 10) {
                to_int = CC = '0';
                temp_infostack.twosteps = to_int;
            }
            else { // saat habis dibagi 11
                to_int = CC - '0';
                temp_infostack.enpassant = to_int;
                Push(termakan,temp_infostack);
            }
        }
        ADV();
    }

    // load namaplayer
    strcpy(str,"..//save_file//namaplayer.txt");
    START(str);
    while (!IsEOP()) {
        CC = GetCC();
        *putih_1 = CC;
        ADV();
        CC = GetCC();
        *putih_2 = CC;
        ADV();
        CC = GetCC();
        *putih_3 = CC;
        ADV();
        ADV();
        CC = GetCC();
        *hitam_1 = CC;
        ADV();CC = GetCC();
        *hitam_2 = CC;
        ADV();CC = GetCC();
        *hitam_3 = CC;
        ADV();
        ADV();
    }
}



// // int main () {
// //     char str[50];
// // 	char CC;
// // 	static FILE *pita;
// //     list A; // list yang dimaksud
// //     CreateEmpty_list(&A); // buat gampang overwritenya
// // 	strcpy(str,"contohList.txt");
// //     pita = fopen(str,"r");
// //     int retval;
// //     retval = fscanf(pita,"%c",&CC);
// //     while (CC != '|') {
// //         printf("%c",CC);
// //         retval = fscanf(pita,"%c",&CC);
// //     }
// //     printf("\n");
// //     fclose(pita);
// //     pita = fopen(str,"r");
// //     retval = fscanf(pita,"%c",&CC);
// //     int temp;
// // 	while (CC != '|') {
// //         if (CC != ' ') {
// //             temp = CC - '0'; // karena disimpan dalam ascii jadi harus dicasting
// //             InsVLast(&A,temp);
// //         }
// //         retval = fscanf(pita,"%c",&CC);
// //     }
// //     address P;
// //     P = First(A);
// //     while (P != Nil) {
// //         printf("%d ",Info(P));
// //         P = Next(P);
// //     }
// // 	printf("\n");
	
// // 	return 0;
// // }
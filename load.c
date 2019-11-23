#include "tipe_bentukan.h"
#include "mesin_kar.h"
#include "mesin_kar.c"
#include "mesin_kata.h"
#include "mesin_kata.c"

void load (list *list_ada_putih , list *list_ada_hitam , int *poin_putih , int *poin_hitam , queue *giliran , stack *history , stack *termakan) {
    char CC;
    boolean EOP;
    FILE *pita;
    char str[50];
    
    // load list_ada_putih
    EOP = false;
    CreateEmpty_list(list_ada_putih);
    strcpy(str,"list_ada_putih.txt");
    START(str); // window di P
    address_list P;
    P = First(*list_ada_putih);
    infotype_list temp_load_list;
    int to_int;
    int l;
    int temp_input;
    temp_input = 0;
    while(!EOP) { // jika formatnya adalah P,1,30,6,7.;
        CC = GetCC(); // CC = P
        temp_load_list.nama = CC;
        ADV(); // window di ,
        ADV(); // window di 1
        CC = GetCC();
        to_int = CC - '0';
        temp_load_list.player = to_int;
        ADVKATASTACK(); // windownya di ,
        // disimpan ke CKata
        for (l = 1 ; l <= CKata.Length ; l++) {
            to_int = CKata.TabKata[l] - '0';
            temp_input = 10*temp_input + to_int;
        }
        temp_load_list.poin = temp_input; 
        ADV(); // windownya di 6
        CC = GetCC();
        to_int = CC - '0';
        temp_load_list.posisiR = to_int;
        ADV(); // windownya di ,
        ADV(); // windownya di 7
        CC = GetCC();
        to_int = CC - '0';
        temp_load_list.posisiC = to_int;
        ADV(); // windownya di .
        ADV(); // windownya di selanjutnya antara ; atau nama pion
    }
    InsVLast(list_ada_putih,temp_load_list);
    // fclose(pita);


    // load list_ada_hitam
    EOP = false;
    CreateEmpty_list(list_ada_hitam);
    strcpy(str,"list_ada_hitam.txt");
    START(str); // window di P
    // address_list P;
    P = First(*list_ada_hitam);
    infotype_list temp_load_list;
    // int to_int;
    // int l;
    // int temp_input;
    temp_input = 0;
    while(!EOP) { // jika formatnya adalah P,1,30,6,7.;
        CC = GetCC(); // CC = P
        temp_load_list.nama = CC;
        ADV(); // window di ,
        ADV(); // window di 1
        CC = GetCC();
        to_int = CC - '0';
        temp_load_list.player = to_int;
        ADVKATASTACK(); // windownya di ,
        // disimpan ke CKata
        for (l = 1 ; l <= CKata.Length ; l++) {
            to_int = CKata.TabKata[l] - '0';
            temp_input = 10*temp_input + to_int;
        }
        temp_load_list.poin = temp_input; 
        ADV(); // windownya di 6
        CC = GetCC();
        to_int = CC - '0';
        temp_load_list.posisiR = to_int;
        ADV(); // windownya di ,
        ADV(); // windownya di 7
        CC = GetCC();
        to_int = CC - '0';
        temp_load_list.posisiC = to_int;
        ADV(); // windownya di .
        ADV(); // windownya di selanjutnya antara ; atau nama pion
    }
    InsVLast(list_ada_hitam,temp_load_list);
    // fclose(pita);


    // load poin putih, poin hitam, dan giliran
    // formatnya 20|60|1;
    int poin_putih = 0;
    int poin_hitam = 0;
    int giliran;
    strcpy(str,"poin.txt");
    STARTKATA(str); // window di |
    temp_input = 0;
    for (l = 1 ; l <= CKata.Length ; l++) {
        to_int = CKata.TabKata[l] - '0';
        temp_input = 10*temp_input + to_int;
    }
    poin_putih = temp_input;
    ADV(); // window di 6
    ADVKATA(); // window di |
    temp_input = 0;
    for (l = 1 ; l <= CKata.Length ; l++) {
        to_int = CKata.TabKata[l] - '0';
        temp_input = 10*temp_input + to_int;
    }
    poin_hitam = temp_input;
    ADV(); // window di 1
    CC = GetCC();
    to_int = CC - '0';
    giliran = to_int;
    ADV();


    // load stack history
    // formatnya P|1|32|5|5|7|7|1|0.;
    stack history;
    stack reverse_history;
    CreateEmpty_stack(&history);
    CreateEmpty_stack(&reverse_history);
    infotype_stack temp_infostack;
    strcpy(str,"history.txt");
    START(str); // window di P
    while (!EOP) {
        CC = GetCC();
        temp_infostack.nama = CC;
        ADV(); // window di |
        ADV(); // window di 1
        CC = GetCC();
        to_int = CC - '0';
        temp_infostack.player = to_int;
        ADV(); // window di |
        ADV(); // window di 32
        ADVKATA(); // window di |
        temp_input = 0;
        for (l = 1 ; l <= CKata.Length ; l++) {
            to_int = CKata.TabKata[i] - '0';
            temp_input = temp_input*10 + to_int;
        }
        temp_infostack.poin = temp_input;
        ADV(); // window di 5
        CC = GetCC();
        to_int = CC - '0';
        temp_infostack.posisiR_lama = to_int;
        ADV(); // window di |
        ADV(); // window di 5
        CC = GetCC();
        to_int = CC - '0';
        temp_infostack.posisiC_lama = to_int;
        ADV();
        ADV(); // window di 7
        CC = GetCC();
        to_int = CC - '0';
        temp_infostack.posisiR_baru = to_int;
        ADV();
        ADV(); // window di 7
        CC = GetCC();
        to_int = CC - '0';
        temp_infostack.posisiC_baru = to_int; 
        ADV();
        ADV(); // window di 1
        CC = GetCC();
        to_int = CC - '0';
        temp_infostack.promotion = to_int;
        ADV();
        ADV(); // window di 0
        temp_infostack.twosteps = to_int;
        ADV();
        ADV(); // window di ; atau nama bidak
        Push(&reverse_history,temp_infostack);
    }
    while (!IsEmpty_stack(reverse_history)) {
        Pop(&reverse_history,&temp_infostack);
        Push(&history,temp_infostack);
    }


    // load stack termakan
    // formatnya P|1|32|5|5|7|7|1|0.;
    stack termakan;
    stack reverse_termakan;
    CreateEmpty_stack(&termakan);
    CreateEmpty_stack(&reverse_termakan);
    // infotype_stack temp_infostack;
    strcpy(str,"termakan.txt");
    START(str); // window di P
    while (!EOP) {
        CC = GetCC();
        temp_infostack.nama = CC;
        ADV(); // window di |
        ADV(); // window di 1
        CC = GetCC();
        to_int = CC - '0';
        temp_infostack.player = to_int;
        ADV(); // window di |
        ADV(); // window di 32
        ADVKATA(); // window di |
        temp_input = 0;
        for (l = 1 ; l <= CKata.Length ; l++) {
            to_int = CKata.TabKata[i] - '0';
            temp_input = temp_input*10 + to_int;
        }
        temp_infostack.poin = temp_input;
        ADV(); // window di 5
        CC = GetCC();
        to_int = CC - '0';
        temp_infostack.posisiR_lama = to_int;
        ADV(); // window di |
        ADV(); // window di 5
        CC = GetCC();
        to_int = CC - '0';
        temp_infostack.posisiC_lama = to_int;
        ADV();
        ADV(); // window di 7
        CC = GetCC();
        to_int = CC - '0';
        temp_infostack.posisiR_baru = to_int;
        ADV();
        ADV(); // window di 7
        CC = GetCC();
        to_int = CC - '0';
        temp_infostack.posisiC_baru = to_int; 
        ADV();
        ADV(); // window di 1
        CC = GetCC();
        to_int = CC - '0';
        temp_infostack.promotion = to_int;
        ADV();
        ADV(); // window di 0
        temp_infostack.twosteps = to_int;
        ADV();
        ADV(); // window di ; atau nama bidak
        Push(&reverse_history,temp_infostack);
    }
    while (!IsEmpty_stack(reverse_termakan)) {
        Pop(&reverse_termakan,&temp_infostack);
        Push(&termakan,temp_infostack);
    }
}


// int main () {
//     char str[50];
// 	char CC;
// 	static FILE *pita;
//     list A; // list yang dimaksud
//     CreateEmpty_list(&A); // buat gampang overwritenya
// 	strcpy(str,"contohList.txt");
//     pita = fopen(str,"r");
//     int retval;
//     retval = fscanf(pita,"%c",&CC);
//     while (CC != '|') {
//         printf("%c",CC);
//         retval = fscanf(pita,"%c",&CC);
//     }
//     printf("\n");
//     fclose(pita);
//     pita = fopen(str,"r");
//     retval = fscanf(pita,"%c",&CC);
//     int temp;
// 	while (CC != '|') {
//         if (CC != ' ') {
//             temp = CC - '0'; // karena disimpan dalam ascii jadi harus dicasting
//             InsVLast(&A,temp);
//         }
//         retval = fscanf(pita,"%c",&CC);
//     }
//     address P;
//     P = First(A);
//     while (P != Nil) {
//         printf("%d ",Info(P));
//         P = Next(P);
//     }
// 	printf("\n");
	
// 	return 0;
// }
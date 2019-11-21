// #include "listlinier.h"
#include "tipe_bentukan.h"
#include <stdio.h>
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
    pita = fopen("list_ada_putih.txt","r");
    address_list P;
    P = First(*list_ada_putih);
    infotype_list temp_load_list;
    int to_int;
    ADV();
    int l;
    int temp_input;
    temp_input = 0;
    while(!EOP) {
        temp_load_list.nama = CC;
        ADV();
        to_int = CC - '0';
        temp_load_list.player = to_int;
        ADVKATA(); // belum diperbaiki biar casting integer
        // disimpan ke CKata
        for (l = 1 ; l <= CKata.Length ; l++) {
            to_int = CKata.TabKata[l] - '0';
            temp_input = 10*temp_input + to_int;
        }
        ADVKATA()
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
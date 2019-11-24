// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include "mesin_kata.c"

void swap_skor(int skor[10] , int index_baru) {
    int temp;
    temp = skor[index_baru];
    skor[index_baru] = skor[index_baru + 1];
    skor[index_baru + 1] = temp;
}

void swap_nama(char nama[10][3], int index_baru) {
    char temp;
    int q;
    for (q = 1 ; q <= 3 ; q++) {
        temp = nama[index_baru][q];
        nama[index_baru][q] = nama[index_baru + 1][q];
        nama[index_baru + 1][q] = temp;
    }
}

void tampilkan_leaderboards () {
    // inisialisasi data nama dan skor
    char nama[11][3]; //ada 10 nama, maks 20 karakter per nama
    int skor[11];
    int i;
    int j;
    for (i = 0 ; i <= 11 ; i++) { // inisialisasi semua skor dengan 0 dan string dengan spasi
        skor[i] = 0;
        for (j = 1 ; j <= 3 ; j++) {
            nama[i][j] = ' ';
        }
    };

    // load leaderboards yang sudah ada
    char str[50];
    char CC;
    FILE *filename;
    strcpy(str,"leaderboards.txt");
    START(str);
    // filename = fopen("leaderboards.txt","r");
    i = 1;
    j = 1;
    int temp;
	while ((!EOP) && (i <= 10)) {
        j = 1;
        CC = GetCC();
        ADVKATA();
        for (j = 1 ; j <= 3 ; j++) {
            nama[i][j] = CKata.TabKata[j];
        }
        // while (CC != '|') {
        //     nama[i][j] = CC;
        //     j++;
        //     // retval = fscanf(pita,"%c",&CC);
        //     ADV();
        //     CC = GetCC();
        // }
        ADV();
        CC = GetCC();
        while (CC != '^') {
            temp = CC - '0';
            skor[i] = skor[i]*10 + temp;
            ADV();
            CC = GetCC();
        }
        i++;
        ADV();
    }   
    
    // // user memasukkan nama dan skornya : hanya untuk test nanti bakal diilangin
    // //user input nama mereka
    // char inputan_nama[20];
    // printf("nama : ");
    // scanf("%s", inputan_nama);
    // int z;
    // for (z = 0 ; z <= 2 ; z++) { // masukkan nama pemain yang menang ke dalam list pemain yang ada
    //     nama[0][z+1] = inputan_nama[z];
    // }
    // //user input nilai
    // int nilai;
    // scanf("%d",&nilai);
    // skor[0] = nilai; // nilai yang menang dimasukkan ke index 0

    // fungsi mengurutkan leaderboards berdasarkan skor dan nama
    int urut = 0; // ini sebenernya boolean cuma belum include booleanh
    int index_baru;
    char ctemp;
    int btemp;
    int q;
    index_baru = 0;
    int urut_nama;
    while(urut == 0) {
        if (skor[index_baru] > skor[index_baru + 1]) {
            urut = 1;
        }
        else if (skor[index_baru] < skor[index_baru + 1]) {
            swap_skor(skor, index_baru);
            swap_nama(nama, index_baru);
            index_baru++;
        }
        else { //saat skornya sama
            urut_nama = 0;
            q = 1;
            if (nama[index_baru][1] < nama[index_baru + 1][1]) {
                urut = 1;
            }
            else if (nama[index_baru][1] == nama[index_baru + 1][1]) {
                if (nama[index_baru][2] < nama[index_baru + 1][2]) {
                    urut = 1;
                }
                else if (nama[index_baru][2] == nama[index_baru + 1][2]) {
                    if (nama[index_baru][3] < nama[index_baru + 1][3]) {
                        urut = 1;
                    }
                    else if (nama[index_baru][3] == nama[index_baru + 1][3]) {
                        urut = 1;
                    }
                    else { // saat nama[index_baru][3] > nama[index_baru][3]
                        swap_nama(nama, index_baru);
                        index_baru++;
                    }
                }
                else { // saat nama[index_baru][2] > nama[index_baru + 1][2]
                    swap_nama(nama, index_baru);
                    index_baru++;
                }
            }
            else { // saat nama[index_baru] > nama[index_baru + 1]
                swap_nama(nama,index_baru);
                index_baru++;
            }
        }

    }

    // ngeprint ke layar nama dan skornya
    printf("\033[0;31m");
    printf("###########################################################################\n");
    printf("\033[0m");
    printf("###########################################################################\n");
    printf("\n\n\n");
    i = 0;
    j = 1;
    int printed;
    printed = 0;
    while ((skor[i] != 0) && (printed < 10)) {
        printf("                            ");
        for (j = 1 ; j <= 3 ; j++) {
            printf("%c",nama[i][j]);
        }
        printf("    -   ");
        printf("%d\n",skor[i]);
        i++;
        printed++;
    }
    printf("\n\n\n");
    printf("\033[0;31m");
    printf("###########################################################################\n");
    printf("\033[0m");
    printf("###########################################################################\n");

    // write ke leaderboards.txt
    pita = fopen(str,"w");
    i = 0;
    j = 1;
    while (skor[i] != 0) {
        for (j = 1 ; j <= 3 ; j++) {
            fprintf(pita,"%c",nama[i][j]);
        }
        fprintf(pita,"|");
        fprintf(pita,"%d",skor[i]);
        fprintf(pita,"^"); 
        i++;
    }
    fprintf(pita,";");
    fclose(pita);
	// return 0;
    
}
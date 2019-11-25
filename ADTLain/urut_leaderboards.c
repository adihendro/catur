#include "..//ProgramUtama//tipe_bentukan.h"

void swap_skor(int skor[10] , int index_baru) {
    int temp;
    temp = skor[index_baru];
    skor[index_baru] = skor[index_baru + 1];
    skor[index_baru + 1] = temp;
}

void swap_nama(char nama[10][4], int index_baru) {
    char temp;
    int q;
    for (q = 1 ; q <= 3 ; q++) {
        temp = nama[index_baru][q];
        nama[index_baru][q] = nama[index_baru + 1][q];
        nama[index_baru + 1][q] = temp;
    }
}

void tampilkan_leaderboards () {
    // load leaderboards yang sudah ada
    char str[50];
    char CC;
    FILE *filename;
    strcpy(str,"..//save_file//leaderboards.txt");
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
    printf("\n\n");
    printf("\033[1;33m");
    printf("             __    _         __                _             __            \n");
    printf("      |     |__   /_\\   |\\  |__  |)  |)  /\\   /_\\   |)  |\\  |__            \n");
    printf("      |__   |__  /   \\  |/  |__  |\\  |)  \\/  /   \\  |\\  |/   __|           \n");
    printf("\n");
    printf("\033[0m");
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
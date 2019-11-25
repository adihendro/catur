#include "tipe_bentukan.h"

#include "start.c"
#include "inisialisasi.c"
#include "print_papan.c"
#include "listlinier.c"
#include "listposisi.c"
#include "stack.c"
#include "queue.c"
#include "ascii_checker.c"
#include "move.c"
#include "special_move.c"
#include "undo.c"
#include "save.c"
#include "load.c"
#include "urut_leaderboards.c"


int main(){

    //GAME START 
    int pilihan_user;
    start(&pilihan_user);
    // printf("%d\n",*pilihan_user);

    while (pilihan_user == 51) { //3. Leaderboard
        tampilkan_leaderboards();
        printf("Apakah kamu mau kembali sekarang? (Y/N)\n");
        char *pilihannya;
        pilihannya = (char*) malloc (sizeof(char));
        scanf("%c", pilihannya);
        scanf("%c", pilihannya); // jangan dihapus ntar error
        if ((*pilihannya != 'y') && (*pilihannya != 'Y')) {
            while ((*pilihannya != 'y') && (*pilihannya != 'Y')) {
                printf("\nBaiklah, silakan melihat leaderboards dulu.\nJika sudah siap kembali tekan Y. ");
                scanf("%c", pilihannya);
                scanf("%c", pilihannya); // jangan dihapus ntar error
            }
        } 
        start(&pilihan_user); // lanjut tadi        
    }

    if (pilihan_user == 50) { //2. Load Game
        CreateEmpty_stack(&history);
        CreateEmpty_stack(&termakan);
        CreateEmpty_list(&list_ada_putih);
        CreateEmpty_list(&list_ada_hitam);
        CreateEmpty_queue(&giliran, 2);
        // Add(&giliran, 1); //giliran pertama putih (1)
        poin_putih=0;
        poin_hitam=0;
        turn=0;
        load (&list_ada_putih, &list_ada_hitam, &poin_putih, &poin_hitam, &giliran, &history, &termakan, &putih_1, &putih_2, &putih_3, &hitam_1, &hitam_2, &hitam_3);
        int v;
        nama_putih[0] = putih_1;
        nama_putih[1] = putih_2;
        nama_putih[2] = putih_3;
        nama_hitam[0] = hitam_1;
        nama_hitam[1] = hitam_2;
        nama_hitam[2] = hitam_3;
        for (i = 0 ; i <= 2 ; i++) {
            printf("%c", nama_putih[i]);
        }
        for (i = 0 ; i <= 2 ; i++) {
            printf("%c", nama_hitam[i]);
        }
    }

    else if (pilihan_user == 49){ //1. New Game
        inisialisasi();
        Add(&giliran, 1);
        for (g = 0 ; g <= 3 ; g++) {
            nama_putih[g] = ' ';
            nama_hitam[g] = ' ';
        }
        printf("Sebelum main, boleh tahu namamu dulu?\n");
        printf("Nama Putih: ");
        scanf("%s", nama_putih);
        printf("Oke, kalau nama temanmu siapa?\n");
        printf("Nama Hitam: ");
        scanf("%s", nama_hitam);
        printf("Baiklah, SELAMAT BERMAIN!!\n\n\n");
        putih_1 = nama_putih[0];
        putih_2 = nama_putih[1];
        putih_3 = nama_putih[2];
        hitam_1 = nama_hitam[0];
        hitam_2 = nama_hitam[1];
        hitam_3 = nama_hitam[2];
        // delay(2000);
    }

    papan *board2[10][10];
    for(int i=0;i<=10;i++){
        for(int j=0;j<=10;j++){
            board2[i][j] = &board[i][j];
        }
    }



    do{
        updateboard(board2, list_ada_putih, list_ada_hitam);
        PrintPapan(board2);

        if (InfoTail(giliran) == 1){ //putih
            printf("\033[1;32m"); //warna hijau
            printf("Giliran Putih\n");
            printf("\033[0m"); 

            kawan = list_ada_putih; //piece yg masih ada di papan
            lawan = list_ada_hitam;
            poin = poin_putih;

        } else{ //InfoTail(giliran) == 2, hitam
            printf("\033[1;31m"); //warna merah
            printf("Giliran Hitam\n");
            printf("\033[0m"); 

            kawan = list_ada_hitam;
            lawan = list_ada_putih;
            poin = poin_hitam;
        }



        //kondisi STALEMATE atau CHECKMATE
        gerakaman(kawan, lawan, board2, &list_bisa_gerak, &jml_bs_grk, &endgame);
        printf("endgame: %d\n", endgame);
        iskak = isskak(lawan, kawan, board2, &K, &P1, &jml);
        if(iskak && endgame) //lagi skak dan ga ada yg bisa gerak
            printf("CHECKMATE\n");
        else if(endgame) //tidak lagi skak dan ga ada yg bisa gerak
            printf("STALEMATE\n");
        


        do{
            go=false;
            printf("MOVE, SPECIAL_MOVE, UNDO, SAVE, RESET\n");
            printf("Masukkan command: ");
            scanf("%s",command);
            if((strcmp(command,"MOVE") == 0) || (strcmp(command,"SPECIAL_MOVE") == 0) ||
            (strcmp(command,"UNDO") == 0) || (strcmp(command,"SAVE") == 0) ||
            (strcmp(command,"RESET") == 0)){
                go=true;
            } else{
                printf("Command salah!\n\n");
            }
        } while(!go);



        if(strcmp(command,"MOVE") == 0){
            turn++;
            move(board2, &history, &termakan, &poin_putih, &poin_hitam, &list_ada_putih, &list_ada_hitam, &giliran, turn, list_bisa_gerak, jml_bs_grk, iskak);
            // delay(1000);
        }
        else if(strcmp(command,"SPECIAL_MOVE") == 0){
            turn++;
            special_move(&history, &termakan, &poin_putih, &poin_hitam, &list_ada_putih, &list_ada_hitam, &giliran, turn);
            // delay(2000);
        }
        else if(strcmp(command,"UNDO") == 0){
            undo(&history, &termakan, &poin_putih, &poin_hitam, &list_ada_putih, &list_ada_hitam, &giliran, turn);
            if(turn==1)
                turn--;
            else if(turn>=2)
                turn=turn-2;
        }
        else if(strcmp(command,"SAVE") == 0){
            save(list_ada_putih , list_ada_hitam , poin_putih , poin_hitam , giliran , history , termakan, putih_1, putih_2, putih_3, hitam_1, hitam_2, hitam_3);
            printf("Save success!\n");
        }
        else if(strcmp(command,"RESET") == 0){
            printf("Are you sure?\n");
            printf("(Y)es, (N)o\n");
            scanf("%s",&choice2);
            if(choice2=='Y'){
                inisialisasi();
                Add(&giliran, 1);
                printf("Success!\n");
            } else
                printf("Canceled.\n");
        }


        printf("\nPoin Putih: %d\nPoin Hitam: %d\n", poin_putih, poin_hitam);
        printf("\n\n");
        
    } while(1);

    return 0;
}


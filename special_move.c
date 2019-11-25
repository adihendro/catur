#include "tipe_bentukan.h"

boolean cek_enpassant(papan *board[10][10], stack* history, list *list_ada_putih, list *list_ada_hitam, queue *giliran, address_list *P);
void enpassant(papan *board[10][10], stack *history, stack *termakan, int *poin_putih, int *poin_hitam, list *list_ada_putih, list *list_ada_hitam, queue *giliran, int turn, address_list P);
boolean cek_castling(stack* history, list *list_ada_putih, list *list_ada_hitam, queue *giliran, address_list *P, address_list *P2, papan *board[10][10]);
void castling(stack *history, list *list_ada_putih, list *list_ada_hitam, queue *giliran, address_list P, address_list P2, int turn);


void special_move(papan *board[10][10], stack *history, stack *termakan, int *poin_putih, int *poin_hitam, list *list_ada_putih, list *list_ada_hitam, queue *giliran, int turn){
    address_list P;
    address_list P2;
    int X;
    
    if(!cek_enpassant(board, history, list_ada_putih, list_ada_hitam, giliran, &P) && !cek_castling(history, list_ada_putih, list_ada_hitam, giliran, &P, &P2, board)){ //ga bisa dua-duanya
        printf("\nTidak ada gerakan khusus yang bisa dilakukan.\n");

    } else if(cek_enpassant(board, history, list_ada_putih, list_ada_hitam, giliran, &P) && cek_castling(history, list_ada_putih, list_ada_hitam, giliran, &P, &P2, board)){ //bisa dua-duanya
        printf("\nDaftar gerakan khusus yang bisa dilakukan:\n");
        printf("   1. Castling\n");
        printf("   2. En Passant\n");
        printf("Pilih gerakan khusus yang ingin dilakukan: ");
        do{    
            choice = (char*) malloc (sizeof(100));
            scanf("%s",choice);
            stringToInt(choice,&X);
            if(!(X==49 || X==50))
                printf("Wrong input!\n");
        } while(!(X==49 || X==50));
        if(X==49){
        //kalau 1
            castling(history, list_ada_putih, list_ada_hitam, giliran, P, P2, turn);
            printf("Castling berhasil dilakukan\n");}
        else {//kalau 2
            enpassant(board, history, termakan, poin_putih, poin_hitam, list_ada_putih, list_ada_hitam, giliran, turn, P);
            printf("En Passant berhasil dilakukan\n");
        }

    } else if(cek_enpassant(board, history, list_ada_putih, list_ada_hitam, giliran, &P)){
        printf("\nDaftar gerakan khusus yang bisa dilakukan:\n");
        printf("   1. En Passant\n");
        printf("Pilih gerakan khusus yang ingin dilakukan: ");
        do{    
            choice = (char*) malloc (sizeof(100));
            scanf("%s",choice);
            stringToInt(choice,&X);
            if(!(X==49))
                printf("Wrong input!\n");
        } while(!(X==49));
        if(X==49){
            enpassant(board, history, termakan, poin_putih, poin_hitam, list_ada_putih, list_ada_hitam, giliran, turn, P);
            printf("En Passant berhasil dilakukan\n");}

    } else if(cek_castling(history, list_ada_putih, list_ada_hitam, giliran, &P, &P2, board)){
        printf("\nDaftar gerakan khusus yang bisa dilakukan:\n");
        printf("   1. Castling\n");
        printf("Pilih gerakan khusus yang ingin dilakukan: ");
        do{    
            choice = (char*) malloc (sizeof(100));
            scanf("%s",choice);
            stringToInt(choice,&X);
            if(!(X==49))
                printf("Wrong input!\n");
        } while(!(X==49));
        if(X==49){
            castling(history, list_ada_putih, list_ada_hitam, giliran, P, P2, turn);
            printf("Castling berhasil dilakukan\n");}
    }

}

boolean cek_enpassant(papan *board[10][10], stack* history, list *list_ada_putih, list *list_ada_hitam, queue *giliran, address_list *P){
    boolean found=false;
    int tempR;
    if ((*history).T[(*history).TOP].twosteps){ //pion musuh baru jalan 2 kotak
        //dicek di sebelah pion musuh tsb ada pion temen atau tidak
        if (InfoTail(*giliran) == 1){ //giliran putih
            *P = First(*list_ada_putih);
            kawan = *list_ada_putih;
            lawan = *list_ada_hitam;
            tempR = 3;
        } else{ //giliran == 2, hitam
            *P = First(*list_ada_hitam);
            kawan = *list_ada_hitam;
            lawan = *list_ada_putih;
            tempR = 6;
        }

        while((*P) != Nil_list){
            if(Info(*P).nama == 'P'){ //kalau pion
                if(Info(*P).posisiR == (*history).T[(*history).TOP].posisiR_baru){ //kalau satu baris
                    if(abs(Info(*P).posisiC - (*history).T[(*history).TOP].posisiC_baru) == 1) //kalau sebelahan
                        if(!jadi_skak(lawan, kawan, board, Info(*P), tempR, Info(*P).posisiC)){ //kalau setelah pindah ga skak
                            found=true; //pion temen sebelahan dengan pion musuh tsb
                            break;
                        }
                }
            }
            *P = Next(*P);
        }
    }
    return found;
}

void enpassant(papan *board[10][10], stack *history, stack *termakan, int *poin_putih, int *poin_hitam, list *list_ada_putih, list *list_ada_hitam, queue *giliran, int turn, address_list P){
    infotype_stack X;
    address_list A, A1;
    int tempR = Info(P).posisiR;
    int tempC = Info(P).posisiC;

    Info(P).posisiC = (*history).T[(*history).TOP].posisiC_baru;

    if (InfoTail(*giliran) == 1){ //giliran putih
        Info(P).posisiR--;
        *poin_putih = *poin_putih + 1;

        A1 = Search(*list_ada_hitam, Info(P).posisiC, tempR); //address sebelum bidak lawan yang termakan
        A = Next(A1); //address bidak lawan yang termakan
        DelAfter(list_ada_hitam, &A, A1); // hapus bidak lawan dari list linier lawan 

    } else{ //giliran == 2, hitam
        Info(P).posisiR++;
        *poin_hitam = *poin_hitam + 1;
        
        A1 = Search(*list_ada_putih, Info(P).posisiC, tempR); //address sebelum bidak lawan yang termakan
        A = Next(A1); //address bidak lawan yang termakan
        DelAfter(list_ada_putih, &A, A1); // hapus bidak lawan dari list linier lawan 
    }

    //bidak lawan yg termakan
    X.nama = Info(P).nama; 
    X.player = (InfoTail(*giliran) % 2) + 1; //lawan
    X.poin = 1;
    X.turn = turn;
    X.posisiR_lama = X.posisiR_baru = InfoTail(*giliran)==1 ? ++Info(P).posisiR : --Info(P).posisiR;
    X.posisiC_lama = X.posisiC_baru = Info(P).posisiC;
    X.enpassant = true;
    Push(termakan, X); //masukkan ke stack termakan

    //bidak yg barusan makan en passant
    X.nama = Info(P).nama; 
    X.player = InfoTail(*giliran);
    X.posisiR_lama = tempR;
    X.posisiC_lama = tempC;
    X.posisiR_baru = InfoTail(*giliran)==1 ? --tempR : ++tempR;
    Push(history, X); //masukkan ke stack history

    // update nilai awal di list_ada menjadi nilai akhir
    Info(P).posisiR = X.posisiR_baru;

    if (InfoTail(*giliran) == 1) //giliran berubah
        Add(giliran, 2);
    else
        Add(giliran, 1);
}


boolean HasMoved(piece P, stack history) //ngecek apakah raja ada di stack history ato ngga
{ //note for some reason pas gw cek indeks 1 ama 2 ga kedeteksi. semoga kompi gw doang.
    infotype_stack X;
    int counter = 1;
    boolean Moved = false;
    int jml = history.TOP;
    while ((!Moved) && (counter <= jml)){   
        X = (history).T[counter];
        counter++;
        if (X.nama == P.nama)
            Moved = true;
    }
    return Moved;
}

boolean cek_castling(stack* history, list *list_ada_putih, list *list_ada_hitam, queue *giliran, address_list *P, address_list *P2, papan *board[10][10]){
    boolean can = false;
    list kawan, lawan;
    if (InfoTail(*giliran) == 1) { //putih
        kawan = *list_ada_putih; //piece yg masih ada di papan
        lawan = *list_ada_hitam;
    }
    else { //giliran == 2, hitam
        kawan = *list_ada_hitam;
        lawan = *list_ada_putih;
    }
    if (InfoTail(*giliran) == 1){ //giliran putih
        *P = First(*list_ada_putih); //raja
        *P2 = First(*list_ada_putih);} //benteng
    else{ //giliran == 2, hitam
        *P = First(*list_ada_hitam); //raja
        *P2 = First(*list_ada_hitam);} //benteng
    while(((*P) != Nil_list)&&!can){
        if((Info(*P).nama == 'K') && (!(HasMoved(Info(*P),*history)))){
            while((*P2) != Nil_list){
                if((Info(*P2).nama == 'R') && (!(HasMoved(Info(*P),*history)))){
                    if((((Info(*P2)).posisiC==(Info(*P).posisiC+3)) && !isthreaten(lawan, Info(*P).posisiC, Info(*P).posisiR, board, &P1, &jml) && 
                    !isthreaten(lawan, Info(*P).posisiC+1, Info(*P).posisiR, board, &P1, &jml) && !isthreaten(lawan, Info(*P).posisiC+2, Info(*P).posisiR, board, &P1, &jml) 
                    && (*board[Info(*P).posisiR][Info(*P).posisiC+1]).nama==' ' && (*board[Info(*P).posisiR][Info(*P).posisiC+2]).nama==' ' ) || 
                    //atau castling kiri
                    (((Info(*P2)).posisiC==(Info(*P).posisiC-4)) && !isthreaten(lawan, Info(*P).posisiC, Info(*P).posisiR, board, &P1, &jml) && 
                    !isthreaten(lawan, Info(*P).posisiC-1, Info(*P).posisiR, board, &P1, &jml) && !isthreaten(lawan, Info(*P).posisiC-2, Info(*P).posisiR, board, &P1, &jml) 
                    && !isthreaten(lawan, Info(*P).posisiC-3, Info(*P).posisiR, board, &P1, &jml) && (*board[Info(*P).posisiR][Info(*P).posisiC-1]).nama==' ' 
                    && (*board[Info(*P).posisiR][Info(*P).posisiC-2]).nama==' '  && (*board[Info(*P).posisiR][Info(*P).posisiC-2]).nama==' ' )){
                        can = true;
                        break;
                    }
                }
                *P2 = Next(*P2);
            }
        }
        if(!can)        
            *P = Next(*P);
    }
    return can;
}


void castling(stack *history, list *list_ada_putih, list *list_ada_hitam, queue *giliran, address_list P, address_list P2, int turn){
    infotype_stack X;
    int temp_posC;
    if(Info(P2).posisiC==8){
        Info(P2).posisiC = 6;
        Info(P).posisiC = 7;
    } else if (Info(P2).posisiC==1){
        Info(P2).posisiC = 4;
        Info(P).posisiC = 3;
    } 
    X.nama = Info(P).nama;
    X.player = InfoTail(*giliran);
    X.poin = Info(P).poin;
    X.posisiR_lama = Info(P).posisiR;
    X.posisiC_lama = 5;
    X.posisiR_baru = Info(P).posisiR;
    X.posisiC_baru = Info(P).posisiC;
    X.turn = turn;
    X.promotion = false;
    X.twosteps = false;
    X.enpassant = false;
    X.P = P2; //alamat benteng yg castling
    Push(history,X);
    if (InfoTail(*giliran) == 1) //giliran berubah
        Add(giliran, 2);
    else
        Add(giliran, 1);
}
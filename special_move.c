#include <stdio.h>
#include <stdlib.h>
#include "tipe_bentukan.h"


boolean cek_enpassant(stack* history, list *list_ada_putih, list *list_ada_hitam, queue *giliran, address_list *P);
void enpassant(stack *history, stack *termakan, int *poin_putih, int *poin_hitam, list *list_ada_putih, list *list_ada_hitam, queue *giliran, int turn, address_list P);

void special_move(stack *history, stack *termakan, int *poin_putih, int *poin_hitam, list *list_ada_putih, list *list_ada_hitam, queue *giliran, int turn){
    address_list P;
    /*
    if(!cek_enpassant() && !cek_castling()){ //ga bisa dua-duanya
        printf("\nTidak ada gerakan khusus yang bisa dilakukan.\n");

    } else if(cek_enpassant() && cek_castling()){ //bisa dua-duanya
        printf("\nDaftar gerakan khusus yang bisa dilakukan:\n");
        printf("   1. Castling\n");
        printf("   2. En Passant\n");
        printf("Pilih gerakan khusus yang ingin dilakukan: ");
        //kalau 1
            castling();
            printf("Castling berhasil dilakukan\n");
        //kalau 2
            enpassant();
            printf("En Passant berhasil dilakukan\n");
    
    }*/ 
    if(cek_enpassant(history, list_ada_putih, list_ada_hitam, giliran, &P)){
        enpassant(history, termakan, poin_putih, poin_hitam, list_ada_putih, list_ada_hitam, giliran, turn, P);
        printf("En Passant berhasil dilakukan\n");
    } else{
        printf("\nTidak ada gerakan khusus yang bisa dilakukan.\n");
    }
}

boolean cek_enpassant(stack* history, list *list_ada_putih, list *list_ada_hitam, queue *giliran, address_list *P){
    boolean found=false;
    if ((*history).T[(*history).TOP].twosteps){ //pion musuh baru jalan 2 kotak
        //dicek di sebelah pion musuh tsb ada pion temen atau tidak
        if (InfoTail(*giliran) == 1) //giliran putih
            *P = First(*list_ada_putih);
        else //giliran == 2, hitam
            *P = First(*list_ada_hitam);

        while((*P) != Nil_list){
            if((Info(*P).nama == 'P') || (Info(*P).nama == 'p')){ //kalau pion
                if(Info(*P).posisiR == (*history).T[(*history).TOP].posisiR_baru){ //kalau satu baris
                    if(abs(Info(*P).posisiC - (*history).T[(*history).TOP].posisiC_baru) == 1) //kalau sebelahan
                        found=true; //pion temen sebelahan dengan pion musuh tsb
                        break;
                }
            }
            *P = Next(*P);
        }
    }
    return found;
}

void enpassant(stack *history, stack *termakan, int *poin_putih, int *poin_hitam, list *list_ada_putih, list *list_ada_hitam, queue *giliran, int turn, address_list P){
    infotype_stack X;
    int tempR = Info(P).posisiR;
    int tempC = Info(P).posisiC;

    printf("%d\n",tempR);
    printf("%d\n",tempC);

    if (InfoTail(*giliran) == 1){ //giliran putih
        Info(P).posisiR--;
        *poin_putih = *poin_putih + 1;
    } else{ //giliran == 2, hitam
        Info(P).posisiR++;
        *poin_hitam = *poin_hitam + 1;
    }

    Info(P).posisiC = (*history).T[(*history).TOP].posisiC_baru;

    X.nama = InfoTail(*giliran)==1 ? 'p' : 'P'; //bidak lawan yg termakan
    X.player = (InfoTail(*giliran) % 2) + 1; //lawan
    X.poin = 1;
    X.turn = turn;
    X.posisiR_lama = X.posisiR_baru = InfoTail(*giliran)==1 ? Info(P).posisiR++ : Info(P).posisiR--;
    X.posisiC_lama = X.posisiC_baru = Info(P).posisiC;
    Push(termakan, X); //masukkan ke stack termakan

    printf("%d\n",X.posisiC_baru);
    printf("%d\n",X.posisiR_baru);

    X.nama = InfoTail(*giliran)==1 ? 'P' : 'p'; //bidak yg barusan makan en passant
    X.player = InfoTail(*giliran);
    X.posisiR_lama = tempR;
    X.posisiC_lama = tempC;
    X.posisiR_baru = InfoTail(*giliran)==1 ? tempR-- : tempR++;
    Push(history, X); //masukkan ke stack history
}


/*
boolean HasMoved(piece P, stack history)
{
    infotype_stack X;
    int counter = 1;
    boolean Moved = false;

    while ((!Moved) && (counter <= (history.T[(history).TOP].turn))){   
        X = (history).T[(history).TOP];
        history.TOP--;
    
        if (X.nama == P.nama)
            Moved = true;
        counter++;
    }
    return Moved;
}

void castling(piece Raja, piece Benteng, stack history, papan* board[10][10])
{
    if (!(HasMoved(Raja, history))) //kalau raja belum pernah gerak
    {
        if (((*board[Raja.posisiR][Raja.posisiC+2]).nama == ' ') && ((*board[Raja.posisiR][Raja.posisiC+1]).nama == ' ') && (!(HasMoved(Benteng, history))))
        {
            // (*board[Raja.posisiR][Raja.posisiC+2]).nama == 'R';
        }
    }
}*/
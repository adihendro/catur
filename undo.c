#include <stdio.h>
#include "tipe_bentukan.h"

void undo(stack *history, stack *termakan, int *poin_putih, int *poin_hitam, list *list_ada_putih, list *list_ada_hitam, queue *giliran, int turn){
    infotype_stack X;
    address_list P;

    if(turn==0){ //belum ada gerakan
        printf("Belum ada gerakan.\n");
        printf("Undo gagal.\n");

    } else if(turn==1){ //baru putih yang gerak
        Pop(history, &X);
        P = First(*list_ada_putih);
        while((Info(P).posisiC != X.posisiC_baru) || (Info(P).posisiR != X.posisiR_baru))
            P = Next(P);
        //P sudah menunjuk kepada bidak yg ingin diundo
        Info(P).posisiC = X.posisiC_lama;
        Info(P).posisiR = X.posisiR_lama;
        Add(giliran, 1);

        printf("Gerakan sebelumnya berhasil dibatalkan.\n");

    } else{ //game udh jalan biasa
            Pop(history, &X);
        if (InfoTail(*giliran) == 1) { //giliran putih
            P = First(*list_ada_hitam);//hitam dulu yang diambil
            while((Info(P).posisiC != X.posisiC_baru) || (Info(P).posisiR != X.posisiR_baru))
                P = Next(P);
            //P sudah menunjuk kepada bidak yg ingin diundo
            Info(P).posisiC = X.posisiC_lama;
            Info(P).posisiR = X.posisiR_lama;

            Pop(history, &X);
            P = First(*list_ada_putih);//baru putih yang diambil
            while((Info(P).posisiC != X.posisiC_baru) || (Info(P).posisiR != X.posisiR_baru))
                P = Next(P);
            //P sudah menunjuk kepada bidak yg ingin diundo
            Info(P).posisiC = X.posisiC_lama;
            Info(P).posisiR = X.posisiR_lama;

        } else{ //giliran hitam
            P = First(*list_ada_putih);//putih dulu yang diambil
            while((Info(P).posisiC != X.posisiC_baru) || (Info(P).posisiR != X.posisiR_baru))
                P = Next(P);
            //P sudah menunjuk kepada bidak yg ingin diundo
            Info(P).posisiC = X.posisiC_lama;
            Info(P).posisiR = X.posisiR_lama;

            Pop(history, &X);
            P = First(*list_ada_hitam);//baru hitam yang diambil
            while((Info(P).posisiC != X.posisiC_baru) || (Info(P).posisiR != X.posisiR_baru))
                P = Next(P);
            //P sudah menunjuk kepada bidak yg ingin diundo
            Info(P).posisiC = X.posisiC_lama;
            Info(P).posisiR = X.posisiR_lama;
        }
            
        printf("Gerakan sampai giliran sebelumnya berhasil dibatalkan.\n");
    }
}
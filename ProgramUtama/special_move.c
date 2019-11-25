#include "tipe_bentukan.h"

boolean cek_enpassant(papan *board[10][10], stack* history, list *list_ada_putih, list *list_ada_hitam, queue *giliran, address_list *Pe);
void enpassant(papan *board[10][10], stack *history, stack *termakan, int *poin_putih, int *poin_hitam, list *list_ada_putih, list *list_ada_hitam, queue *giliran, int turn, address_list Pe);
boolean cek_castling(stack* history, list *list_ada_putih, list *list_ada_hitam, queue *giliran, address_list *P, address_list *P1, address_list *P2, papan *board[10][10], int *jumlah);
void castling(stack *history, list *list_ada_putih, list *list_ada_hitam, queue *giliran, address_list P, address_list P2, int turn);


void special_move(papan *board[10][10], stack *history, stack *termakan, int *poin_putih, int *poin_hitam, list *list_ada_putih, list *list_ada_hitam, queue *giliran, int turn){
    address_list Pe, P, P1, P2;
    int X, jumlah;
    
    if(!cek_enpassant(board, history, list_ada_putih, list_ada_hitam, giliran, &Pe) && !cek_castling(history, list_ada_putih, list_ada_hitam, giliran, &P, &P1, &P2, board, &jumlah)){ //ga bisa dua-duanya
        printf("\nTidak ada gerakan khusus yang bisa dilakukan.\n");

    } else if(cek_enpassant(board, history, list_ada_putih, list_ada_hitam, giliran, &Pe) && cek_castling(history, list_ada_putih, list_ada_hitam, giliran, &P, &P1, &P2, board, &jumlah)){ //bisa dua-duanya
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

        if(X==49){ //kalau 1
            if(jumlah==1) //cuman castling kanan
                castling(history, list_ada_putih, list_ada_hitam, giliran, P, P1, turn);
            else if(jumlah==2) //cuman castling kiri
                castling(history, list_ada_putih, list_ada_hitam, giliran, P, P2, turn);
            else{ //jumlah==3, castling kanan kiri
                printf("\nTerdapat dua jenis Castling:\n");
                printf("   1. Castling pendek\n");
                printf("   2. Castling panjang\n");
                printf("Pilih gerakan Castling yang ingin dilakukan: ");
                do{    
                    choice = (char*) malloc (sizeof(100));
                    scanf("%s",choice);
                    stringToInt(choice,&X);
                    if(!(X==49 || X==50))
                        printf("Wrong input!\n");
                } while(!(X==49 || X==50));
                if(X==49)
                    castling(history, list_ada_putih, list_ada_hitam, giliran, P, P1, turn);
                else //kalau 2
                    castling(history, list_ada_putih, list_ada_hitam, giliran, P, P2, turn);
            }
            printf("\nCastling berhasil dilakukan.\n");
        }

        else { //kalau 2
            enpassant(board, history, termakan, poin_putih, poin_hitam, list_ada_putih, list_ada_hitam, giliran, turn, Pe);
            printf("\nEn Passant berhasil dilakukan.\n");
        }

    } else if(cek_enpassant(board, history, list_ada_putih, list_ada_hitam, giliran, &Pe)){
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
            enpassant(board, history, termakan, poin_putih, poin_hitam, list_ada_putih, list_ada_hitam, giliran, turn, Pe);
            printf("\nEn Passant berhasil dilakukan.\n");}

    } else if(cek_castling(history, list_ada_putih, list_ada_hitam, giliran, &P, &P1, &P2, board, &jumlah)){
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
            if(jumlah==1) //cuman castling kanan
                castling(history, list_ada_putih, list_ada_hitam, giliran, P, P1, turn);
            else if(jumlah==2) //cuman castling kiri
                castling(history, list_ada_putih, list_ada_hitam, giliran, P, P2, turn);
            else{ //jumlah==3, castling kanan kiri
                printf("\nTerdapat dua jenis Castling:\n");
                printf("   1. Castling pendek\n");
                printf("   2. Castling panjang\n");
                printf("Pilih gerakan Castling yang ingin dilakukan: ");
                do{    
                    choice = (char*) malloc (sizeof(100));
                    scanf("%s",choice);
                    stringToInt(choice,&X);
                    if(!(X==49 || X==50))
                        printf("Wrong input!\n");
                } while(!(X==49 || X==50));
                if(X==49){
                    castling(history, list_ada_putih, list_ada_hitam, giliran, P, P1, turn);
                }else //kalau 2
                    castling(history, list_ada_putih, list_ada_hitam, giliran, P, P2, turn);
            }
            printf("\nCastling berhasil dilakukan.\n");
        }
    }
}


boolean cek_enpassant(papan *board[10][10], stack* history, list *list_ada_putih, list *list_ada_hitam, queue *giliran, address_list *Pe){
    boolean found=false;
    int tempR;
    if ((*history).T[(*history).TOP].twosteps){ //pion musuh baru jalan 2 kotak
        //dicek di sebelah pion musuh tsb ada pion temen atau tidak
        if (InfoTail(*giliran) == 1){ //giliran putih
            *Pe = First(*list_ada_putih);
            kawan = *list_ada_putih;
            lawan = *list_ada_hitam;
            tempR = 3;
        } else{ //giliran == 2, hitam
            *Pe = First(*list_ada_hitam);
            kawan = *list_ada_hitam;
            lawan = *list_ada_putih;
            tempR = 6;
        }

        while((*Pe) != Nil_list){
            if(Info(*Pe).nama == 'P'){ //kalau pion
                if(Info(*Pe).posisiR == (*history).T[(*history).TOP].posisiR_baru){ //kalau satu baris
                    if(abs(Info(*Pe).posisiC - (*history).T[(*history).TOP].posisiC_baru) == 1) //kalau sebelahan
                        if(!jadi_skak(lawan, kawan, board, Info(*Pe), tempR, Info(*Pe).posisiC)){ //kalau setelah pindah ga skak
                            found=true; //pion temen sebelahan dengan pion musuh tsb
                            break;
                        }
                }
            }
            *Pe = Next(*Pe);
        }
    }
    return found;
}

void enpassant(papan *board[10][10], stack *history, stack *termakan, int *poin_putih, int *poin_hitam, list *list_ada_putih, list *list_ada_hitam, queue *giliran, int turn, address_list Pe){
    infotype_stack X;
    address_list A, A1;
    int tempR = Info(Pe).posisiR;
    int tempC = Info(Pe).posisiC;

    Info(Pe).posisiC = (*history).T[(*history).TOP].posisiC_baru;

    if (InfoTail(*giliran) == 1){ //giliran putih
        Info(Pe).posisiR--;
        *poin_putih = *poin_putih + 1;

        A1 = Search(*list_ada_hitam, Info(Pe).posisiC, tempR); //address sebelum bidak lawan yang termakan
        A = Next(A1); //address bidak lawan yang termakan
        DelAfter(list_ada_hitam, &A, A1); // hapus bidak lawan dari list linier lawan 

    } else{ //giliran == 2, hitam
        Info(Pe).posisiR++;
        *poin_hitam = *poin_hitam + 1;
        
        A1 = Search(*list_ada_putih, Info(Pe).posisiC, tempR); //address sebelum bidak lawan yang termakan
        A = Next(A1); //address bidak lawan yang termakan
        DelAfter(list_ada_putih, &A, A1); // hapus bidak lawan dari list linier lawan 
    }

    //bidak lawan yg termakan
    X.nama = Info(Pe).nama; 
    X.player = (InfoTail(*giliran) % 2) + 1; //lawan
    X.poin = 1;
    X.turn = turn;
    X.posisiR_lama = X.posisiR_baru = InfoTail(*giliran)==1 ? ++Info(Pe).posisiR : --Info(Pe).posisiR;
    X.posisiC_lama = X.posisiC_baru = Info(Pe).posisiC;
    X.enpassant = true;
    Push(termakan, X); //masukkan ke stack termakan

    //bidak yg barusan makan en passant
    X.nama = Info(Pe).nama; 
    X.player = InfoTail(*giliran);
    X.posisiR_lama = tempR;
    X.posisiC_lama = tempC;
    X.posisiR_baru = InfoTail(*giliran)==1 ? --tempR : ++tempR;
    Push(history, X); //masukkan ke stack history

    // update nilai awal di list_ada menjadi nilai akhir
    Info(Pe).posisiR = X.posisiR_baru;

    if (InfoTail(*giliran) == 1) //giliran berubah
        Add(giliran, 2);
    else
        Add(giliran, 1);
}


boolean hasmoved(piece P, stack history){ //ngecek apakah raja ada di stack history ato ngga
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

boolean cek_castling(stack* history, list *list_ada_putih, list *list_ada_hitam, queue *giliran, address_list *P, address_list *P1, address_list *P2, papan *board[10][10], int *jumlah){
    boolean can = false;
    list kawan, lawan;
    *jumlah = 0;
    address_list Pt, P1t, P2t, P3;
    if (InfoTail(*giliran) == 1) { //putih
        kawan = *list_ada_putih; //piece yg masih ada di papan
        lawan = *list_ada_hitam;
        Pt = First(*list_ada_putih); //raja
        P1t = Pt; //benteng
        P2t = Pt; //benteng
    } else { //giliran == 2, hitam
        kawan = *list_ada_hitam;
        lawan = *list_ada_putih;
        Pt = First(*list_ada_hitam); //raja
        P1t = Pt; //benteng
        P2t = Pt; //benteng
    }

    while((Pt != Nil_list) && !can){
        if((Info(Pt).nama == 'K') && !hasmoved(Info(Pt),*history)){
            *P = Pt;
            while(P1t != Nil_list){
                if((Info(P1t).nama == 'R') && !hasmoved(Info(Pt),*history)){
                    //castling kanan
                    if(((Info(P1t).posisiC==(Info(Pt).posisiC+3)) && !isthreaten(lawan, Info(Pt).posisiC, Info(Pt).posisiR, board, &P3) && 
                    !isthreaten(lawan, (Info(Pt).posisiC+1), Info(Pt).posisiR, board, &P3) && !isthreaten(lawan, Info(Pt).posisiC+2, Info(Pt).posisiR, board, &P3) 
                    && (*board[Info(Pt).posisiR][Info(Pt).posisiC+1]).nama==' ' && (*board[Info(Pt).posisiR][Info(Pt).posisiC+2]).nama==' ' )){
                        (*jumlah) += 1;
                        *P1 = P1t;
                    }
                    //atau castling kiri
                    if(((Info(P2t).posisiC==(Info(Pt).posisiC-4)) && !isthreaten(lawan, Info(Pt).posisiC, Info(Pt).posisiR, board, &P3) && 
                    !isthreaten(lawan, Info(Pt).posisiC-1, Info(Pt).posisiR, board, &P3) && !isthreaten(lawan, Info(Pt).posisiC-2, Info(Pt).posisiR, board, &P3) 
                    && !isthreaten(lawan, Info(Pt).posisiC-3, Info(Pt).posisiR, board, &P3) && (*board[Info(Pt).posisiR][Info(Pt).posisiC-1]).nama==' ' 
                    && (*board[Info(Pt).posisiR][Info(Pt).posisiC-2]).nama==' '  && (*board[Info(Pt).posisiR][Info(Pt).posisiC-2]).nama==' ' )){
                        (*jumlah) += 2;
                        *P2 = P2t;
                    }
                }
                P1t = Next(P1t);
                P2t = Next(P2t);
            }
        }
        Pt = Next(Pt);
    }

    if(*jumlah != 0)
        can = true;

    return can;
}

void castling(stack *history, list *list_ada_putih, list *list_ada_hitam, queue *giliran, address_list P, address_list P2, int turn){
    infotype_stack X;
    int temp_posC;
    if(Info(P2).posisiC==8){ //benteng
        Info(P2).posisiC = 6;
        Info(P).posisiC = 7;
    } else if (Info(P2).posisiC==1){ //benteng
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
    Push(history,X);

    if (InfoTail(*giliran) == 1) //giliran berubah
        Add(giliran, 2);
    else
        Add(giliran, 1);
}
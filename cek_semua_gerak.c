#include <stdio.h>
#include "tipe_bentukan.h"
#include "boolean.h"

#define kotak (*board[F.posisiR + a*x1*x2][F.posisiC + b*x1*x2])
int i,j,k,a,b,temp;
boolean br;
posisi P;

void cek(int a, int b, int x1, int x2, piece F, papan *board[10][10], list_posisi *L){
    br=false;
    if(kotak.nama==' '){ //kalau kotak kosong
        P.posisiR = F.posisiR + a*x1*x2;
        P.posisiC = F.posisiC + b*x1*x2;
        InsVLast_posisi(L,P);

    } else{ //kotak = */temen/musuh
        br=true; //break loop
        if(kotak.nama!='*' && kotak.player!=F.player){ //kalau kotak = musuh
            P.posisiR = F.posisiR + a*x1*x2;
            P.posisiC = F.posisiC + b*x1*x2;
            InsVLast_posisi(L,P);
        }
    }
}

void pawn(piece F, papan *board[10][10], list_posisi *L){
    a = F.player==1 ? -1 : 1;
    b = F.player==1 ? 2 : 1;
    cek(a,0,1,1,F,board, L);
    for(i=-1;i<=1;i=i+2){
        if((*board[F.posisiR + a][F.posisiC + i]).player==b){ //kalau kotak = musuh
            cek(a,i,1,1,F,board, L);
        }
    }
    
    if(F.player==1 && F.posisiR==7){
        cek(-2,0,1,1,F,board, L);
    } else if(F.player==2 && F.posisiR==2){
        cek(2,0,1,1,F,board, L);
    }
}

void rook(piece F, papan *board[10][10], list_posisi *L){
    a=1, b=0;
    for(i=0;i<2;i++){
        for(j=-1;j<=1;j=j+2){
            for(k=1;k<=7;k++){
                cek(a,b,j,k,F,board, L);
                if(br){break;}
            }
        }
        a=0;
        b=1;
    }
}

void bishop(piece F, papan *board[10][10], list_posisi *L){
    a=1;
    for(i=0;i<2;i++){
        for(j=-1;j<=1;j=j+2){
            for(k=1;k<=7;k++){
                cek(a,1,j,k,F,board, L);
                if(br){break;}
            }
        }
        a=-1;
    }
}

void king(piece F, papan *board[10][10], list_posisi *L){
    a=1, b=1;
    for(i=0;i<8;i++){
        cek(a,b,1,1,F,board, L);
        temp=a;
        a=b;
        b=-temp;
        if(i==3){
            a=0;
        }
    }
}

void knight(piece F, papan *board[10][10], list_posisi *L){
    a=1, b=2;
    for(i=0;i<8;i++){
        if((F.posisiR+a) >=1 && (F.posisiR+a) <=8 && 
           (F.posisiC+b) >=1 && (F.posisiC+b) <=8){
            cek(a,b,1,1,F,board, L);
        }
        temp=a;
        a=b;
        b=-temp;
        if(i==3){
            a=2;
            b=1;
        }
    }
}

void ceksemuagerak(piece F, papan *board[10][10], list_posisi *L){
    switch(F.nama){
        case 'P': pawn(F, board, L); break;
        case 'R': rook(F, board, L); break;
        case 'B': bishop(F, board, L); break;
        case 'Q': rook(F, board, L); bishop(F, board, L); break;
        case 'K': king(F, board, L); break;
        case 'N': knight(F, board, L); break;
    }
}

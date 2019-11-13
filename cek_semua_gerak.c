#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"
#include "tipe_bentukan.h"
#include "boolean.h"

#define kotak board[F.posisiR + a*x1*x2][F.posisiC + b*x1*x2]
int i,j,k,a,b,temp;
boolean br;
list L;

void cek(int a, int b, int x1, int x2, piece F, papan board[10][10]){
    br=false;
    if(kotak.nama==' '){ //kalau kotak kosong
        InsVLast(&L,F);

    } else{ //kotak = */temen/musuh
        br=true; //break loop
        if(kotak.nama!='*' && kotak.player!=F.player){ //kalau kotak = musuh
            InsVLast(&L,F);      
        }
    }
}

void pawn(piece F, papan board[10][10]){
    a = F.player==1 ? -1 : 1;
    for(i=-1;i<=1;i++){
        cek(a,i,1,1,F,board);
    }
    if(F.player==1 && F.posisiR==7){
        cek(-2,0,1,1,F,board);
    } else if(F.player==2 && F.posisiR==2){
        cek(2,0,1,1,F,board);
    }
}

void rook(piece F, papan board[10][10]){
    a=1, b=0;
    for(i=0;i<2;i++){
        for(j=-1;j<=1;j=j+2){
            for(k=1;k<=7;k++){
                cek(a,b,j,k,F,board);
                if(br){printf("\n");break;}
            }
        }
        a=0;
        b=1;
    }
}

void bishop(piece F, papan board[10][10]){
    a=1;
    for(i=0;i<2;i++){
        for(j=-1;j<=1;j=j+2){
            for(k=1;k<=7;k++){
                cek(a,1,j,k,F,board);
                if(br){printf("\n");break;}
            }
        }
        a=-1;
    }
}

void king(piece F, papan board[10][10]){
    a=1, b=1;
    for(i=0;i<8;i++){
        cek(a,b,1,1,F,board);
        temp=a;
        a=b;
        b=-temp;
        if(i==3){
            a=0;
        }
    }
}

void knight(piece F, papan board[10][10]){
    a=1, b=2;
    for(i=0;i<8;i++){
        if((F.posisiR+a) >=1 && (F.posisiR+a) <=8 && 
           (F.posisiC+b) >=1 && (F.posisiC+b) <=8){
            cek(a,b,1,1,F,board);
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

void ceksemuagerak(piece F, papan board[10][10]){
    CreateEmpty(&L);
    switch(F.nama){
        case 'P': pawn(F, board); break;
        case 'R': rook(F, board); break;
        case 'B': bishop(F, board); break;
        case 'Q': rook(F, board); bishop(F, board); break;
        case 'K': king(F, board); break;
        case 'N': knight(F, board); break;
    }
}


/*
int main() {
    piece F;
    papan board[10][10];
    F.nama = 'K';
    F.poin = 1;
    F.player = 1;
    F.posisiR = 2;
    F.posisiC = 2;

    for(i=1;i<=8;i++){
        for(j=1;j<=8;j++){
            board[i][j].nama = ' ';
        }
    }

    board[1][1].nama = 'P';
    board[1][1].player = 1;

    board[1][2].nama = 'P';
    board[1][2].player = 2;

    board[1][3].nama = ' ';
    board[1][3].player = 1;

    board[2][1].nama = ' ';
    board[2][1].player = 1;

    board[2][3].nama = 'Q';
    board[2][3].player = 1;
    
    board[3][1].nama = 'P';
    board[3][1].player = 2;

    board[3][2].nama = ' ';
    board[3][2].player = 2;

    board[3][3].nama = ' ';
    board[3][3].player = 1;

    ceksemuagerak(F,board);
    
    return 0;
}
*/
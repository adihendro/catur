#include <stdio.h>
#include <stdlib.h>
// #include "listlinier.h"
#include "tipe_bentukan.h"
#include "boolean.h"

#define kotak board[F.posisiR + a*x1*x2][F.posisiC + b*x1*x2]
int i,j,k,temp;
boolean br, enemy;

void cek(int a, int b, int x1, int x2, piece F, papan board[10][10]){
    br=false;
    enemy=false;
    if(kotak.nama==' '){ //kalau kotak kosong
        //InsVLast(L,F);
        printf("kosong\n");
    } else{
        if(kotak.nama!='*' && kotak.player!=F.player){ //kalau kotak = musuh
            //InsVLast(L,F);
            printf("musuh\n");
            enemy=true;       
        }
        br=true; //break loop
    }
}

void pawn(piece F, papan board[10][10]){
    int a = F.player==1 ? -1 : 1;
    for(i=-1;i<=1;i++){
        cek(a,i,1,1,F,board);
    }
}

void rook(piece F, papan board[10][10]){
    int a=1, b=0;
    for(i=0;i<2;i++){
        for(j=-1;j<=1;j=j+2){
            for(k=1;k<=7;k++){
                cek(a,b,j,k,F,board);
                if(br){break;}
            }
        }
        temp=a;
        a=b;
        b=temp;
    }
}

void bishop(piece F, papan board[10][10]){
    int a=1;
    for(i=0;i<2;i++){
        for(j=-1;j<=1;j=j+2){
            for(k=1;k<=7;k++){
                cek(a,1,j,k,F,board);
                if(br){break;}
            }
        }
        a=-1;
    }
}

void king(piece F, papan board[10][10]){
    int a=1, b=1;
    for(i=0;i<8;i++){
        cek(a,b,1,1,F,board);
        temp=a;
        a=b;
        b=-temp;
        if(i==4){
            a=0;
        }
    }
}

void knight(piece F, papan board[10][10]){
    int a=1, b=2;
    for(i=0;i<8;i++){
        cek(a,b,1,1,F,board);
        temp=a;
        a=b;
        b=-temp;
        if(i==4){
            a=2;
            b=1;
        }
    }
}

void ceksemuagerak(piece F, papan board[10][10]){
    // if(F.nama=='P'){
    //     pawn(F, board);
    // } else if(F.nama=='R'){
    //     rook(F, board);
    // } else if(F.nama=='B'){
    //     bishop(F, board);
    // } else if(F.nama=='Q'){
    //     rook(F, board);
    //     bishop(F, board);
    // } else if(F.nama=='K'){
    //     king(F, board);
    // } else if(F.nama=='N'){
    //     knight(F, board);
    // }

    switch(F.nama){
        case 'P': pawn(F, board); break;
        case 'R': rook(F, board); break;
        case 'B': bishop(F, board); break;
        case 'Q': rook(F, board); bishop(F, board); break;
        case 'K': king(F, board); break;
        case 'N': knight(F, board); break;
    }
}




int main() {
    piece F;
    papan board[10][10];
    F.nama = 'P';
    F.poin = 1;
    F.player = 1;
    F.posisiR = 3;
    F.posisiC = 5;

    board[2][4].nama = 'P';
    board[2][4].player = 1;
    
    board[2][5].nama = ' ';
    board[2][5].player = 1;

    board[2][6].nama = 'P';
    board[2][6].player = 2;

    ceksemuagerak(F,board);
    
    return 0;
}

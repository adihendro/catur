#include <stdio.h>
#include <stdlib.h>
#include "tipe_bentukan.h"
#include "boolean.h"

//posisiR dan posisiC terdefinisi
int cekbisagerak(piece F, papan board[10][10]){ //cek bisa atau tidak {1:bisa ; 0:tidak} kalo bisa kita masukin ke list linier list_bisa_gerak
    if(F.nama=='P'){
        if(F.player==1){ //putih
            if(board[F.posisiR-1][F.posisiC].nama == ' '){
                return 1;
            } else if(((board[F.posisiR-1][F.posisiC+1].nama != '*') && (board[F.posisiR-1][F.posisiC+1].nama != ' ') && (board[F.posisiR-1][F.posisiC+1].player != 1))
            || ((board[F.posisiR-1][F.posisiC-1].nama != '*') && (board[F.posisiR-1][F.posisiC-1].nama != ' ') && (board[F.posisiR-1][F.posisiC-1].player != 1))){
                return 1;
            } else{
                return 0;
            }
        } else if (F.player==2){ //hitam
            if(board[F.posisiR+1][F.posisiC].nama == ' '){
                return 1;
            } else if(((board[F.posisiR+1][F.posisiC+1].nama != '*') && (board[F.posisiR+1][F.posisiC+1].nama != ' ') && (board[F.posisiR+1][F.posisiC+1].player != 2))
            || ((board[F.posisiR+1][F.posisiC-1].nama != '*') && (board[F.posisiR+1][F.posisiC-1].nama != ' ') && (board[F.posisiR+1][F.posisiC-1].player != 2))){
                return 1;
            } else{
                return 0;
            }
        }
    } else if(F.nama=='K'){
        if (F.player==1){
            if(board[F.posisiR-1][F.posisiC].nama == ' ' || board[F.posisiR-1][F.posisiC-1].nama == ' ' || board[F.posisiR][F.posisiC-1].nama == ' '
            || board[F.posisiR+1][F.posisiC-1].nama == ' ' || board[F.posisiR+1][F.posisiC].nama == ' ' || board[F.posisiR+1][F.posisiC+1].nama == ' '
            || board[F.posisiR][F.posisiC+1].nama == ' ' || board[F.posisiR-1][F.posisiC+1].nama == ' '){
                return 121;
            } else if (((board[F.posisiR+1][F.posisiC+1].nama != '*') && (board[F.posisiR+1][F.posisiC+1].nama != ' ') && (board[F.posisiR+1][F.posisiC+1].player != 1))
            || ((board[F.posisiR+1][F.posisiC].nama != '*') && (board[F.posisiR+1][F.posisiC].nama != ' ') && (board[F.posisiR+1][F.posisiC].player != 1))
            || ((board[F.posisiR+1][F.posisiC-1].nama != '*') && (board[F.posisiR+1][F.posisiC-1].nama != ' ') && (board[F.posisiR+1][F.posisiC-1].player != 1))
            || ((board[F.posisiR][F.posisiC+1].nama != '*') && (board[F.posisiR][F.posisiC+1].nama != ' ') && (board[F.posisiR][F.posisiC+1].player != 1))
            || ((board[F.posisiR-1][F.posisiC+1].nama != '*') && (board[F.posisiR-1][F.posisiC+1].nama != ' ') && (board[F.posisiR-1][F.posisiC+1].player != 1))
            || ((board[F.posisiR][F.posisiC-1].nama != '*') && (board[F.posisiR][F.posisiC-1].nama != ' ') && (board[F.posisiR][F.posisiC-1].player != 1))
            || ((board[F.posisiR-1][F.posisiC-1].nama != '*') && (board[F.posisiR-1][F.posisiC-1].nama != ' ') && (board[F.posisiR-1][F.posisiC-1].player != 1))
            || ((board[F.posisiR-1][F.posisiC].nama != '*') && (board[F.posisiR-1][F.posisiC].nama != ' ') && (board[F.posisiR-1][F.posisiC].player != 1))){
                return 12;
            } else{
                return 0;
            }
        } else if (F.player==2){
            if(board[F.posisiR-1][F.posisiC].nama == ' ' || board[F.posisiR-1][F.posisiC-1].nama == ' ' || board[F.posisiR][F.posisiC-1].nama == ' '
            || board[F.posisiR+1][F.posisiC-1].nama == ' ' || board[F.posisiR+1][F.posisiC].nama == ' ' || board[F.posisiR+1][F.posisiC+1].nama == ' '
            || board[F.posisiR][F.posisiC+1].nama == ' ' || board[F.posisiR-1][F.posisiC+1].nama == ' '){
                return 18;
            } else if (((board[F.posisiR+1][F.posisiC+1].nama != '*') && (board[F.posisiR+1][F.posisiC+1].nama != ' ') && (board[F.posisiR+1][F.posisiC+1].player != 2))
            || ((board[F.posisiR+1][F.posisiC].nama != '*') && (board[F.posisiR+1][F.posisiC].nama != ' ') && (board[F.posisiR+1][F.posisiC].player != 2))
            || ((board[F.posisiR+1][F.posisiC-1].nama != '*') && (board[F.posisiR+1][F.posisiC-1].nama != ' ') && (board[F.posisiR+1][F.posisiC-1].player != 2))
            || ((board[F.posisiR][F.posisiC+1].nama != '*') && (board[F.posisiR][F.posisiC+1].nama != ' ') && (board[F.posisiR][F.posisiC+1].player != 2))
            || ((board[F.posisiR-1][F.posisiC+1].nama != '*') && (board[F.posisiR-1][F.posisiC+1].nama != ' ') && (board[F.posisiR-1][F.posisiC+1].player != 2))
            || ((board[F.posisiR][F.posisiC-1].nama != '*') && (board[F.posisiR][F.posisiC-1].nama != ' ') && (board[F.posisiR][F.posisiC-1].player != 2))
            || ((board[F.posisiR-1][F.posisiC-1].nama != '*') && (board[F.posisiR-1][F.posisiC-1].nama != ' ') && (board[F.posisiR-1][F.posisiC-1].player != 2))
            || ((board[F.posisiR-1][F.posisiC].nama != '*') && (board[F.posisiR-1][F.posisiC].nama != ' ') && (board[F.posisiR-1][F.posisiC].player != 2))){
                return 18;
            } else{
                return 0;
            }
        }
    } else if (F.nama=='Q'){
        if(F.player==1){
            if(board[F.posisiR-1][F.posisiC].nama == ' ' || board[F.posisiR-1][F.posisiC-1].nama == ' ' || board[F.posisiR][F.posisiC-1].nama == ' '
            || board[F.posisiR+1][F.posisiC-1].nama == ' ' || board[F.posisiR+1][F.posisiC].nama == ' ' || board[F.posisiR+1][F.posisiC+1].nama == ' '
            || board[F.posisiR][F.posisiC+1].nama == ' ' || board[F.posisiR-1][F.posisiC+1].nama == ' '){
                return 13;
            } else if (((board[F.posisiR+1][F.posisiC+1].nama != '*') && (board[F.posisiR+1][F.posisiC+1].nama != ' ') && (board[F.posisiR+1][F.posisiC+1].player != 1))
            || ((board[F.posisiR+1][F.posisiC].nama != '*') && (board[F.posisiR+1][F.posisiC].nama != ' ') && (board[F.posisiR+1][F.posisiC].player != 1))
            || ((board[F.posisiR+1][F.posisiC-1].nama != '*') && (board[F.posisiR+1][F.posisiC-1].nama != ' ') && (board[F.posisiR+1][F.posisiC-1].player != 1))
            || ((board[F.posisiR][F.posisiC+1].nama != '*') && (board[F.posisiR][F.posisiC+1].nama != ' ') && (board[F.posisiR][F.posisiC+1].player != 1))
            || ((board[F.posisiR-1][F.posisiC+1].nama != '*') && (board[F.posisiR-1][F.posisiC+1].nama != ' ') && (board[F.posisiR-1][F.posisiC+1].player != 1))
            || ((board[F.posisiR][F.posisiC-1].nama != '*') && (board[F.posisiR][F.posisiC-1].nama != ' ') && (board[F.posisiR][F.posisiC-1].player != 1))
            || ((board[F.posisiR-1][F.posisiC-1].nama != '*') && (board[F.posisiR-1][F.posisiC-1].nama != ' ') && (board[F.posisiR-1][F.posisiC-1].player != 1))
            || ((board[F.posisiR-1][F.posisiC].nama != '*') && (board[F.posisiR-1][F.posisiC].nama != ' ') && (board[F.posisiR-1][F.posisiC].player != 1))){
                return 13;
            } else{
                return 0;
            }
        } else if (F.player==2){
            if(board[F.posisiR-1][F.posisiC].nama == ' ' || board[F.posisiR-1][F.posisiC-1].nama == ' ' || board[F.posisiR][F.posisiC-1].nama == ' '
            || board[F.posisiR+1][F.posisiC-1].nama == ' ' || board[F.posisiR+1][F.posisiC].nama == ' ' || board[F.posisiR+1][F.posisiC+1].nama == ' '
            || board[F.posisiR][F.posisiC+1].nama == ' ' || board[F.posisiR-1][F.posisiC+1].nama == ' '){
                return 17;
            } else if (((board[F.posisiR+1][F.posisiC+1].nama != '*') && (board[F.posisiR+1][F.posisiC+1].nama != ' ') && (board[F.posisiR+1][F.posisiC+1].player != 2))
            || ((board[F.posisiR+1][F.posisiC].nama != '*') && (board[F.posisiR+1][F.posisiC].nama != ' ') && (board[F.posisiR+1][F.posisiC].player != 2))
            || ((board[F.posisiR+1][F.posisiC-1].nama != '*') && (board[F.posisiR+1][F.posisiC-1].nama != ' ') && (board[F.posisiR+1][F.posisiC-1].player != 2))
            || ((board[F.posisiR][F.posisiC+1].nama != '*') && (board[F.posisiR][F.posisiC+1].nama != ' ') && (board[F.posisiR][F.posisiC+1].player != 2))
            || ((board[F.posisiR-1][F.posisiC+1].nama != '*') && (board[F.posisiR-1][F.posisiC+1].nama != ' ') && (board[F.posisiR-1][F.posisiC+1].player != 2))
            || ((board[F.posisiR][F.posisiC-1].nama != '*') && (board[F.posisiR][F.posisiC-1].nama != ' ') && (board[F.posisiR][F.posisiC-1].player != 2))
            || ((board[F.posisiR-1][F.posisiC-1].nama != '*') && (board[F.posisiR-1][F.posisiC-1].nama != ' ') && (board[F.posisiR-1][F.posisiC-1].player != 2))
            || ((board[F.posisiR-1][F.posisiC].nama != '*') && (board[F.posisiR-1][F.posisiC].nama != ' ') && (board[F.posisiR-1][F.posisiC].player != 2))){
                return 17;
            } else{
                return 0;
            }
        }
    } else if (F.nama=='R'){
        if(F.player==1){
            if(board[F.posisiR-1][F.posisiC].nama == ' ' ||  board[F.posisiR][F.posisiC-1].nama == ' '
            || board[F.posisiR+1][F.posisiC].nama == ' ' || board[F.posisiR][F.posisiC+1].nama == ' ') {
                return 14;
            } else if (
             ((board[F.posisiR+1][F.posisiC].nama != '*') && (board[F.posisiR+1][F.posisiC].nama != ' ') && (board[F.posisiR+1][F.posisiC].player != 1))
            || ((board[F.posisiR][F.posisiC+1].nama != '*') && (board[F.posisiR][F.posisiC+1].nama != ' ') && (board[F.posisiR][F.posisiC+1].player != 1))
            || ((board[F.posisiR][F.posisiC-1].nama != '*') && (board[F.posisiR][F.posisiC-1].nama != ' ') && (board[F.posisiR][F.posisiC-1].player != 1))
            || ((board[F.posisiR-1][F.posisiC].nama != '*') && (board[F.posisiR-1][F.posisiC].nama != ' ') && (board[F.posisiR-1][F.posisiC].player != 1))){
                return 14;
            } else {
                return 0;
            }
        } else if (F.player==2){
            if(board[F.posisiR-1][F.posisiC].nama == ' ' ||  board[F.posisiR][F.posisiC-1].nama == ' '
            || board[F.posisiR+1][F.posisiC].nama == ' ' || board[F.posisiR][F.posisiC+1].nama == ' ') {
                return 16;
            } else if 
             (((board[F.posisiR+1][F.posisiC].nama != '*') && (board[F.posisiR+1][F.posisiC].nama != ' ') && (board[F.posisiR+1][F.posisiC].player != 2))
            || ((board[F.posisiR][F.posisiC+1].nama != '*') && (board[F.posisiR][F.posisiC+1].nama != ' ') && (board[F.posisiR][F.posisiC+1].player != 2))
            || ((board[F.posisiR][F.posisiC-1].nama != '*') && (board[F.posisiR][F.posisiC-1].nama != ' ') && (board[F.posisiR][F.posisiC-1].player != 2))
            || ((board[F.posisiR-1][F.posisiC].nama != '*') && (board[F.posisiR-1][F.posisiC].nama != ' ') && (board[F.posisiR-1][F.posisiC].player != 2))){
                return 16;
            } else {
                return 0;
            }
        }
    } else if (F.nama=='B'){
        if(F.player==1){
            if(board[F.posisiR-1][F.posisiC-1].nama == ' ' || board[F.posisiR+1][F.posisiC-1].nama == ' ' || board[F.posisiR+1][F.posisiC+1].nama == ' '
            || board[F.posisiR-1][F.posisiC+1].nama == ' '){
                return 15;
            } else if (((board[F.posisiR+1][F.posisiC+1].nama != '*') && (board[F.posisiR+1][F.posisiC+1].nama != ' ') && (board[F.posisiR+1][F.posisiC+1].player != 1))
            || ((board[F.posisiR+1][F.posisiC-1].nama != '*') && (board[F.posisiR+1][F.posisiC-1].nama != ' ') && (board[F.posisiR+1][F.posisiC-1].player != 1))
            || ((board[F.posisiR-1][F.posisiC+1].nama != '*') && (board[F.posisiR-1][F.posisiC+1].nama != ' ') && (board[F.posisiR-1][F.posisiC+1].player != 1))
            || ((board[F.posisiR-1][F.posisiC-1].nama != '*') && (board[F.posisiR-1][F.posisiC-1].nama != ' ') && (board[F.posisiR-1][F.posisiC-1].player != 1))){
                return 195;
            } else{
                return 0;
            }
        } else if (F.player==2){
            if(board[F.posisiR-1][F.posisiC-1].nama == ' ' || board[F.posisiR+1][F.posisiC-1].nama == ' ' || board[F.posisiR+1][F.posisiC+1].nama == ' '
            || board[F.posisiR-1][F.posisiC+1].nama == ' '){
                return 210;
            } else if (((board[F.posisiR+1][F.posisiC+1].nama != '*') && (board[F.posisiR+1][F.posisiC+1].nama != ' ') && (board[F.posisiR+1][F.posisiC+1].player != 2))
            || ((board[F.posisiR+1][F.posisiC-1].nama != '*') && (board[F.posisiR+1][F.posisiC-1].nama != ' ') && (board[F.posisiR+1][F.posisiC-1].player != 2))
            || ((board[F.posisiR-1][F.posisiC+1].nama != '*') && (board[F.posisiR-1][F.posisiC+1].nama != ' ') && (board[F.posisiR-1][F.posisiC+1].player != 2))
            || ((board[F.posisiR-1][F.posisiC-1].nama != '*') && (board[F.posisiR-1][F.posisiC-1].nama != ' ') && (board[F.posisiR-1][F.posisiC-1].player != 2))){
                return 10;
            } else{
                return 0;
            }
        }
    }  else if (F.nama=='N'){
        int hasil=0;
        int pemain=F.player;
            if(F.posisiR>=2 && F.posisiR<=7 && F.posisiC>=2 && F.posisiC <=7){
                if(board[F.posisiR+1][F.posisiC+2].nama == ' ' || board[F.posisiR+1][F.posisiC-2].nama == ' ' || board[F.posisiR+2][F.posisiC+1].nama == ' ' || 
                   board[F.posisiR+2][F.posisiC-1].nama == ' ' || board[F.posisiR-1][F.posisiC+2].nama == ' ' || board[F.posisiR-1][F.posisiC-2].nama == ' ' ||
                   board[F.posisiR-2][F.posisiC+1].nama == ' ' || board[F.posisiR-2][F.posisiC-1].nama == ' '){
                    hasil= 16;
                }
                else if((board[F.posisiR+1][F.posisiC+2].nama != '*' && board[F.posisiR+1][F.posisiC+2].nama != ' ' && board[F.posisiR+1][F.posisiC+2].player != pemain) || 
                        (board[F.posisiR+1][F.posisiC-2].nama != '*' && board[F.posisiR+1][F.posisiC-2].nama != ' ' && board[F.posisiR+1][F.posisiC-2].player != pemain) ||
                        (board[F.posisiR-1][F.posisiC+2].nama != '*' && board[F.posisiR-1][F.posisiC+2].nama != ' ' && board[F.posisiR-1][F.posisiC+2].player != pemain) ||
                        (board[F.posisiR-1][F.posisiC-2].nama != '*' && board[F.posisiR-1][F.posisiC-2].nama != ' ' && board[F.posisiR-1][F.posisiC-2].player != pemain) ||
                        (board[F.posisiR+2][F.posisiC+1].nama != '*' && board[F.posisiR+2][F.posisiC+1].nama != ' ' && board[F.posisiR+2][F.posisiC+1].player != pemain) ||
                        (board[F.posisiR+2][F.posisiC-1].nama != '*' && board[F.posisiR+2][F.posisiC-1].nama != ' ' && board[F.posisiR+2][F.posisiC-1].player != pemain) ||
                        (board[F.posisiR-2][F.posisiC+1].nama != '*' && board[F.posisiR-2][F.posisiC+1].nama != ' ' && board[F.posisiR-2][F.posisiC+1].player != pemain) ||
                        (board[F.posisiR-2][F.posisiC-1].nama != '*' && board[F.posisiR-2][F.posisiC-1].nama != ' ' && board[F.posisiR-2][F.posisiC-1].player != pemain)) {
                        hasil= 7;
                } else{
                    hasil= 102;
                }

            } else if(F.posisiR==1 && F.posisiC==1){ //knight di pojok kiri atas
                if(board[F.posisiR+1][F.posisiC+2].player != pemain || board[F.posisiR+2][F.posisiC+1].player != pemain ){
                    hasil= 78;
                }
            } else if(F.posisiR==1 && F.posisiC==8){ //knight di pojok kanan atas
                if(board[F.posisiR+1][F.posisiC-2].player != pemain || board[F.posisiR+2][F.posisiC-1].player != pemain ){
                    hasil= 99;
                }
            } else if(F.posisiR==8 && F.posisiC==1){ //knight di pojok kiri bawah
                if(board[F.posisiR-1][F.posisiC+2].player != pemain || board[F.posisiR-2][F.posisiC+1].player != pemain ){
                    hasil= 99;
                }
            } else if(F.posisiR==8 && F.posisiC==8){ //knight di pojok kanan bawah
                if(board[F.posisiR-1][F.posisiC-2].player != pemain || board[F.posisiR-2][F.posisiC-1].player != pemain ){
                    hasil= 99;
                }
            }

            else if(F.posisiR==1 && F.posisiC>=2 && F.posisiC<=7){ //knight di baris atas
                if((board[F.posisiR+1][F.posisiC+2].player != pemain && board[F.posisiR+1][F.posisiC+2].nama != '*') ||
                   (board[F.posisiR+1][F.posisiC-2].player != pemain && board[F.posisiR+1][F.posisiC-2].nama != '*') ||
                    board[F.posisiR+2][F.posisiC-1].player != pemain || board[F.posisiR+2][F.posisiC+1].player != pemain ){
                    hasil= 22;
                }
            } else if(F.posisiR>=2 && F.posisiR<=7 && F.posisiC==8){ //knight di baris kanan
                if((board[F.posisiR+2][F.posisiC-1].player != pemain && board[F.posisiR+2][F.posisiC-1].nama != '*') ||
                   (board[F.posisiR-2][F.posisiC-1].player != pemain && board[F.posisiR-2][F.posisiC-1].nama != '*') ||
                    board[F.posisiR+1][F.posisiC-2].player != pemain || board[F.posisiR-1][F.posisiC-2].player != pemain ){
                    hasil= 99;
                }
            } else if(F.posisiR==8 && F.posisiC>=2 && F.posisiC<=7){ //knight di baris bawah
                if((board[F.posisiR-1][F.posisiC+2].player != pemain && board[F.posisiR-1][F.posisiC+2].nama != '*') ||
                   (board[F.posisiR-1][F.posisiC-2].player != pemain && board[F.posisiR-1][F.posisiC-2].nama != '*') ||
                    board[F.posisiR-2][F.posisiC+1].player != pemain || board[F.posisiR-2][F.posisiC-1].player != pemain ){
                    hasil= 99;
                }
            } else if(F.posisiR>=2 && F.posisiR<=7 && F.posisiC==1){ //knight di baris kiri
                if((board[F.posisiR+2][F.posisiC+1].player != pemain && board[F.posisiR+2][F.posisiC+1].nama != '*') ||
                   (board[F.posisiR-2][F.posisiC+1].player != pemain && board[F.posisiR-2][F.posisiC+1].nama != '*') ||
                    board[F.posisiR+1][F.posisiC+2].player != pemain || board[F.posisiR-1][F.posisiC+2].player != pemain ){
                    hasil= 99;
                }
            }

            return hasil;
    }
    else {return 4;}
}

int main() {
    piece F;
    papan board[10][10];
    F.nama = 'N';
    F.poin = 1;
    F.player = 2;
    F.posisiR = 1;
    F.posisiC = 2;

    board[2][0].nama = '*';
    board[2][0].player = 2;

    board[3][3].nama = 'P';
    board[3][3].player = 1;
    
    board[3][1].nama = 'P';
    board[3][1].player = 2;

    board[2][4].nama = 'P';
    board[2][4].player = 2;

    board[4][1].nama = 'P';
    board[4][1].player = 2;

    board[1][2].nama = 'P';
    board[1][2].player = 2;

    board[1][4].nama = 'P';
    board[1][4].player = 2;

    board[5][2].nama = 'P';
    board[5][2].player = 2;

    board[5][4].nama = 'P';
    board[5][4].player = 2;

    board[4][1].nama = 'P';
    board[4][1].player = 2;
    
    
    printf("%d\n",cekbisagerak(F,board));
}


// if(board[F.posisiR+1][F.posisiC].nama != '*'){
//                 if(board[F.posisiR+1][F.posisiC+1].nama != '*'){
//                     if((board[F.posisiR+1][F.posisiC+2].nama == ' ') || ((board[F.posisiR+1][F.posisiC+2].nama != '*')&&(board[F.posisiR+1][F.posisiC+2].player == 2))){
//                         return 7;
//                     }
//                 } else if(board[F.posisiR+1][F.posisiC-1].nama != '*'){
//                     if((board[F.posisiR+1][F.posisiC-2].nama == ' ') || ((board[F.posisiR+1][F.posisiC-2].nama != '*')&&(board[F.posisiR+1][F.posisiC-2].player != 1))){
//                         return 9;
//                     }
//                 }
//             } else {
//                 return 8;
//             }
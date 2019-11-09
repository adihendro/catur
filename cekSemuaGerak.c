#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

typedef struct 
{
	infotype_posisi info;
	address next;
} list_posisi;  // list posisi adalah tipe bentukan dari infotype posisi, yang terdiri dari posisi baris dan posisi kolom, address next

typedef struct 
{
	int posisiR;
	int posisiC;
} infotype_posisi; // infotype posisi adalah tipe bentukan dari posisi baris dan posisi kolom

typedef struct 
{
	char nama;
	int player;
	int poin;
	int posisiR;
	int posisiC;
} piece; //sebuah piece memiliki nama (P,R,N,B,Q,K), punya putih(1) atau hitam(2), poin, dan posisi saat ini
	
typedef piece infotype;

void printKotak (piece square) // ngeprint square yang terdapat pada papan catur, sekaligus menkonversi dari papan kecil ke papan GUI
{
    if (squa)
}

void cekSemuaGerak (piece P , list_posisi *L)
{
    piece board[10][10]; // board adalah kumpulan square yang memiliki atribut sama dengan piece

    if (P.nama = "P") // kalo pion
    {
        // maju
            // putih: board[row][column] jadi board[row-1][column], hitam: board[row+1][column]
            // (opt) maju 2 langkah kalo di baris 2 (putih) atau di baris 7 (hitam)
                //maju 2 langkah kalo di board[n][7] (putih) atau di board[n][2] (hitam)
            // maju 1 langkah kalo di baris 2 - baris 7 (putih), baris 7 - baris 2 (hitam)

        // makan
            // putih: anggap posisi bidak di c,r; maka posisi bidak yang dapat dimakan adalah di posisi c+1 r-1 atau c-1 r-1
            // hitam: sama tapi ganti r+1 untuk rownya
        if(P.player = "1") // kalo pion putih
        {
            if( board[P.posisiC-1][P.posisiR].nama != " " && board[P.posisiC-1][P.posisiR].player == 2) // kalo sorong kiri atas pemain putih ada bidak lawan yang menempati, bisa dimakan
                {
                    InsVLast(L,P);
                }
            
            if( board[P.posisiC-1][P.posisiR].nama != " " && board[P.posisiC+1][P.posisiR].player == 2) // kalo sorong kanan atas pemain putih ada bidak lawan yang menempati, bisa dimakan
                {
                    InsVLast(L,P);
                }
        }

        // promosi
            // putih: jika bidak putih sedang di baris ke 2 dan maju maka promosi dan bidak diganti dengan Q,R,B,N

    }
    
    List L;
    CreateEmpty(&L);


}
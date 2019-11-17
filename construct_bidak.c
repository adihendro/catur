#include "tipe_bentukan.h"

void ConstructBidak(piece bidak, char nama, int player, int poin, int posisiR, int posisiC){
    bidak.nama = nama;
    bidak.player = player;
    bidak.poin = poin;
    bidak.posisiC = posisiC;
    bidak.posisiR = posisiR;
}
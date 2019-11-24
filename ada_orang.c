#include "tipe_bentukan.h"

boolean adaorang(list lawan, int x, int y, address_list *P1){
    boolean found=false;
    address_list P;
    P = First(lawan);
    *P1=P;
    while ((P != Nil_list)) {
        if ((Info(P).posisiR==y) && (Info(P).posisiC==x)) {
            found=true;
            break;
        }
        *P1=P;
        P = Next(P);
    }
    return found;
}
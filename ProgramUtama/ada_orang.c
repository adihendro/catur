#include "tipe_bentukan.h"

boolean adaorang(list lawan, int x, int y, address_list *P1, address_list *P2, address_list *P){
    boolean found=false;
    *P = First(lawan);
    *P1 = *P;
    *P2 = *P1;
    while ((*P != Nil_list)) {
        if ((Info(*P).posisiR==y) && (Info(*P).posisiC==x)) {
            found=true;
            break;
        }
        *P2 = *P1;
        *P1 = *P;
        *P = Next(*P);
    }
    return found;
}
#include "..//ProgramUtama//tipe_bentukan.h"

boolean adaorang(list lawan, int x, int y, address_list *Prec, address_list *P){
    boolean found=false;
    *P = First(lawan);
    *Prec = *P;
    while ((*P != Nil_list)) {
        if ((Info(*P).posisiR==y) && (Info(*P).posisiC==x)) {
            found=true;
            break;
        }
        *Prec = *P;
        *P = Next(*P);
    }
    return found;
}
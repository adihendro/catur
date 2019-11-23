#include "tipe_bentukan.h"

boolean adaorang(list lawan, int x, int y){
    boolean found=false;
    address_list P;
    P = First(lawan);
    while ((P != Nil_list) && !found) {
        if ((Info(P).posisiC==x) && (Info(P).posisiR==y)) {
            found=true;
        }
        P = Next(P);
    }
    return found;
}
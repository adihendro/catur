#include<stdio.h>

void PrintNamaBidak(char c){
    if (c=='K'){
        printf("Raja");
    } else if(c=='Q'){
        printf("Ratu");
    } else if(c=='B'){
        printf("Menteri");
    } else if(c=='N'){
        printf("Kuda");
    } else if(c=='R'){
        printf("Rook");
    } else if(c=='P'){
        printf("Pion");
    }
}

void PrintBaris(int k){
    if (k==1){
        printf("8");
    } else if(k==2){
        printf("7");
    } else if(k==3){
        printf("6");
    } else if(k==4){
        printf("5");
    } else if(k==5){
        printf("4");
    } else if(k==6){
        printf("3");
    } else if(k==7){
        printf("2");
    } else if(k==8){
        printf("1");
    }
}

void PrintKolom(int k){
    if (k==1){
        printf("a");
    } else if(k==2){
        printf("b");
    } else if(k==3){
        printf("c");
    } else if(k==4){
        printf("d");
    } else if(k==5){
        printf("e");
    } else if(k==6){
        printf("f");
    } else if(k==7){
        printf("g");
    } else if(k==8){
        printf("h");
    }
}

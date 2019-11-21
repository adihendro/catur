#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "tipe_bentukan.h"

void string2ByteArray(char* input, int* output)
{
    // mengubah byte string ke array of integer
    int loop = 0;
    int i = 0;

    while(input[loop] != '\0')
        output[i++] = input[loop++];
}
void stringToInt(char* ascii_str,int* Ret){
    //mendapatkan nilai bilangan integer pertama dari array of string
    int len = strlen(ascii_str);
    int arr[len];
    string2ByteArray(ascii_str, arr);
    *Ret = arr[0];
}

/*int main(){
    int X;
    choice = (char*) malloc (sizeof(100));
    scanf("%s",choice);
    stringToInt(choice,&X);
    int Y = X+2;
    printf("%d\n",X);
    printf("%d\n",Y);
    return 0;
}*/
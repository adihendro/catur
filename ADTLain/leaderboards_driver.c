#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    char str[50];
	char CC;
	static FILE *pita;
	strcpy(str,"leaderboards.txt");
    pita = fopen(str,"r");
    int retval;
    retval = fscanf(pita,"%c",&CC);
	while (CC != '%') {
        printf("%c",CC);
        retval = fscanf(pita,"%c",&CC);
    }
	printf("\n");
	
	return 0;
}
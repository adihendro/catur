#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} point;

int main () {
    point a;
    a.x = 1;
    a.y = 1;
    point b;
    b = a;
    printf("%d %d\n", a.x , a.y);
    printf("%d %d\n", b.x , b.y);
    
    return 0;
}
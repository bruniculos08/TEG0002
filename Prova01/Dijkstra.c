#include <stdio.h>
#include <stdbool.h>

int main(){
    int *i = NULL;
    int matriz[1][1];
    printf("%i\n", matriz[0][0]);
    bool b = true;
    bool rest[2];
    rest[0] = true;
    rest[1] = false;
    printf("%i", rest[1]);
}
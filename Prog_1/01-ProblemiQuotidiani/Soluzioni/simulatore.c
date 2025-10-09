#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int Lancio(){
    int valore_dato = rand()%6;
    return valore_dato+1;
}

int main(){
    srand(time(NULL));
    printf("Il valore del primo dado è: %d\n",Lancio());
    printf("Il valore del secondo dado è: %d\n",Lancio());
}
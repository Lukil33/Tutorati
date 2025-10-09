#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int Lancio(int valore_dado){
    int valore_dato = rand()%valore_dado;
    return valore_dato+1;
}

int main(){
    srand(time(NULL));
    int valore_primo_dado,valore_secondo_dado;
    printf("Inserire il valore dei due dadi: ");
    scanf(" %d %d",&valore_primo_dado, &valore_secondo_dado);
    printf("Il valore del primo dado è: %d\n",Lancio(valore_primo_dado));
    printf("Il valore del secondo dado è: %d\n",Lancio(valore_secondo_dado));
}
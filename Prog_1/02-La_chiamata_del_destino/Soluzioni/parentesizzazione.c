#include <stdio.h>
#define N 100

char parentesi[N] = {'(',')','(','(','(',')',')',')',')','(','\0'};

int main(void){
    int controllo = 0;
    int i;

    for(i=0; controllo >= 0 && parentesi[i] != '\0' && i<N; i++){
        switch(parentesi[i]){
            case '(': controllo+=1; break;
            case ')': controllo-=1; break;
            default: printf("Errore\n");
        }
    }

    if(controllo != 0){
        printf("Peccato, la parentesizzazione non è perfetta\n");
    }else{
        printf("Complimenti, la parentesizzazione è perfetta\n");
    }

    return 0;
}
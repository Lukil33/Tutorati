#include <stdio.h>

/*
    Esempio per chi non ha compreso:
    dato un valore di esempio n di 4 questa è la spirale che deve essere generata:

    1  - 2  - 3 - 4
                  |
    12 - 13 - 14  5
    |         |   |
    11   16 - 15  6
    |             |
    10 - 9 - 8 -  7

    Data la seguente spirale se io voglio sapere la somma della colonna numero 2 (partendo da 1)
    il risultato sarà 2 + 13 + 16 + 9 = 40
*/

/*
    int n = 4;
    int col = 2;
    risultato atteso: 40
*/

/*
    int n = 4;
    int col = 1;
    risultato atteso: 34
*/
int gauss_summ(int start, int end){ // Funzione che somma tutti i numeri da start a end inclusi tramite la formula di Gauss
    int diff = end - start + 1;
    return diff*(end+start)/ 2;
}

int quadrato(int N, int col, int start){
    if(col == 1){
        return start*N + (1 + gauss_summ(3*N-2,4*N-4));
    }else if(col == N){
        return start*N + (gauss_summ(N,2*N-1));
    }else{
        return start*2 + (3*N-1) + quadrato(N-2, col-1, start + 4*N-4);
    }
}

int main(){
    int n, col;
    
    printf("Inserisci dimensione della spirale: ");
    scanf(" %d", &n);
    printf("Inserisci colonna da sommare (da 1 a N estremi inclusi): ");
    scanf(" %d", &col);

    printf("Risultato: %d\n",quadrato(n,col,0));

    return 0;
}
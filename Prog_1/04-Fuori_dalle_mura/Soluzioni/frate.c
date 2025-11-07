#include <stdio.h>
#include <stdlib.h>

#define N 100

/*
    Versione in C: converte due numeri interi, scambia gli ultimi 8 bit
    (LSB) tra le loro rappresentazioni binarie e stampa i risultati.

    Esempio: ./frate 2025 101
*/

int char_to_int(const char *s){
    return (int)strtol(s, NULL, 10);
}

/* Converte num in rappresentazione binaria little-endian in arr.
   Restituisce la dimensione (numero di bit). */
int int_to_byn(int *arr, int num){
    int i = 0;
    if(num == 0){
        arr[0] = 0;
        return 1;
    }
    while(num > 0){
        arr[i++] = num & 1;
        num >>= 1;
    }
    return i;
}

/* Scambia gli ultimi k bit (indici 0..k-1) tra bin1 e bin2.
   dim1/dim2 sono puntatori e possono essere aggiornati se si estendono
   le rappresentazioni con zeri. */
void swap_bits(int *bin1, int *dim1, int *bin2, int *dim2, int k){
    for(int i = 0; i < k; i++){
        if(i >= *dim1){
            bin1[i] = 0;
            (*dim1)++;
        }
        if(i >= *dim2){
            bin2[i] = 0;
            (*dim2)++;
        }
        int tmp = bin1[i];
        bin1[i] = bin2[i];
        bin2[i] = tmp;
    }
}

/* Converte array binario little-endian in intero */
int byn_to_int(int *arr, int dim){
    int res = 0;
    for(int i = dim - 1; i >= 0; i--){
        res = (res << 1) | (arr[i] & 1);
    }
    return res;
}

/* Stampa binario in ordine MSB->LSB per leggibilità */
void print_byn(int *arr, int dim){
    for(int i = dim - 1; i >= 0; i--){
        putchar(arr[i] ? '1' : '0');
    }
    putchar('\n');
}

int main(int argc, char **argv){
    if(argc != 3){
        fprintf(stderr, "Usage: %s <num1> <num2>\n", argv[0]);
        return 1;
    }

    int num1 = char_to_int(argv[1]);
    int num2 = char_to_int(argv[2]);

    printf("Numeri di partenza: %d, %d\n", num1, num2);

    int bin1[N] = {0}, bin2[N] = {0};
    int dim1 = int_to_byn(bin1, num1);
    int dim2 = int_to_byn(bin2, num2);

    printf("Prima dello scambio:\n");
    print_byn(bin1, dim1);
    print_byn(bin2, dim2);

    swap_bits(bin1, &dim1, bin2, &dim2, 8);

    printf("Dopo lo scambio:\n");
    print_byn(bin1, dim1);
    print_byn(bin2, dim2);

    int res1 = byn_to_int(bin1, dim1);
    int res2 = byn_to_int(bin2, dim2);

    printf("Risultato finale: %d, %d\n", res1, res2);
    return 0;
}
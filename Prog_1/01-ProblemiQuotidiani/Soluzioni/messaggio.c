#include <stdio.h>

char messaggio[] = {'M','D','C','X','X','X','V','I','\0'};

int traduci_lettera(char carattere){
    int res = 0;
    switch (carattere) {
        case 'M': res = 1000; break;
        case 'D': res = 500; break;
        case 'C': res = 100; break;
        case 'L': res = 50; break;
        case 'X': res = 10; break;
        case 'V': res = 5; break;
        case 'I': res = 1; break;
    }
    return res;
}

int main(){
    int counter = 0, risultato = 0;
    while( messaggio[counter] != '\0' ){
        risultato += traduci_lettera(messaggio[counter]);
        counter += 1;
    }
    printf("Il numero finale è: %d\n",risultato);
}
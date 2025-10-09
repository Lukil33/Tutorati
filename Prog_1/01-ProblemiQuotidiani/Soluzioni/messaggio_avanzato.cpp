#include <iostream>
using namespace std;

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
        default: res = -1;
    }
    return res;
}

int main(){
    int counter = 0, risultato = 0;
    while( messaggio[counter] != '\0' ){
        int risultato_parziale = traduci_lettera(messaggio[counter]);
        if(risultato_parziale == -1){
            cerr<<"La stringa contiene una lettera sbagliata"<<endl;
            exit(-1);
        }
        risultato += risultato_parziale;
        counter += 1;
    }
    cout<<"Il numero finale è: "<<risultato<<endl;
}
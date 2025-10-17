#include <iostream>
using namespace std;
#define N 100

int banca_dati[N] = {'\0'};

void aggiungere(int* banca, int num){
    int i=0;
    for(; banca[i] != '\0'; i++);
    banca[i] = num;
    banca[i+1] = '\0';
}

void rimuovere_semplice(int* banca, int num){
    // Un modo molto basico di rimozione consiste nell'inserire un valore prestabilito per segnare che all'interno di quella cella non vi è più nulla
    // Vantaggi: Molto semplice da implementare
    // Svantaggi: Non permette di inserire più di N elementi all'interno dell'array ed è poco efficiente

    for(int i=0; banca[i] != '\0'; i++){
        if( banca[i] == num ){
            banca[i] = -1; 
        }
    }
}

void rimuovere_completo(int* banca, int num){
    // Una tecnica più "pulita"
    // Vantaggi: molto efficiente, risparmia spazio
    // Svantaggi: più complessa da implementare, la rimozione può causare dei problemi
    
    for(int i=0; banca[i] != '\0'; i++){
        if( banca[i] == num ){
            int j=i;
            for(; banca[j] == num; j++);
            banca[i] = banca[j];
            banca[j] = num;
            if(banca[i] == '\0'){
                banca[i+1] = '\0';
            }
        }
    }
}

int cercare(int* banca, int num){
    int first_position = -1;
    for(int i=0; banca[i] != '\0'; i++){
        if( banca[i] == num && first_position == -1){
            first_position = i;
        }
    }
    return first_position;
}

void stampare(int* banca){
    cout<<"Banca dati: ";
    for(int i=0; banca[i] != '\0'; i++){
        cout<<banca[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int scelta, numero, posizione;
    bool continua = true;

    while(continua) {
        cout << "\nMenu Banca Dati:" << endl;
        cout << "1. Aggiungi numero" << endl;
        cout << "2. Rimuovi numero (modo semplice)" << endl;
        cout << "3. Rimuovi numero (modo completo)" << endl;
        cout << "4. Cerca numero" << endl;
        cout << "5. Stampa banca dati" << endl;
        cout << "0. Esci" << endl;
        cout << "\nScegli un'operazione: ";
        cin >> scelta;

        switch(scelta) {
            case 1:
                cout << "Inserisci il numero da aggiungere: ";
                cin >> numero;
                aggiungere(banca_dati, numero);
                cout << "Numero aggiunto con successo!" << endl;
                break;
            
            case 2:
                cout << "Inserisci il numero da rimuovere: ";
                cin >> numero;
                rimuovere_semplice(banca_dati, numero);
                cout << "Numero rimosso con successo (modo semplice)!" << endl;
                break;
            
            case 3:
                cout << "Inserisci il numero da rimuovere: ";
                cin >> numero;
                rimuovere_completo(banca_dati, numero);
                cout << "Numero rimosso con successo (modo completo)!" << endl;
                break;
            
            case 4:
                cout << "Inserisci il numero da cercare: ";
                cin >> numero;
                posizione = cercare(banca_dati, numero);
                if(posizione != -1)
                    cout << "Numero trovato in posizione: " << posizione << endl;
                else
                    cout << "Numero non trovato!" << endl;
                break;
            
            case 5:
                stampare(banca_dati);
                break;
            
            case 0:
                cout << "Arrivederci!" << endl;
                continua = false;
                break;
            
            default:
                cout << "Scelta non valida!" << endl;
        }
    }

    return 0;
}
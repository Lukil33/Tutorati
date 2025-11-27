#include <iostream>
using namespace std;

int* rimuovi_elementi_Pila(int* vett, int& dim){
    if(dim == 0) {
        cout<<"Il vettore e' vuoto, impossibile rimuovere elementi."<<endl;
        return vett;
    }else{
        int* res = new int[dim-1];

        for(int i=0; i<dim-1; i++){ // Copio tutti gli argomeni all'interno del nuovo vettore a parte l'ultimo
            res[i] = vett[i];
        }

        delete[] vett; // Libero il vecchio vettore
        dim -= 1;
        return res;
    }
}

int* rimuovi_elementi_Coda(int* vett, int& dim){
    if(dim == 0) {
        cout<<"Il vettore e' vuoto, impossibile rimuovere elementi."<<endl;
        return vett;
    }else{
        int* res = new int[dim-1];

        for(int i=1; i<dim; i++){ // Copio tutti gli argomeni all'interno del nuovo vettore a parte il primo
            res[i-1] = vett[i];
        }

        delete[] vett; // Libero il vecchio vettore
        dim -= 1;
        return res;
    }
}

int* aggiungi_elemento(int* vett, int& dim){
    int N;
    cout<<"Inserisci l'elemento da aggiungere: ";
    cin>>N;

    int* res = new int[dim+1];

    for(int i=0; i<dim; i++){ // Copio tutti gli elementi vecchi all'interno del nuovo vettore
        res[i] = vett[i];
    }
    res[dim] = N; // Inserisco come ultimo elemento il nuovo valore N
    
    if (vett != nullptr) delete[] vett; // Libero il vecchio vettore
    dim += 1;
    return res;
}

void stampa(int* pozzo, int dim){
    cout<<"Dimensione vettore: "<<dim<<endl;
    cout<<"Vettore -> ";
    for(int i=0; i<dim; i++){
        cout<<pozzo[i]<<" ";
    }
    cout<<endl;
}

int main(){
    // Inizializzo le variabili importanti
    int input;
    int dim = 0;
    int* vett = nullptr;
    
    do{
        cout<<"Quale operazione vuoi effettuare?\n\t1: push Pila\n\t2: pop Pila\n\t3: enquque Coda\n\t4: dequeue Coda\n\t5: Stampa\n\t6: Esci\n";
        cin>>input;

        switch(input){
            case 2: vett = rimuovi_elementi_Pila(vett, dim); break;
            case 3: ; // Nel caso di enqueue Coda uso la stessa funzione di push Pila perchè effettuano la stessa operazione
            case 1: vett = aggiungi_elemento(vett, dim); break;
            case 4: vett = rimuovi_elementi_Coda(vett, dim); break;
            case 5: stampa(vett, dim); break;
            case 6: break;
            default: cout<<"Valore inserito non valido"<<endl; break;
        }

    }while(input != 6);
    
    if (vett != nullptr) delete[] vett; // Libero il vettore
    return 0;
}
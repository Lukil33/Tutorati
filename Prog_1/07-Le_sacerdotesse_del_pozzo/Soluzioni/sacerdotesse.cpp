#include <iostream>
using namespace std;

bool elemento_presente(int* pozzo, int dim, int N){
    bool res = false;
    for(int i=0; i<dim; i++){
        if(pozzo[i] == N){
            res = true;
        }
    }
    return res;
}

int* rimuovi_elemento(int* pozzo, int& dim, int N){
    int counter = 0;
    int* res = new int[dim-1];

    for(int i=0; i<dim; i++){ // Copio tutti gli argomeni all'interno del nuovo vettore a parte quelli uguali ad N
        if(pozzo[i] != N){
            res[counter] = pozzo[i];
            counter += 1;
        }
    }

    delete[] pozzo; // Libero il vecchio pozzo
    dim -= 1;
    return res;
}

int* aggiungi_elemento(int* pozzo, int& dim, int N){
    int* res = new int[dim+1];

    for(int i=0; i<dim; i++){ // Copio tutti gli elementi vecchi all'interno del nuovo vettore
        res[i] = pozzo[i];
    }
    res[dim] = N; // Inserisco come ultimo elemento in nuovo valore N
    
    if (pozzo != nullptr) delete[] pozzo; // Libero il vecchio pozzo
    dim += 1;
    return res;
}

void stampa_pozzo(int* pozzo, int dim){
    cout<<"Dimensione pozzo: "<<dim<<endl;
    cout<<"Pozzo -> ";
    for(int i=0; i<dim; i++){
        cout<<pozzo[i]<<" ";
    }
    cout<<endl;
}

int main(){
    // Inizializzo le variabili importanti
    char input = 's';
    int dim_pozzo = 0;
    int* pozzo = nullptr;

    while(input == 's' || input == 'S'){
        // Faccio inserire all'utente il numero che si vuole cercare nel pozzo
        int N;
        cout<<"Inserisci un numero da cercare all'interno del pozzo: ";
        cin>>N;

        // Cerco l'elemento (Questa parte di codice può essere ottimizzata ma ho preferito di crearla in modo più intuitivo)
        if(elemento_presente(pozzo,dim_pozzo,N)){
            pozzo = rimuovi_elemento(pozzo,dim_pozzo,N);
        }else{
            pozzo = aggiungi_elemento(pozzo,dim_pozzo,N);
        }

        if(dim_pozzo <= 0){
            cout<<"Il pozzo si è seccato"<<endl;
            input = 'n';
        }else if(dim_pozzo >= 10){
            cout<<"Il pozzo si sta straripando"<<endl;
            input = 'n';
        }else{
            cout<<"Vuoi inserire un nuovo numero? (S/N) ";
            cin>>input;
        }

        stampa_pozzo(pozzo,dim_pozzo);
    }
    
    if (pozzo != nullptr) delete[] pozzo; // Libero il pozzo
    return 0;
}
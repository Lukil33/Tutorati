#include <iostream>
using namespace std;

enum Man{
    Scriba,
    Cuoco,
    Botanico,
    Religioso
};

struct Monaco{
    char nome[30];
    int eta;
    Man mansione;
    int anni_in_monastero;
};

void stampaMonaco(Monaco* m, int num_monaci){
    for(int i=0; i<num_monaci; i++){
        cout<<"Monaco "<<i+1<<": "<<endl;
        cout<<"\tNome: "<<m[i].nome<<endl;
        cout<<"\tEta': "<<m[i].eta<<endl;
        cout<<"\tMansione: ";
        switch(m[i].mansione){
            case Scriba: cout<<"Scriba"; break;
            case Cuoco: cout<<"Cuoco"; break;
            case Botanico: cout<<"Botanico"; break;
            case Religioso: cout<<"Religioso"; break;
        }
        cout<<endl;
        cout<<"\tAnni in monastero: "<<m[i].anni_in_monastero<<endl;
        cout<<endl;
    }
}

void swapMonaci(Monaco& m1, Monaco& m2){
    Monaco temp = m1;
    m1 = m2;
    m2 = temp;
}

void toggleOrdine(Monaco* m, int num_monaci, bool& ordine){
    // Ordinamento per anni_in_monastero (bubble sort)
    for(int i=0; i<num_monaci-1; i++){
        for(int j=0; j<num_monaci-i-1; j++){
            if((ordine && m[j].anni_in_monastero > m[j+1].anni_in_monastero) || (!ordine && m[j].anni_in_monastero < m[j+1].anni_in_monastero)){
                swapMonaci(m[j], m[j+1]);
            }
        }
    }
    ordine = !ordine;
}

int main(){
    srand(time(NULL));
    int n;
    cout<<"Inserisci il numero di monaci da inserire: ";
    cin>>n;

    struct Monaco* monaci = new Monaco[n];

    for(int i=0; i<n; i++){
        char nome[30];
        int eta;
        Man mansione;
        int anni;

        cout<<"Inserisci il nome del monaco "<<i+1<<": ";
        cin>>monaci[i].nome;
        cout<<"Inserisci l'eta' del monaco "<<i+1<<": ";
        cin>>monaci[i].eta;
        switch(rand() % 4){
            case 0: monaci[i].mansione = Scriba; break;
            case 1: monaci[i].mansione = Cuoco; break;
            case 2: monaci[i].mansione = Botanico; break;
            case 3: monaci[i].mansione = Religioso; break;
        }
        monaci[i].anni_in_monastero = rand() % monaci[i].eta;
    }

    int decisione = 1;
    bool ordine = true;
    while(decisione != 0){
        cout<<"Cosa vuoi stampare (0=esci, 1=stampa, 2=toggle): ";
        cin>>decisione;
        switch(decisione){
            case 0: cout<<endl; break;
            case 1: stampaMonaco(monaci,n); break;
            case 2: toggleOrdine(monaci,n, ordine); break;
            default: cout<<"Numero inserito non valido"<<endl; break;
        }
    }
    
    return 0;
}
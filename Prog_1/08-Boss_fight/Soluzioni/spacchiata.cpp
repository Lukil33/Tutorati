#include <iostream>
using namespace std;

struct Nodo {
    int valore;
    Nodo* prev;
    Nodo* next;
};
struct Lista {
    Nodo* head;
    Nodo* tail;
};


void inizializza(Lista& lista){ // Inizializza la lista
    lista.head = nullptr;
    lista.tail = nullptr;
}


void inserisci_in_posizione(Lista& lista, int posizione, int valore){ // Inserisce in una posizione (0 = inizio)
    Nodo* nuovo = new Nodo{valore, nullptr, nullptr};

    if(posizione <= 0 || lista.head == nullptr){ // Inserimento in testa
        nuovo->next = lista.head;
        if (lista.head) lista.head->prev = nuovo;
        lista.head = nuovo;
        if (lista.tail == nullptr) lista.tail = nuovo;
        return;
    }

    Nodo* corrente = lista.head;
    int index = 0;

    while(corrente->next != nullptr && index < posizione){
        corrente = corrente->next;
        index++;
    }

    if(index < posizione){ // Inserimento in coda  
        nuovo->prev = lista.tail;
        lista.tail->next = nuovo;
        lista.tail = nuovo;
    }else{ // Inserimento in mezzo
        Nodo* precedente = corrente->prev;
        precedente->next = nuovo;
        nuovo->prev = precedente;
        nuovo->next = corrente;
        corrente->prev = nuovo;
    }
}


void rimuovi_in_posizione(Lista& lista, int posizione){ // Rimuove il nodo in una posizione (0 = testa)
    if(lista.head == nullptr) return;

    Nodo* corrente = lista.head;

    if(posizione <= 0){ // Rimozione in testa
        lista.head = corrente->next;
        if (lista.head) lista.head->prev = nullptr;
        else lista.tail = nullptr;
        delete corrente;
        return;
    }

    int index = 0;
    while(corrente != nullptr && index < posizione){
        corrente = corrente->next;
        index++;
    }

    if(corrente == nullptr) return;

    if(corrente->prev) corrente->prev->next = corrente->next;
    if(corrente->next) corrente->next->prev = corrente->prev;

    if(corrente == lista.tail) lista.tail = corrente->prev;

    delete corrente;
}


void rimuovi_valore(Lista& lista, int valore){ // Rimuove il primo nodo che contiene un certo valore
    Nodo* corrente = lista.head;

    while(corrente != nullptr && corrente->valore != valore){
        corrente = corrente->next;
    }

    if(!corrente) return; // non trovato

    if(corrente->prev) corrente->prev->next = corrente->next;
    else lista.head = corrente->next;

    if(corrente->next) corrente->next->prev = corrente->prev;
    else lista.tail = corrente->prev;

    delete corrente;
}


void stampa_lista(const Lista& lista){ // Stampa la lista in entrambi i sensi
    cout << "Avanti: ";
    for(Nodo* n = lista.head; n != nullptr; n = n->next){
        cout << n->valore << " ";
    }
    cout << "\nIndietro: ";
    for(Nodo* n = lista.tail; n != nullptr; n = n->prev){
        cout << n->valore << " ";
    }
    cout << "\n";
}

int main() {
    Lista lista;
    inizializza(lista);

    inserisci_in_posizione(lista, 0, 3);
    inserisci_in_posizione(lista, 1, 5);
    inserisci_in_posizione(lista, 1, 4);
    inserisci_in_posizione(lista, 10, 7); // inserito in coda
    inserisci_in_posizione(lista, -10, 7); // inserito in testa
    stampa_lista(lista);

    rimuovi_in_posizione(lista, 2);
    stampa_lista(lista);

    rimuovi_valore(lista, 7);
    stampa_lista(lista);

    return 0;
}

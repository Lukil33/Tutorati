#include <iostream>
#include <climits>
using namespace std;

struct CircularArray {
    int* buffer;
    int capacity;
    int start;   // indice del primo elemento
    int count;   // quanti elementi sono presenti
};

void init(CircularArray& c, int cap = 8){ // Inizializza il vettore circolare
    c.buffer = new int[cap];
    c.capacity = cap;
    c.start = 0;
    c.count = 0;
}

int idx(const CircularArray& c, int logicalIndex){ // Trasforma un indice logico (0,1,2...) in un indice reale del buffer
    return (c.start + logicalIndex) % c.capacity;
}

void resize(CircularArray& c){ // Espande il buffer quando necessario
    int newCap = c.capacity * 2;
    int* nuovo = new int[newCap];

    for (int i = 0; i < c.count; i++)
        nuovo[i] = c.buffer[idx(c, i)];

    delete[] c.buffer;
    c.buffer = nuovo;
    c.capacity = newCap;
    c.start = 0;
}

void inserisci_rec(CircularArray& c, int value, int pos){ // Inserimento in fondo
    // Caso base: pos == count → inseriamo in fondo
    if (pos == c.count) {
        if (c.count == c.capacity)
            resize(c);

        int i = idx(c, c.count);
        c.buffer[i] = value;
        c.count++;
        return;
    }

    // Passo ricorsivo
    inserisci_rec(c, value, pos + 1);
}
void inserisci(CircularArray& c, int value){
    inserisci_rec(c, value, 0);
}

int lunghezza_rec(const CircularArray& c, int pos){
    if (pos == c.count)
        return 0;
    return 1 + lunghezza_rec(c, pos + 1);
}
int lunghezza(const CircularArray& c){
    return lunghezza_rec(c, 0);
}

int find_max_rec(const CircularArray& c, int pos, int bestPos, int bestVal){ // Trova la posizione del massimo in modo ricorsivo
    if (pos == c.count){
        return bestPos;
    }
    int curVal = c.buffer[idx(c, pos)];
    if (curVal > bestVal){
        return find_max_rec(c, pos + 1, pos, curVal);
    }else{
        return find_max_rec(c, pos + 1, bestPos, bestVal);
    } 
}
int find_max(const CircularArray& c){
    if (c.count == 0) return -1;
    return find_max_rec(c, 0, 0, c.buffer[idx(c, 0)]);
}

void remove_at(CircularArray& c, int pos){ // Rimuove l’elemento in posizione specifica
    for (int i = pos; i < c.count - 1; i++){
        c.buffer[idx(c, i)] = c.buffer[idx(c, i + 1)];
    }
    c.count--;
}


void remove_max(CircularArray& c){ // Rimuove il massimo
    if (c.count == 0) return;
    int pos = find_max(c);
    remove_at(c, pos);
}

void stampa_rec(const CircularArray& c, int pos){
    if (pos == c.count)
        return;

    cout << c.buffer[idx(c, pos)] << " ";
    stampa_rec(c, pos + 1);
}
void stampa(CircularArray& c){
    cout << "[ ";
    stampa_rec(c, 0);
    cout << "] (ciclico)" << endl;
}

int main() {
    CircularArray c;
    init(c);

    inserisci(c, 5);
    inserisci(c, 3);
    inserisci(c, 7);
    inserisci(c, 2);
    inserisci(c, 9);

    cout << "Lista: ";
    stampa(c);
    cout << "Lunghezza: " << lunghezza(c) << endl;

    remove_max(c);
    cout << "Dopo remove_max: ";
    stampa(c);
    cout << "Lunghezza: " << lunghezza(c) << endl;
    
    remove_max(c);
    cout << "Dopo remove_max: ";
    stampa(c);
    cout << "Lunghezza: " << lunghezza(c) << endl;


    return 0;
}
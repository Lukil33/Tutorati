#include<iostream>
using namespace std;

struct node{
    int val;
    node* next;
};

void inserisci(node*& lista, int valore){
    lista = new node{valore, lista};
}

void stampa_lista(node* lista){
    if(lista == nullptr){
        cout<<endl;
    }else{
        cout<<lista->val<<" ";
        stampa_lista(lista->next);
    }
}

void rimuovi_nodo(node* prec){
    node* rimuovere = prec->next;
    prec->next = rimuovere->next;
    delete rimuovere;
}
bool duplicati(node* prec, node* lista, int num){
    if(lista != nullptr){
        if(lista->val == num){
            rimuovi_nodo(prec);
            duplicati(prec,prec->next,num);
            return true;
        }else{
            return duplicati(lista,lista->next,num);
        }
    }
    return false;
}
void rimuovi_duplicati(node*& lista, node* prec = nullptr){
    if(lista != nullptr){
        if(duplicati(lista, lista->next, lista->val)){
            if(prec == nullptr){
                prec = lista;
                lista = lista->next;
                delete prec;
                rimuovi_duplicati(lista);
            }else{
                rimuovi_nodo(prec);
                rimuovi_duplicati(prec->next,prec);
            }
        }else{
            rimuovi_duplicati(lista->next,lista);
        }
    }
}

int main(){
    node* lista = nullptr;
    
    inserisci(lista, 3);
    inserisci(lista, 2);
    inserisci(lista, 5);
    inserisci(lista, 3);
    inserisci(lista, 6);
    inserisci(lista, 7);
    inserisci(lista, 2);
    inserisci(lista, 1);

    cout << "Lista originale: ";
    stampa_lista(lista);

    rimuovi_duplicati(lista);

    cout << "Lista senza duplicati: ";
    stampa_lista(lista);

    return 0;
}
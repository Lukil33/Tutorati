#include <iostream>
using namespace std;

struct node{
    int mese;
    int giorno;
    int num_compleanni;
    node* next;
};

void cambio_data(int& giorno, int& mese){
    if(mese == 2 && giorno == 28){
        giorno = 1;
        mese += 1;
    }else if(giorno == 30 && (mese == 4 || mese == 6 || mese == 9 || mese == 11)){
        giorno = 1;
        mese += 1;
    }else if(giorno == 31){
        giorno = 1;
        mese += 1;
    }else{
        giorno += 1;
    }
}
node* crea_lista(int giorno=1, int mese=1){
    node* data = new node{mese, giorno, 0, nullptr};
    if(giorno == 31 && mese == 12){
        return data;
    }else{
        cambio_data(giorno,mese);
        data->next = crea_lista(giorno,mese);
        return data;
    }
}

void add_compleanno(node* calendario, int giorno, int mese){
    while(calendario->giorno != giorno || calendario->mese != mese){
        calendario = calendario->next;
    }
    calendario->num_compleanni += 1;
}

void stampa_calendario(node* calendario){
    if(calendario == nullptr){
        cout<<endl;
        return;
    }else if(calendario->giorno != 1){
        cout<<"("<<calendario->giorno<<", "<<calendario->num_compleanni<<") ";
        return stampa_calendario(calendario->next);
    }else{
        cout<<endl<<calendario->mese<<" -> ("<<calendario->giorno<<", "<<calendario->num_compleanni<<") ";
        return stampa_calendario(calendario->next);
    }
}

void remove_calendario(node* calendario){
    if(calendario == nullptr){
        return;
    }else{
        if(calendario->next != nullptr){
            remove_calendario(calendario->next);
        }
        delete calendario;
        return;
    }
}

int main(){
    node* calendario = crea_lista();

    add_compleanno(calendario, 1, 12);
    add_compleanno(calendario, 3, 3);
    add_compleanno(calendario, 3, 3);

    stampa_calendario(calendario);
}
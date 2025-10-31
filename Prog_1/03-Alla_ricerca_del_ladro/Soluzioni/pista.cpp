#include <cmath>
#include <cstdlib>
#include <iostream>
#include <utility>
using namespace std;

void swap(char* a, char* b){
    (*a) += (*b);
    (*b) = (*a) - (*b);
    (*a) -= (*b);
}

void move(char& a, char& b, char& c){
    int scambio = rand()%4;

    switch(scambio){
        case 0: swap(a,b); break;
        case 1: swap(a,c); break;
        case 2: swap(b,c); break;
        default: ;
    }
}

void genera_posizione_iniziale(char& a, char& b, char& c){ // Volendo ci si può risprmiare la seguente funzione hardcodando la posizione iniziale
    int pos_queen = rand()%3;
    switch(pos_queen){
        case 0: a ='Q',b='8',c='8'; break;
        case 1: a ='8',b='Q',c='8'; break;
        case 2: a ='8',b='8',c='Q'; break;
    }
}
bool round(){
    int numero_spostamenti = rand()%10 + 1;
    char a,b,c;
    genera_posizione_iniziale(a,b,c);
    cout<<"Mercante: <<Mischio le carte>>"<<endl;
    for(int i=0; i<numero_spostamenti; i++){
        move(a,b,c);
    }
    cout<<"Mercante: <<Finito, ora tocca a te, dove si trova la regina?>>"<<endl;
    cout<<"\t[1]\t[2]\t[3]"<<endl;
    cout<<"Inserire un numero da 1 a 3: ";
    int num;
    cin>>num;
    bool check = false;
    switch(num){
        case 1: a=='Q'?check = true:check=false; break;
        case 2: b=='Q'?check = true:check=false; break;
        case 3: c=='Q'?check = true:check=false; break;
        default: cout<<"Mercante: <<Il numero inserito era sbagliato, peggio per te, lo considererò come un'errore>>"<<endl;
    }
    if(check){
        cout<<"Mercante: <<Complimenti, hai scelto la carta giusta>>"<<endl;
    }else{
        cout<<"Mercante: <<Mi spiace, hai sbagliato>>"<<endl;
    }
    cout<<"Le carte erano messe così:"<<endl<<"\t["<<a<<"]\t["<<b<<"]\t["<<c<<"]"<<endl<<endl;
    return check;
}

int game(int numero_round){
    int res = 0;
    for(int i=0; i<numero_round; i++){
        if(round()){
            res += 1;
        }
    }
    return res;
}

int main(){
    srand(time(NULL));
    int n;
    cout<<"Inserisci il numero di round da effettuare: ";
    cin>>n;
    int round_vinti = game(n);
    cout<<"Il numero di round vinti in totale è: "<<round_vinti<<endl;
    return 0;
}
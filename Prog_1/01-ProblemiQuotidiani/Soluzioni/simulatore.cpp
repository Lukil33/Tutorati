#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int Lancio(){
    int valore_dato = rand()%6;
    return valore_dato+1;
}

int main(){
    srand(time(NULL));
    cout<<"Il valore del primo dado è: "<<Lancio()<<endl;
    cout<<"Il valore del secondo dado è: "<<Lancio()<<endl;
}
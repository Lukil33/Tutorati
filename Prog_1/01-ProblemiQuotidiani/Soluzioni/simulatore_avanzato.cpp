#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int Lancio(int valore_dado){
    int valore_dato = rand()%valore_dado;
    return valore_dato+1;
}

int main(){
    srand(time(NULL));
    int valore_primo_dado,valore_secondo_dado;
    cout<<"Inserire il valore dei due dadi: ";
    cin>>valore_primo_dado>>valore_secondo_dado;
    cout<<"Il valore del primo dado è: "<<Lancio(valore_primo_dado)<<endl;
    cout<<"Il valore del secondo dado è: "<<Lancio(valore_secondo_dado)<<endl;
}
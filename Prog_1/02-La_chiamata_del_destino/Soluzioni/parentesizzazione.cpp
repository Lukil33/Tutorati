#include <iostream>
using namespace std;
#define N 100

char parentesi[N] = {'(',')','(','(','(',')',')',')',')','(','\0'};

int main(){
    int controllo = 0;
    for(int i=0; controllo >= 0 && parentesi[i] != '\0' && i<N; i++){
        switch(parentesi[i]){
            case '(': controllo+=1; break;
            case ')': controllo-=1; break;
            default: cout<<"Errore"<<endl;
        }
    }

    if(controllo != 0){
        cout<<"Peccato, la parentesizzazione non è perfetta"<<endl;
    }else{
        cout<<"Complimenti, la parentesizzazione è perfetta"<<endl;
    }

    return 0;
}
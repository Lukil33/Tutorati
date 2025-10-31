#include <iostream>
using namespace std;
#define N 100

//int arr[] = {1,2,3,4,8,32,87,3,54,24,75,42,'\0'};
//int arr[] = {1,3,4,8,3,19,302,24,32,65,'\0'};
//int arr[] = {9,8,7,6,5,4,2,1,3,'\0'};

int iterazione(int* a){
    int res = 0;
    for(int i=0; i<N && a[i] != '\0'; i++){ // Per tutti gli elementi all'interno dell'array
        if(i > 2){ // se ho due o più elementi precedenti controlla se l'elemento in posizione X e più grande della somma tra X-1 e X-2 
            res += (a[i-2]+a[i-1]<a[i])?1:0;
        }
    }
    return res;
}

int ricorsione(int* a, int elem){
    if(a[elem] == '\0'){ // Se sono arrivato alla fine dell'array allora termina la ricorsione
        return 0;
    }else{
        if(elem < 2){ // Se non ho i due elementi precedenti allora passa al prossimo elemento
            return ricorsione(a, elem+1);
        }else{ // se ho due o più elementi precedenti controlla se l'elemento in posizione X e più grande della somma tra X-1 e X-2
            return ricorsione(a, elem+1) + ((a[elem-2]+a[elem-1]<a[elem])?1:0);
        }
    }
}

int main(){
    cout<<"Calcolo utilizzando l'Iterazione: "<<iterazione(arr)<<endl;
    cout<<"Calcolo utilizzando la Ricorsione: "<<ricorsione(arr,0)<<endl;
    return 0;
}
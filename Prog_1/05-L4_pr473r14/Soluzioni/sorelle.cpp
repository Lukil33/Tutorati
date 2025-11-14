#include <iostream>
using namespace std;

/*
    Esempio per chi non ha compreso:
    dato l'array: arr[] = {10,9,8,7,9,5,4,3,2,1}
    il risultato deve essere: {0,0,0,0,0,0,0,0,0,1}
    in quanto 2 è maggiore rispetto ai suoi successivi (1) quindi viene eliminato (diventa 0),
    3 è maggiore rispetto ai suoi successivi validi (1) quindi viene eliminato, ecc...
*/

/*
    int arr[] = {10,9,8,7,9,5,4,3,2,1,-1};
    risultato atteso: {0,0,0,0,0,0,0,0,0,1}
*/

/*
    int arr[] = {10,93,3,73,22,14,22,5,10,-1};
    risultato atteso: {10,0,3,0,22,14,0,5,10}
*/

void stampa_array(int* arr, int counter = 0){
    if(arr[counter] == -1){
        cout << endl;
        return;
    }else{
        cout << arr[counter] << ", ";
        stampa_array(arr, counter + 1);
    }
}

int modifica_array(int* arr, int index = 0){
    if(arr[index] == -1){
        return -1;
    }else{
        int somma_seguenti = modifica_array(arr, index + 1);
        if(somma_seguenti<0){ // Se sono alla fine dell'array (elemento prima del terminatore)
            somma_seguenti = arr[index];
        }else if(somma_seguenti > arr[index]){ // Se la somma dei successivi è maggiore dell'elemento attuale
            somma_seguenti += arr[index];
        }else{ // Se invece il mio elemento ha valore maggiore o uguale alla somma dei successivi
            arr[index] = 0;
        }
        return somma_seguenti;
    }
}

int main(){

    stampa_array(arr);
    modifica_array(arr);
    stampa_array(arr);

    return 0;
}
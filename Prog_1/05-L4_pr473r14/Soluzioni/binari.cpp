#include <iostream>
using namespace std;

/*
    Esempio per chi non ha compreso:
    dato l'array: arr_1[] = {1,0,1} e l'array arr_2[] = {1,0,1}
    il risultato deve essere: {1,0,1,0}
*/

/*
    int arr_1[] = {1,0,0,0,-1};
    int arr_2[] = {0,0,1,0,-1};
    risultato atteso: {1,0,1,0}
*/

/*
    int arr_1[] = {1,0,0,0,1,-1};
    int arr_2[] = {1,0,1,-1};
    risultato atteso: {1,0,1,1,0}
*/

/*
    int arr_1[] = {1,-1};
    int arr_2[] = {1,0,1,-1};
    risultato atteso: {1,1,0}
*/

int arr_len(int* arr, int start = 0){
    if(arr[start] == -1){
        return 0;
    }else{
        return 1 + arr_len(arr, start + 1);
    }
}

void recursive_reverse(int* arr, int end, int start = 0){
    if(start >= end/2){
        return;
    }else{
        arr[start] += arr[end-start-1];
        arr[end-start-1] = arr[start] - arr[end-start-1];
        arr[start] -= arr[end-start-1];
        recursive_reverse(arr, end, start + 1);
    }
}

void print_array(int* arr, int start = 0){
    if(arr[start] == -1){
        cout << endl;
        return;
    }else{
        cout << arr[start] << " ";
        print_array(arr, start + 1);
    }
}

void summ_array(int* res, int*arr1, int* arr2, int arr1_len, int arr2_len, int start = 0, int carry = 0){
    if(arr1_len <= start && arr2_len <= start && carry == 0){
        res[start] = -1;
        return;
    }else{
        int val1 = (arr1_len <= start) ? 0 : arr1[start];
        int val2 = (arr2_len <= start) ? 0 : arr2[start];
        int sum = val1 + val2 + carry;
        res[start] = sum % 2;
        carry = sum / 2;
        summ_array(res, arr1, arr2, arr1_len, arr2_len, start + 1, carry);
    }
}

int main(){
    // Per la soluzione di questo esercizio esistono diversi approcci validi
    // quello utilizzato qui consiste nel reversare i due array e successivamente farne la somma.
    
    print_array(arr_1);
    recursive_reverse(arr_1, arr_len(arr_1)); // Reverso il primo Array
    print_array(arr_1);
    
    print_array(arr_2);
    recursive_reverse(arr_2, arr_len(arr_2)); // Reverso il secondo Array
    print_array(arr_2);

    int result[max(arr_len(arr_1), arr_len(arr_2)) + 2]; // Creo l'array risultato con una lunghezza massima pari alla somma delle lunghezze dei due array più uno per l'eventuale riporto e uno per il -1 di terminazione
    summ_array(result, arr_1, arr_2, arr_len(arr_1), arr_len(arr_2)); // Sommo i due array reversati
    recursive_reverse(result, arr_len(result)); // Reverso il risultato per avere l'ordine corretto
    print_array(result); // Stampo il risultato

    return 0;
}
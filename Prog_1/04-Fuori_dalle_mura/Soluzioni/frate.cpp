#include <iostream>
using namespace std;
#define N 100

/*
    Esempio per chi non ha compreso:
    dati i numeri: 2025e 101

    le corrispettive rappresentazioni binarie sono:
    2025=11111101001
    101=1100101

    scambiando le ultime 8 cifre vengono:
    111 '01100101' = 1893
        '11101001' = 233
    
    il risultato deve quindi essere: 1893, 233
*/
int char_to_int(char* c){
    int res = 0;
    for(int i=0; c[i]!='\0'; i++){
        res = res*10 + (c[i] - '0');
    }
    return res;
}

int int_to_byn(int* arr, int num){ // Creo un array di interi che rappresenta il numero in binario, con il bit meno significativo in posizione 0
    int i = 0;
    while(num > 0){
        arr[i] = num % 2;
        num /= 2;
        i++;
    }
    arr[i] = '\0';
    return i;
}

void swap(int* bin1, int& dim1, int* bin2, int& dim2, int k=8){
    for(int i=0; i<k; i++){
        if(i >= dim1){
            bin1[i] = 0;
            dim1++;
        }
        if(i >= dim2){
            bin2[i] = 0;
            dim2++;
        }
        int temp = bin1[i];
        bin1[i] = bin2[i];
        bin2[i] = temp;
    }
}

int byn_to_int(int* arr, int dim){
    int res = 0;
    for(int i=dim-1; i>=0; i--){
        res = res*2 + arr[i];
    }
    return res;
}

void print_byn(int* arr, int dim){
    for(int i=0; i<dim; i++){
        cout<<arr[i];
    }
    cout<<endl;
}

int main(int argc, char** argv){
    if(argc != 3){
        cerr<<"Error: "<<argv[0]<<" <num1> <num2>"<<endl;
        return 1;
    }

    int num1 = char_to_int(argv[1]), num2 = char_to_int(argv[2]); // Converto i numeri sotto forma di array di char in interi

    cout<<"Numeri di partenza: "<<num1<<", "<<num2<<endl;
    
    int bin1[N], bin2[N]; // Converto i numeri interi in array di binari
    int dim1 = int_to_byn(bin1, num1); // Dalle funzioni mi sono fatto restituire anche la dimensione degli array nonostante si possa fare anche con caratteri terminatori (es: -1)
    int dim2 = int_to_byn(bin2, num2);

    cout<<"Prima dello scambio:"<<endl;
    print_byn(bin1, dim1);
    print_byn(bin2, dim2);

    swap(bin1, dim1, bin2, dim2);

    cout<<"Dopo lo scambio:"<<endl;
    print_byn(bin1, dim1);
    print_byn(bin2, dim2);

    int res1 = byn_to_int(bin1, dim1); // Riconverto gli array binari in interi
    int res2 = byn_to_int(bin2, dim2);

    cout<<"Risultato finale: "<<res1<<", "<<res2<<endl;

    return 0;
}
#include <iostream>
using namespace std;

/*
    Esempio per chi non ha compreso:
    dato l'array: arr[] = {'L','4',' ','p','r','4','7','3','r','1','4','\0'}
    il risultato deve essere: "La prateria"
*/

void stampa_parola(char* arr, int counter = 0){
    if(arr[counter] == '\0'){
        cout << endl;
        return;
    }else{
        cout << arr[counter];
        stampa_parola(arr, counter + 1);
    }
}

void converti_parola(char* arr, int counter = 0){
    if(arr[counter] == '\0'){
        return;
    }else{
        switch(arr[counter]){
            case '0':
                arr[counter] = 'o';
                break;
            case '1':
                arr[counter] = 'i';
                break;
            case '2':
                arr[counter] = 'z';
                break;
            case '3':
                arr[counter] = 'e';
                break;
            case '4':
                arr[counter] = 'a';
                break;
            case '5':
                arr[counter] = 's';
                break;
            case '6':
                arr[counter] = 'g';
                break;
            case '7':
                arr[counter] = 't';
                break;
            case '8':
                arr[counter] = 'b';
                break;
            default:
                // non fa nulla
                break;
        }
        converti_parola(arr, counter + 1);
    }
}

int main(int argc, char** argv){
    if(argc != 2){
        cerr << "Uso: ./a.out <stringa>" << endl;
        return 1;
    }

    stampa_parola(argv[1]);
    converti_parola(argv[1]);
    stampa_parola(argv[1]);

    return 0;
}
#include <stdio.h>
#include <string.h>

/*
    Esempio per chi non ha compreso:
    dato l'array: arr[] = {'L','4',' ','p','r','4','7','3','r','1','4','\0'}
    il risultato deve essere: "La prateria"
*/

/*
    char arr[] = {'L','4',' ','p','r','4','7','3','r','1','4','\0'};
    risultato atteso: La prateria
*/

/*
    char arr[] = {'n','3','5','7',' ','m','3','r','d','4','\0'};
    risultato atteso: nest merda
*/

/*
    char arr[] = {'8','u','7','7','4','n','3','\0'};
    risultato atteso: buttane
*/

void stampa_parola(const char *arr, int counter){
    if(arr[counter] == '\0'){
        printf("\n");
        return;
    }
    printf("%c",arr[counter]);
    stampa_parola(arr, counter + 1);
}

void converti_parola(char *arr, int counter){
    if(arr[counter] == '\0'){
        return;
    }
    switch(arr[counter]){
        case '0': arr[counter] = 'o'; break;
        case '1': arr[counter] = 'i'; break;
        case '2': arr[counter] = 'z'; break;
        case '3': arr[counter] = 'e'; break;
        case '4': arr[counter] = 'a'; break;
        case '5': arr[counter] = 's'; break;
        case '6': arr[counter] = 'g'; break;
        case '7': arr[counter] = 't'; break;
        case '8': arr[counter] = 'b'; break;
        default: break; /* non fa nulla */
    }
    converti_parola(arr, counter + 1);
}

int main(){

    stampa_parola(arr, 0);
    converti_parola(arr, 0);
    stampa_parola(arr, 0);

    return 0;
}
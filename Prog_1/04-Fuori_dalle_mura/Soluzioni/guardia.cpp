#include <iostream>
using namespace std;

/*
    Esempio per chi non ha compreso:
    dato il vettore: [1,2,3,-5,2,1,2,1,-4,3]

    la somma massima che si può ottenere è di: 7
    sommando gli elementi da 0 a 7 si ottiene la somma massima, ovvero 7
*/

/*
    int vec[] = {1,2,3,-5,2,1,2,1,-4,3,'\0'};
    risultato atteso: 7
*/

/*
    int vec[] = {1,1,1,-2,1,-4,4};
    risultato atteso: 4
*/

/*
    int vec[] = {12,43,-24,-15,46,-82,35,-23,14,41,-32,13};
    risultato atteso: 67
*/

int main(){
    int res_totale = vec[0];
    int res_parziale = 0;

    for(int i=0; vec[i] != '\0'; i++){
        res_parziale += vec[i];
        if(res_parziale>res_totale){
            res_totale = res_parziale;
        }
        if(res_parziale < 0){
            res_parziale = 0;
        }
    }

    cout<<"Risultato: "<<res_totale<<endl;

    return 0;
}
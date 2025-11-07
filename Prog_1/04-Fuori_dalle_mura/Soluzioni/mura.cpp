#include <iostream>
using namespace std;

/*
    const int N = 5;
    int mat[N][N] = {{0,0,1,0,0},
                   {0,0,1,0,0},
                   {0,0,1,0,0},
                   {0,0,0,0,0},
                   {0,0,1,0,0}
                    };

    risultato atteso: si può passare
*/

/*
    const int N = 5;
    int mat[N][N] = {{0,0,1,0,0},
                   {0,0,0,1,0},
                   {0,0,1,0,0},
                   {0,0,0,1,0},
                   {0,0,1,0,0}
                    };

    risultato atteso: non si può passare
*/

/*
    const int N = 7;
    int mat[N][N] = {{0,0,1,0,0,0,0},
                   {0,0,1,0,1,1,0},
                   {0,0,1,0,0,1,0},
                   {0,0,1,1,0,1,0},
                   {0,0,0,0,0,1,0},
                   {0,0,1,1,1,1,0},
                   {0,0,1,0,0,0,0}
                    };
    
    risultato atteso: si può passare
*/

/*
    const int N = 7;
    int mat[N][N] = {{0,0,1,0,0,0,0},
                   {0,0,1,0,1,1,0},
                   {0,0,1,0,0,1,0},
                   {0,0,1,1,0,1,0},
                   {0,0,0,0,0,1,1},
                   {0,0,1,0,1,0,0},
                   {0,0,1,0,0,1,0}
                    };

    risultato atteso: non si può passare
*/

bool dentro(int x, int y){ // Funzione che controlla se le coordinate x e y sono dentro la matrice
    return x >= 0 && y >= 0 && x < N && y < N;
}

bool valido(int x, int y){ // Funzione che controlla se le coordinate x e y sono valide (ovvero se non mi sto spostando in diagonale)
    return (x == 0 || y == 0);
}

bool expand(int mat[N][N], int x, int y){ // Funzione che controlla se data una cella di partenza io mi posso spostare nelle celle vicine
    int cambiamento = false;

    for(int i=x-1; i<=x+1; i++){
        for(int j=y-1; j<=y+1; j++){
            if(dentro(i,j) && valido(i-x,j-y) && mat[i][j] == 0){
                mat[i][j] = 2;
                cambiamento = true;
            }
        }
    }

    return cambiamento;
}

void print_matrice(int mat[N][N]){ // Funzione di debug per stampare la matrice
    cout<<"Matrice attuale: "<<endl;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main() {
    if(mat[0][0] == 1 || mat[N-1][N-1] == 1){ // Controllo fin da subito se inizio o fine sono bloccati
        cout<<"Non si può passare (bloccato all'inizio o alla fine)."<<endl;
        return 0;
    }

    // IDEA: espando la mia matrice poco alla volta, in base al numero della cella agisco di conseguenza:
    //      0 = cella libera non ancora visitata
    //      1 = muro/bloccato
    //      2 = celle raggiungibili ma delle quali non ho ancora espanso le vicinanze
    //      3 = celle raggiungibili ma delle quali ho già espanso le vicinanze

    // Inizializziamo il punto di partenza con 2 (raggiungibile non espanso)
    mat[0][0] = 2;
    bool passaggio_esistente = true;
    bool fine_raggiunta = false;

    // Finché ho delle celle da visitare
    while(passaggio_esistente && !fine_raggiunta){
        passaggio_esistente = false;

        for(int i=0; i<N; i++){ // Per ogni elemento all'interno della matrice
            for(int j=0; j<N; j++){

                if(mat[i][j] == 2){ // Se la cella è raggiungibile ma non ancora espansa
                    mat[i][j] = 3;

                    if(i == N-1 && j == N-1){
                        fine_raggiunta=true;
                    }else{
                        passaggio_esistente = expand(mat,i,j) ||passaggio_esistente; // Espando le celle vicine e se ho fatto cambiamenti segno che dovrò continuare il ciclo
                    }
                    
                }

            }
        }
        print_matrice(mat); // Debug: stampo la matrice ad ogni iterazione
    }

    if(fine_raggiunta){
        cout << "Si può passare" << endl;
    }else{
        cout << "Non si può passare" << endl;
    }
    return 0;
}
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv){
    if(argc != 3){
        cerr << "Usage: "<< argv[0] <<" <messaggio> <posizioni>\n";
        return -1;
    }

    fstream messaggio, posizioni;
    messaggio.open(argv[1], ios::in);
    if(!messaggio.is_open()){
        cerr << "Error during file opening: " << argv[1] << "\n";
        return -2;
    }
    posizioni.open(argv[2], ios::in);
    if(!posizioni.is_open()){
        cerr << "Error during file opening: " << argv[2] << "\n";
        messaggio.close();
        return -2;
    }

    // Leggo il numero di righe e creo la matrice dimanica che terrà il messaggio completo
    int numero_righe;
    posizioni >> numero_righe;
    char** messaggio_completo = new char*[numero_righe];

    // Riempio la matrice con i caratteri del messaggio
    int riga, num_char;
    while(posizioni >> riga >> num_char){
        messaggio_completo[riga] = new char[num_char + 1];
        messaggio_completo[riga][num_char] = '\0';
        for(int i = 0; i < num_char; i++){
            char c;
            messaggio.get(c);
            messaggio_completo[riga][i] = c; 
        }
    }

    // Stampo il messaggio completo
    for(int i=0; i<numero_righe; i++){
        cout<< messaggio_completo[i] << "\n";
        delete[] messaggio_completo[i]; // Libero la riga dopo averla stampata
    }

    delete[] messaggio_completo; // Libero la matrice e chiudo i file
    messaggio.close();
    posizioni.close();

    return 0;
}
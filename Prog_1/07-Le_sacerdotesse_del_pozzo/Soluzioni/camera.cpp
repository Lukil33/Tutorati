#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

char* aggiungi_carattere_ricorsivo(char* sottostringa){
    int len = strlen(sottostringa);
    char* res = new char[len + 2];
    
    res[0] = '@';
    strcpy(res + 1, sottostringa);
    delete[] sottostringa;
    return res;
}

char* Funzione_ricorsiva(char* testo, int dim = 0){
    if(testo[dim] == '\0'){
        char* res = new char[1];
        res[0] = '\0';
        return res;
    }else{
        char* sottostringa = Funzione_ricorsiva(testo, dim + 1);
        if(testo[dim] == '@'){
            sottostringa = aggiungi_carattere_ricorsivo(sottostringa);
        }
        return sottostringa;
    }
}

int main(int argc, char** argv){
    if(argc != 2){
        cerr << "Usage: " << argv[0] << " <input_file>" << endl;
        return -1;
    }

    fstream testo;
    testo.open(argv[1], ios::in);
    if(!testo.is_open()){
        cerr << "Error during file opening: " << argv[1] << endl;
        return -2;
    }

    int dim;
    testo >> dim;
    char* t = new char[dim + 1];
    testo >> t;

    cout<<"Testo originale: "<<t<<endl;
    char* risultato = Funzione_ricorsiva(t);
    cout<<risultato<<endl;

    delete[] risultato;
    delete[] t;
    testo.close();

    return 0;
}
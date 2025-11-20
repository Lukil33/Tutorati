#include <iostream>
#include <fstream>
using namespace std;

bool strcmp(const char* a, const char* b){
    int i = 0;
    while(a[i]!='\0' && b[i]!='\0'){
        if(a[i]!=b[i]){
            return false;
        }
        i++;
    }
    return a[i]=='\0' && b[i]=='\0';
}

void strcpy(char* dest, const char* src){
    int i = 0;
    while(src[i]!='\0'){
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

bool sostituisci(char* parola, char db_criptato[100][100], char db_decriptato[100][100]){
    for(int i=0; db_criptato[i][0]!='\0'; i++){
        if(strcmp(parola, db_criptato[i])){
            strcpy(parola, db_decriptato[i]);
            return true;
        }
    }
    return false;
}

int main(){
    fstream input, criptato, decriptato;
    input.open("testo.txt", ios::in);
    if(input.fail()){
        cerr<<"Error during file opening"<<endl;
        return -2;
    }
    criptato.open("parole_criptate.txt", ios::in);
    if(criptato.fail()){
        cerr<<"Error during file opening"<<endl;
        return -2;
    }
    decriptato.open("parole_decriptate.txt", ios::in);
    if(decriptato.fail()){
        cerr<<"Error during file opening"<<endl;
        return -2;
    }

    char db_criptato[100][100];
    int n_criptate = 0;
    while(criptato>>db_criptato[n_criptate]){
        n_criptate++;
    }
    db_criptato[n_criptate][0] = '\0'; // Segnalo la fine delle parole criptate

    char db_decriptato[100][100];
    int n_decriptate = 0;
    while(decriptato>>db_decriptato[n_decriptate]){
        n_decriptate++;
    }
    db_decriptato[n_decriptate][0] = '\0'; // Segnalo la fine delle parole decriptate

    char parola[100];
    while(input>>parola){
        bool check = false;
        do{
            check = sostituisci(parola, db_criptato, db_decriptato);
        }while(check);
        cout<<parola<<" ";
    }
    cout<<endl;

    input.close();
    criptato.close();
    decriptato.close();
    return 0;
}
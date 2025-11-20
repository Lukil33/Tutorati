#include <iostream>
#include <fstream>
using namespace std;

struct Libro{
    char nome[30];
    char autore[30];
    int anno_pubblicazione;
    int numero_caratteri;
};

void stampaLibri(Libro* l, int num_libri){
    for(int i=0; i<num_libri; i++){
        cout<<"Libro "<<i+1<<": "<<endl;
        cout<<"\tTitolo: "<<l[i].nome<<endl;
        cout<<"\tAutore: "<<l[i].autore<<endl;
        cout<<"\tAnno di pubblicazione: "<<l[i].anno_pubblicazione<<endl;
        cout<<"\tNumero di caratteri: "<<l[i].numero_caratteri<<endl;
        cout<<endl;
    }
}

int len(char* str){
    int counter = 0;
    while(str[counter]!='\0'){
        counter++;
    }
    return counter;
}

int main(){
    fstream input;
    input.open("input.txt", ios::in);
    if(input.fail()){
        cerr<<"Error during file opening"<<endl;
        return -2;
    }
    
    struct Libro* lib = new struct Libro[100];
    char title[30];
    int n = 0;
    while(input>>title){
        fstream file;
        file.open(title, ios::in);
        if(file.fail()){
            cerr<<"Error during file opening"<<endl;
            return -2;
        }
        
        file>>lib[n].nome;
        file>>lib[n].autore;
        file>>lib[n].anno_pubblicazione;
        lib[n].numero_caratteri = 0;
        char parola[100];
        while(file>>parola){
            lib[n].numero_caratteri += len(parola);
        }
        n++;
        file.close();
    }

    stampaLibri(lib,n);

    input.close();
    return 0;
}
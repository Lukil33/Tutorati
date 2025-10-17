#include <iostream>
using namespace std;
#define N 255

char prima_parola[N] = {'A','b','b','a','s','s','o',' ','l','e',' ','g','u','a','r','d','i','e','\0'};
char seconda_parola[N] = {'\0'};

void strcpy(char* src, char* dest){
    for(int i=0; i<N && src[i] != '\0'; i++){
        dest[i] = src[i];
    }
}

bool strcmp(char* src, char* dest){
    int i = 0;
    while(src[i] == dest[i]){
        if(src[i] == '\0'){
            return true;
        }
        i += 1;
    }
    return false;
}

void print_parola(char* str){
    for(int i=0; i<N && str[i] != '\0'; i++){
        cout<<str[i];
    }
}

int main(){
    cout<<"Prima parola: ";
    print_parola(prima_parola);
    cout<<endl;
    cout<<"Seconda parola: ";
    print_parola(seconda_parola);
    cout<<endl;

    strcpy(prima_parola, seconda_parola);

    cout<<"Prima parola: ";
    print_parola(prima_parola);
    cout<<endl;
    cout<<"Seconda parola: ";
    print_parola(seconda_parola);
    cout<<endl;

    cout<<"Le stringhe sono uguali?: "<<strcmp(prima_parola,seconda_parola)<<endl;

    return 0;
}
#include <stdio.h>
#include <stdbool.h>

#define N 255

char prima_parola[N] = {'A','b','b','a','s','s','o',' ','l','e',' ','g','u','a','r','d','i','e','\0'};
char seconda_parola[N] = {'\0'};

/* custom copy that ensures termination and does not overflow dest */
void my_strcpy(const char* src, char* dest){
    int i;
    for(i = 0; i < N-1 && src[i] != '\0'; ++i){
        dest[i] = src[i];
    }
    dest[i] = '\0';
}

/* custom compare returning true if equal */
bool my_strcmp(const char* a, const char* b){
    int i = 0;
    while(i < N){
        if(a[i] != b[i]) return false;
        if(a[i] == '\0') return true;
        ++i;
    }
    return false;
}

void print_parola(const char* str){
    for(int i = 0; i < N && str[i] != '\0'; ++i){
        putchar((unsigned char)str[i]);
    }
}

int main(void){
    printf("Prima parola: ");
    print_parola(prima_parola);
    printf("\n");
    printf("Seconda parola: ");
    print_parola(seconda_parola);
    printf("\n\n");

    my_strcpy(prima_parola, seconda_parola);

    printf("Dopo la copia:\n");
    printf("Prima parola: ");
    print_parola(prima_parola);
    printf("\n");
    printf("Seconda parola: ");
    print_parola(seconda_parola);
    printf("\n\n");

    printf("Le stringhe sono uguali?: %s\n", my_strcmp(prima_parola, seconda_parola) ? "true" : "false");

    return 0;
}
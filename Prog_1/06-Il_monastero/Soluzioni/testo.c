#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Convertito in C: usa FILE*, fopen, fscanf, printf e funzioni di string.h */

static int sostituisci(char* parola, char db_criptato[100][100], char db_decriptato[100][100]){
    for(int i = 0; db_criptato[i][0] != '\0'; i++){
        if(strcmp(parola, db_criptato[i]) == 0){
            strcpy(parola, db_decriptato[i]);
            return 1;
        }
    }
    return 0;
}

int main(void){
    FILE *input = fopen("testo.txt", "r");
    if(!input){
        fprintf(stderr, "Error during file opening: testo.txt\n");
        return -2;
    }
    FILE *criptato = fopen("parole_criptate.txt", "r");
    if(!criptato){
        fprintf(stderr, "Error during file opening: parole_criptate.txt\n");
        fclose(input);
        return -2;
    }
    FILE *decriptato = fopen("parole_decriptate.txt", "r");
    if(!decriptato){
        fprintf(stderr, "Error during file opening: parole_decriptate.txt\n");
        fclose(input);
        fclose(criptato);
        return -2;
    }

    char db_criptato[100][100];
    int n_criptate = 0;
    while(fscanf(criptato, "%99s", db_criptato[n_criptate]) == 1){
        n_criptate++;
        if(n_criptate >= 100) break;
    }
    db_criptato[n_criptate][0] = '\0'; /* segnalo fine */

    char db_decriptato[100][100];
    int n_decriptate = 0;
    while(fscanf(decriptato, "%99s", db_decriptato[n_decriptate]) == 1){
        n_decriptate++;
        if(n_decriptate >= 100) break;
    }
    db_decriptato[n_decriptate][0] = '\0'; /* segnalo fine */

    char parola[100];
    while(fscanf(input, "%99s", parola) == 1){
        int check = 0;
        do{
            check = sostituisci(parola, db_criptato, db_decriptato);
        }while(check);
        printf("%s ", parola);
    }
    printf("\n");

    fclose(input);
    fclose(criptato);
    fclose(decriptato);
    return 0;
}
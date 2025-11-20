#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[30];
    char autore[30];
    int anno_pubblicazione;
    int numero_caratteri;
} Libro;

static void stampaLibri(const Libro* l, int num_libri){
    for(int i=0; i<num_libri; i++){
        printf("Libro %d:\n", i+1);
        printf("\tTitolo: %s\n", l[i].nome);
        printf("\tAutore: %s\n", l[i].autore);
        printf("\tAnno di pubblicazione: %d\n", l[i].anno_pubblicazione);
        printf("\tNumero di caratteri: %d\n\n", l[i].numero_caratteri);
    }
}

int main(void){
    FILE *input = fopen("input.txt", "r");
    if(!input){
        fprintf(stderr, "Error during file opening: input.txt\n");
        return -2;
    }

    Libro *lib = (Libro*)malloc(sizeof(Libro) * 100);
    if(!lib){
        fprintf(stderr, "Memory allocation failed\n");
        fclose(input);
        return -3;
    }

    char title[256];
    int n = 0;
    while(fscanf(input, "%255s", title) == 1){
        FILE *file = fopen(title, "r");
        if(!file){
            fprintf(stderr, "Error during file opening: %s\n", title);
            free(lib);
            fclose(input);
            return -2;
        }

        if(fscanf(file, "%29s", lib[n].nome) != 1) strcpy(lib[n].nome, "<unknown>");
        if(fscanf(file, "%29s", lib[n].autore) != 1) strcpy(lib[n].autore, "<unknown>");
        if(fscanf(file, "%d", &lib[n].anno_pubblicazione) != 1) lib[n].anno_pubblicazione = 0;

        lib[n].numero_caratteri = 0;
        char parola[256];
        while(fscanf(file, "%255s", parola) == 1){
            lib[n].numero_caratteri += (int)strlen(parola);
        }

        fclose(file);
        n++;
        if(n >= 100) break; /* limit to allocated size */
    }

    stampaLibri(lib, n);

    free(lib);
    fclose(input);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef enum {
    Scriba,
    Cuoco,
    Botanico,
    Religioso
} Man;

typedef struct Monaco{
    char nome[30];
    int eta;
    Man mansione;
    int anni_in_monastero;
} Monaco;

void stampaMonaco(Monaco* m, int num_monaci){
    for(int i=0; i<num_monaci; i++){
        printf("Monaco %d:\n", i+1);
        printf("\tNome: %s\n", m[i].nome);
        printf("\tEta': %d\n", m[i].eta);
        printf("\tMansione: ");
        switch(m[i].mansione){
            case Scriba: printf("Scriba"); break;
            case Cuoco: printf("Cuoco"); break;
            case Botanico: printf("Botanico"); break;
            case Religioso: printf("Religioso"); break;
            default: printf("Unknown"); break;
        }
        printf("\n");
        printf("\tAnni in monastero: %d\n\n", m[i].anni_in_monastero);
    }
}

void swapMonaci(Monaco* m1, Monaco* m2){
    Monaco temp = *m1;
    *m1 = *m2;
    *m2 = temp;
}

void toggleOrdine(Monaco* m, int num_monaci, int *ordine){
    // Ordinamento per anni_in_monastero (bubble sort)
    for(int i=0; i<num_monaci-1; i++){
        for(int j=0; j<num_monaci-i-1; j++){
            if((*ordine && m[j].anni_in_monastero > m[j+1].anni_in_monastero) || (!*ordine && m[j].anni_in_monastero < m[j+1].anni_in_monastero)){
                swapMonaci(&m[j], &m[j+1]);
            }
        }
    }
    *ordine = !*ordine;
}

int main(void){
    srand((unsigned)time(NULL));
    int n = 0;
    printf("Inserisci il numero di monaci da inserire: ");
    if(scanf("%d", &n) != 1 || n <= 0){
        fprintf(stderr, "Numero non valido\n");
        return 1;
    }

    Monaco* monaci = (Monaco*)malloc(n * sizeof(Monaco));
    if(!monaci){
        fprintf(stderr, "Allocazione fallita\n");
        return 1;
    }

    for(int i=0; i<n; i++){
        printf("Inserisci il nome del monaco %d: ", i+1);
        if(scanf("%29s", monaci[i].nome) != 1){
            strncpy(monaci[i].nome, "<sconosciuto>", sizeof(monaci[i].nome));
            monaci[i].nome[sizeof(monaci[i].nome)-1] = '\0';
        }
        printf("Inserisci l'eta' del monaco %d: ", i+1);
        if(scanf("%d", &monaci[i].eta) != 1){
            monaci[i].eta = 0;
        }
        switch(rand() % 4){
            case 0: monaci[i].mansione = Scriba; break;
            case 1: monaci[i].mansione = Cuoco; break;
            case 2: monaci[i].mansione = Botanico; break;
            default: monaci[i].mansione = Religioso; break;
        }
        if(monaci[i].eta > 0)
            monaci[i].anni_in_monastero = rand() % monaci[i].eta;
        else
            monaci[i].anni_in_monastero = 0;
    }

    int decisione = 1;
    int ordine = 1; /* 1 = crescente, 0 = decrescente */
    while(decisione != 0){
        printf("Cosa vuoi stampare (0=esci, 1=stampa, 2=toggle): ");
        if(scanf("%d", &decisione) != 1){
            /* consumare input non valido */
            int c;
            while((c = getchar()) != '\n' && c != EOF){}
            decisione = -1;
        }
        switch(decisione){
            case 0: printf("\n"); break;
            case 1: stampaMonaco(monaci,n); break;
            case 2: toggleOrdine(monaci,n, &ordine); break;
            default: printf("Numero inserito non valido\n"); break;
        }
    }

    free(monaci);
    return 0;
}
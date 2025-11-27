#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int elemento_presente(int* pozzo, int dim, int N){
    for(int i=0; i<dim; i++){
        if(pozzo[i] == N) return 1;
    }
    return 0;
}

int* rimuovi_elemento(int* pozzo, int *dim, int N){ // Rimuove il primo elemento uguale a N e aggiorna dim tramite puntatore
    int counter = 0;
    int* res = (int*)malloc((*dim - 1) * sizeof(int));
    if(!res) return NULL;

    for(int i=0; i<*dim; i++){
        if(pozzo[i] != N){
            res[counter++] = pozzo[i];
        }
    }

   free(pozzo);
    *dim -= 1;
    return res;
}

int* aggiungi_elemento(int* pozzo, int *dim, int N){ // Aggiunge l'elemento N in coda e aggiorna dim tramite puntatore
    int* res = (int*)malloc((*dim + 1) * sizeof(int));
    if(!res) return NULL;

    for(int i=0; i<*dim; i++){
        res[i] = pozzo[i];
    }
    res[*dim] = N;

    if(pozzo) free(pozzo);
    *dim += 1;
    return res;
}

static void stampa_pozzo(int* pozzo, int dim){
    printf("Dimensione pozzo: %d\n", dim);
    printf("Pozzo -> ");
    for(int i=0; i<dim; i++){
        printf("%d ", pozzo[i]);
    }
    printf("\n");
}

int main(void){
    char input = 's';
    int dim_pozzo = 0;
    int* pozzo = NULL;

    while(input == 's' || input == 'S'){
        int N;
        printf("Inserisci un numero da cercare all'interno del pozzo: ");
        if(scanf("%d", &N) != 1){
            /* consumare input non valido */
            int c;
            while((c = getchar()) != '\n' && c != EOF){}
            continue;
        }

        if(elemento_presente(pozzo, dim_pozzo, N)){
            pozzo = rimuovi_elemento(pozzo, &dim_pozzo, N);
        }else{
            pozzo = aggiungi_elemento(pozzo, &dim_pozzo, N);
        }

        if(dim_pozzo <= 0){
            printf("Il pozzo si è seccato\n");
            input = 'n';
        }else if(dim_pozzo >= 10){
            printf("Il pozzo si sta straripando\n");
            input = 'n';
        }else{
            printf("Vuoi inserire un nuovo numero? (S/N) ");
            if(scanf(" %c", &input) != 1) input = 'n';
        }

        stampa_pozzo(pozzo, dim_pozzo);
    }

    if(pozzo) free(pozzo);
    return 0;
}
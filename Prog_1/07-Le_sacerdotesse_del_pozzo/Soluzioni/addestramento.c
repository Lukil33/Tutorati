#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Rimuove l'ultimo elemento (stack pop). Restituisce il nuovo vettore e aggiorna *dim. */
static int* rimuovi_elementi_Pila(int* vett, int *dim){
    if(*dim == 0){
        printf("Il vettore e' vuoto, impossibile rimuovere elementi.\n");
        return vett;
    }

    int new_dim = *dim - 1;
    int* res = NULL;
    if(new_dim > 0){
        res = (int*)malloc(new_dim * sizeof(int));
        if(!res) return vett; /* allocation failed -> keep old vector */
        for(int i=0; i<new_dim; i++) res[i] = vett[i];
    }

    free(vett);
    *dim = new_dim;
    return res; /* may be NULL if new_dim == 0 */
}

/* Rimuove il primo elemento (queue dequeue). Restituisce il nuovo vettore e aggiorna *dim. */
static int* rimuovi_elementi_Coda(int* vett, int *dim){
    if(*dim == 0){
        printf("Il vettore e' vuoto, impossibile rimuovere elementi.\n");
        return vett;
    }

    int new_dim = *dim - 1;
    int* res = NULL;
    if(new_dim > 0){
        res = (int*)malloc(new_dim * sizeof(int));
        if(!res) return vett;
        for(int i=1; i<*dim; i++) res[i-1] = vett[i];
    }

    free(vett);
    *dim = new_dim;
    return res;
}

/* Aggiunge un elemento in coda (push/enqueue). Restituisce il nuovo vettore e aggiorna *dim. */
static int* aggiungi_elemento(int* vett, int *dim){
    int N;
    printf("Inserisci l'elemento da aggiungere: ");
    if(scanf("%d", &N) != 1){
        int c; while((c = getchar()) != '\n' && c != EOF){};
        printf("Input non valido.\n");
        return vett;
    }

    int new_dim = *dim + 1;
    int* res = (int*)malloc(new_dim * sizeof(int));
    if(!res) return vett;

    for(int i=0; i<*dim; i++){
        if(vett) res[i] = vett[i];
    }
    res[*dim] = N;

    if(vett) free(vett);
    *dim = new_dim;
    return res;
}

static void stampa(int* pozzo, int dim){
    printf("Dimensione vettore: %d\n", dim);
    printf("Vettore -> ");
    for(int i=0; i<dim; i++) printf("%d ", pozzo[i]);
    printf("\n");
}

int main(void){
    int input;
    int dim = 0;
    int* vett = NULL;

    do{
        printf("Quale operazione vuoi effettuare?\n\t1: push Pila\n\t2: pop Pila\n\t3: enqueue Coda\n\t4: dequeue Coda\n\t5: Stampa\n\t6: Esci\n");
        if(scanf("%d", &input) != 1) break;

        switch(input){
            case 1: /* push/enqueue */
                vett = aggiungi_elemento(vett, &dim);
                break;
            case 2:
                vett = rimuovi_elementi_Pila(vett, &dim);
                break;
            case 3:
                /* enqueue -> same as push */
                vett = aggiungi_elemento(vett, &dim);
                break;
            case 4:
                vett = rimuovi_elementi_Coda(vett, &dim);
                break;
            case 5:
                stampa(vett, dim);
                break;
            case 6:
                break;
            default:
                printf("Valore inserito non valido\n");
                break;
        }
    }while(input != 6);
    
    if(vett) free(vett);
    return 0;
}
#include <stdio.h>
#define N 100

int banca_dati[N] = {'\0'};

void aggiungere(int* banca, int num){
    int i=0;
    for(; banca[i] != '\0'; i++);
    banca[i] = num;
    banca[i+1] = '\0';
}

void rimuovere_semplice(int* banca, int num){
    /* Un modo molto basico di rimozione consiste nell'inserire un valore prestabilito per segnare che all'interno di quella cella non vi è più nulla
     * Vantaggi: Molto semplice da implementare
     * Svantaggi: Non permette di inserire più di N elementi all'interno dell'array ed è poco efficiente */
    int i;
    for(i=0; banca[i] != '\0'; i++){
        if( banca[i] == num ){
            banca[i] = -1; 
        }
    }
}

void rimuovere_completo(int* banca, int num){
    /* Una tecnica più "pulita"
     * Vantaggi: molto efficiente, risparmia spazio
     * Svantaggi: più complessa da implementare, la rimozione può causare dei problemi */
    int i, j;
    for(i=0; banca[i] != '\0'; i++){
        if( banca[i] == num ){
            int j=i;
            for(; banca[j] == num; j++);
            banca[i] = banca[j];
            banca[j] = num;
            if(banca[i] == '\0'){
                banca[i+1] = '\0';
            }
        }
    }
}

int cercare(int* banca, int num){
    int first_position = -1;
    for(int i=0; banca[i] != '\0'; i++){
        if( banca[i] == num && first_position == -1){
            first_position = i;
        }
    }
    return first_position;
}

void stampare(int* banca){
    int i;
    printf("Banca dati: ");
    for(i=0; banca[i] != '\0'; i++){
        printf("%d ", banca[i]);
    }
    printf("\n");
}

int main(void){
    int scelta, numero, posizione;
    int continua = 1;

    while(continua) {
        printf("\nMenu Banca Dati:\n");
        printf("1. Aggiungi numero\n");
        printf("2. Rimuovi numero (modo semplice)\n");
        printf("3. Rimuovi numero (modo completo)\n");
        printf("4. Cerca numero\n");
        printf("5. Stampa banca dati\n");
        printf("0. Esci\n");
        printf("\nScegli un'operazione: ");
        scanf("%d", &scelta);

        switch(scelta) {
            case 1:
                printf("Inserisci il numero da aggiungere: ");
                scanf("%d", &numero);
                aggiungere(banca_dati, numero);
                printf("Numero aggiunto con successo!\n");
                break;
            
            case 2:
                printf("Inserisci il numero da rimuovere: ");
                scanf("%d", &numero);
                rimuovere_semplice(banca_dati, numero);
                printf("Numero rimosso con successo (modo semplice)!\n");
                break;
            
            case 3:
                printf("Inserisci il numero da rimuovere: ");
                scanf("%d", &numero);
                rimuovere_completo(banca_dati, numero);
                printf("Numero rimosso con successo (modo completo)!\n");
                break;
            
            case 4:
                printf("Inserisci il numero da cercare: ");
                scanf("%d", &numero);
                posizione = cercare(banca_dati, numero);
                if(posizione != -1)
                    printf("Numero trovato in posizione: %d\n", posizione);
                else
                    printf("Numero non trovato!\n");
                break;
            
            case 5:
                stampare(banca_dati);
                break;
            
            case 0:
                printf("Arrivederci!\n");
                continua = 0;
                break;
            
            default:
                printf("Scelta non valida!\n");
        }
    }

    return 0;
}
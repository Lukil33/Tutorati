#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* aggiungi_carattere_ricorsivo(char* sottostringa){
    int len = (int)strlen(sottostringa);
    char* res = (char*)malloc((len + 2) * sizeof(char));
    if(!res) return NULL;
    
    res[0] = '@';
    strcpy(res + 1, sottostringa);
    free(sottostringa);
    return res;
}

char* Funzione_ricorsiva(char* testo, int dim){
    if(testo[dim] == '\0'){
        char* res = (char*)malloc(1);
        if(res) res[0] = '\0';
        return res;
    }else{
        char* sottostringa = Funzione_ricorsiva(testo, dim + 1);
        if(testo[dim] == '@'){
            sottostringa = aggiungi_carattere_ricorsivo(sottostringa);
        }
        return sottostringa;
    }
}

int main(int argc, char **argv){
    if(argc != 2){
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return -1;
    }

    FILE *testo = fopen(argv[1], "r");
    if(!testo){
        fprintf(stderr, "Error during file opening: %s\n", argv[1]);
        return -2;
    }

    int dim;
    if(fscanf(testo, "%d", &dim) != 1){
        fprintf(stderr, "Error reading dim\n");
        fclose(testo);
        return -3;
    }

    char *t = (char*)malloc((dim + 1) * sizeof(char));
    if(!t){
        fprintf(stderr, "Memory allocation failed\n");
        fclose(testo);
        return -3;
    }

    if(fscanf(testo, "%s", t) != 1){
        fprintf(stderr, "Error reading string\n");
        free(t);
        fclose(testo);
        return -3;
    }

    printf("Testo originale: %s\n", t);
    char* risultato = Funzione_ricorsiva(t, 0);
    if(risultato){
        printf("%s\n", risultato);
        free(risultato);
    }

    free(t);
    fclose(testo);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){
    if(argc != 3){
        fprintf(stderr, "Usage: %s <messaggio> <posizioni>\n", argv[0]);
        return -1;
    }

    FILE *messaggio_file = fopen(argv[1], "r");
    if(!messaggio_file){
        fprintf(stderr, "Error during file opening: %s\n", argv[1]);
        return -2;
    }

    FILE *posizioni_file = fopen(argv[2], "r");
    if(!posizioni_file){
        fprintf(stderr, "Error during file opening: %s\n", argv[2]);
        fclose(messaggio_file);
        return -2;
    }

    /* Leggo il numero di righe e creo la matrice dinamica */
    int numero_righe;
    if(fscanf(posizioni_file, "%d", &numero_righe) != 1){
        fprintf(stderr, "Error reading numero_righe\n");
        fclose(messaggio_file);
        fclose(posizioni_file);
        return -3;
    }

    char **messaggio_completo = (char**)malloc(numero_righe * sizeof(char*));
    if(!messaggio_completo){
        fprintf(stderr, "Memory allocation failed\n");
        fclose(messaggio_file);
        fclose(posizioni_file);
        return -3;
    }

    /* Riempio la matrice con i caratteri del messaggio */
    int riga, num_char;
    while(fscanf(posizioni_file, "%d %d", &riga, &num_char) == 2){
        if(riga >= numero_righe){
            fprintf(stderr, "Invalid row index: %d\n", riga);
            continue;
        }

        messaggio_completo[riga] = (char*)malloc((num_char + 1) * sizeof(char));
        if(!messaggio_completo[riga]){
            fprintf(stderr, "Memory allocation failed for row %d\n", riga);
            continue;
        }

        messaggio_completo[riga][num_char] = '\0';
        for(int i = 0; i < num_char; i++){
            int c = fgetc(messaggio_file);
            if(c == EOF) break;
            messaggio_completo[riga][i] = (char)c;
        }
    }

    /* Stampo il messaggio completo e libero la memoria */
    for(int i = 0; i < numero_righe; i++){
        if(messaggio_completo[i]){
            printf("%s\n", messaggio_completo[i]);
            free(messaggio_completo[i]);
        }
    }

    free(messaggio_completo); // libero la matrice e chiudo i file
    fclose(messaggio_file);
    fclose(posizioni_file);

    return 0;
}
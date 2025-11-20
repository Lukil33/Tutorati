#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXW 100

/* Restituisce 1 se la parola è tutta maiuscola A..Z, 0 altrimenti */
static int check_word(const char *word){
    for(int i = 0; word[i] != '\0'; i++){
        if(word[i] < 'A' || word[i] > 'Z') return 0;
    }
    return 1;
}

/* Inverte la stringa in place */
static void reverse_str(char *word){
    int len = (int)strlen(word);
    for(int i = 0; i < len/2; i++){
        char tmp = word[i];
        word[i] = word[len-i-1];
        word[len-i-1] = tmp;
    }
}

int main(int argc, char *argv[]){
    if(argc != 3){
        fprintf(stderr, "Error: %s <input_file> <output_file>\n", argv[0]);
        return -1;
    }

    FILE *input = fopen(argv[1], "r");
    if(!input){
        fprintf(stderr, "Error during file opening: %s\n", argv[1]);
        return -2;
    }

    FILE *output = fopen(argv[2], "w");
    if(!output){
        fprintf(stderr, "Error during file opening: %s\n", argv[2]);
        fclose(input);
        return -2;
    }

    char word[MAXW];
    while(fscanf(input, "%s", word) == 1){
        if(check_word(word)){
            reverse_str(word);
        }
        fprintf(output, "%s ", word);
    }

    fclose(input);
    fclose(output);
    return 0;
}
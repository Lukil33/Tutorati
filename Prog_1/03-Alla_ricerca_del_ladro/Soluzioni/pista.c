#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void swap_chars(char* a, char* b){
    /* swap senza var temporanea (attento a overflow) */
    (*a) += (*b);
    (*b) = (*a) - (*b);
    (*a) -= (*b);
}

void move(char *a, char *b, char *c){
    int scambio = rand() % 4;

    switch(scambio){
        case 0: swap_chars(a,b); break;
        case 1: swap_chars(a,c); break;
        case 2: swap_chars(b,c); break;
        default: ;
    }
}

void genera_posizione_iniziale(char *a, char *b, char *c){ /* Volendo si può hardcodare la posizione iniziale */
    int pos_queen = rand() % 3;
    switch(pos_queen){
        case 0: *a = 'Q'; *b = '8'; *c = '8'; break;
        case 1: *a = '8'; *b = 'Q'; *c = '8'; break;
        case 2: *a = '8'; *b = '8'; *c = 'Q'; break;
    }
}
bool play_round(void){
    int numero_spostamenti = rand() % 10 + 1;
    char a, b, c;
    genera_posizione_iniziale(&a, &b, &c);
    printf("Mercante: <<Mischio le carte>>\n");
    for(int i = 0; i < numero_spostamenti; i++){
        move(&a, &b, &c);
    }
    printf("Mercante: <<Finito, ora tocca a te, dove si trova la regina?>>\n");
    printf("\t[1]\t[2]\t[3]\n");
    printf("Inserire un numero da 1 a 3: ");
    int num = 0;
    if(scanf("%d", &num) != 1){
        /* input non valido */
        printf("Mercante: <<Input non valido>>\n");
        /* svuota stdin fino a newline */
        int ch; while((ch = getchar()) != '\n' && ch != EOF); 
    }
    bool check = false;
    switch(num){
        case 1: check = (a == 'Q'); break;
        case 2: check = (b == 'Q'); break;
        case 3: check = (c == 'Q'); break;
        default:
            printf("Mercante: <<Il numero inserito era sbagliato, peggio per te, lo considererò come un errore>>\n");
            break;
    }
    if(check){
        printf("Mercante: <<Complimenti, hai scelto la carta giusta>>\n");
    }else{
        printf("Mercante: <<Mi spiace, hai sbagliato>>\n");
    }
    printf("Le carte erano messe così:\n\t[%c]\t[%c]\t[%c]\n\n", a, b, c);
    return check;
}

int game(int numero_round){
    int res = 0;
    for(int i = 0; i < numero_round; i++){
        if(play_round()){
            res += 1;
        }
    }
    return res;
}

int main(void){
    srand((unsigned)time(NULL));
    int n = 0;
    printf("Inserisci il numero di round da effettuare: ");
    if(scanf("%d", &n) != 1){
        printf("Input non valido\n");
        return 1;
    }
    int round_vinti = game(n);
    printf("Il numero di round vinti in totale è: %d\n", round_vinti);
    return 0;
}
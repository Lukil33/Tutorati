#include <stdio.h>

int main(){
    char tasca_sinistra,tasca_destra;
    printf("Inserire il contenuto della tasca sinistra: ");
    scanf(" %c",&tasca_sinistra);
    fflush(stdin);
    printf("Inserire il contenuto della tasca destra: ");
    scanf(" %c",&tasca_destra);
    fflush(stdin);

    printf("Contenuto tasca sinistra: %c - Contenuto tasca destra: %c\n",tasca_sinistra,tasca_destra);

    tasca_destra = tasca_destra + tasca_sinistra;
    tasca_sinistra = tasca_destra - tasca_sinistra;
    tasca_destra = tasca_destra - tasca_sinistra;

    printf("Contenuto tasca sinistra: %c - Contenuto tasca destra: %c\n",tasca_sinistra,tasca_destra);
}
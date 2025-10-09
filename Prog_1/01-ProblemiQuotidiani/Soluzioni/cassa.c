#include <stdio.h>

int main(){
    int n;
    printf("Inserire il numero da convertire: ");
    scanf(" %d",&n);

    int n_carattere = 0;
    for(int i=n; i>0; i/=2){
        printf("Carattere %d: %d\n",n_carattere,i%2);
        n_carattere += 1;
    }
}
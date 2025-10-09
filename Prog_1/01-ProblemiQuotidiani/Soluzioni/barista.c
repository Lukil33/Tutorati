#include <stdio.h>

int main(){
    int n,m;
    printf("Inserire il numero di birre (n): ");
    scanf(" %d",&n);
    printf("Inserire il costo delle birre (m): ");
    scanf(" %d",&m);

    for(int i=1; i<=n; i++){
        printf("Il costo di %d Birre è di: %d\n",i,m*i);
    }
}
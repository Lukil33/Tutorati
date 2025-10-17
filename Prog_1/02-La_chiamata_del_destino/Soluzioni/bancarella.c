#include <stdio.h>
#define N 5

int Bancarella[N][N] = {{5,2,3,4,2},{5,6,7,8,0},{7,2,3,6,8},{8,2,5,4,2},{6,2,6,2,4}};
int Supporto[N][N] = {{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};

int main(void){
    printf("Bancarella:\n");
    for(int x=0; x<N; x++){
        for(int y=0; y<N; y++){
            printf("%d ",Bancarella[x][y]);
        }
        printf("\n");
    }
    printf("\n");

    for(int x=0; x<N; x++){
        for(int y=0; y<N; y++){
            Supporto[x][y] = Bancarella[x][y] + Bancarella[y][x];
        }
    }

    int min_val = Supporto[0][0];
    int x_min = 0, y_min = 0;
    for(int x=0; x<N; x++){
        for(int y=0; y<N; y++){
            if(Supporto[x][y] < min_val){
                min_val = Supporto[x][y];
                x_min = x;
                y_min = y;
            }
        }
    }

    printf("Il costo minimo all'interno della bancarella è di: %d\n", min_val);
    printf("La posizione del costo minimo è X: %d - Y: %d\n", x_min, y_min);

    return 0;
}
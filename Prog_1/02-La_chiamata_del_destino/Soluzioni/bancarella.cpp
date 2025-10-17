#include <iostream>
using namespace std;
#define N 5

int Bancarella[N][N] = {{5,2,3,4,2},{5,6,7,8,0},{7,2,3,6,8},{8,2,5,4,2},{6,2,6,2,4}};
int Supporto[N][N] = {{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};

int main(){
    cout<<"Bancarella:"<<endl;
    for(int x=0; x<N; x++){
        for(int y=0; y<N; y++){
            cout<<Bancarella[x][y]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    for(int x=0; x<N; x++){
        for(int y=0; y<N; y++){
            Supporto[x][y] = Bancarella[x][y] + Bancarella[y][x];
        }
    }

    int min = Supporto[0][0];
    int x_min = 0, y_min = 0;
    for(int x=0; x<N; x++){
        for(int y=0; y<N; y++){
            if(Supporto[x][y] < min){
                min = Supporto[x][y];
                x_min = x;
                y_min = y;
            }
        }
    }

    cout<<"Il costo minimo all'interno della bancarella è di: "<<min<<endl;
    cout<<"La posizione del costo minimo è X: "<<x_min<<" - Y: "<<y_min<<endl;

    return 0;
}
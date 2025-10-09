#include <iostream>
using namespace std;

int main(){
    int n,m;
    cout<<"Inserire il numero di birre (n): ";
    cin>>n;
    cout<<"Inserire il costo delle birre (m): ";
    cin>>m;

    for(int i=1; i<=n; i++){
        cout<<"Il costo di "<<i<<" Birre è di: "<<i*m<<endl;
    }
}
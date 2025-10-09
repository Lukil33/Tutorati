#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Inserire il numero da convertire: ";
    cin>>n;

    int n_carattere = 0;
    for(int i=n; i>0; i/=2){
        cout<<"Carattere "<<n_carattere<<": "<<i%2<<endl;
        n_carattere += 1;
    }
}
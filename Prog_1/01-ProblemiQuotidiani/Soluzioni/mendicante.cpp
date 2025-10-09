#include <iostream>
using namespace std;

int main(){
    char tasca_sinistra,tasca_destra;
    cout<<"Inserire il contenuto della tasca sinistra: ";
    cin>>tasca_sinistra;
    cout<<"Inserire il contenuto della tasca destra: ";
    cin>>tasca_destra;

    cout<<"Contenuto tasca sinistra: "<<tasca_sinistra<<" - Contenuto tasca destra: "<<tasca_destra<<endl;

    tasca_destra = tasca_destra + tasca_sinistra;
    tasca_sinistra = tasca_destra - tasca_sinistra;
    tasca_destra = tasca_destra - tasca_sinistra;

    cout<<"Contenuto tasca sinistra: "<<tasca_sinistra<<" - Contenuto tasca destra: "<<tasca_destra<<endl;
}
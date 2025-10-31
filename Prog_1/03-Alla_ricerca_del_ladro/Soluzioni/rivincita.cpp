#include <iostream>
using namespace std;
#define N 100

/*
int primo_array[] = {1,2,3,4,5,6,7,8,'\0'};
int secondo_array[] = {1,2,3,4,5,6,7,8,'\0'};
*/
/*
int primo_array[] = {1,4,5,6,12,23,35,'\0'};
int secondo_array[] = {2,3,5,7,8,'\0'};
*/
/*
int primo_array[] = {1,4,5,6,12,23,35,'\0'};
int secondo_array[] = {1,2,4,5,35,6,73,8,'\0'};
*/

void iterazione(int* p_array, int* s_array, int* res){
    int p = 0,s = 0,r = 0;
    while(p_array[p] != '\0' || s_array[s] != '\0'){
        if(p_array[p] == '\0'){
            res[r] = s_array[s];
            r+=1;
            s+=1;
        }else if(s_array[s] == '\0'){
            res[r] = p_array[p];
            r+=1;
            p+=1;
        }else{
            if(p_array[p] > s_array[s]){
                res[r] = s_array[s];
                r+=1;
                s+=1;
            }else{
                res[r] = p_array[p];
                r+=1;
                p+=1;
            }
        }
    }
    res[r] = '\0';
}

void ricorsione(int* p_array, int p, int* s_array, int s, int* res, int r){
    if(p_array[p] == '\0' && s_array[s] == '\0'){ // Se siamo arrivati alla fine di entrambi gli array inseriamo il terminatore di stringa al risultato
        res[r] = '\0';
    }else if(p_array[p] == '\0'){ // Se siamo arrivati alla fine del primo array allora inserisco i restanti numeri del secondo array
        res[r] = s_array[s];
        ricorsione(p_array, p, s_array, s+1, res, r+1);
    }else if(s_array[s] == '\0'){ // Se siamo arrivati alla fine del secondo array allora inserisco i restanti numeri del primo array
        res[r] = p_array[p];
        ricorsione(p_array, p+1, s_array, s, res, r+1);
    }else{ // Se entrmabi gli array hanno ancora dei numeri all'interno
        if(p_array[p] > s_array[s]){
            res[r] = s_array[s];
            ricorsione(p_array, p, s_array, s+1, res, r+1);
        }else{
            res[r] = p_array[p];
            ricorsione(p_array, p+1, s_array, s, res, r+1);
        }
    }
}

void print_array(int* a){
    cout<<"Array -> [";
    for(int i=0; i<N && a[i]!='\0';i++){
        cout<<a[i]<<", ";
    }
    cout<<"]"<<endl;
}

int main(){
    int terzo_array[N];
    iterazione(primo_array, secondo_array, terzo_array);
    print_array(terzo_array);
    terzo_array[0] = '\0';
    print_array(terzo_array);
    ricorsione(primo_array, 0, secondo_array, 0, terzo_array, 0);
    print_array(terzo_array);

    return 0;
}
#include <iostream>
using namespace std;
#define N 100

/*
char s1[] = {'A','B','C','D','D',' ','F','G','H','I','3','\0'};
char s2[] = {15, 31, 41, 40, 1, 32, 45, 47, 28, 24,'\0'};
*/

char s1[] = {17,1,21,1,16,1,1,13,3,12,50,32,'\0'};
char s2[] = {'A',47,'a','d','b','0',31,'@','0','f','2','A','\0'};
/**/

void iterazione(char* p_array, char* s_array, char* res){
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
            res[r] = p_array[p] + s_array[s];
            r+=1;
            s+=1;
            p+=1;
        }
    }
    res[r] = '\0';
}

void ricorsione(char* p_array, int p, char* s_array, int s, char* res, int r){ // Non era necessario fare la soluzione utilizzando la ricorsione, però per chi ne avesse voglia ho creato una soluzione anche per quella
    if(p_array[p] == '\0' && s_array[s] == '\0'){ // Se siamo arrivati alla fine di entrambi gli array inseriamo il terminatore di stringa al risultato
        res[r] = '\0';
    }else if(p_array[p] == '\0'){ // Se siamo arrivati alla fine del primo array allora inserisco i restanti numeri del secondo array
        res[r] = s_array[s];
        ricorsione(p_array, p, s_array, s+1, res, r+1);
    }else if(s_array[s] == '\0'){ // Se siamo arrivati alla fine del secondo array allora inserisco i restanti numeri del primo array
        res[r] = p_array[p];
        ricorsione(p_array, p+1, s_array, s, res, r+1);
    }else{ // Se entrambi gli array hanno ancora dei numeri all'interno
        res[r] = p_array[p] + s_array[s];
        ricorsione(p_array, p+1, s_array, s+1, res, r+1);
    }
}

void print_array(char* a){
    cout<<"Array -> ";
    for(int i=0; i<N && a[i]!='\0';i++){
        cout<<a[i]<<"";
    }
    cout<<endl;
}

int main(){
    char res[N];
    iterazione(s1, s2, res);
    print_array(res);
    res[0] = '\0';
    print_array(res);
    ricorsione(s1, 0, s2, 0, res, 0);
    print_array(res);
    return 0;
}
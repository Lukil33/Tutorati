#include <iostream>
#include <fstream>
using namespace std;

bool check(char* word){
    for(int i=0; word[i]!='\0'; i++){
        if(word[i]<'A' || word[i]>'Z'){
            return false;
        }
    }
    return true;
}

void reverse(char* word){
    int len = 0;
    while(word[len]!='\0'){
        len++;
    }
    for(int i=0; i<len/2; i++){
        char temp = word[i];
        word[i] = word[len-i-1];
        word[len-i-1] = temp;
    }
}

int main(int argc, char* argv[]){
    if(argc != 3){
        cerr<<"Error: ./a.out <input_fle> <output_file>"<<endl;
        return -1;
    }

    fstream input, output;
    input.open(argv[1], ios::in);
    if(input.fail()){
        cerr<<"Error during file opening"<<endl;
        return -2;
    }
    output.open(argv[2], ios::out);
    if(output.fail()){
        cerr<<"Error during file opening"<<endl;
        input.close();
        return -2;
    }

    char word[100];
    while(input>>word){
        if(check(word)){
            reverse(word);
        }
        output<<word<<" ";
    }

    input.close();
    output.close();
    return 0;
}
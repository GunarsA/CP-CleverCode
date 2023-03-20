#include<iostream>
using namespace std;

int power(int x,int Pow){
    if(!Pow){
        return 1;
    }
    int Res=1; 
    while(Pow>0){ 
        if(Pow&1){
            Res=Res*x; 
        }
        Pow=Pow>>1;
        x=x*x;
    } 
    return Res; 
} 
int main(){
    string Word;
    bool Correct=true;
    unsigned long long int Code=0;
    cin>>Word;
    for(int i=0;i<Word.length();i++){
        if(i<Word.length()-1&&Word[i]>=Word[i+1]){Correct=false;break;}
        Code+=power(26,Word.length()-1-i)*(Word[i]-96);
        cout<<Code<<endl;
    }
    Code-=()
    if(!Correct){
        cout<<"0";
    }
    else{
        cout<<Code;
    }

    return 0;
}
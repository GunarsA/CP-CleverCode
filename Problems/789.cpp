#include<iostream>
#include<string>
using namespace std;

int main(){
    int lenX;
    cin>>lenX;
    string x;
    cin>>x;
    for(int i=0;i<lenX;){
        if(x[i]=='7'){
            if((i>0)&&(x[i-1]=='6')){x.erase(i-1,1);i--;}
            else if(x[i+1]=='6'){x.erase(i+1,1);}
            else if((i<lenX-2)&&(x[i+1]=='8')&&(x[i+2]=='9')){x.erase(i+1,2);}
            else{i++;}
        }
        else{i++;}
    }
    cout<<x<<endl;
    return 0;
}
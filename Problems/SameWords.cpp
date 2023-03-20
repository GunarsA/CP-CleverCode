#include<iostream>
using namespace std;

//Code will count 3 or more duplicates as seperate occasions
//Code wont work with multiple spaces between words
int main(){
    string Text;
    int SameWordsCount=0;
    getline(cin,Text);
    Text=" "+Text+" ";
    for(int WS=0,WE=1;WE<Text.length()-1;WS=WE,WE++){
        while(Text[WE]!=' '){
            WE++;
        }
        if(Text.substr(WE).find(Text.substr(WS,WE-WS+1))!=string::npos){
            cout<<SameWordsCount+1<<". duplicated word is "<<Text.substr(WS+1,WE-WS-1)<<endl;
            SameWordsCount++;
        }
    }
    if(SameWordsCount==0){
        cout<<"There are no duplicates"<<endl;
    }
    return 0;
}
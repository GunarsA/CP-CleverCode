#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct area{
    int L;
    int R;
};
vector<string> Words;
area findArea(char x,int digPos,area Loc){
    int searchP=(Loc.L+Loc.R)/2,left=Loc.L,right=Loc.R;
    while(left<=searchP&&right>=searchP){
        if(Words.at(searchP)[digPos]==x){
            left=searchP;
            right=searchP;
            while(left-1>=Loc.L&&Words[left-1][digPos]==x){
                left--;
            }
            while(right+1<=Loc.R&&Words[right+1][digPos]==x){
                right++;
            }
            return{left,right};
        }
        else if(Words.at(searchP)[digPos]>x){
            right=searchP-1;
        }
        else{
            left=searchP+1;
        }
        searchP=(right+left)/2;
    }
    return{-1,-1};
}
bool matchingEnds(string str,string end){
    for(int i=1;i<=end.length();i++){
        if(str[str.length()-i]!=end[end.length()-i]){
            return false;
        }
    }
    return true;
}
int findRepeating(string F, string E){
    area searchArea={0,Words.size()-1};
    int res=0;
    for(int i=0;i<F.size();i++){
        searchArea=findArea(F[i],i,searchArea);
        if(searchArea.L==-1){
            return 0;
        }
    }
    for(int i=searchArea.L;i<=searchArea.R;i++){
        if(matchingEnds(Words[i],E)){
            res++;
        }
    }
    return res;
}
int main(){
    int wC,//word count
    qC;//question count
    scanf("%d",&wC);
    for(int i=0;i<wC;i++){
        string Word;
        cin>>Word;
        Words.push_back(Word);
    }
    sort(Words.begin(),Words.end());
    scanf("%d",&qC);
    for(int i=0;i<qC;i++){
        string frontQ,endQ;
        cin>>frontQ>>endQ;
        printf("%d\n",findRepeating(frontQ,endQ));
    }
    return 0;
}
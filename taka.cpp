#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int lenY=0,lenX=0,Direction=1;
    while(1){
        char T;
        cin>>T;
        if(T=='S'){
            int L;
            cin>>L;
            switch(Direction){
                case 1:lenY+=L;break;
                case 2:lenX-=L;break;
                case 3:lenY-=L;break;
                case 4:lenX+=L;break;
            }
        }
        else if(T=='K'){
            Direction++;
            if(Direction>4){
                Direction=1;
            }
        }
        else if(T=='L'){
            Direction--;
            if(Direction<1){
                Direction=4;
            }
        }   
        else if(T=='V'){
            break;
        }
    }
    lenY=(int)abs(lenY);
    lenX=(int)abs(lenX);
    cout<<lenY+lenX;
    return 0;
}
#include<iostream>
using namespace std;

int main(){
    char Code[7];
    cin>>Code;
    int Coefficient=0;
    Coefficient+=(Code[0]-48)*2;
    Coefficient+=(Code[1]-48)*7;
    Coefficient+=(Code[2]-48)*6;
    Coefficient+=(Code[3]-48)*5;
    Coefficient+=(Code[4]-48)*4;
    Coefficient+=(Code[5]-48)*3;
    Coefficient+=(Code[6]-48)*2;
    switch(Coefficient%11){
        case 0:cout<<"J"<<endl;break;
        case 1:cout<<"A"<<endl;break;
        case 2:cout<<"B"<<endl;break;
        case 3:cout<<"C"<<endl;break;
        case 4:cout<<"D"<<endl;break;
        case 5:cout<<"E"<<endl;break;
        case 6:cout<<"F"<<endl;break;
        case 7:cout<<"G"<<endl;break;
        case 8:cout<<"H"<<endl;break;
        case 9:cout<<"I"<<endl;break;
        case 10:cout<<"Z"<<endl;break;
    }
    return 0;
}


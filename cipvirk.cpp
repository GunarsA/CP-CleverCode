#include<iostream>
using namespace std;

unsigned int num[2]={},x=0,f,a;

int main(){
    cin >> num[0] >> num[1] >> a;

    if(a<3){cout << num[a-1] << endl;}
    else{
        for(unsigned int y=2; y<a; x++,y++){
            if(x==2){x=0;}
            f = num[0]+num[1];
            num[x] = f % 10;
        }
        cout << num[x-1] << endl;
    }
    return 0;
}
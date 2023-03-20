#include<iostream>
using namespace std;

unsigned int num[4]={},x=0,f,a,cip[4],g,d;
bool p = false, o = false;
int main(){
    cin >> num[0] >> num[1] >> num[2] >> num[3] >> a;

    cip[0] = num[0];
    cip[1] = num[1];
    cip[2] = num[2];
    cip[3] = num[3];

    if(a<5){cout << num[a-1] << endl;}
    else{
        for(unsigned int y=4; y<a; x++, y++, g++){
            if(x==4){x=0;}
            f = num[0]+num[1]+num[2]+num[3];
            num[x] = f % 10;

            if(a>20000000){
                if((num[0]==cip[0]&&num[1]==cip[1]&&num[2]==cip[2]&&num[3]==cip[3])&&p==false){
                    g=0;d=x;p = true;
                }
                else if ((num[0]==cip[0]&&num[1]==cip[1]&&num[2]==cip[2]&&num[3]==cip[3])&&x==d&&o==false){
                    a%=g;y=3;o=true;
                }
            }
        }
        cout << num[x-1] << endl;
    }
    return 0;
}
#include <iostream>
#include <string>

using namespace std;

string protokols;
int var[8]={},y;
unsigned int atk[9]={0};
bool atbilde=false;

int main()
{
    cin >> protokols;
    if(9>=protokols.length()){
        for(unsigned int x=0; x<protokols.length(); x++){
            if(x%2==0){y = 1;} 
            else{y = -1;}

            switch(protokols[x]){
            case '1': var[0]+=y;var[1]+=y;var[2]+=y;atk[0]++;break;
            case '2': var[0]+=y;var[3]+=y;atk[1]++;break;
            case '3': var[0]+=y;var[4]+=y;var[7]+=y;atk[2]++;break;
            case '4': var[1]+=y;var[5]+=y;atk[3]++;break;
            case '5': var[2]+=y;var[3]+=y;var[5]+=y;var[7]+=y;atk[4]++;break;
            case '6': var[4]+=y;var[5]+=y;atk[5]++;break;
            case '7': var[1]+=y;var[6]+=y;var[7]+=y;atk[6]++;break;
            case '8': var[3]+=y;var[6]+=y;atk[7]++;break;
            case '9': var[2]+=y;var[4]+=y;var[6]+=y;atk[8]++;break;
            default: if(atbilde==false){cout << "NEKOREKTS" << endl;atbilde=true;break;}}

            if(atbilde==true){break;}

            if((atk[0]==2||atk[1]==2||atk[2]==2||atk[3]==2||atk[4]==2||atk[5]==2||atk[6]==2||atk[7]==2||atk[8]==2)&&atbilde==false)
                {cout << "NEKOREKTS" << endl;atbilde=true;break;}
            else if((var[0]==3||var[1]==3||var[2]==3||var[3]==3||var[4]==3||var[5]==3||var[6]==3||var[7]==3)&&atbilde==false){
                if(x!=protokols.length()-1){cout << "NEKOREKTS" << endl;atbilde=true;break;}
                else{ cout << "PIRMAIS" << endl;atbilde=true;break;}}
            else if((var[0]==-3||var[1]==-3||var[2]==-3||var[3]==-3||var[4]==-3||var[5]==-3||var[6]==-3||var[7]==-3)&&atbilde==false){
                if(x!=protokols.length()-1){cout << "NEKOREKTS" << endl;atbilde=true;break;}
                else{ cout << "OTRAIS" << endl;atbilde=true;break;}
            }
        }
        if(9==protokols.length()&&atbilde==false){cout << "NEVIENS" << endl;}
        else if(atbilde==false){cout << "NEKOREKTS" << endl;}
    }
    else{cout << "NEKOREKTS" << endl;}
    return 0;
}


#include<iostream>
using namespace std;

int rindas,kolonas,atrViet,uzSanu,uzLeju;

int main(){

    cin >> rindas >> kolonas >> atrViet;
    if(atrViet!=0){

        unsigned int laukums[rindas+2][kolonas+3]={};

        for(int rnd1=1,rnd2=1,rnd9; rnd1<=rindas; rnd1++){
            if(rnd1%2==0){rnd9=1;}else{rnd9=0;}
            for(int rnd3=1; rnd3<=kolonas+rnd9; rnd3++,rnd2++){
                laukums[rnd1][rnd3]=rnd2;
            }
        }

        for(int rnd4=0,rnd5;atrViet!=0; rnd4++){
            if (rnd4%2==0){rnd5=0;}else{rnd5=1;}
            for(int rnd6=0;rnd6<(kolonas+rnd5); rnd6++,atrViet--){
                if(atrViet<1){break;}
                uzSanu=rnd6;
            }
            uzLeju=rnd4;
        }
        uzSanu++;
        uzLeju++;

        for(int rnd8=-1;rnd8<2;rnd8++){
            for(int rnd7=-1;rnd7<2;rnd7++){
                if (((laukums[uzLeju+rnd8][uzSanu+rnd7])!=0)&&(rnd8!=0||rnd7!=0)){
                    if(((rnd8!=-1&&rnd8!=1)||rnd7!=1)&&(uzLeju%2!=1)){
                        cout << laukums[uzLeju+rnd8][uzSanu+rnd7] << " ";
                    }
                    else if (((rnd8!=-1&&rnd8!=1)||rnd7!=-1)&&(uzLeju%2!=0))
                    {
                        cout << laukums[uzLeju+rnd8][uzSanu+rnd7] << " ";
                    }
                }
            }
        }
    }
    else{cout << "ERROR";}   
    return 0;
}
#include<iostream>
using namespace std;

int uzSanu,uzLeju,krdY,krdX,iespVar=0,ieprieksVar[200][2];
bool tukss=true,virziens,pieSk,tikaiAugs=false;

bool VaiVar(int &x,int &y,bool &pieSk,int trase[12][12]){
    unsigned int pieSKX=0,pieSKY=0;
    bool brivs=false;
    if(pieSk==true){pieSKX=-1;}
    else{pieSKY=-1;}
    switch(trase[y+pieSKY][x+pieSKX]){
        case 6 : brivs=true;tukss=true;break;
        case 1 : if(pieSk==true){brivs=true;break;}
        else if(pieSk==false){brivs=false;break;}
        case 2 : if(pieSk==true){brivs=false;break;}
        else if(pieSk==false){brivs=true;break;}
        case 3 : if(pieSk==true){brivs=true;break;}
        else if(pieSk==false){brivs=false;break;}
        case 4 : if(pieSk==true){brivs=false;break;}
        else if(pieSk==false){brivs=true;break;}
        case 5 : brivs=false;break;
        case 0 : brivs=false;break;
    }
    return brivs;
}
int iespVirz(int &x,int &y,int trase[12][12]){
    int virziens;
    switch(trase[y][x]){
        case 6 : virziens = 0;break;
        case 1 : virziens = 2;break;
        case 2 : virziens = 1;break;
        case 3 : virziens = 1;break;
        case 4 : virziens = 2;break;
        default : virziens = 3;break;
    }
    return virziens;
}

int main(){
    cin >> uzSanu >> uzLeju;
    int trase[12][12]={};
    for(int rnd11 =1;rnd11<=uzLeju;rnd11++){
        for(int rnd12=1; rnd12<=uzSanu; rnd12++){
            cin >> trase[rnd11][rnd12];
            if(trase[rnd11][rnd12]==0){trase[rnd11][rnd12]=6;}
        }
    }
    krdY=uzLeju;
    krdX=uzSanu;


    if(krdY==1&&krdX==1){
        if((trase[krdY][krdX]!=6)&&(trase[krdY][krdX]!=1)){
            cout<<'0';
        }
        else{cout<<'1';}
    }
    else if((iespVirz(krdX,krdY,trase)==3)&&(trase[krdY][krdX]!=6)&&((trase[krdY][krdX]!=1))){cout<<'0';}
    else{
        for(int koif=1;;){
            pieSk=true;          
            if(((VaiVar(krdX,krdY,pieSk,trase)==true)&&(iespVirz(krdX,krdY,trase)!=2))&&(tikaiAugs==false)){
                pieSk=false;
                if((VaiVar(krdX,krdY,pieSk,trase)==true)&&(iespVirz(krdX,krdY,trase)!=1)){
                    ieprieksVar[koif][0]=krdX;
                    ieprieksVar[koif][1]=krdY;
                    koif++;
                }
                krdX--;
            }
            else{
                tikaiAugs=false;
                pieSk=false;
                if((VaiVar(krdX,krdY,pieSk,trase)==true)&&(iespVirz(krdX,krdY,trase)==0||2)){krdY--;}
                else{
                    if(koif!=0){
                        koif--;
                        krdX=ieprieksVar[koif][0];
                        krdY=ieprieksVar[koif][1];
                        tikaiAugs=true;
                    }
                    else{cout<<iespVar;break;}
                }
            }
            if(krdX==1&&krdY==1){
                if(iespVirz(krdX,krdY,trase)!=1){iespVar++;}                   
                if(koif!=0){
                    koif--;
                    krdX=ieprieksVar[koif][0];
                    krdY=ieprieksVar[koif][1];
                    tikaiAugs=true;    
                }
                else{cout<<iespVar;break;}
            }
        }
    }
    return 0;
}

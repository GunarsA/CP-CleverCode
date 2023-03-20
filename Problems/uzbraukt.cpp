#include<iostream>
using namespace std;

int main(){

    int count,up=0,down=0,cons=0;
    cin >> count;
    int kord[count+2];

    for(int x=0;x<count;x++){
        cin >> kord[x];
    }
    for(int x=0;x<3;x++){  
        kord[count+x]=kord[x];
    }

    for(int x=0;x<count+1;){
            
        if(kord[x]<kord[x+1]){
            x++;
            if(x!=count+1){
            while(kord[x]<kord[x+1]){
                if(x==count+1){break;}                
                x++;
            }
            if(((x==(count+1))&&(kord[count+1]>kord[count]))&&up!=0){break;}
            up++;
            if(x==count+1){break;}
            }
            else{break;}
        }

        if(kord[x]>kord[x+1]){
            x++;
            if(x!=count+1){
            while(kord[x]>kord[x+1]){
                if(x==count+1){break;}
                x++;
                }
            if(((x==(count+1))&&(kord[count+1]<kord[count]))&&down!=0){break;}
            down++;
            if(x==count+1){break;}
            }
            else{break;}                     
        }

        if(kord[x]==kord[x+1]){
            x++;
            if(x!=count+1){
            while(kord[x]==kord[x+1]){
                if(x==count+1){break;}
                x++;
            }
            if(((x==(count+1))&&(kord[count+1]==kord[count]))&&cons!=0){break;}
            cons++;
            if(x==count+1){break;}
            }
            else{break;}                 
        }                      
    }
    cout<<up<<" "<<down<<" "<<cons;
    return 0;
}
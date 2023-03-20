#include<stdio.h>
using namespace std;

bool prime(int &x){
    bool prime = true;
    for(int y = 2;y*y<=x;y++){
        if(x%y==0){prime=false;break;}
    }
    if(x==1){prime=false;}   
    return prime;
}

int main(){
    int bil,cena,max;
    double rez=0;
    
    scanf("%d%d%d",&bil,&cena,&max);
    int *var = new int[max]();
      
    for(int x=0,a,b;x<bil;x++){
        scanf("%d%d",&a,&b);
        for(int y=(a-1);y<b;y++){
            var[y]++;
        }
        rez+=((b-a)+1)*cena;
    }
    
    for(int x=2;x<max;x++){
        if(prime(x)){
            for(int z,y=x;y>0;){
                z=y%10;
                y/=10;
                rez-=z*var[x-1];               
            }           
        }
    }
    delete[] var;
    printf("%.0f",rez);
    return 0;
}
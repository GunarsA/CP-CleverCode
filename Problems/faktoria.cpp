#include <iostream>
#include <stdio.h>
using namespace std;

unsigned int trailZeros(unsigned int n) { 
    unsigned int count = 0; 
    for (unsigned int i=5;n/i>=1;i*=5){ 
        count+=n/i; 
    }
    return count; 
} 
int main(){
unsigned int x; 
unsigned long long int res=1;
scanf ("%u", &x);
for (unsigned int i=2; i<=x;i++){
    res*=i;
    //if(i<17){cout<<i<<"   test   "<<res<<endl;}
    for(;;){
      if(res%10==0){
            res/=10;
        }
        else{break;}
    }
    if(res>   9999999999999999){
        res-=10000000000000000;
        
    }
    if(res>   999999999999999){
        res-=1000000000000000;
        //cout<<"test"<<endl;
    }
    if(res>   99999999999999){
        res-=100000000000000;
    }
    if(res>   9999999999999){
        res-=10000000000000;
    }
    if(res>   999999999999){
        res-=1000000000000;
    }
    if(res>   99999999999){
        res-=100000000000;
    }
    if(res>   9999999999){
        res-=10000000000*(res/100000000000);
    }
    if(res>   999999999){
        res-=1000000000*(res/10000000000);
    }
    if(res>   99999999){
        res-=100000000*(res/100000000);
    }
    if(res>   9999999){
        res-=10000000*(res/10000000);
    }
    if(res>   999999){
        res-=1000000*(res/1000000);
    }
    //if(i<17){cout<<i<<"   test   "<<res<<endl;}
    
}

unsigned int res1,res2;
res2=res%10;
res1=(res%100-res1)/10;
if(res>9){
    printf ("%u%u %u",res1,res2,trailZeros(x));
}
else{
    printf ("%u %u",res,trailZeros(x));
}
return 0;
}
#include <stdio.h>
using namespace std;

bool isPrime(int &x){
  for(long int y=2;y*y<=x;y++){
    if(x%y==0){
        return false;
      }
  }
  return true;
}

int digitSum(int x){
  int rez=0;
  while(x>0){
    rez+=x%10;
    x/=10;
  }
  return rez;
}
//Sieve of Eratosthenes
void fillPrimeDigitSum(int pDS[],int l){
  for(int x=2;x<=l;x++){
    pDS[x]=-1;
  }
  for(int x=2;x*x<=l;x++){
    if(pDS[x]==-1){
      if(isPrime(x)){
        pDS[x]=digitSum(x);
        for(int y=x*x;y<=l;y+=x){
          pDS[y]=0;
        }
      }
    }
  }
  for(int x=2;x<=l;x++){
    if(pDS[x]==-1){
      pDS[x]=digitSum(x);
    }
    pDS[x]+=pDS[x-1];
  }
}

int main(){
  int tick,price,len;
  long long int rez=0;
  scanf("%d%d%d",&tick,&price,&len);

  int *primeDigitSum=new int[len+1]();
  fillPrimeDigitSum(primeDigitSum, len);
  
  for(int x=0,a,b;x<tick;x++){
    scanf("%d%d",&a,&b);
    rez+=(b-a+1)*price;
    rez-=primeDigitSum[b]-primeDigitSum[a-1];
  }
  printf("%lld",rez);
}

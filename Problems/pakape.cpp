#include<stdio.h> 
using namespace std; 

int LastDigitsOfPower(long long int Num,long long int Pow,long long int DC){ 
    long long int Res=1,Mod=1;
    for(int i=0;i<DC;i++){
		Mod*=10; 
    }
	Num=Num%Mod;
	while(Pow>0){ 
		if(Pow%2){
			Res=(Res*Num)%Mod; 
        }
		Pow/=2;
		Num=(Num*Num)%Mod; 
	} 
	return Res; 
} 
int DigitCount(int x){ 
	int Res=0; 
	while(x){ 
		x/=10; 
		Res++; 
	} 
	return Res; 
} 
void printLastDigits(int Number,int Power,int DigitC) { 
	int Res=LastDigitsOfPower(Number,Power,DigitC); 
	for(int i=0;i<DigitC-DigitCount(Res);i++){
		printf("0");
    }
	if(Res){
		printf("%d",Res);
    }
} 
int main(){
    int Number,Power,DigitCount;
    scanf("%d%d%d",&Number,&Power,&DigitCount);
	printLastDigits(Number,Power,DigitCount); 
	return 0; 
} 

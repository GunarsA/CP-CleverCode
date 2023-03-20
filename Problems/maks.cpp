#include<iostream>
#include<stack>
using namespace std;

//Sum From One to X
long long int SFOX(long long int x){
    return x*(x+1)/2;
}
//get Next or Previos Biggest element
void NPB(int arr[],int &len,int res[],bool Direction){
	stack<int>S;
    int i=Direction?0:len-1;
	while(i<len&&i>=0){
		if(S.empty()||arr[S.top()]>arr[i]-Direction){ 
			S.push(i);
            Direction?i++:i--;
        }
		else{
			res[S.top()]=(i-S.top());	
			S.pop();
		}	
	}
}
int main(){
    ios_base::sync_with_stdio(false);//I/O Boost
    cin.tie(NULL);//I/O Boost
    int SIZE;
    cin>>SIZE;
    int LL[SIZE],//Lowest Level
        ONC=0;//Odd Number Count
    for(int i=0;i<SIZE;i++){
        cin>>LL[i];
        if(LL[i]%2){ONC++;}
    }
    //------- Chose fastest solution -------
    bool Pick,//Search odd or even
    Solution=true;
    if(ONC>SIZE-ONC){
        Pick=false;//Check even
        if(SFOX(SIZE)-SFOX(ONC)<SIZE*5){
            Solution=false;
        }
    }
    else if(ONC<SIZE-ONC){
        Pick=true;//Check odd
        if(SFOX(SIZE)-SFOX(SIZE-ONC)<SIZE*5){
            Solution=false;
        }
    }
    //-------------- Solve -----------------
    if(Solution){//Check all
        int Two=2,
        Area[Two][SIZE]={};
        long long int Odd=0,Even=0;
        //--------------------------
        NPB(LL,SIZE,Area[0],true);
        NPB(LL,SIZE,Area[1],false);
        //--------------------------
        for(long long int i=0,Left,Right;i<SIZE;i++){
            Area[0][i]?
            Right=Area[0][i]:
            Right=SIZE-i;
            //----------------
            Area[1][i]?
            Left=Area[1][i]*(-1):
            Left=(i+1);
            //----------------
            LL[i]%2?
            Odd+=(Left*Right):
            Even+=(Left*Right);
        }
        //--------------------------
        cout<<Odd<<" "<<Even;
    }
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    else{//Check smalest half
        long long int Odd=0,Even=0,
        Both=SFOX(SIZE);
        //--------------------------
        for(long long int i=0,L=1,R=1;i<SIZE;i++){
            if(LL[i]%2==Pick){
                while(LL[i]>=LL[i-L]&&(i-L)>=0){
                    L++;//Next biggest to left
                }
                while(LL[i]>LL[i+R]&&(i+R)<SIZE){
                    R++;//Next biggest to right
                }
                Odd+=(L*R);//Not Always Odd
                L=1;R=1;
            }
        }
        //--------------------------
        Even=Both-Odd;//Not Always Even
        if(!Pick){
            Both=Odd;
            Odd=Even;
            Even=Both;
        }
        //--------------------------
        cout<<Odd<<" "<<Even;
    }
    return 0;
}
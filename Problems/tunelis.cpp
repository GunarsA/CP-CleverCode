#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);//I/O Boost
    cin.tie(0);//I/O Boost
    cout.tie(0);//I/O Boost
    int CarCount,MinOvertake=0;
    cin>>CarCount;
    string CarsBefore[CarCount];
    for(int i=0;i<CarCount;i++){
        cin>>CarsBefore[i];
    }
    string CarsAfter[CarCount];
    for(int i=0;i<CarCount;i++){
        cin>>CarsAfter[i];
    }
    for(int i=1,j=0;i<CarCount;i++,j=0){
        bool Overtook=0;
        while(CarsBefore[i]!=CarsAfter[j]){
            j++;
        }
        for(int l=0;l<i&&!Overtook;l++){
            for(int r=j+1;r<CarCount&&!Overtook;r++){
                if(CarsBefore[l]==CarsAfter[r]){
                    MinOvertake++;
                    Overtook=1;
                }
            }
        }
    }
    cout<<MinOvertake;
    return 0;
}
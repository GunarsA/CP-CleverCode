#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    string x,y;
    unsigned int c;
    cin>>x>>c;
    sort(x.begin(),x.end());
    for(unsigned int i=0;i<c;i++){
        cin>>y;
        string z=y;
        sort(z.begin(),z.end());
        if(x.compare(z)==false){
            cout<<y<<endl;
        }
    }
    return 0;
}
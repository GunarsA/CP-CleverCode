#include<stdio.h>
#include<iostream>
using namespace std;

struct task{
    int A;//add
    int T;//take
};
//Create Task
task CT(int &add,int &take){
    task res;
    res.A=add;
    res.T=take;
    return res;
}
task getMinTasks(int &x,int &add,int &take){
    task res=CT(0,0);
    if(x%add==0){
        return CT(x/add,0);
    }
    else if(take%add==0){
        return CT(-1,-1);
    }
    //---------------------
    
    for(int currentAmount=0,){





        if(!(x-currentAmount)%add){

        }
    }







    //---------------------
    return res;
}




int main(){
    int x,add,take;
    scanf("%d%d%d",&x,&add,&take);
    task res=getMinTasks(x,add,take);
    if(res.A==-1){printf("NEVAR");}
    else{printf("%d %d",res.A,res.T);}
    return 0;
}
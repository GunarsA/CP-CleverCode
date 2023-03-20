#include<stdio.h>
#include<algorithm>
using namespace std; 

short int editDist(char strX[],char strY[],int &lenX,int &lenY){
    if(lenX<lenY){swap(strX,strY);swap(lenX,lenY);}
    short int** EditDist=new short int*[2];
    EditDist[0]=new short int[lenY+1];
    EditDist[1]=new short int[lenY+1];
    for(int i=0;i<=lenX;i++){ 
        for(int j=0;j<=lenY;j++){ 
            if(i==0){
                EditDist[i][j]=j;
            }
            else if(j==0){
                EditDist[i%2][j]=i; 
            }
            else if(strX[i-1]==strY[j-1]){
                EditDist[i%2][j]=EditDist[(i-1)%2][j-1]; 
            }
            else{
                EditDist[i%2][j]=1+min(EditDist[i%2][j-1],EditDist[(i-1)%2][j]);                 
            }
        } 
    } 
    return EditDist[lenX%2][lenY]; 
} 
int main() { 
    int xLen,yLen;
    scanf("%d%d",&xLen,&yLen);
    char strX[xLen+1];
    char strY[yLen+1];
    scanf("%s%s",&strX[0],&strY[0]);
    printf("%hu",editDist(strX,strY,xLen,yLen)); 
    return 0; 
} 
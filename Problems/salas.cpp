#include<stdio.h> 
#include<vector>
using namespace std;

void floydWarshall(vector<vector<short int> > &map,int &C){ 
    for(int k=0;k<C;k++){ 
        for(int i=0;i<C;i++){ 
            for(int j=0;j<C;j++){ 
                if(map[i][k]+map[k][j]<map[i][j]){
                    map[i][j]=map[i][k]+map[k][j]; 
                }
            } 
        } 
    }  
} 
void printSolution(vector<vector<short int> > &map,int &C){  
    for(int i=0;i<C;i++) { 
        for(int j=0;j<C;j++){ 
            printf("%hu ",map[i][j]); 
        } 
        printf("\n"); 
    } 
} 
int main(){ 
    int C,S;//cities,ships
    scanf("%d%d",&C,&S);
    vector<vector<short int> > map(C);
    for(int i=0;i<C;i++){
        map[i].resize(C,32767);
    }//set max distance
    for(int i=0;i<C;i++){
        map[i][i]=0;
    }//set start points
    for(short int i=0,x,y,z;i<S;i++){
        scanf("%hu%hu%hu",&x,&y,&z);
        map[x-1][y-1]=z;
        map[y-1][x-1]=z;
    }
    floydWarshall(map,C); 
    printSolution(map,C);
    return 0; 
} 
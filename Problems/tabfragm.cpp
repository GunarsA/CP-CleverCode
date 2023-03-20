#include<stdio.h> 
#include<vector>
#define INF 0x3f3f3f3f
using namespace std;

int KadanesAlgorithm(vector <int> &Vec, int &Len){ 
   int max_so_far = Vec[0]; 
   int curr_max = Vec[0]; 
   for(int i = 1; i < Len; ++i){ 
        curr_max = max(Vec[i], curr_max + Vec[i]); 
        max_so_far = max(max_so_far, curr_max); 
   } 
   return max_so_far; 
} 
int MaxRectangleSum(vector< vector<int> > &Matrix){
    int lenY = (int)Matrix.size();
    int lenX = (int)Matrix.front().size();
    int res = -INF;
    for(int top = 0; top < lenY; ++top){
        vector <int> CurrRowSum(lenX, 0);
        for(int bottom = top; bottom < lenY; ++bottom){
            for(int i = 0; i < lenX; ++i){
                CurrRowSum[i] += Matrix[bottom][i];
            }
            res = max(res, KadanesAlgorithm(CurrRowSum, lenX));
        } 
    }
    return res;
}  
int main(){
    int side_len;
    scanf("%d", &side_len);
    vector< vector<int> > Matrix(side_len, vector<int>(side_len));
    for(int i = 0; i < side_len; ++i){
        for(int j = 0; j < side_len; ++j){
            scanf("%d", &Matrix[i][j]);
        }
    }
    printf("%d", MaxRectangleSum(Matrix));
    return 0; 
}
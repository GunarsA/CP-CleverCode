#include<stdio.h>
#include<algorithm>
using namespace std;

int main(){
    int grocery_count;
    scanf("%d", &grocery_count);
    int* Groceries = new int[grocery_count];
    for(int i = 0; i < grocery_count; ++i){
        scanf("%d", &Groceries[i]);
    }

    int request_count;
    scanf("%d", &request_count);
    for(int i = 0, tmp; i < request_count; ++i){
        scanf("%d", &tmp);
        binary_search(Groceries, Groceries + grocery_count, tmp)?
        printf("JA\n"):
        printf("NE\n");
    }
    return 0;
}
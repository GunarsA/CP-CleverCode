#include<stdio.h>
#include<set>
#define LLI long long int
using namespace std;

LLI getArea(LLI l, LLI b, LLI r, LLI t){
    if(b >= t || l >= r){
        return 0;
    }
    return (t - b) * (r - l);
}
int main(){
    int operation_count;
    scanf("%d", &operation_count);
    multiset<int, greater<int> > Left, Bottom;
    multiset<int> Right, Top;
    while(operation_count-- > 0){
        char operation;
        int bottom, left, right, top;
        scanf(" %c %d %d %d %d",
        &operation, &left, &bottom, &right, &top);
        if(operation == '+'){
            Left.insert(left);
            Bottom.insert(bottom);
            Right.insert(right);
            Top.insert(top);
        }
        else{
            Left.erase(Left.find(left));
            Bottom.erase(Bottom.find(bottom));
            Right.erase(Right.find(right));
            Top.erase(Top.find(top));
        }
        printf("%lld \n", getArea(*Left.begin(), *Bottom.begin(), *Right.begin(), *Top.begin()));
    }
    return 0;
}
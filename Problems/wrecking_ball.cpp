#include<stdio.h>
#include<vector>
#include<queue>
#define F first
#define S second
using namespace std;

int main(){
    int len_y, len_x;
    scanf("%d %d",&len_y, &len_x);

    vector<vector<pair<char, bool> > > Matrix(len_y, vector<pair<char, bool> >(len_x));
    queue<queue<pair<int, int> > > Queue;

    for(int i = 0; i < len_y; ++i){
        for(int j = 0; j < len_x; ++j){
            scanf(" %c", &Matrix[i][j].F);
            if(Matrix[i][j].F == 'A')
            {
                Queue.push(queue<pair<int, int> >());
                Queue.back().push({i, j});
                Matrix[i][j].S = 1;
            }
        }
    }
    int res = -1;
    for(bool found = 0; !found; res++)
    {
        Queue.push(queue<pair<int, int> >());
        while(!Queue.front().empty())
        {
            pair<int, int> curr = Queue.front().front();
            if(curr.F + 1 < len_y && !Matrix[curr.F + 1][curr.S].S)
            {
                Matrix[curr.F + 1][curr.S].S = 1;
                if(Matrix[curr.F + 1][curr.S].F == '.'){
                    Queue.front().push({curr.F + 1, curr.S});
                }
                else if(Matrix[curr.F + 1][curr.S].F == '#'){
                    Queue.back().push({curr.F + 1, curr.S});
                }
                else{
                    found = 1;
                    break;
                }
            }
            if(curr.F - 1 >= 0 && !Matrix[curr.F - 1][curr.S].S)
            {
                Matrix[curr.F - 1][curr.S].S = 1;
                if(Matrix[curr.F - 1][curr.S].F == '.'){
                    Queue.front().push({curr.F - 1, curr.S});
                }
                else if(Matrix[curr.F - 1][curr.S].F == '#'){
                    Queue.back().push({curr.F - 1, curr.S});
                }
                else{
                    found = 1;
                    break;
                }
            }
            if(curr.S + 1 < len_x && !Matrix[curr.F][curr.S + 1].S)
            {
                Matrix[curr.F][curr.S + 1].S = 1;
                if(Matrix[curr.F][curr.S + 1].F == '.'){
                    Queue.front().push({curr.F, curr.S + 1});
                }
                else if(Matrix[curr.F][curr.S + 1].F == '#'){
                    Queue.back().push({curr.F, curr.S + 1});
                }
                else{
                    found = 1;
                    break;
                }
            }
            if(curr.S - 1 >= 0 && !Matrix[curr.F][curr.S - 1].S)
            {
                Matrix[curr.F][curr.S - 1].S = 1;
                if(Matrix[curr.F][curr.S - 1].F == '.'){
                    Queue.front().push({curr.F, curr.S - 1});
                }
                else if(Matrix[curr.F][curr.S - 1].F == '#'){
                    Queue.back().push({curr.F, curr.S - 1});
                }
                else{
                    found = 1;
                    break;
                }
            }
            Queue.front().pop();
        }
        Queue.pop();
    }
    printf("%d", res);
    return 0;
}
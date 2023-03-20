#include<stdio.h>
#include<vector>
#include<list>
#include<set>
#include<unordered_map>
#include<algorithm>
#include<iostream>
#define INF 0x3f3f3f3f
using namespace std;

struct Graph{
    private:
    //------------------ Variables -----------------
    int V;
    //Adjacency List
    list< pair<int, int> > *AL;
    //Shortest Path Adjacency List
    unordered_map<int, set<pair<int, int> > > SPAL;
    //----------------- Functions ------------------
    bool allPathsFound(vector<bool> Found, vector<int> Needed){
        for(auto i : Needed){
            if(!Found[i]){
                return false;
            }
        }
        return true;
    }
    void DijkstraAlgorithm(int src, vector<int> &N){ 
        //Distance To Unincluded Vertices
        set< pair<int, int> > Out;
        Out.insert(
            make_pair(0, src)
        ); 
        //Distance To Included Vertices
        vector<int> In(V,INF);
        In[src] = 0; 
        //Check Included Vertices
        vector<bool> Check(V,0);
        while(!Out.empty()){
            //Get Vertice With Smallest Distance
            int s = (*Out.begin()).second; 
            Out.erase(Out.begin()); 
            for(auto i : AL[s]){ 
                int v = i.first; 
                int weight = i.second; 
                if(In[v] > In[s] + weight) { 
                    if(In[v] != INF){
                        Out.erase(
                            Out.find(
                                make_pair(In[v], v)
                            )
                        ); 
                    }
                    In[v] = In[s] + weight; 
                    Out.insert(
                        make_pair(In[v], v)
                    ); 
                } 
            }
            //Add Shortest Path To Graph
            if((find(N.begin(), N.end(), s) != N.end())&&(s != src)){
                SPAL[src].insert(make_pair(In[s], s));
                SPAL[s].insert(make_pair(In[s], src));
                //cout<<"src- "<<src<<" end- "<<s<<" dis- "<<In[s]<<endl;
            }
            Check[s]=1;
            if(allPathsFound(Check,N)){
                break;
            }
            
        } 
    }
    pair<int, int> smallestUnincludedEdge(set<pair<int, int> > &S, unordered_map<int, bool> &M){
        for(auto i : S){
            if(!M[i.second]){
                //cout<<i.second<<endl;
                return i;
            }
        }
        return make_pair(-1,-1);
    }
    public:
    //---------------- Intializers -----------------
    Graph(int V){ 
        this->V = V;
        AL = new list< pair<int, int> >[V];
    }
    //----------------- Functions ------------------
    void addUndirectedEdge(int a, int b, int len){
        AL[a].push_back(make_pair(b, len)); 
        AL[b].push_back(make_pair(a, len)); 
    }
    void findShortestPaths(vector <int> N){
        for(int i = N.size() - 1;i > 0;i--){
            //cout<<"------------"<<endl;
            DijkstraAlgorithm(N[i], N);
            N.pop_back();
        }
    }
    
    //Shortest Path Visiting All Vertices
    int SPVAV(vector<int> &N){
        
        cout<<"-------- map --------"<<endl;
        for(auto i : SPAL){
            for(auto j : i.second){
                cout<<i.first<<" -> "<<j.second<<" | "<<j.first<<endl;
            }
        }
        
        cout<<"------- path --------"<<endl;
        int res = 0;
        //Current Vertice
        int CV = N[0];
        unordered_map<int, bool> Check;
        for(auto i : N){
            Check[i] = 0;
        }
        Check[N.back()] = Check[N[0]] = 1;
        while(1){
            pair<int, int> tmp = smallestUnincludedEdge(SPAL[CV], Check);
            if(tmp.first < 0){
                Check[N.back()] = 0;
                tmp = smallestUnincludedEdge(SPAL[CV], Check);
                res += tmp.first;
                cout<<CV+1<<" -> "<<tmp.second+1<<" | res- "<<res<<"("<<tmp.first<<")"<<endl;
                break;
            }
            res += tmp.first;
            cout<<CV+1<<" -> "<<tmp.second+1<<" | res- "<<res<<"("<<tmp.first<<")"<<endl;
            CV = tmp.second;
            Check[tmp.second] = 1;
        }
        return res;
    }
}; 
int main(){
    //Vertice Count, Must Visit Count, Edge Count
    int V,MVC,E;
    scanf("%d %d %d",&V,&MVC,&E);
    //Must Visit Vertices
    vector<int> MV(MVC);
    for(int i = 0;i < MVC;i++){
        scanf("%d",&MV[i]);
        MV[i]--;
    }
    int start,finish;
    scanf("%d %d",&start, &finish);
    start--;finish--;
    if(find(MV.begin(),MV.end(),start)!=MV.end()){
        MV.erase(find(MV.begin(),MV.end(),start));
    }
    if(find(MV.begin(),MV.end(),finish)!=MV.end()){
        MV.erase(find(MV.begin(),MV.end(),finish));
    }
    MV.insert(MV.begin(),start);
    MV.push_back(finish);
    Graph G(V);
    for(int i = 0, tmp1, tmp2 ,tmp3;i < E;i++){
        scanf("%d %d %d",&tmp1, &tmp2, &tmp3);
        G.addUndirectedEdge(--tmp1, --tmp2, tmp3);
    }
    /*
    for(auto i : MV){
        cout<<i<<" ";
    }
    cout<<endl;
    */
    G.findShortestPaths(MV);
    printf("%d",G.SPVAV(MV));
    return 0;
}
//
//  main.cpp
//  9205. 맥주 마시면서 걸어가기


#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;
int n;
vector< vector<int> > adj;
vector< pair<int,int> > loc;
int visited[102];

void makeGraph(){
    adj.resize(n+2);

    for(int i=0;i<loc.size();i++){
        for(int j=i+1;j<loc.size();j++)
            if(abs(loc[i].first-loc[j].first) + abs(loc[i].second-loc[j].second) <= 1000){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
    }
}
void dfs(int here){

    visited[here]=true;
    
    for(int i=0;i<adj[here].size();i++){
        int there=adj[here][i];

        if(!visited[there])
            dfs(there);
    }
}
void init(){

    for(int i=0;i<102;i++)
        visited[i]=false;

    adj.clear();
    loc.clear();
}
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc,x,y;
    cin >>tc;
    
    for(int i=0;i<tc;i++){
        init();

        cin>>n;
        cin>>x>>y;
        loc.push_back(make_pair(x,y));
        for(int j=0;j<n;j++){
            cin >>x>>y;
            loc.push_back(make_pair(x,y));
        }
        cin>>x>>y;
        loc.push_back(make_pair(x,y));
        
        makeGraph(); 
        dfs(0);   

        if(!visited[n+1])
            cout<<"sad"<<'\n';
        else cout<<"happy"<<'\n';
    }
    
    return 0;
}


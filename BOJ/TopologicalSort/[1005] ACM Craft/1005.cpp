#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int N,K,W;
int times[1001];
int dp[1001];
int indegree[1001];
vector< vector<int> > adj;
void constructBuilding(int here){

    for(int i=0;i<adj[here].size();i++){
        int there=adj[here][i];
        dp[there]=max(dp[there], dp[here]+times[there]);
    }
}
void topologicalSort(){
    queue<int> q;
    for(int i=1;i<=N;i++)
        if(indegree[i]==0)
            q.push(i);
    

    while(!q.empty()){
        int here=q.front();
        q.pop();
        constructBuilding(here);

        for(int i=0;i<adj[here].size();i++){
            int there=adj[here][i];
            indegree[there]--;

            if(indegree[there]==0)
                q.push(there);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;
    cin>>TC;
    for(int tc=0;tc<TC;tc++){
        cin>>N>>K;
        memset(dp,0,sizeof(dp));
        memset(times,0,sizeof(times));
        memset(indegree,0,sizeof(indegree));
        for(int i=1;i<=N;i++){
            cin>>times[i];
            dp[i]=times[i];
        }
        
        adj.clear();
        adj.resize(N+1);
        int a,b;
        for(int i=0;i<K;i++){
            cin>>a>>b;
            adj[a].push_back(b);
            indegree[b]++;
        }
        cin>>W;
        
        topologicalSort();
        cout<<dp[W]<<'\n';
    }
    return 0;
}
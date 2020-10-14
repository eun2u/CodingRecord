//
//  main.cpp
//  1697.숨바꼭질

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;
int n,k;
vector<vector<int>> adj;
void pushMovement(int here, vector<int>& distance){
   
    if((here-1>=0&& here-1<=100000) && distance[here-1]==-1)
        adj[here].push_back(here-1);
    
    if((here+1>=0 && here+1<=100000) && distance[here+1]==-1 )
        adj[here].push_back(here+1);
    
    if((here*2>=0 && here*2<=100000) && distance[here*2]==-1 )
        adj[here].push_back(here*2);
         
}
void bfs(int start,vector<int>& distance){

    distance=vector<int>(adj.size(),-1);
    queue<int> q;
    distance[start]=0;
    q.push(start);
    
    while(!q.empty()){
        int here=q.front();
        q.pop();
        
        if(here==k) break;
        if(here<0) continue;
        
        pushMovement(here,distance);
     
        
        for(int i=0;i<adj[here].size();i++){
            int there=adj[here][i];
            
            if(distance[there]==-1){
                q.push(there);
                distance[there]=distance[here]+1;
            }
        }
    }
}
int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    vector<int> distance;
    
    cin>>n>>k;
    if(n>k){
        cout<<n-k<<endl;
        return 0;
        
    }
    adj.resize(100001);
    bfs(n,distance);
    cout<< distance[k]<<endl;
    
    return 0;
}

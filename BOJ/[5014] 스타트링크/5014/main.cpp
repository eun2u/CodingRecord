//
//  main.cpp
//  5014. 스타트링크
//
//  Created by 한은주 on 2020/07/28.
//  Copyright © 2020 한은주. All rights reserved.
//

#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int f,s,g,u,d; //1 ≤ S, G ≤ F ≤ 1000000, 0 ≤ U, D ≤ 1000000)
vector<vector<int>> adj;

void bfs2(int start,vector<int>& distance){
    
    distance=vector<int>(adj.size(),-1);
    queue<int> q;
    distance[start]=0;
    q.push(start);
    
    while(!q.empty()){
        int here=q.front();
        q.pop();
        
        if(here==g) break;
        
        if((here+u>=1 && here+u<= f) && distance[here+u]==-1)
            adj[here].push_back(here+u);
        
        if((here-d>=1 && here-d<=f) && distance[here-d]==-1)
            adj[here].push_back(here-d);
        
        
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
    
    cin>>f>>s>>g>>u>>d;
    
    adj.resize(1000001);
    
    bfs2(s,distance);
    
    if(distance[g]==-1)
        cout<<"use the stairs";
    else  cout<< distance[g]<<endl;
    
}

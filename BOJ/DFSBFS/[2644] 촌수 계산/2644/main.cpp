//
//  main.cpp
//  2644
//
//  Created by 한은주 on 2020/07/27.
//  Copyright © 2020 한은주. All rights reserved.
//

#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;

void bfs2(int start,vector<int>& distance){
    distance=vector<int>(adj.size()+1,-1);
    //방문할정점 목록을 유지하는 큐
    queue<int> q;
    distance[start]=0;
    q.push(start);
    while(!q.empty()){
        int here=q.front();
        q.pop();
        //here의 모든 인접한 정점을 검사한다
        for(int i=0;i<adj[here].size();i++){
            int there=adj[here][i];
            //처음 보는 정점이면 방문목록에 집어넣는다
            if(distance[there]==-1){
                q.push(there);
                distance[there]=distance[here]+1;
            }
        }
    }
}
int main() {
    int n,x,y,m,a,b;
    cin>>n>>x>>y>>m;
    adj.resize(n+1);
    
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    
    }
    vector<int> distance;
    bfs2(x,distance);
    cout<< distance[y]<<endl;

    return 0;
}

//
//  main.cpp
//  7569 토마토
//
//  Created by 한은주 on 2020/07/27.
//  Copyright © 2020 한은주. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;
const int MAX_V=100;
int adj[MAX_V][MAX_V][MAX_V];
int distances[MAX_V][MAX_V][MAX_V];
bool discovered[MAX_V][MAX_V][MAX_V];
int dz[6]={0,0,0,0,1,-1};
int dy[6]={0,1,0,-1,0,0};
int dx[6]={1,0,-1,0,0,0};
int m,n,h;

struct loc{
    int z,y,x;
};

void init(int a[MAX_V][MAX_V][MAX_V]){
 
    for(int i=0;i<MAX_V;i++)
        for(int j=0;j<MAX_V;j++)
            for(int k=0;k<MAX_V;k++)
                a[i][j][k]=-1;
}

bool inRange(int z, int y, int x){
    
    if(z<0 || z >= h) return false;
    if(y<0 || y>=n) return false;
    if (x<0 || x>=m) return false;
    
    return true;
}
void bfs(queue<loc> q){
    
    while(!q.empty()){
        loc here=q.front();
        int z=here.z;
        int y=here.y;
        int x=here.x;
        q.pop();
        
        for(int dir=0;dir<6;dir++){
             int nextZ=z+dz[dir];
             int nextY=y+dy[dir];
             int nextX=x+dx[dir];
            
            if(!inRange(nextZ,nextY,nextX)) continue;
            int there=adj[nextZ][nextY][nextX];
            if(there==-1) continue;
            
            if(distances[nextZ][nextY][nextX]==-1){
                q.push({nextZ,nextY,nextX});
                discovered[nextZ][nextY][nextX]=true;
                distances[nextZ][nextY][nextX]=distances[z][y][x]+1;
            }
        }
    }
        
}
int checkDiscovered(){
    
    for(int i=0;i<h;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<m;k++)
                if(!discovered[i][j][k])
                    return -1;
    return 1;
}
int maxTomato(){
    int result=0;
    for(int i=0;i<h;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<m;k++)
                result=max(result,distances[i][j][k]);
                
                
    return result;

}
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    int input;
    queue<loc> q;

    init(distances);
    cin>>m>>n>>h;
    
    for(int i=0;i<h;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<m;k++){
                cin>>input;
                if(input==1){
                    distances[i][j][k]=0;
                    discovered[i][j][k]=true;
                    q.push({i,j,k});
                }
                else if(input==-1){
                    discovered[i][j][k]=true;
                }
                adj[i][j][k]=input;
            }
    
    
    bfs(q);
    
    if(checkDiscovered()==-1)
        cout<<-1<<endl;
    
    else cout<<maxTomato()<<endl;
    
    
    return 0;
}

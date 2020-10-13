//
//  main.cpp
//  1987. 알파벳

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <cstring>
using namespace std;

int r,c,result;
char adj[21][21];
bool visited[21][21];
bool seen[26];
int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};

bool inRange(int y, int x){
    
    if(y<0 || y>=r) return false;
    if(x<0 || x>=c) return false;
    return true;
    
}
void dfs(int y, int x,int picked){
    
    int idx=adj[y][x];
    visited[y][x]=true;
    seen[idx]=true; //알파벳이 중복되는지

    result=max(result,picked);

    
    for(int dir=0;dir<4;dir++){
        int nextY=y+dy[dir];
        int nextX=x+dx[dir];
        
        if(!inRange(nextY,nextX)) continue;
        int nextIdx=adj[nextY][nextX];
        
        if(!seen[nextIdx] && !visited[nextY][nextX]){
            dfs(nextY,nextX,picked+1);
            
            seen[nextIdx]=false;
            visited[nextY][nextX]=false;
        }
    }
}
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>r>>c;
    
    char data;
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++){
            cin>>data;
            adj[i][j]=data-'A';
        }
            
    dfs(0,0,1);

    cout<<result<<endl;
    return 0;
}

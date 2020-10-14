//
//  main.cpp
//  4963. 섬의 개수
//
//  Created by 한은주 on 2020/07/30.
//  Copyright © 2020 한은주. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;
int adj[50][50];
bool visited[50][50];
int dx[8]={1,1,0,-1,-1,-1,0,1};
int dy[8]={0,1,1,1,0,-1,-1,-1};

int w, h;       // w와 h는 50보다 작거나 같은 양의 정수

bool inRange(int y, int x){
    if(y<0 || y>=h) return false;
    if(x<0 || x>=w) return false;
    
    return true;
}
void init(){
    
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++){
            adj[i][j]=0;
            visited[i][j]=false;
        }
}
bool dfs(int hereY, int hereX){
    
    visited[hereY][hereX]=true;
    
    for(int dir=0; dir< 8 ;dir++){
        int nextY=hereY+dy[dir];
        int nextX=hereX+dx[dir];
        
        if(!inRange(nextY,nextX)) continue;
        
        if(!visited[nextY][nextX] && adj[nextY][nextX]==1)
            dfs(nextY,nextX);
    }
    return true;
}
int dfsAll(){
    
    int land=0;
    
    for(int i=0; i<h; i++){
        for(int j=0;j<w;j++){
            if(!visited[i][j] && adj[i][j]==1){
                if(dfs(i,j))  land++;
            }
        }
    }
    return land;
}

int main() {
    
    while(1){
        
        cin>>w>>h;
        if(w==0 && h==0) break;
        
        init();
        
        for(int i=0;i<h;i++)
            for(int j=0;j<w;j++)
                cin>>adj[i][j];
        
        int land= dfsAll();
        cout<<land<<endl;
    }
}

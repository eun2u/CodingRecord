//
//  main.cpp
//  2573
//
//  Created by 한은주 on 2020/07/29.
//  Copyright © 2020 한은주. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;
int m,n; //N과 M은 3 이상 300 이하이다. n은 세로 m은 가로
int adj[300][300];
int melted[300][300];
bool visited[300][300];
int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};

void init(){
    
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            visited[i][j]=false;
    
}
bool meltingIce(){ //다녹았으면 0을 반환
    int cnt=0;
    bool allMelted=true;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            //녹을 빙하가 있으면
            if(adj[i][j]){
                allMelted=false;
                
                cnt=0;
                for(int dir=0;dir<4;dir++){
                    int nextY=i+dy[dir];
                    int nextX=j+dx[dir];

                    if(adj[nextY][nextX]==0)
                        cnt++;
                }
                //adj배열에 녹은 빙하값을 넣으니, 새로 녹은 빙하도 포함하게됨.
                //새로운 녹은 빙하배열을 만들어서, copy
                if(adj[i][j]-cnt<0)
                    melted[i][j]=0;
                else melted[i][j]=adj[i][j]-cnt;
            }
        }
    }
    
    if(allMelted) //다녹았으면
        return false;
    else  return true;
}
bool checkDivided(int y, int x){
    
    visited[y][x]=true;
    
    for(int dir=0;dir<4;dir++){
        int nextY=y+dy[dir];
        int nextX=x+dx[dir];
        
        // 빙하가 존재하고, 방문되지 않았다면
        if(adj[nextY][nextX] && !visited[nextY][nextX])
            checkDivided(nextY,nextX);
    }
    return true;
}
int main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int iceburg=0,year=0;
    
    cin>>n>>m;
    
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>adj[i][j];
   
    while(1){
        init();
        iceburg=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // visited가 false이고 adj[i][j]가 0이 아닐때
                if(!visited[i][j] && adj[i][j]){
                    if(checkDivided(i,j))
                        iceburg++;
                }
            }
        }

        if(iceburg>=2){
            cout<<year<<endl;
            return 0;
        }
        
        year++;
        //다녹았고 덩어리가 2개 미만
        if(meltingIce()==false && iceburg<2){
            cout<<0<<endl;
            return 0;
        }
        //melted -> adj배열 복사해서 값이 중복되지 않게
        copy(&melted[0][0], &melted[0][0] + 300 * 300, &adj[0][0]);
    }
}

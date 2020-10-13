//
//  main.cpp
//  14503
//
//  Created by 한은주 on 2020/07/30.
//  Copyright © 2020 한은주. All rights reserved.
//

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int n,m;//n은 세로, m은 가로
int blocked;
int adj[50][50];//벽은 1 빈칸은 0 청소는 -1
int dy[4]={0,1,0,-1};
int dx[4]={-1,0,1,0};

int checkCleaned(){
    int result=0;
    
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(adj[i][j]==-1)
                result++;
    
    return result;
}
int direction(int d){
    
    if(d==0)      return 3;
    else if(d==1) return 2;
    else if(d==2) return 1;
    else if(d==3) return 0;
    else return -1;
    
}
void robotCleaner(int y, int x,int head){
    
    adj[y][x]=-1;//청소
    blocked=0;
    
    for(int i=0;i<4;i++){
        
        int go=(head+1)%4;//가리키는 head의 왼쪽으로 go
        int nextY=y+dy[go];
        int nextX=x+dx[go];
        

        if(adj[nextY][nextX]!=0) {//벽이나 청소했던 곳이면
            blocked++;
            head++;
            
            if(blocked==4){
                int back=(head+2)%4;
                int backY=y+dy[back];
                int backX=x+dx[back];
                
                
                if(adj[backY][backX]==-1){//청소한 곳이면
                    robotCleaner(backY,backX,head%4);
                    return;
                }
                else if(adj[backY][backX]==1)//벽이면
                    return;
                
            }
            else continue;
        }
        
        else if(adj[nextY][nextX]==0){
            robotCleaner(nextY,nextX,go);
            return;
        }
    }
}

int main() {
    int r,c,d;
    
    cin>>n>>m;
    //d가 0이면 북, 1이면 동, 2이면 남, 3이면 서
    cin>>r>>c>>d;
    
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>> adj[i][j];
    
    robotCleaner(r,c,direction(d));
    cout<<checkCleaned()<<endl;
    
    return 0;
}

//
//  main.cpp
//  14502. 연구소

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;
int adj[8][8];
bool discovered[8][8];
vector<vector<int>> pWalls;
vector<pair<int,int>> walls;
vector<pair<int,int>> virus;
vector<pair<int,int>> space;
int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};

int n,m;// 세로 크기 N과 가로 크기 M이 주어진다. (3 ≤ N, M ≤ 8)

void pickWall(int n, vector<int> &picked, int toPick){
    if(toPick==0) { pWalls.push_back(picked);  return;}
    int smallest=picked.empty() ? 0 :picked.back()+1;
    for(int next=smallest;next<n;next++){
        picked.push_back(next);
        pickWall(n,picked,toPick-1);
        picked.pop_back();
    }
}
void init(){
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            discovered[i][j]=false;
}
bool inRange(int y, int x){
    if(y<0 || y>=n) return false;
    if(x<0 || x>=m) return false;
    
    return true;
}
int bfs(vector<pair<int,int>> virus){
    
    init();
    queue<pair<int,int>> q;
    
    for(int i=0;i<virus.size();i++){
        q.push({virus[i]});
        discovered[virus[i].first][virus[i].second]=true;
    }
    int virusArea=virus.size();
    
    while(!q.empty()){
        pair<int,int> here=q.front();
        q.pop();
        
        for(int dir=0;dir<4;dir++){
            int ny=here.first+dy[dir];
            int nx=here.second+dx[dir];
            
            if(!inRange(ny,nx)) continue;
            
            if(!discovered[ny][nx] && adj[ny][nx]==0){
                q.push({ny,nx});
                discovered[ny][nx]=true;
                virusArea++;
            }
        }
    }
    
    return virusArea;
    
}
void deleteWall(pair<int,int> wall1, pair<int,int> wall2, pair<int,int> wall3){
 
    adj[wall1.first][wall1.second]=0;
    walls.pop_back();
    
    adj[wall2.first][wall2.second]=0;
    walls.pop_back();
    
    adj[wall3.first][wall3.second]=0;
    walls.pop_back();
    
}
void makeWall(pair<int,int> wall1, pair<int,int> wall2, pair<int,int> wall3){
 
    adj[wall1.first][wall1.second]=1;
    walls.push_back(wall1);
    
    adj[wall2.first][wall2.second]=1;
    walls.push_back(wall2);
    
    adj[wall3.first][wall3.second]=1;
    walls.push_back(wall3);
    
}
int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int data;
    
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>> data;
            if(data==0)
                space.push_back({i,j});
            else if(data==1)
                walls.push_back({i,j});
            else if(data==2)
                virus.push_back({i,j});
            adj[i][j]=data;
        }
    }
    vector<int> picked;
    
    pickWall(space.size(),picked,3);
    int ret=987654321;
    for(int i=0;i<pWalls.size();i++){
        pair<int,int> wall1=space[pWalls[i][0]];
        pair<int,int> wall2=space[pWalls[i][1]];
        pair<int,int> wall3=space[pWalls[i][2]];
        
        makeWall(wall1,wall2,wall3);
        ret=min(ret,bfs(virus));
        deleteWall(wall1,wall2,wall3);
    }
    
    int result=n*m-(ret + walls.size()+3);
    cout<<result<<endl;
    
    return 0;
}

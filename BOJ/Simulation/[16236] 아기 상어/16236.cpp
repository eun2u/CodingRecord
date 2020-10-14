#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF=987654321;
int n;
int adj[100][100];
int dist[100][100];
int sSize=2;
int result=0;
pair<int,int> shark;
int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};
struct FISH{
    int y,x,fdist;
};

bool inRange(int y,int x){
    if(y<0 || y>=n) return false;
    if(x<0 || x>=n) return false;
    
    return true;
}
vector<FISH> initFishDists(){
    
    vector<FISH> fish;
    adj[shark.first][shark.second]=-1;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(adj[i][j]>sSize )    //상어가 먹을 수 없는 곳
                dist[i][j]=INF;
            
            else if(adj[i][j]==-1){
                dist[i][j]=0;
                shark={i,j};
            }
            else{ //지나갈 수 있는 곳
                dist[i][j]=-1;
                if(adj[i][j]>0 && adj[i][j]<sSize)
                    fish.push_back({i,j,-1});
            }
        }
    }
    
    return fish;
}
void makeFishDists(){
    
    queue<pair<int,int>> q;
    q.push(shark);
    
    while(!q.empty()){
        pair<int,int> here=q.front();
        q.pop();
        int y=here.first;
        int x=here.second;
        
        for(int dir=0;dir<4;dir++){
            int nextY=y+dy[dir];
            int nextX=x+dx[dir];
            
            if(!inRange(nextY,nextX)) continue;
            
            if(dist[nextY][nextX]==-1){
                q.push({nextY,nextX});
                dist[nextY][nextX]=dist[y][x]+1;
            }
        }
    }
}
bool cmp(const FISH & a, const FISH & b){
    if (a.y < b.y) return true; // 제일 먼저 y를 기준으로 오름차순 정렬
    else if (a.y == b.y) // 만약에 y가 같다면
        if (a.x < b.x) return true; // x를 기준으로 오름차순 정렬
 
    return false;
}
void chooseFish(vector<FISH> fish){
   
    for(int i=0;i<fish.size();i++)
        fish[i].fdist = dist[fish[i].y][fish[i].x];
    
    int minDist=INF;
//  가장 가까운 물고기의 거리
    for(int i=0;i<fish.size() ;i++)
        if(fish[i].fdist>0)
            minDist=min(minDist,fish[i].fdist);
    
    
    vector<FISH> minfishes; //가장 가까운 물고기들을 minfishes에 넣음
    for(int i=0;i<fish.size();i++)
        if(fish[i].fdist==minDist)
            minfishes.push_back(fish[i]);

    
    int goY=INF, goX=INF, etime=0;

    if(minfishes.empty()) {
        cout<<result <<endl;
        exit(0);
    }
    
    etime=minDist;
    if(minfishes.size()==1){    //가장 가까운 물고기가 한마리
        goY=minfishes[0].y;
        goX=minfishes[0].x;
    }
    else{//같은 거리의 물고기가 두마리 이상
        sort(minfishes.begin(),minfishes.end(),cmp);
        
        goY=minfishes[0].y;
        goX=minfishes[0].x;
   }
    
    adj[shark.first][shark.second]=0;
    shark={goY,goX};
    result+=etime;
    
    return;
}
void eatFish(){
    
    int eaten=0;
    while(1){
        if(eaten==sSize){
            sSize++;
            eaten=0;
        }
        
        vector<FISH> fish=initFishDists();
        if(fish.empty()) break;
        
        makeFishDists();
        chooseFish(fish);
        
        eaten++;
    }
}
int main(){
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int data;
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            cin>> data;
            if(data==9)
                shark={i,j};
            adj[i][j]=data;
        }
    
    eatFish();
    cout<<result<<endl;
    return 0;
}

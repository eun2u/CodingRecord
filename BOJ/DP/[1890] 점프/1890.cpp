#include <iostream>
#include <utility>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int N;
int map[101][101];
long long  dist[101][101];
int dy[2]={0,1};
int dx[2]={1,0};

bool inRange(int y, int x){
    if(y<0 || y>=N) return false;
    if(x<0 || x>=N) return false;
    return true;
}
long long jump(int y, int x){
    if(y==N-1 && x==N-1) return 1;
    if(dist[y][x]!=-1) 
        return dist[y][x];

    dist[y][x]=0;
    for(int dir=0;dir<2;dir++){
        int len=map[y][x];
        int ny=y+dy[dir]*len;
        int nx=x+dx[dir]*len;

        if(len==0) continue;
        if(!inRange(ny,nx)) continue;
        
        dist[y][x]+=jump(ny,nx);
    }
    return dist[y][x];
}
int main(){
    cin>>N;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>map[i][j];
    memset(dist,-1,sizeof(dist));
    jump(0,0);
    cout<<dist[0][0]<<'\n';

    return 0;
}
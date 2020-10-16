#include <iostream>
#include <cstring>
#include <utility>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int N,L,R;
int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};
int A[50][50];
int cA[50][50];
bool visited[50][50];

bool inRange(int y ,int x){
    if(y<0 || y>= N) return false;
    if(x<0 || x>=N) return false;
    return true;
}
bool bfs(int y, int x){
    queue< pair<int,int> > q;
    vector<pair<int, int> > order;
    int sumU=0;
    q.push(make_pair(y,x));

    visited[y][x]=true;

    while(!q.empty()){
        pair<int,int> here=q.front();
        q.pop();
        order.push_back(make_pair(here.first,here.second));
        sumU+=A[here.first][here.second];

        for(int dir=0;dir<4;dir++){
            int ny=here.first+dy[dir];
            int nx=here.second+dx[dir];

            if(!inRange(ny,nx)) continue;
            int diff=abs( A[here.first][here.second] - A[ny][nx]);
            if(!visited[ny][nx] && (diff >=L && diff<=R)){ //방문되지 않았고, 인구차이 가능
                visited[ny][nx]=true;
                q.push(make_pair(ny,nx));
            }
        }
    }
    if(order.size()>1){ //국경선 공유하는 나라가 두개 이상일때
        int avr=sumU/order.size();
        for(int i=0;i<order.size();i++)
            cA[order[i].first][order[i].second]=avr;

        return true;
    }
    return false;
}
int solution(){
    int time=0;
    while(1){
        memset(visited,false,sizeof(visited));
        //copy A to cA
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                cA[i][j]=A[i][j];


        bool toMove=false;
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                if(!visited[i][j])
                    if(bfs(i,j))
                        toMove=true;

        if(toMove==false)
            break;
        //copy cA to A
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                A[i][j]=cA[i][j];

         time++;
    }
    return time;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>L>>R;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>A[i][j];
    
    cout<< solution()<<'\n';

    return 0;
}
#include <iostream>
#include <utility>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int INF=987654321;
int result=INF;
int N,M,space=0;
int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};
int map[51][51];
int visited[51][51];
vector< pair<int,int> > virus;

bool inRange(int y, int x){
    if(y<0 || y>=N) return false;
    if(x<0 || x>=N) return false;
    return true;
}
int calculTime(){
    int ret=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(visited[i][j]==-1 && map[i][j]!=1) // 벽도 아니고, 방문되지 않았을 때
                return INF;
            ret=max(ret,visited[i][j]);   
        }
    }
    return ret;
}
void findShortest(vector<int> picked){

    queue< pair<int,int> > q;
    bool total[11];
    memset(total, false, sizeof(total));
    memset(visited,-1, sizeof(visited));
    for(int i=0;i<picked.size();i++){
        total[picked[i]]=true;
        int y=virus[picked[i]].first;
        int x=virus[picked[i]].second;
        q.push(make_pair(y,x));
        visited[y][x]=0;
    }
    for(int i=0;i<virus.size();i++)
        if(!total[i])
            visited[virus[i].first][virus[i].second]=-2; //비활성 바이러스

    int cnt=0;// 빈칸 세는 카운트
    
    while(!q.empty() ){
        if(cnt== space) break;
        pair<int,int> here=q.front();
        q.pop();

        for(int dir=0;dir<4;dir++){
            int ny=here.first+dy[dir];
            int nx=here.second+dx[dir];
            if(!inRange(ny,nx)) continue;
            
            if(visited[ny][nx]<0  && map[ny][nx]!=1){ //방문되지 않았고, 벽이 아닐때
                if(visited[ny][nx]==-1) 
                    cnt++;
                q.push(make_pair(ny,nx));
                visited[ny][nx]=visited[here.first][here.second]+1;   
            }
        }
    }

    result=min(result,calculTime());
}
void pickVirus(vector<int> picked, int n, int cnt){

    if(cnt==M){
        findShortest(picked);
        return;
    }
    int smallest=picked.empty()? 0 : picked.back()+1;

    for(int next=smallest;next<n;next++){
        picked.push_back(next);
        pickVirus(picked,n,cnt+1);
        picked.pop_back();
    }
}
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>map[i][j];
            if(map[i][j]==2)
                virus.push_back(make_pair(i,j));
            else if(map[i][j]==0)
                space++;
        }
    }
    vector<int> picked;
    pickVirus(picked, virus.size(),0);
    if(result==INF)    cout<<-1<<'\n';
    else   cout<<result<<'\n';

    return 0;
}
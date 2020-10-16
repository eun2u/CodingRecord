#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int map[8][8];
bool seen[8][8];
int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};
int N,M; //세로 N, 가로 M
int cNum=0, minResult=987654321;
int pos[6][4][4]={
    {{-1}},
    {{0,-1},{1,-1},{2,-1},{3,-1}},
    {{0,2,-1},{1,3,-1}},
    {{0,3,-1},{0,1,-1},{1,2,-1},{2,3,-1}},
    {{0,1,2,-1},{0,1,3,-1},{0,2,3,-1},{1,2,3,-1}},
    {{0,1,2,3}}};
struct CCTV{
    int y, x, num, dir;
};
vector<CCTV> cctv;

int calculResult(){
    int result=0;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            if(!seen[i][j] && map[i][j]!=6) //seen 되지 않고, 벽이 아닌 곳
                result++;        
    
    return result;
}
bool inRange(int y, int x){
    if(y<0 || y>=N) return false;
    if(x<0 || x>=M) return false;
    return true;
}
void findSquare(vector<CCTV>  picked){
    //사각 지대 탐지. 6 발견 전까지. 경계 밖 안됨
    memset(seen,false,sizeof(seen));

    for(int i=0;i<picked.size();i++){
        CCTV c=picked[i];
        seen[c.y][c.x]=true;
        
        for(int j=0;j<4;j++){//-1은 break;
            if(pos[c.num][c.dir][j]==-1) break;
            int toDir=pos[c.num][c.dir][j];
            int ny=c.y+dy[toDir];
            int nx=c.x+dx[toDir];

            while(inRange(ny,nx) && map[ny][nx]!=6){ //경계 내에 있고 벽이 아닐때
                seen[ny][nx]=true;
                ny+=dy[toDir];
                nx+=dx[toDir];
            }
        }
    }
    int ret= calculResult();
    minResult=min(ret,minResult);
}
void solution(vector< CCTV > picked, int cnt){
    if(cNum==cnt){
        findSquare(picked);
        return;
    }

    CCTV c= cctv[cnt];
    int csize=0;
    if(c.num==5) csize=1;
    else if (c.num==2) csize=2;
    else csize=4;

    for(int dir=0;dir<csize;dir++){
        CCTV input={c.y,c.x,c.num,dir};
        picked.push_back(input);
        solution(picked,cnt+1);
        picked.pop_back();
    }
}
int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>map[i][j];
            if(map[i][j]>= 1 && map[i][j]<=5 ){
                CCTV c={i,j,map[i][j],-1};
                cctv.push_back(c);
            }
        }
    }
    cNum=cctv.size();
    vector<CCTV > picked;
    solution(picked,0);
    cout<<minResult<<'\n';

    return 0;
}
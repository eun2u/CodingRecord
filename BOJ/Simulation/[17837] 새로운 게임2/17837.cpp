#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;
int N,K;
int dy[4]={0,0,-1,1};
int dx[4]={1,-1,0,0};

int chess[12][12]; //체스판 색깔
vector<int> map[12][12]; //map위에 있는 말들
struct PIECE{
    int y, x, dir;
};
vector< PIECE > piece; //말을 순서대로 저장

bool inRange(int y, int x){
    if(y<0 || y>=N) return false;
    if(x<0 || x>=N) return false;
    return true;
}
int reverseDir(int d){
    if(d==0) return 1;
    if(d==1) return 0;
    if(d==2) return 3;
    if(d==3) return 2;
}
void moveIfWhite(int ny, int nx,PIECE cur,int num){

    int start=0;
    for(int j=0;j<map[cur.y][cur.x].size();j++){
        if(map[cur.y][cur.x][j] == num ){
            start=j;
            break;
        }
    }

    for(int j=start;j<map[cur.y][cur.x].size();j++){
        map[ny][nx].push_back(map[cur.y][cur.x][j]);
        piece[map[cur.y][cur.x][j]].y=ny;
        piece[map[cur.y][cur.x][j]].x=nx;
    }
    //size 를 지정해놓고 Pop해야함
    int size=map[cur.y][cur.x].size();
    for(int j=start;j<size;j++)
        map[cur.y][cur.x].pop_back();
    
}
void moveIfRed(int ny, int nx, PIECE cur,int num){
    int start=0;
    for(int j=0;j<map[cur.y][cur.x].size();j++){
        if(map[cur.y][cur.x][j] == num ){
            start=j;
            break;
        }
    }
    for(int j=map[cur.y][cur.x].size()-1;j>=start;j--){
        map[ny][nx].push_back(map[cur.y][cur.x][j]);
        piece[map[cur.y][cur.x][j]].y=ny;
        piece[map[cur.y][cur.x][j]].x=nx;
    }

    int size=map[cur.y][cur.x].size();
    for(int j=size-1;j>=start;j--)
        map[cur.y][cur.x].pop_back();
               
}
bool checkCount(){
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(map[i][j].size()>=4)
                return true;
    return false;
}
int solution(){

    int turn=1;
    
    while(turn<=1000){
        for(int i=0;i<K;i++){
            PIECE cur=piece[i];
            int ny=cur.y+dy[cur.dir];
            int nx=cur.x+dx[cur.dir];

            if(!inRange(ny,nx) || chess[ny][nx]==2){// 파랑
                piece[i].dir=reverseDir(piece[i].dir);
                int ry=cur.y+dy[piece[i].dir];
                int rx=cur.x+dx[piece[i].dir];
                if(!inRange(ry,rx) || chess[ry][rx]==2)
                    continue;
                else{
                    cur=piece[i];
                    if(chess[ry][rx]==0)
                        moveIfWhite(ry,rx,cur,i);
                    else if(chess[ry][rx]==1)
                        moveIfRed(ry,rx,cur,i);
                }
            }
            else if(chess[ny][nx]==0){ //흰색
                moveIfWhite(ny,nx,cur,i);               
            }
            else if(chess[ny][nx]==1){ //빨강
                moveIfRed(ny,nx,cur,i);
            }
            //turn 다끝나고 확인하는게 아니라, 매번 확인해야함. 다 끝나면 4가 아닐 수도 있음
            if(checkCount()) return turn;
        }
       
        turn++;
    }
    if(turn>1000) 
        return -1;
    return turn;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>K;

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>chess[i][j];
        
    int y,x,dir;
    for(int i=0;i<K;i++){
        cin>>y>>x>>dir;
        map[y-1][x-1].push_back(i);
        
        PIECE p={y-1,x-1,dir-1};
        piece.push_back(p);
    }

    cout<< solution()<<'\n';
    return 0;
}
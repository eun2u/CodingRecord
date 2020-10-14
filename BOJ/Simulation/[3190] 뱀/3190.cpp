#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;
int board[100][100]; //사과는 1, 뱀은 -1, 빈칸은 0
queue< pair<int,char> > rotinfo; //방향 회전 정보 
queue< pair<int,int> > snakeinfo;
int N,movtime=0,dir=0;
int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};

bool inRange(int y, int x){
    if(y<0 || y>=N) return false;
    if(x<0 ||x>=N ) return false;

    return true;
}
void checkRoatate(){

    if(rotinfo.empty()) return;

    pair<int,char> check = rotinfo.front();
    
    if(movtime==check.first){
        rotinfo.pop();
        if(check.second=='D')//오른쪽
            dir=(dir+1)%4;
        else if(check.second=='L')//왼쪽
            dir=(dir-1+4)%4;
    }
}
void dummygame(int y, int x){ //1초에 수행하는 단위
   
    while(1){
        int ny=y+dy[dir];
        int nx=x+dx[dir];

        if(!inRange(ny,nx) || board[ny][nx]==-1)
            return;

        if(board[ny][nx]==1){
            snakeinfo.push(make_pair(ny,nx));
            board[ny][nx]=-1; //사과를 뱀의 위치로 
        }
        else if(board[ny][nx]==0){
            board[ny][nx]=-1;
            snakeinfo.push(make_pair(ny,nx));

            pair<int,int> tail=snakeinfo.front();
            snakeinfo.pop();
            board[tail.first][tail.second]=0;
        }

        movtime++;
        checkRoatate();
        y=ny,x=nx;
   }
}
int main(){

    int k,l,r,c,t;//사과 개수, 방향 개수
    char d;

    cin>>N>>k;
    for(int i=0;i<k;i++){
        cin>>r>>c;
        board[r-1][c-1]=1;
    }
    cin>>l;
    for(int i=0;i<l;i++){
        cin>>t>>d;
        rotinfo.push(make_pair(t,d));
    }

    board[0][0]=-1;
    snakeinfo.push(make_pair(0,0));

    dummygame(0,0);
    
    cout<<movtime+1<<'\n';

    return 0;
}

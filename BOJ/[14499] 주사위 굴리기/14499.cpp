//14499. 주사위 굴리기

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
int n, m; //(1 ≤ N, M ≤ 20),n은 세로, m은 가로
int map[20][20];
pair<int, int> dice_loc;
int dice[6]; // 0은 윗면, 5가 바닥
int dy[4]={0,0,-1,1}; //동 서 북 남
int dx[4]={1,-1,0,0};

bool inRange(int y, int x){

    if(y<0 || y>=n) return false;
    if(x<0 || x>=m) return false;

    return true;
}
void makeDice(int dir){
    int ndice[6];

    for(int i=0;i<6;i++)
        ndice[i]=dice[i];

    if(dir==0){//동쪽
        ndice[0]=dice[3]; //4가 1로
        ndice[2]=dice[0]; //1이 3으로        
        ndice[5]=dice[2];//3이 6으로
        ndice[3]=dice[5];//6이 4로
    }
    else if(dir==1){//서쪽
        ndice[3]=dice[0];//1이 4로
        ndice[0]=dice[2];//3이 1로
        ndice[2]=dice[5];//6이 3으로
        ndice[5]=dice[3];//4가 6으로
    }
    else if(dir==2){//북쪽
        ndice[5]=dice[1];//2가 6으로
        ndice[4]=dice[5];//6이 5로
        ndice[0]=dice[4];//5가 1로
        ndice[1]=dice[0];//1이 2로
    }
    else if(dir==3){//남쪽
        ndice[0]=dice[1];//2가 1로
        ndice[4]=dice[0];//1이5로
        ndice[5]=dice[4];//5가 6으로
        ndice[1]=dice[5];//6이 2로
    }
    
    for(int i=0;i<6;i++)
        dice[i]=ndice[i];

}
void rollingDice(int dir){
    
    int ny=dice_loc.first + dy[dir];
    int nx=dice_loc.second + dx[dir];

    if(!inRange(ny,nx)) return;

    dice_loc=make_pair(ny,nx);

    makeDice(dir);
    
    if(map[ny][nx]==0)
        map[ny][nx]=dice[5];
    else {
        dice[5]=map[ny][nx];
        map[ny][nx]=0;
    }
    cout<<dice[0]<<'\n';    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k;

    cin >> n >> m >> dice_loc.first >> dice_loc.second >> k;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];

    vector<int> order;
    order.resize(k);
    for(int i=0;i<k;i++)
        cin>>order[i];
    
    for(int i=0;i<k;i++)
        rollingDice(order[i]-1);

    return 0;
}

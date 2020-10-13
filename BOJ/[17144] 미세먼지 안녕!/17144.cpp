//17144. 미세먼지 안녕!

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;
int R, C, T;
int dust[50][50];
int after[50][50];
int puri_y;
int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};

void copying(int A[][50], int B[][50]){

    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++)
            A[i][j]=B[i][j];
        
}
bool inRange(int y, int x){
    if(y<0 || y>=R)   return false;
    if(x<0 || x>=C) return false;
    
    return true;
}
void spreadDust(){
    //copying dust to after
    copying(after, dust);

    for(int y=0;y<R;y++){
        for(int x=0;x<C;x++){
            if(dust[y][x]>0){
                int amount=dust[y][x]/5;
                int cnt=0;

                for(int dir=0;dir<4;dir++){
                    int ny=y+dy[dir];
                    int nx=x+dx[dir];

                    if(!inRange(ny,nx) || dust[ny][nx]==-1) continue;
                    cnt++;
                    after[ny][nx]+=amount;
                }

                after[y][x]-=amount*cnt;
            }
        }
    }
    copying(dust, after);
}
void purifying(){

    int y2=puri_y;
    int y1=y2-1;

    for(int i=1;i<C-1;i++)
        dust[y1][i+1]=after[y1][i];
    for(int i=y1;i>0;i--)
        dust[i-1][C-1]=after[i][C-1];
    for(int i=C-1;i>=0;i--)
        dust[0][i-1]=after[0][i];
    for(int i=0;i<y1-1;i++)
        dust[i+1][0]=after[i][0];


    for(int i=1;i<C-1;i++)
        dust[y2][i+1]=after[y2][i];
    for(int i=y2;i<R-1;i++)
        dust[i+1][C-1]=after[i][C-1];
    for(int i=C-1;i>0;i--)
        dust[R-1][i-1]=after[R-1][i];
    for(int i=R-1;i>y2+1;i--)
        dust[i-1][0]=after[i][0];

    dust[y1][1]=0;
    dust[y2][1]=0;
 
}
int countDusts(){
    int result=0;

    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++)
            if(dust[i][j]>0)
                result+=dust[i][j];

    return result;
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>R>>C>>T;
    
    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++){
            cin>> dust[i][j];
            if(dust[i][j]==-1)
                puri_y=i;
        }

    for(int i=0;i<T;i++){
       spreadDust();
       purifying();
    }

    int result= countDusts();
    cout<<result<<'\n';

    return 0;
}

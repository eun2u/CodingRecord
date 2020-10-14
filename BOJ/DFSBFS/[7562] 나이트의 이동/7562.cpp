//7562. 나이트의 이동

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int l;
pair<int,int> curLoc;
pair<int,int> destLoc;
int distances[300][300];
int dy[8]={1,2,2,1,-1,-2,-2,-1};
int dx[8]={2,1,-1,-2,-2,-1,1,2};

bool inRange(int y, int x){
    if(y<0 || y>=l) return false;
    if(x<0 || x>=l) return false;

    return true;
}
void moveKnite(){
    queue< pair<int,int> > q;
    q.push(curLoc);
    distances[curLoc.first][curLoc.second];
    
    while(!q.empty()){
        pair<int,int> here=q.front();
        q.pop();

        for(int dir=0;dir<8;dir++){
            int ny=here.first+dy[dir];
            int nx=here.second+dx[dir];

            if(!inRange(ny,nx)) continue;

            if(distances[ny][nx]==0){
                q.push(make_pair(ny,nx));
                distances[ny][nx]=distances[here.first][here.second]+1;
                
                if(ny==destLoc.first && nx==destLoc.second)
                    return;
            }
        }
    }
}
void init(){
    for(int i=0;i<l;i++)
        for(int j=0;j<l;j++)
            distances[i][j]=0;

}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin>>tc;
    for(int i=0;i<tc;i++){
        init();
        cin>>l;
        cin>>curLoc.first>>curLoc.second;
        cin>>destLoc.first>>destLoc.second;

        if(curLoc == destLoc){
            cout<<0<<'\n';
            continue;
        }
        init();
        moveKnite();
        cout<<distances[destLoc.first][destLoc.second]<<'\n';
    }
    return 0;
}
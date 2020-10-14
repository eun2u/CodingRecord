#include <iostream>
#include <utility>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int dy[8]={-1,-1,0,1,1,1,0,-1};
int dx[8]={0,-1,-1,-1,0,1,1,1};

int N,M,K;
int a[10][10];
int food[10][10];
int result=0;
vector< int >  trees[10][10];//죽으면 나이 -1
struct dead{
    int y,x,age;
};
vector<dead> deadtrees;

bool inRange(int y, int x){
    if(y<0 || y>=N) return false;
    if(x<0 || x>=N) return false;
    return true;
}
int calculTrees(){
    int ret=0;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            ret+=trees[i][j].size();

    return ret;
}
void deleteDead(int y, int x, vector<int> a){
    vector<int> newv;
    for(int i=0;i<a.size();i++){
        if(a[i]==-1) continue;
        newv.push_back(a[i]);
    }
    trees[y][x].clear();
    for(int i=0;i<newv.size();i++)
        trees[y][x].push_back(newv[i]);

}
void spring(){
    deadtrees.clear();
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(trees[i][j].size()>0){       
                sort(trees[i][j].begin(),trees[i][j].end());

                for(int k=0;k<trees[i][j].size();k++){
                    if(trees[i][j][k] > food[i][j]){
                        dead d;
                        d.y=i, d.x=j, d.age=trees[i][j][k];
                        deadtrees.push_back(d);
                        trees[i][j][k]=-1;  
                    }
                    else{
                        food[i][j]-=trees[i][j][k];
                        trees[i][j][k]++;
                    }
                }
                deleteDead(i,j, trees[i][j]);
            }
        }
    }  
}
void summer(){
    for(int i=0;i<deadtrees.size();i++){
        int y=deadtrees[i].y;
        int x=deadtrees[i].x;
        food[y][x] += deadtrees[i].age/2;
    }
}

void fall(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){

            if(trees[i][j].size()>0){
                for(int k=0;k<trees[i][j].size();k++){
                    if(trees[i][j][k] % 5 == 0){
                        for(int dir=0;dir<8;dir++){
                            int ny=i+dy[dir];
                            int nx=j+dx[dir];
                            if(!inRange(ny,nx)) 
                                continue;
                            else
                                trees[ny][nx].push_back(1);                            
                        }
                    }
                }
            }
        }
    }
}
void winter(){
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            food[i][j]+=a[i][j];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M>>K;

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>a[i][j];
        
    fill(food[0], food[10],5);
     
    int x,y,z;
    for(int i=0;i<M;i++){
        cin>>x>>y>>z;
        trees[x-1][y-1].push_back(z);
    }

    for(int year=0;year<K;year++){
        spring();
        summer();
        fall();
        winter();
    }
    
    cout<<calculTrees()<<'\n';
    return 0;
}
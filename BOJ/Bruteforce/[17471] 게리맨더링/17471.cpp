#include <iostream>
#include <cstring>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
const int INF=987654321;
int N;
int minResult=INF;
int pop[10];
vector<int> adj[10];
bool visited[10];

void findMin(vector<int> picked, vector<int> another){
    int sum1=0,sum2=0;
    for(int i=0;i<picked.size();i++)
        sum1+=pop[picked[i]];
    for(int i=0;i<another.size();i++)
        sum2+=pop[another[i]];
    
    minResult=min(minResult,abs(sum1-sum2));
}
void dfs(int here){
    visited[here]=true;

    for(int i=0;i<adj[here].size();i++){
        int there=adj[here][i];
        if(!visited[there])
            dfs(there);
    }
}
void checkAvailable(vector<int> picked){
    //전체 노드에서 picked에 해당되는것만 false, 나머진 true
    memset(visited,true,sizeof(visited));
    for(int i=0;i<picked.size();i++)
        visited[picked[i]]=false;
    
    vector<int> another;
    for(int i=0;i<N;i++)
        if(visited[i]==true)
            another.push_back(i);

    
    dfs(picked[0]);

    for(int i=0;i<picked.size();i++){
        if(!visited[picked[i]]) //방문되지 않는 노드가 있으면 불가능한 조합
            return ;
    }
    //picked가 모두 방문되면 아래 코드 실행
    // N까지 picked가 아닌 수를 another에 push
   

    //전체 노드에서 another에 해당되는것만 false, 나머진 true
    memset(visited,true,sizeof(visited));
    for(int i=0;i<another.size();i++)
        visited[another[i]]=false;

    dfs(another[0]);
    for(int i=0;i<another.size();i++){
        if(!visited[another[i]]) //방문되지 않는 노드가 있으면 불가능한 조합
            return ;
    }

    findMin(picked, another);    
}

void pickComb(vector<int> picked, int toPick){
    if(toPick==0){
        checkAvailable(picked);
        return;
    }

    int smallest=picked.empty()? 0: picked.back()+1;

    for(int next=smallest;next<N;next++){
        picked.push_back(next);
        pickComb(picked,toPick-1);
        picked.pop_back();
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;
    for(int i=0;i<N;i++)
        cin>>pop[i];
    for(int i=0;i<N;i++){
        int num;
        cin>>num;
        for(int j=0;j<num;j++){
            int con;
            cin>> con;
            adj[i].push_back(con-1);
        }
    }

    for(int i=1;i<=N/2;i++){
        vector<int> picked;
        pickComb(picked, i);
    }
    if(minResult==INF)
        cout<<"-1"<<'\n';
    else
        cout<<minResult<<'\n';

    return 0;
}
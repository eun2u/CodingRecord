//1707. 이분 그래프

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int V,E;
vector< vector<int> > adj;
vector<bool> visited;
vector<bool> color;

void dfs(int here){

    visited[here]=true;
    
    for(int i=0;i<adj[here].size();i++){
        int there=adj[here][i];
        if(!visited[there]){
            color[there]=(color[here]+1) % 2;
            dfs(there);
        }
    }
}
void dfsAll(){	
    visited=vector<bool>(adj.size(), false);
    color=vector<bool>(adj.size(), false);

	for(int i=0; i<adj.size(); i++){
		if(!visited[i])
			dfs(i);
	}
}
bool isBipartite(){

    for(int here=1;here<adj.size();here++){
        for(int i=0;i<adj[here].size();i++){
            int there=adj[here][i];
            if(color[there]==color[here])
                return false;
        }
    }
    return true;

}
void init(){
    adj.clear();
    visited.clear();
    color.clear();

    adj.resize(V+1);
    
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int tc;
    cin>>tc;
    for(int i=0;i<tc;i++){
        cin>>V>>E;
        init();
     
        int a,b;
        for(int j=0;j<E;j++){
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfsAll();

        if(!isBipartite())
            cout<<"NO"<<'\n';
        else cout<<"YES"<<'\n';

    }
    return 0;
}

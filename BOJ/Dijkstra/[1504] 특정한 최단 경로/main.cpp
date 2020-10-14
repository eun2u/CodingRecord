//
//  main.cpp
//  1504

#include <iostream>
#include <utility>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
const int INF=987654321;
const int MAX_V=801;
int V,E,x,y;
vector<pair<int, int>> adj[MAX_V];

vector<int> dijkstra(int src) {
    vector<int> dist(V, INF);
    dist[src] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, src));

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        //만약 지금 꺼낸 것보다 더 짧은 경로를 알고 있다면 지금 꺼낸 것을 무시한다.
        if (dist[here] < cost) continue;
        //인접한 정점들을 모두 검사한다
        for (int i = 0; i < adj[here].size(); i++) {
            int there = adj[here][i].first;
            int nextDist = cost + adj[here][i].second;
            //더 짧은 경로를 발견하면, dist[]를 갱신하고 우선순위 큐에 넣는다.
            if (dist[there] > nextDist) {
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist, there));
            }
        }
    }
    return dist;

}
bool isLinked(vector<int> dist){
    
    if(dist[x]==INF) return false;
    if(dist[y]==INF) return false;
    if(dist[V]==INF) return false;
    
    return true;
}
int main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>V>>E;
    int a,b,c;
    for(int i=0;i<E;i++){
        cin>>a>>b>>c;
        a--; b--;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    cin>>x>>y;
    x--; y--;
    
    vector<int> dist=dijkstra(0);
    if(!isLinked(dist)) {
        cout<<-1 <<endl;
        return 0;
    }
    int min1=dist[x];
    dist=dijkstra(x);
    int min2=dist[y];
    dist=dijkstra(y);
    int min3=dist[V-1];
    
    int sum1=min1+min2+min3;
    
    dist=dijkstra(0);
     min1=dist[y];
    dist=dijkstra(y);
     min2=dist[x];
    dist=dijkstra(x);
     min3=dist[V-1];
    int sum2=min1+min2+min3;
    
    int result=min(sum1,sum2);
    if(result>200000000 )
        cout<< -1 <<endl;
    else  cout<< result <<endl;
    

    return 0;
}

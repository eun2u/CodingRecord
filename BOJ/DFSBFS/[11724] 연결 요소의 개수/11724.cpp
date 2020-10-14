//11724. 연결 요소의 개수

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int n, m;
vector< vector<int> > adj;
vector<bool> visited;
int result = 0;

void dfs(int here)
{
    visited[here] = true;
    for (int i = 0; i < adj[here].size(); i++)
    {
        int there = adj[here][i];
        if (!visited[there])
            dfs(there);
    }
}
void dfsAll()
{
    visited = vector<bool>(adj.size(), false);

    for (int i = 0; i < adj.size(); i++)
        if (!visited[i])
        {
            dfs(i);
            result++;
        }
}
int main()
{
    cin >> n >> m;
    int a, b;

    adj.resize(n);

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    dfsAll();

    cout << result << '\n';
    return 0;
}
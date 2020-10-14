
## 알고리즘
> DFS, Backtracking

## 접근과정

1. 좌측 상단에서 시작해서 네 방향 탐색한다
2. visited, seen 배열을 이용해서, 중복된 알파벳과 방문된 장소임을 확인함
3. 재귀 호출 종료 후에는 visited, seen을 다시 원래대로 복구시켜줌
4. 매 호출마다 최대값인지 확인하여 최대값을 구한다.


## 틀렸습니다 이유

```cpp
2 6
CCBABB
CABABC
```

- 1이 나와야 하는데 3이 나왔다.
- 왜냐하면 dfs를 모든 배열 다 돌면서 했기 때문이다. 좌측 상단에서 시작하는 조건인데 왜 모두 탐색했을까 ...


```cpp
void dfs(int y, int x,int picked){
    
    int idx=adj[y][x];
    visited[y][x]=true;
    seen[idx]=true; //알파벳이 중복되는지

    result=max(result,picked);

    for(int dir=0;dir<4;dir++){
        int nextY=y+dy[dir];
        int nextX=x+dx[dir];
        
        if(!inRange(nextY,nextX)) continue;
        int nextIdx=adj[nextY][nextX];
        
        if(!seen[nextIdx] && !visited[nextY][nextX]){
            dfs(nextY,nextX,picked+1);
            
            seen[nextIdx]=false;
            visited[nextY][nextX]=false;
        }
    }   
}
```

### 후기
- 처음에 dfs로 풀다가 안되서 bfs로도 풀어봤는데 중복되는 알파벳 때문에 실패했다

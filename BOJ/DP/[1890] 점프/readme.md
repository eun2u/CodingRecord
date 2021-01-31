# [1890] 점프

## 분류💁

DFS + DP

## 접근법

> 가장 왼쪽 위 칸에서 가장 오른쪽 아래 칸으로 규칙에 맞게 이동할 수 있는 경로의 개수를 구하는 프로그램을 작성하시오.
- 반드시 오른쪽 방향 혹은 아래쪽 방향으로만 움직일 수 있다.
- 점프할 때 도착 지점이면 1을 반환하고, 방문된 지점은 저장된 `dist[y][x]`값을 리턴한다.
- 방문되지 않은 지점이면 두 방향을 검사하면서 `jump(ny,nx)`를 top-down 방식으로 값을 알아낸다. 


```cpp 
long long jump(int y, int x){
    if(y==N-1 && x==N-1) return 1;
    if(dist[y][x]!=-1) 
        return dist[y][x];

    dist[y][x]=0;
    for(int dir=0;dir<2;dir++){
        int len=map[y][x];
        int ny=y+dy[dir]*len;
        int nx=x+dx[dir]*len;

        if(len==0) continue;
        if(!inRange(ny,nx)) continue;
        
        dist[y][x]+=jump(ny,nx);
    }
    return dist[y][x];
}
```
## 후기💡

- 0인 경우에 처리하지 않아서 메모리 초과 발생함.
- [1520] 내리막길 문제와 비슷하다.
- DFS + DP 유형은 더 풀어봐야겠다.
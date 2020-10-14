## 알고리즘

Backtracking

## 접근과정

1. 현재 y값을 가지고 n개의 행에 접근함

2. 갈 수 있으면 퀸을 벡터에 넣음. 

3. 만약 퀸 개수가 n개이면 종료함.

```cpp
void nQueen(int curY, int picked){
    
    if(picked==n) {result++; return;}
    
    for(int j=0;j<n;j++){
        if(canGo(curY,j)){
            queens.push_back({curY,j});
            nQueen(curY+1,picked+1);
            queens.pop_back();
        }
    }
}
```

## 후기
- 백트래킹에 취약함. 그래서 어려웠음

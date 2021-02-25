# [1005] ACM Craft

## 분류💁

DP + 위상정렬

## 접근법
> 특정건물을 가장 빨리 지을 때까지 걸리는 최소시간을 알아내는 프로그램
- topological sort를 이용하여 구한 순서대로 메모이제이션을 하면 된다.
- 인접한 정점을 확인하면서 `dp[]`에 최대로 걸리는 시간을 저장하면 된다.

### 위상정렬
1. 진입차수가 0인 노드를 큐에 삽입(시작 정점)
2. 큐에서 노드를 하나씩 꺼내면서 연결된 간선 모두 제거.
3. 진입차수가 0인 노드를 발견하면 큐에 삽입.
4. 큐가 빌때까지 반복.


## 후기💡
- 위상정렬을 오랜만에 풀어서 다시 봤다.
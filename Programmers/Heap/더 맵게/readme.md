# [42626] 더 맵게

## 분류💁

[level2] 우선순위 큐

## 문제

> Leo는 모든 음식의 스코빌 지수가 K 이상이 될 때까지 반복하여 섞습니다. 모든 음식의 스코빌 지수를 K 이상으로 만들기 위해 섞어야 하는 최소 횟수를 return 하도록 solution 함수를 작성해주세요.

## 접근법
- scoville 길이가 100만 보다 작거나 같기 때문에 O(nlogn)을 가지는 우선순위 큐를 이용해서 풀어야한다.

## 더 나은 코드를 위해

**vector를 queue에 복사**
```cpp
    //내가 짠 코드
    priority_queue<int,vector<int>,greater<int> > q;
    for(int s: scoville)
        q.push(s);
    //한번에 복사할 수 있는 코드
    priority_queue<int,vector<int>,greater<int>> pq (scoville.begin(),scoville.end());

```


## 후기💡
- 모든 음식의 스코빌 지수가 K이상인 것을 확인하기 위해서는 전체 원소를 검사할 필요가 없다
    - 우선순위 큐 이기 때문에, pq.top() 에 있는 원소가 K 이상이면 모든 원소가 K 이상인 것을 알 수 있다.
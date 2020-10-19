# 위장

## 분류

해쉬[level 2]


## 접근법

- vector<vector< int> > 자료구조를 unordered_map 형태로 바꿔준다

- 입을 수 있는 경우의 수는 의상의 종류(Key)를 k개라고 하면 answer*=k+1(안입는 경우) 이 된다

- 하루에 최소 한 개 이상은 입어야 하기 때문에 answer-1을 한 값을 리턴한다(모두 안입고 있는 경우)

## iter
```cpp
    for(auto it=cmap.begin();it!=cmap.end();it++){
        answer*=it->second+1;
    }
```

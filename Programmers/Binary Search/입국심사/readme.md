# [43238] 입국심사

## 분류💁

[level3] 이분탐색

## 문제

> 모든 사람이 심사를 받는데 걸리는 시간의 최솟값을 return

## 접근법
- 최소시간 : 1
- 최대시간 : 가장 느린 심사관이 모든 사람들을 한명씩 검사하는 경우(times.back()*n)

## Binary Search
```cpp
    while(low<=high){
        long long mid=(low+high)/2;
        long long peoples=calculPeople(mid,times);
    
        if(peoples >=n){
            if(mid < answer) 
                answer=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    
    return answer;
```

## 후기💡
- 테케 8번이 자꾸 틀렸는데 `long long high= (long long)times.back()*n;` 꼭 (long long) 타입 캐스팅 해야한다.. 
    - int 형을 벗어날 수 있기 때문에
- 으아 이분탐색 너무 어렵다

# [42748] K번째 수

## 분류💁

정렬

## 접근법
> 배열 array의 i번째 숫자부터 j번째 숫자까지 자르고 정렬했을 때, k번째에 있는 수를 구하기
- 전반적인 vector와 sort에 대해 이해하고 있으면 금방 풀 수 있다.

### 원하는 범위 정렬하기
```cpp
    //중요한 것은 두번째 인자도 begin() 에서 더한다.
    sort(newarr.begin()+commands[i][0]-1, newarr.begin()+commands[i][1]);
```
### 벡터 대입
우변의 모든 요소가 좌변으로 복사되어 두 벡터가 완전히 같아지며 좌변 벡터에 원래 들어 있던 값은 파괴된다.

## 후기💡
- 늘 사용하는 벡터와 sort 사용만 해봐서 푸는데 꽤나 오류가 있었다.
# [42746] 가장 큰 수 

## 분류💁

정렬

## 접근법
> 0 또는 양의 정수가 주어졌을 때, 정수를 이어 붙여 만들 수 있는 가장 큰 수를 알아내 주세요.
- 숫자를 담고있는 벡터를 `numcmp`를 기준으로 정렬한다.
- 정렬은 `a+b` 와 `b+a`를 비교하면 된다. 
    - 예를 들어, 3과 35는 335와 353을 비교하는 것이다. 

## compare 함수
```cpp
bool numcmp(string a, string b){
    return a+b >b+a;  
}
혹은
bool numcmp(string a, string b){
    if(a+b > b+a) return true;
    return false
}
```

내가 잘못 작성한 코드
```cpp
bool numcmp(string a, string b){
    if(a+b > b+a) 
        return a>b;}
```


## 후기💡
- cmp 직접 구현에서 많은 시행착오를 겪었다.
- 실패한 cmp에서는 길이 구하고, 마지막 직전 자리와 비교를 하느니 했는데, 정말 시간낭비였다. 
- 이젠 compare함수 제대로 알고 사용할 수 있을 것 같다
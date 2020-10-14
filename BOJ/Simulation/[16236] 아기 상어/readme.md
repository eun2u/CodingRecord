
### 구조체 배열 정렬
내가 정의한 cmp에 의해 정렬을 수행하게 되어서 손쉽게 구조체 배열 정렬 가능.

```cpp
sort(minfishes.begin(), minfishes.end(), cmp)


bool cmp(const fish & a, const fish & b)
{
    if (a.y < b.y) return true; // 제일 먼저 y를 기준으로 오름차순 정렬
    else if (a.y == b.y) // 만약에 y가 같다면
        if (a.x < b.x) return true; // x를 기준으로 오름차순 정렬
 
    return false;
}
```



### 런타임 에러 이유

- minfishes가 비어있는데, 배열을 참조해서 런타임 에러 오류 발생

### 틀렸습니다 이유 

- 종료조건 미약. minfishes가 비었을때 그때까지 하던 result반환해야하는데 0을 반환함
- 가장 가까운 물고기 거리가 -1이 되어 이상하게 비교를 진행함
- 처음에 상어위치를 초기화 하지않고 사용해서 dist[0][0]에 9가 저장되어있고.. 문제 많았음.
- 아기 상어가 9보다 클 수 있기 때문에 위치 값을 9로 설정하면 틀림

### 참고하기 좋은 글
접근 과정이 상세하게 나와있다

[https://velog.io/@skyepodium/%EB%B0%B1%EC%A4%80-16236-%EC%95%84%EA%B8%B0-%EC%83%81%EC%96%B4](https://velog.io/@skyepodium/%EB%B0%B1%EC%A4%80-16236-%EC%95%84%EA%B8%B0-%EC%83%81%EC%96%B4)
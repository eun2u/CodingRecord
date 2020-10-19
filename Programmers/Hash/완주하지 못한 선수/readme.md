# 완주하지 못한 선수

## 분류💁

해시[level 1]

## Unordered_map
C++ STL에는 

`map` 과 `unordered_map` 컨테이너가 있고, 둘 다 *key*로*value*에 접근할 수 있다.

 `map`은 *Red-Black Tree*를 사용해 키의 순서를 유지하므로 탐색 속도에 시간복잡도 O(log n)을 가진다. 

반면 `unordered_map`은 *Hash Table*을 사용해 키의 순서를 유지하지 않는다. key 분포에 따라 탐색 속도에 O(1) 이상의 시간 복잡도를 가진다.

```cpp
#include <unordere_map> 

unordered_map<string, int> pCnt; //pair로 값에 접근이 가능하다.

## 알고리즘
#시뮬레이션


## 접근 방법

1. 명령에 따라 굴려서 바뀐 주사위 공간을 업데이트한다
    1. 바깥으로 이동하면 해당 명령 무시 다시 1로 돌아감.
2. 이동한 주사위 현재 칸를 저장한다. 지도 업데이트
    1. 이동한 칸이 0이면, 주사위 바닥면 → 지도 칸에 복사된다
    2. 이동한 칸이 0이 아니면, 지도 칸 → 주사위 바닥면으로 복사된다.
3. 주사위 윗칸을 출력한다.
4. 다시 1 반복

접근방법을 순차적으로 푸니 복합 문제도 디버깅 없이 쉽게 풀 수 있다.

## 틀렸습니다 이유

- x,y 행 열을 반대로 생각해서 틀렸음.

## 후기
- 항상 풀면서 예외적인 경우 생각해보기!!

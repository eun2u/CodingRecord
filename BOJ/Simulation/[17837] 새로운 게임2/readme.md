# [17837] 새로운 게임2

## 분류💁

시뮬레이션

## 접근법

- 1번말부터 K번 말까지 순서대로 움직인다.

- 한 말 위에 올려져 있는 말 함께 이동한다.

- 말이 4개 이상 쌓이면 종료한다

- 이동할 곳
    
    - 흰색: 그 칸으로 이동. 말 이미 존재-> 가장 위에 놓음

    - 빨강: 이동 후에 A 순서 바꿈

    - 파랑(경계 밖): A번 말 이동 방향 반대로 하고 한칸 이동한다. 만약 이동할 곳이 파랑(경계 밖)이면, 이동안함



## 시퀀스
1. chess 판 입력

2. map 에서 이동(1번부터 순서대로)
    
    2.1 흰색 -> 순서 그대로 push

    2.2 빨강 -> 순서 뒤집어서 Push

    2.3 파랑(경계 밖) -> 이동방향 뒤집고, 한칸 이동. 이동할 곳이 파랑(경계 밖) 이면 이동안함


## 후기💡
- 말이 4보다 많은 걸 확인하는 게 turn 다끝나고 확인하는게 아니라, 매번 확인해야함. 다 끝나면 4가 아닐 수도 있음

- 흰색이나 빨간색으로 이동할 때, 한꺼번에 다 이동하고 clear했었는데, 그 말 위에 애들만 함께 움직임.

- size만큼 pop했었는데, size를 변수로 지정해놓고 pop해야 크기가 실시간으로 바뀌지 않음
```cpp
    //size 를 지정해놓고 Pop해야함
    int size=map[cur.y][cur.x].size();
    for(int j=start;j<size;j++)
        map[cur.y][cur.x].pop_back();
```

- 여러가지 실수가 많은 문제였다. ㅜㅜ
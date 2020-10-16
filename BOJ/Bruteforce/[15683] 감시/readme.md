## 분류💁

시뮬레이션, 브루트포스

## 접근법

각 CCTV는 방향이 있다.
1은 한 방향. 
-   (상) (하) (좌) (우)
2는 두방향(서로 반대). 
-   (상 하) (좌 우)
3은 두방향(서로 직각).
-   (상 우) (우 하) (하 좌) (좌 상)
4는 세방향
-   (상 좌 하) (좌 하 우) (하 우 좌) (우 좌 상)
5는 네방향
-   (상 하 좌 우)
이렇게 감시가 가능하다.


<모든 cctv의 방향을 설정>
``` cpp
void solution(vector< CCTV > picked, int cnt){
    if(cNum==cnt){
        findSquare(picked);
        return;
    }

    CCTV c= cctv[cnt];
    int csize=0;
    if(c.num==5) csize=1;
    else if (c.num==2) csize=2;
    else csize=4;

    for(int dir=0;dir<csize;dir++){
        CCTV input={c.y,c.x,c.num,dir};
        picked.push_back(input);
        solution(picked,cnt+1);
        picked.pop_back();
    }
}
```



## 후기💡
> 걸린 시간: 1시간 30분

- 각 cctv가 볼 수 있는 방향들을 어떤 자료구조로 저장할지 고민하는데 가장 오래 걸렸다.

# 베스트 앨범

## 분류💁

해쉬[level 3]


## 접근법

- 각 장르의 재생횟수 합을 구해서, 가장 많이 재생된 장르부터 수록한다.

- 장르 내에서 많이 재생된 노래를 먼저 수록하는데, 재생 횟수가 같으면 고유번호 낮은 노래를 먼저 수록한다.

- `map<string,int> genreCnt` - 각 장르의 재생횟수를 저장함

- `map<string,vector<pair<int,int> > > playlist` - 각 장르의 고유번호, 재생 수를 저장함ㄴ


## Map sort

- map을 sort하기 위해서는 

1. map을 vector로 이동

2. vector를 second 기준으로 정렬

하는 두과정을 거쳐야 한다.

```cpp
    vector< pair<string,int> > vec (genreCnt.begin(), genreCnt.end() );
    sort(vec.begin(), vec.end(), cmp);

```

## reference

- reference &를 사용해야 값이 바뀐게 적용이 됨.


``` cpp
    for(auto &elem: playlist) //reference 안 붙이면 값 안바뀜
        sort(elem.second.begin(), elem.second.end(), cmp2);

```
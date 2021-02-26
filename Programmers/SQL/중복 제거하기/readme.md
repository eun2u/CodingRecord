# [59408] 중복 제거하기

```sql
SELECT count(DISTINCT(name))
FROM animal_ins
WHERE name is not NULL;
```
## DISTINCT
컬럼 내 같은 데이터가 존재하면, 중복을 제거하기 위해 DISTINCT를 사용한다.

중복 데이터를 제거하고자 하는 열은 NAME 이므로, 옆에 DISTINCT 키워드를 붙인다.

## NULL
NULL 값이 아닌 것을 비교하는 방법은 IS NOT NULL 을 붙인다.
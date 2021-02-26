# [59405] 상위 n개 레코드

```sql
SELECT name
from animal_ins
order by datetime
limit 1;
```
## LIMIT
MySQL의 경우 : NAME 값을 조회하는데 가장 맨 위 행 1개만을 조회하기 위해 LIMIT 구문을 사용해야 한다.
- LIMIT 1 : 맨 위에서부터 1개까지의 정보 조회
- LIMIT 3 : 맨 위에서부터 3개까지의 정보 조회
- LIMIT 2, 6 : 위에서 2번째부터 6번째까지의 정보 조회
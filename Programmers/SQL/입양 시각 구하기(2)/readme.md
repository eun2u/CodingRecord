# [59413] 입양 시각 구하기(2)
## 문제
> 0시부터 23시까지, 각 시간대별로 입양이 몇 건이나 발생했는지 조회하는 SQL문을 작성해주세요. 이때 결과는 시간대 순으로 정렬해야 합니다.

## 사용자 정의 변수 사용
``` sql
SET @start := 15, @finish := 20;
SELECT * FROM employee WHERE id BETWEEN @start AND @finish;
```
- :=은 비교 연산자 =과 혼동을 피하기 위한의 대입 연산입니다.
</br>
----
</br>

```sql
set @hour:=-1;

select (@hour:=@hour+1) hour,
(select count(*) from animal_outs where hour(datetime)=@hour) count
from animal_outs
where @hour<23;
```
- SELECT (@hour := @hour +1) 은 @hour의 값에 1씩 증가시키면서 SELECT 문 전체를 실행하게 됩니다.
- WHERE @hour < 23일 때까지, @hour 값이 계속 + 1씩 증가합니다.

## 틀린 SQL
```sql
SELECT hour(datetime) hour , count(*) count
from animal_outs
where hour(datetime)>=0 and
hour(datetime)<=23
group by hour(datetime)
order by hour(datetime);
```
- 이렇게 되면 존재하지 않는 hour(datetime) 의 결과는 나오지 않는다. 존재하지 않는 hour(datetime)은 0을 출력해야 한다.

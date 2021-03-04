# [59049] 중성화 여부 파악하기
## 문제
> 보호소의 동물이 중성화되었는지 아닌지 파악하려 합니다. 중성화된 동물은 SEX_UPON_INTAKE 컬럼에 'Neutered' 또는 'Spayed'라는 단어가 들어있습니다. 동물의 아이디와 이름, 중성화 여부를 아이디 순으로 조회하는 SQL문을 작성해주세요. 이때 중성화가 되어있다면 'O', 아니라면 'X'라고 표시해주세요.


```sql
SELECT animal_id, name, 
case 
when sex_upon_intake like 'Neutered%' or sex_upon_intake like 'Spayed%'
then 'O' 
else 'X'
end as '중성화'
from animal_ins
order by animal_id;
```

## CASE ~ WHEN ~ THEN ~ ELSE ~ END
CASE 구문은 삼항연산자와 비슷하다. 
WHEN 절에 조건을 넣고
THEN 절에는 참일 경우 출력 내용
ELSE 절에는 거짓일 경우 출력 내용을 입력하시면 됩니다.
마지막에는 END로 닫아주시면 됩니다.
# [59045] 보호소에서 중성화한 동물
## 문제
> 보호소에서 중성화 수술을 거친 동물 정보를 알아보려 합니다. 보호소에 들어올 당시에는 중성화1되지 않았지만, 보호소를 나갈 당시에는 중성화된 동물의 아이디와 생물 종, 이름을 조회하는 아이디 순으로 조회하는 SQL 문을 작성해주세요.

```sql
select ins.animal_id, ins.animal_type, ins.name
from animal_ins ins join animal_outs outs
on ins.animal_id=outs.animal_id
where sex_upon_intake like 'Intact%'
and (sex_upon_outcome like 'Spayed%' 
     or sex_upon_outcome like 'Neutered%')
order by ins.animal_id;

```

## LIKE
'-' : 글자숫자를 정해줌(EX 컬럼명 LIKE '홍_동')
'%' : 글자숫자를 정해주지않음(EX 컬럼명 LIKE '홍%')
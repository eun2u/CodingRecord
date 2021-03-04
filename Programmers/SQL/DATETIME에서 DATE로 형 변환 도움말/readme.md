# [59414] DATETIME에서 DATE로 형 변환
## 문제
> ANIMAL_INS 테이블에 등록된 모든 레코드에 대해, 각 동물의 아이디와 이름, 들어온 날짜1를 조회하는 SQL문을 작성해주세요. 이때 결과는 아이디 순으로 조회해야 합니다.

```sql
SELECT animal_id, name, date_format(datetime,'%Y-%m-%d')
from animal_ins
order by animal_id;

```

## DATE_FORMAT
DATE_FORMAT(날짜 , 형식) : 날짜를 지정한 형식으로 출력

<img src="https://user-images.githubusercontent.com/44988609/109954033-2bad3b80-7d24-11eb-9d30-0257aed0faa0.png" width="40%">
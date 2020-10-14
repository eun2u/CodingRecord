N*H 로 풀면 제한 시간 내에 풀 수가 없어서, 시간 초과가 뜬다

시간 초과를 어떻게 해결? ⇒ Binary Search

lower_bound, upper_bound를 사용하자!

lower_bound는 일종의 이분 탐색으로, target으로 하는 값보다 큰 가장 작은 정수 위치를 반환함.

## Lower Bound 와 Upper Bound
Lower Bound와 Upper Bound는 일종의 이분 탐색에서 파생된 것으로,

이분 탐색이 '원하는 값 k를 찾는 과정' 이라면

Lower Bound는 **'원하는 값 k 이상이 처음 나오는 위치를 찾는 과정'** 이며,

Upper Bound는 **'원하는 값 k를 초과한 값이 처음 나오는 위치를 찾는 과정'**이다.
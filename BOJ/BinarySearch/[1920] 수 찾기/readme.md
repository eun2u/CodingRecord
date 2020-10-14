### 가장 기본적인 이진탐색 알고리즘

```cpp
int binarySearch(int target){

    int low=0;
    int high=arr.size()-1;
    
    while(low<=high){
        int mid=(low+high)/2;

        if(target < arr[mid]){
            high=mid-1;
            continue;
        }
        else if(arr[mid] < target){
            low=mid+1;
            continue;
        }
        else return 1;
    }
    return 0;
}
```
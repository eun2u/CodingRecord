//1920. 수 찾기

#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
vector<int> arr;

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
int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,var;

    cin>>n;
    arr.resize(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];

    sort(arr.begin(), arr.end());

    cin>>m;
    for(int i=0;i<m;i++){
        cin>>var;
        cout<<binarySearch(var)<<'\n';
    }
    return 0;
}
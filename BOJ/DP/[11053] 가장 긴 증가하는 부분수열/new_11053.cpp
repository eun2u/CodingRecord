//[11053] 가장 긴 증가하는 부분수열 1
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int N,result=1;
int arr[1001];
int main(){
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>arr[i];
    
    vector<int> dp;
    dp.resize(N+1,1);
    for(int i=1;i<N;i++){
        for(int j=0;j<i;j++){
            if(arr[i] > arr[j]){
                dp[i]=max(dp[i],dp[j]+1);
                result=max(result,dp[i]);
            }
        }
    }

    cout<<result<<'\n';

    return 0;
}
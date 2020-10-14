//2805. 나무자르기

#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>

using namespace std;
long long n,m;
vector<long long> wood;
long long maxwood;

long long calculSum(long long mid){
    long long ret=0;

    for(int i=0;i<n;i++)
        if(wood[i]>mid)
          ret+=wood[i]-mid;

    return ret;
}
long long findMaxLength(){

    long long result=0;
    long long high=maxwood;
    long long low=0;

    while(low<=high){
        long long mid=(low+high)/2;

        long long key= calculSum(mid);
        if(key<m){
            result=mid-1;
            high=mid-1;
        }
        else if(key>m)
            low= mid+1;
        else return mid;
        
    }
    return result;
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>m;
    wood.resize(n);

    for(int i=0;i<n;i++){
        cin>>wood[i];
        maxwood=max(maxwood,wood[i]);
    }
    cout<<findMaxLength()<<'\n';
}
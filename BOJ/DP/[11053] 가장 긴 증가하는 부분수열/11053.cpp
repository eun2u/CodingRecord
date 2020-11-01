//[11053] 가장 긴 증가하는 부분수열 1
#include <iostream>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int N,result=1;
vector<pair<int,int> > arr;
vector<int> cnt;
int main(){
    cin>>N;
    int num;
    for(int i=0;i<N;i++){
        cin>>num;
        arr.push_back(make_pair(num,i));
    }
    cnt.resize(N+1,1);
    
    for(int i=0;i<N-1;i++){
        int target=arr[i].first;
        int idx=arr[i].second;
        
        for(int next=0;next<N;next++){
            if(arr[next].first > target && arr[next].second>idx){
                cnt[next]=max(cnt[next],cnt[i]+1);
                result=max(result,cnt[next]);
            }
        }  
    }

    cout<<result<<'\n';

    return 0;
}
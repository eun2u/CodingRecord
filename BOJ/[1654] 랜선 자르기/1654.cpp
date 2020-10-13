//1654. 랜선 자르기

#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>

using namespace std;
vector<long long> wires;
long long longest;
int k,n;

bool cuttedWires(int mid){

    long long sum=0;

    for(int i=0;i<k;i++)
        sum+=wires[i]/mid;
    
    if(sum>=n)    return true;
    else return false;
}
long long findMaxLength(){
    long long low=1;
    long long high=longest;
    long long result=0;

    while(low<=high){
        long long mid=(low+high)/2;

        if(cuttedWires(mid)){
            result=mid;
            low=mid+1;
        }
        else
            high=mid-1;
    }

    return result;
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>k>>n;
    wires.resize(k);
    for(int i=0;i<k;i++){
        cin>>wires[i];
        longest=max(longest,wires[i]);
    }
    
    cout<<findMaxLength()<<'\n';

    return 0;
}
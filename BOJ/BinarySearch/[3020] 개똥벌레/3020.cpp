//3020. 개똥벌레

#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>

using namespace std;
int n,h;
vector<int> upper; //짝수
vector<int> lower; //홀수
int section;

int calculBarriors(){
    int minRet=987654321;

    for(int i=1;i<=h;i++){
        //i이상이 처음 나오는 위치 반환
        int ustart=lower_bound(upper.begin(),upper.end(),i)-upper.begin();
        int cnt=n/2-ustart;
        //i를 초과한 값이 처음 나오는 위치 반환
        int bstart=upper_bound(lower.begin(),lower.end(),h-i)-lower.begin();
        cnt+=n/2-bstart;

        if(minRet==cnt)
            section++;

        if(minRet > cnt){
            section=1;
            minRet=cnt;
        }
    }
    return minRet;
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>h;
    upper.resize(n/2);
    lower.resize(n/2);

    for(int i=0;i<n/2;i++)
        cin>>lower[i]>>upper[i];
        
    sort(upper.begin(), upper.end());
    sort(lower.begin(), lower.end());

    int result= calculBarriors();
    cout<<result<<" " << section<<'\n';

    return 0;
}

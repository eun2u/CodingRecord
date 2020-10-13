//
//  main.cpp
//  14501. 퇴사

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <utility>

using namespace std;
int n;
pair<int,int> work[17]; //N (1 ≤ N ≤ 15)
int profit[17];

int maxProfit(){
    int ret=0;
    
    for(int i=1;i<=n+1;i++){
        int nt=work[i].first;
        int np=work[i].second+profit[i];
        
        if(i+nt > n+1) continue; //N+1일이 넘어가는 경우
        int maxP=max(profit[i+nt],np);
        profit[i+nt]=maxP;
        
        for(int j=i+nt;j<=n+1;j++)
            if(maxP>profit[j])
                profit[j]=maxP;
        
        ret=max(ret,maxP);
    }
    
    return ret;
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n;
    
    for(int i=1;i<=n;i++)
        cin>>work[i].first>>work[i].second;
    
    int result=maxProfit();
    cout<<result<<endl;
    return 0;
}

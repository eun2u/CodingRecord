#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long calculPeople(long long mid,vector<int> times){
    long long ret=0;
    for(int time:times)
        ret+=mid/time;
    
    return ret;
}
long long solution(int n, vector<int> times) {
    sort(times.begin(),times.end());
    long long low=1, high= (long long)times.back()*n;
    long long answer=high;
    
    while(low<=high){
        long long mid=(low+high)/2;
        long long peoples=calculPeople(mid,times);
    
        if(peoples >=n){
            if(mid < answer) 
                answer=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    
    return answer;
}
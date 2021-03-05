#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int,vector<int>,greater<int> > q(scoville.begin(), scoville.end());
    

    while(q.size()>=2){
        if(q.top()>=K)
            return answer;
        
        int s1=q.top();
        q.pop();
        int s2=q.top();
        q.pop();
        
        q.push(s1+s2*2);
        answer++;
    }
    
    if(q.top()>=K) return answer;
    else    return -1;
}
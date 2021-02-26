#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
        
    int answer = 0;
    int csize=citations.size();

    for(int h=1;h<=csize;h++){
        int cnt=0;
        for(int i=0;i<csize;i++){
            if(citations[i] >=h) 
                cnt++;
        }
        
        if(cnt>=h)
            answer=max(answer,h);
        
    }
    return answer;
}
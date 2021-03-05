#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector<int> v;
    
    for(string op:operations){
        if(op[0]=='I')
            v.push_back(stoi(op.substr(2)));
        else if(op=="D 1"){ //최대값 삭제
            if(v.empty()) continue;
            sort(v.begin(), v.end());
            v.pop_back();
        }
        else if(op=="D -1"){ //최소값 삭제
            if(v.empty()) continue;
            sort(v.begin(), v.end(),greater<int>());
            v.pop_back();
        }
    }
    if(v.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        sort(v.begin(), v.end());
        answer.push_back(v[v.size()-1]);
        answer.push_back(v[0]);
    }

    return answer;
}
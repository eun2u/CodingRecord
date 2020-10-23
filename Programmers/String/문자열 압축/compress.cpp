#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int compress(int unit, string s){
    int n=s.size();
    string ret="";
    
    for(int i=0;i<n;){
        if(i+unit >= n){
            ret+=s.substr(i);
            break;
        }
        string prev=s.substr(i,unit);
        int cnt=1;
        while(i+unit+unit-1 < n){
            string next=s.substr(i+unit, unit);
            if(prev.compare(next)==0){
                cnt++;
                i=i+unit;
            }
            else break;
        }
        if(cnt>1){
            ret+=to_string(cnt)+prev;
            i+=unit;
        }
        else {
            ret+=prev;
            i+=unit;
        }
    }
    
    return ret.size();
}
int solution(string s) {
    int answer = 987654321;
    int n=s.size();
    if(n==1) return 1;
    
    for(int i=1;i<=n/2;i++){
        int ret=compress(i,s);
        answer=min(answer,ret);
    }
    return answer;
}
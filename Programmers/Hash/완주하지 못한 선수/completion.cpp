#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    //string answer = "";
    unordered_map<string, int> pCnt;
    
    for(string elem: participant)
        ++pCnt[elem];
    
    for(string elem: completion)
        --pCnt[elem];
    
    for(auto elem: pCnt)
        if(elem.second>0)
            return elem.first;
}
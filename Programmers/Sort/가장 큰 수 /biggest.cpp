#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool numcmp(string a, string b){
    return a+b >b+a;  
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> snum;
    for(int num: numbers)
        snum.push_back(to_string(num));    
    
    
    sort(snum.begin(), snum.end(), numcmp);
    for(string s:snum)
        answer+=s;
    if(answer[0]=='0') return "0";
    return answer;
}
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b){
    int alen=a.size();
    int blen=b.size();
    int idx=0;
    if(alen==blen)  return a>b;
    else if(alen<blen){
        while(idx<alen){
            if(a[idx]==b[idx]){
                idx++;
                continue;
            }
            else 
                return a[idx]>b[idx];
        }
        return a[idx-1] > b[idx];
    
    }
    else{ 
        while(idx<blen){
            if(a[idx]==b[idx]){
                idx++;
                continue;
            }
            else 
                return a[idx]>b[idx];
        }
        return a[idx] > b[idx-1];
    }
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> snum;
    for(int num : numbers){
        snum.push_back(to_string(num));    
    }
    
    sort(snum.begin(), snum.end(), cmp);
    for(string s : snum){
        answer+=s;
    }
    
    return answer;
}
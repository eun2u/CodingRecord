#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> cmap;
    
    for(auto cloth: clothes)
        cmap[cloth[1]]+=1;
    
    for(auto it=cmap.begin();it!=cmap.end();it++){
        answer*=it->second+1;
    }
    
    return answer-1;
}
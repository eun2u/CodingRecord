#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int> > commands) {
    vector<int> answer;
    vector<int> newarr;
    for(int i=0;i<commands.size();i++){
        newarr.clear();
        newarr=array;
        
        sort(newarr.begin()+commands[i][0]-1, newarr.begin()+commands[i][1]);
        answer.push_back(newarr[commands[i][0]+commands[i][2]-2]);
    }
    
    return answer;
}
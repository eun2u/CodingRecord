#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int solve(int idx,vector<int> answers){
    int ret=0;
    if(idx==0){
        int rule[5]={1,2,3,4,5};
        for(int i=0;i<answers.size();i++)
            if(answers[i] == rule[i%5])
                ret++;
    }
    else if(idx==1){
        int rule[8]={2,1,2,3,2,4,2,5};
        for(int i=0;i<answers.size();i++)
            if(answers[i] == rule[i%8])
                ret++;
    }
    else if(idx==2){
        int rule[10]={3,3,1,1,2,2,4,4,5,5};
        for(int i=0;i<answers.size();i++)
            if(answers[i] == rule[i%10])
                ret++;
    }
    return ret;
}
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int score[3]={0,0,0};
    int maxScore=0;
    
    for(int i=0;i<3;i++)
        score[i]=solve( i, answers);

    for(int i=0;i<3;i++)
        maxScore=max(maxScore,score[i]);
    
    for(int i=0;i<3;i++)
        if(score[i]==maxScore)
            answer.push_back(i+1);
    
    return answer;
}
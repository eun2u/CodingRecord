#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0; 

    vector<int> list(n,1);
    for(int i=0;i<lost.size();i++)
        list[lost[i]-1]--;
    for(int i=0;i<reserve.size();i++)
        list[reserve[i]-1]++;
    
    
    for(int i=0;i<n;i++){
        if(list[i]==0){
            if(i-1>=0 && list[i-1]==2){
                list[i-1]--;
                list[i]++;
            }
            if(i+1<n && list[i+1]==2){
                list[i+1]--;
                list[i]++;
            }
        }
    }
    
    for(int i=0;i<n;i++)
        if(list[i]>0)
            answer++;

    return answer;
}
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int N,result=0;
vector<int> nums;
vector<bool> visitedNum(9999999,false);
bool visited[8];

bool isPrime(vector<int> picked){
    int number=0;
    for(int i=0;i<picked.size();i++)
        number+=picked[i] * pow(10,picked.size()-i-1);
    
    if(visitedNum[number]==true) return false;
    if(number==0 || number==1)  return false;
    
    for(int i=2;i<number;i++)
        if(number%i==0) 
            return false;
    
    visitedNum[number]=true;
    return true;
}
void dfs(vector<int> picked, int toPick,int cnt){
    if(cnt==toPick){
        if(isPrime(picked))
            result++;
        return;
    }
    
    for(int i=0;i<N;i++){
        if(visited[i]) continue;
        
        visited[i]=true;
        picked.push_back(nums[i]);
        dfs(picked,toPick, cnt+1);
        picked.pop_back();
        visited[i]=false;
    }
}
int solution(string numbers) {
    N=numbers.size();
    for(int i=0;i<numbers.size();i++)
        nums.push_back(numbers[i]-'0');
    
    vector<int> picked;
    for(int i=1;i<=nums.size();i++){
        memset(visited,0,sizeof(visited));
        dfs(picked, i,0);
    }
    
    return result;
}
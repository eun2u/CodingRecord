#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int N;
int maxValue=-987654321;
int minValue=987654321;
vector<int> nums; //0 : +, 1: -, 2: *, 3: /
vector<int>  oprtr;
bool visited[100];

int calculate(vector<int> picked){
    int ret=nums[0];
    for(int i=1;i<N;i++){
        if(picked[i-1]==0){
            ret+=nums[i];
        }
        else if(picked[i-1]==1){
            ret-=nums[i];
        }
        else if(picked[i-1]==2){
            ret*=nums[i];
        }
        else if(picked[i-1]==3){
            ret/=nums[i];
        }
    }

    return ret;
}
void findValues(vector<int> picked, int cnt){
    if(cnt==N-1){
        int ret=calculate(picked);
        maxValue=max(maxValue,ret);
        minValue=min(minValue,ret);
        return;
    }

    for(int i=0;i<oprtr.size();i++){
        if(!visited[i]){
            visited[i]=true;
            picked.push_back(oprtr[i]);
            findValues(picked,cnt+1);
            visited[i]=false;
            picked.pop_back();
        }
    }
        
}
int main(){
    cin>>N;
    int val;
    for(int i=0;i<N;i++){
        cin>>val;
        nums.push_back(val);
    }

    for(int i=0;i<4;i++){
        cin>>val;
        for(int j=0;j<val;j++)
            oprtr.push_back(i);
    }
    memset(visited,false,sizeof(visited));
    vector<int> picked;
    findValues(picked,0);

    cout<<maxValue<<'\n';
    cout<<minValue<<'\n';

    return 0;
}
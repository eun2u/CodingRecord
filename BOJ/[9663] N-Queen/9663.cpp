//
//  9663. N-Queen

#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstring>

using namespace std;
int n;// 1 ≤ N < 15
vector<pair<int,int>> queens;
int result=0;

bool canGo(int y, int x){

    for(int i=0;i<queens.size();i++){
        int qy=queens[i].first;
        int qx=queens[i].second;
        
        if(qy==y || qx==x)
            return false;
        
        if(abs(qy-y) == abs(qx-x))
            return false;
    }
    
    return true;
}
void nQueen(int curY, int picked){
    
    if(picked==n) {result++; return;}
    
    for(int j=0;j<n;j++){
        if(canGo(curY,j)){
            queens.push_back({curY,j});
            nQueen(curY+1,picked+1);
            queens.pop_back();
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n;
    
    nQueen(0,0);
    cout<<result<<endl;
    return 0;
}

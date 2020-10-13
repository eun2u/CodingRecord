#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
int n,m;
int result;

bool checkSmaller(queue< pair<int,int> > priority){//더 큰게 있으면 false, 그렇지 않으면 true
    
    if(priority.empty()) return false;

    queue< pair<int,int> > copy=priority;
    pair<int,int> here=copy.front();
    copy.pop();
    for(int i=1;i<priority.size();i++){
        pair<int,int> there=copy.front();
        copy.pop();
        if(here.second < there.second)
            return false;
    }

    return true;
}
void printerQueue(queue< pair<int,int> > priority){
    
    while(1){
        if(priority.empty()) return;
        pair<int,int> here=priority.front();

        if(checkSmaller(priority)){
            if(here.first==m) return;  

            priority.pop();
            result++;       
        }
        else{
            priority.pop();
            priority.push(here);   
        }
    }
    
}
int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc,data;
    cin>>tc;

    for(int i=0;i<tc;i++){
        result=1;
        queue< pair<int,int> > priority;//첫번째는 num, 두번째는 중요도

        cin>>n>>m;        
        for(int j=0;j<n;j++){
            cin>>data;
            priority.push(make_pair(j,data));
        }

        printerQueue(priority);
        cout<<result<<'\n';
    }

    return 0;
}
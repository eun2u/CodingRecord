
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int main(){

    int N;
    cin>>N;
    vector<pair<int,int> > meeting(N);

    for(int i=0;i<N;i++)
        cin>>meeting[i].second>>meeting[i].first; //시작을 second, 끝을 first
    
    sort(meeting.begin(),meeting.end()); //끝을 기준으로 sort
    int result=1;
    int cur=meeting[0].first;
    for(int i=1;i<N;i++){
        if(meeting[i].second >= cur){
            cur=meeting[i].first;
            result++;
        }
    }
    cout<<result<<'\n';

    return 0;
}
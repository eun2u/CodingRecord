#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <string>
using namespace std;
int N,M;
int main(){
    cin>>N>>M;
    map<string,int> heardseen;
    vector<string> answer;
    int cnt=0;

    string s;
    for(int i=0;i<N;i++){
        cin>>s;
        heardseen[s]++;
    }
    for(int i=0;i<M;i++){
        cin>>s;
        heardseen[s]--;
    }
    for(auto iter=heardseen.begin(); iter!=heardseen.end();iter++){
        if(iter->second==0){
            answer.push_back(iter->first);
            cnt++;
        }
    }
    cout<<cnt<<'\n';
    for(string elem: answer)
        cout<<elem<<'\n';

    return 0;
}
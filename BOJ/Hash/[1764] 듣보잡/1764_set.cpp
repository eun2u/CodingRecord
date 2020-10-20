#include <iostream>
#include <set>
#include <string>
using namespace std;

int main(){
    int N,M;
    string s;
    set<string> heard;
    set<string> answer;

    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>s;
        heard.insert(s);
    }
    for(int i=0;i<M;i++){
        cin>>s;
        auto iter=heard.find(s);
        if(iter!=heard.end()) answer.insert(s);
    }
    cout<<answer.size()<<'\n';
    for(auto elem: answer)
        cout<<elem<<'\n';


    return 0;
}
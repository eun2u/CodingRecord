#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
bool cmp(pair<string, int> a, pair<string, int> b){return a.second > b.second;}
bool cmp2(pair<int,int> a, pair<int,int> b){
    if(a.second==b.second) return a.first<b.first;
    else return a.second>b.second;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string,int> genreCnt;
    map<string,vector<pair<int,int> > > playlist; //genre, 고유번호, 재생수

    for(int i=0;i<genres.size();i++){
        genreCnt[genres[i]]+=plays[i];
        playlist[genres[i]].push_back(make_pair(i,plays[i]));
    }
    vector< pair<string,int> > vec (genreCnt.begin(), genreCnt.end() );
    sort(vec.begin(), vec.end(), cmp);

    for(auto &elem: playlist) //reference 안 붙이면 값 안바뀜
        sort(elem.second.begin(), elem.second.end(), cmp2);

    for(auto elem: vec){ 
        string name=elem.first;

        for(int i=0;i<playlist[name].size();i++){
            if(i==2) break;
            answer.push_back(playlist[name][i].first);
        }
    }
    return answer;
}
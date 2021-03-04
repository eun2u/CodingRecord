#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<string> answer;
vector<string> temp;
bool done=false;
bool discoveredAll(vector<bool> visited){
    for(int i=0;i<visited.size();i++)
        if(!visited[i]) 
            return false;
    
    return true;
}
void dfs(string start,vector<vector<string> > tickets, vector<bool> visited,int cnt){

    if(cnt==tickets.size()){
        if(discoveredAll(visited) && !done) {
            answer=temp;
            done =true;
        }
        return;
    }
    
    for(int i=0;i<tickets.size();i++){
        if(tickets[i][0]==start && !visited[i]){
            visited[i]=true;
            temp.push_back(tickets[i][1]);
            dfs(tickets[i][1], tickets, visited,cnt+1);
            visited[i]=false;
            temp.pop_back();
        }
    }
    
}
vector<string> solution(vector<vector<string> > tickets) {
    vector<bool> visited(tickets.size(),false);
    sort(tickets.begin(), tickets.end());
    temp.push_back("ICN");
    dfs("ICN",tickets,visited,0);
    
    return answer;
}
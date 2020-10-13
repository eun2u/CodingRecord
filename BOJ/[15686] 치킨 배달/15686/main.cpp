//
//  main.cpp
//  15686. 치킨 배달
//


#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <utility>
#include <algorithm>

using namespace std;
int n,m;
int city[50][50];
vector<pair<int,int>> chicken;
vector<pair<int,int>> house;
vector<vector<int>> combination;

int cityChickenDist(vector<int> combination){
    
    int ret=0;
    
    for(int i=0;i<house.size();i++){
        pair<int,int> hereH=house[i];
        
        int minD=987654321;
        for(int j=0;j<combination.size();j++){//picked.size()는 m
            pair<int,int> hereC = chicken[combination[j]];
            int distY=abs(hereH.first-hereC.first);
            int distX=abs(hereH.second-hereC.second);
            //집에서 가장 가까운 치킨집 거리
            minD=min(minD,distX+distY);
        }
        ret+=minD;
    }
    return ret;
}
void pickChicken(int n, vector<int>&picked, int toPick){
    
    if(toPick==0)  {
        combination.push_back(picked);
        return;
    }

    int smallest=picked.empty() ? 0 :picked.back()+1;

    for(int next=smallest;next<n;next++){
        picked.push_back(next);
        pickChicken(n,picked,toPick-1);
        picked.pop_back();
    }
}
int main() {
    
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>m;
    int data;
    
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            cin>>data;
            if(data==1)
                house.push_back({i,j});
            else if(data==2)
                chicken.push_back({i,j});
            
            city[i][j]=data;
        }
    
    vector<int> picked;
    pickChicken(int(chicken.size()),picked,m);
  
    
    int ret=987654321;
    for(int i=0;i<combination.size();i++)
        ret=min(ret,cityChickenDist(combination[i]));
    
    cout<<ret<<endl;
    return 0;
}

//
//  main.cpp
//  ShortestPath
//
//  Created by 한은주 on 2020/07/27.
//  Copyright © 2020 한은주. All rights reserved.
//
//1238. 파티

#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX_V=1001;
const int INF= 999999;
int V,m,x;
int adj[MAX_V][MAX_V];

void floyd2() {
    for (int i = 1; i <= V; i++) adj[i][i] = 0;
    for(int k=1;k<=V;k++)
        for(int i=1;i<=V;i++)
            for(int j=1;j<=V;j++)
                if (adj[i][j] > adj[i][k] + adj[k][j]) {
                    adj[i][j] = adj[i][k] + adj[k][j];
                }

}
void printResult(int x){
    int maxResult=0;
    
    for(int i=1;i<=V;i++)
        maxResult=max(maxResult,adj[i][x]+adj[x][i]);
    
    cout<< maxResult<<endl;
    
}
int main() {

    int a,b,c;
    
    cin>> V>>m>>x;
    
    for(int i=1;i<=V;i++){
        for(int j=1;j<=V;j++){
            adj[i][j]=INF;
        }
    }
    
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        adj[a][b]=c;
    }
    floyd2();
    
    
    printResult(x);
}

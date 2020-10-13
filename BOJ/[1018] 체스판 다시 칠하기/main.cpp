//
//  main.cpp
//  1018
//
//  Created by 한은주 on 2020/08/06.
//  Copyright © 2020 한은주. All rights reserved.
//

#include <iostream>
#include <utility>
#include <string>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
const int BLACK=0;
const int WHITE=1;
int m,n;
int board[50][50];
int chess1[8][8];
int chess2[8][8];

void makeChess(){
    
    int cnt;
    for(int i=0;i<8;i++){
        cnt=0;
        if(i%2==1){ //홀수 줄일때
            for(int j=0;j<8;j++){
                cnt++;
                if(cnt%2==0) chess1[i][j]=BLACK;
                else chess1[i][j]=WHITE;
            }
        }
        else if(i%2==0){ //짝수 줄일때
            for(int j=0;j<8;j++){
                cnt++;
                if(cnt%2==0) chess1[i][j]=WHITE;
                else chess1[i][j]=BLACK;
            }
        }
    }
    
    for(int i=0;i<8;i++){
        cnt=0;
        if(i%2==1){ //홀수 줄일때
            for(int j=0;j<8;j++){
                cnt++;
                if(cnt%2==0) chess2[i][j]=WHITE;
                else chess2[i][j]=BLACK;
            }
        }
        else if(i%2==0){ //짝수 줄일때
            for(int j=0;j<8;j++){
                cnt++;
                if(cnt%2==0) chess2[i][j]=BLACK;
                else chess2[i][j]=WHITE;
            }
        }
    }
}
int paintChess(int startY,int startX){
    
    int cnt1=0,cnt2=0;
    
    for(int i=startY;i<startY+8;i++){
        for(int j=startX;j<startX+8;j++){
            if(board[i][j]!=chess1[i-startY][j-startX])
                cnt1++;
            if(board[i][j]!=chess2[i-startY][j-startX])
                cnt2++;
        }
    }
    
    return min(cnt1,cnt2);
}
void makeGraph(vector<string> input){
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
        if(input[i].at(j)=='W')
             board[i][j]=WHITE;
        else if(input[i].at(j)=='B')
             board[i][j]=BLACK;
    }
}
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    string s;
    vector<string> input;
    
    cin>>m>>n;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++){
            cin>>s;
            input.push_back(s);
        }
    makeGraph(input);
    makeChess();
    
    int result=987654321;
    for(int i=0;i<=m-8;i++)
        for(int j=0;j<=n-8;j++)
            result=min(result,paintChess(i,j));
    
    cout<<result<<endl;
    return 0;
}

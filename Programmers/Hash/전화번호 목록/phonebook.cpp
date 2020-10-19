#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end());
    
    for(int i=0;i<phone_book.size();i++){
        for(int j=0;j<phone_book.size();j++){
            if(i!=j && phone_book[i].find(phone_book[j])==0){
                return false;
            }
        }   
    }
    return true;
}
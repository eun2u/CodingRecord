#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int makeArray(int num){

    int arr[1000001];
    arr[1]=0;
    arr[2]=1;
    arr[3]=1;

    for(int i=4;i<=num;i++){
        if(i%3==0)
            arr[i]=min(arr[i/3]+1, arr[i-1]+1);
        else if(i%2==0)
            arr[i]=min(arr[i/2]+1,arr[i-1]+1);
        else 
            arr[i]=arr[i-1]+1;
    }
    return arr[num];
}
int main(){

    int input;
    cin>>input;
    cout << makeArray(input)<<endl;

    return 0;
}
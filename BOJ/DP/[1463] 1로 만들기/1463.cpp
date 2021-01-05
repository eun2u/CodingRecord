#include <iostream>
#include <algorithm>
using namespace std;
int N;
int main(){
    cin>>N;
    int arr[1000001];

    arr[1]=0;
    for(int i=2;i<=N;i++){
        int minVal=987654321;
        if(i%3==0)
            minVal=min(minVal,arr[i/3]+1);
        if(i%2==0)
            minVal=min(minVal,arr[i/2]+1);
        
        minVal=min(minVal,arr[i-1]+1);

        arr[i]=minVal;
    }
    cout<<arr[N]<<'\n';
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;
vector<int> arr;
int N,B,C;

long long calculate(){
    long long ret=0;
    for(int i=0;i<N;i++){
        if(arr[i]>=B)
            arr[i]-=B;
        else 
            arr[i]=0;

        if(arr[i]%C!=0)
            ret+=(arr[i]/C )+1;
        else
            ret+=arr[i]/C;
    }
    return ret+N;
}
int main(){
    cin>>N;
    arr.resize(N);
    for(int i=0;i<N;i++)
        cin>>arr[i];
    
    cin>>B>>C;

    cout<< calculate() <<'\n';

}
//2343.기타레슨

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;
int n,m,tot;
vector<int> blueray;

bool canRecord(int mid){
    int sum=0;
    int cnt=1;

    for(int i=0;i<n;i++){
        if(blueray[i]>mid)
            return false;
        
        sum+=blueray[i];
        if(sum>mid){
            sum=blueray[i];
            cnt++;
        }
    }

    if(m>=cnt)  
        return true;
    else return false;
}
int findMinBlueray(){

    int low=0;
    int high=tot;
    int result;

    while(low<=high){
        int mid=(low+high)/2;

        if(canRecord(mid)){
            result=mid;
            high=mid-1; 
        }
        else low=mid+1;
    }
    return result;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;
    blueray.resize(n);

    for(int i=0;i<n;i++){
        cin>>blueray[i];
        tot+=blueray[i];
    }

    cout<< findMinBlueray()<<'\n';
    
    return 0;
}

#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int n;
int arr[1001];
int dp[1001];
int solve(int pos){
    int& cache = dp[pos+1];
    if(cache!=-1) return cache;
    
    int ret=0;
    for(int i=pos+1; i<n;i++) {
        if(pos==-1 || arr[pos] > arr[i]) {
            ret=max(ret,1+solve(i));
        }
    }
    return cache=ret;
}
int main(){
    memset(dp,-1,sizeof(dp));
    cin >> n;
    for(int i=0; i<n;i++){
        cin >> arr[i];
    }
    cout << solve(-1);
    
    
    
    return 0;
}
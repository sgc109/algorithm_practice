#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <queue>

#define REP(i,a,b) for(int i=a;i<b;++i)
#define FOR(i,n) REP(i,0,n)
#define LONG long long
#define INF 0x3a3a3a3a

using namespace std;

struct RMQ {
    int n;
    vector<int> rangeMin;
    RMQ(vector<int> &arr){
        n = arr.size();
        rangeMin.resize(4*n);
        init(arr,0,n-1,1);
    }
    int init(vector<int> &arr, int nodeLeft, int nodeRight, int node) {
        if(nodeLeft == nodeRight) return rangeMin[node] = arr[nodeLeft];
        
        int nodeMid = (nodeLeft + nodeRight) / 2;
        return rangeMin[node] = min(init(arr, nodeLeft, nodeMid, 2*node), init(arr, nodeMid+1, nodeRight, 2*node+1));
    }
    int query(int left, int right, int nodeLeft, int nodeRight, int node) {
        if(right < nodeLeft || left > nodeRight) return INF;
        if(left <= nodeLeft && nodeRight <= right) return rangeMin[node];
        
        int nodeMid = (nodeLeft + nodeRight) / 2;
        
        return min(query(left, right, nodeLeft, nodeMid, 2*node), query(left, right, nodeMid+1, nodeRight, 2*node+1));
    }
    int query(int left, int right) {
        return query(left, right, 0, n-1, 1);
    }
};

int main() {
    
    vector<int> a(7);
    FOR(i,7)
        a[i]=i;
    
    RMQ rmq(a);
    
    
    return 0;
}
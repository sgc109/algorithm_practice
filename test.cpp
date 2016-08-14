#define REP(i,a,b) for(int i = a;i < b; ++i)
#define FOR(i,n) REP(i,0,n)
#define LONG long long
#define INFL 0x7fffffffffffffff
  
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
  
using namespace std;
 
struct RangeTree {
  int n;
  vector<int> rangeMax;
  RangeTree(vector<int> &v) {
      n = v.size();
      rangeMax.resize(4*n);
      init(0,n-1,1,v);
  }
  int init(int left, int right, int node, vector<int> &v) {
      if(left==right) return rangeMax[node] = v[left];
       
      int mid = (left+right)/2;
      return rangeMax[node] = max(init(left,mid,2*node,v),init(mid+1,right,2*node+1,v));
  }
  int RMQ(int nodeLeft, int nodeRight, int left, int right, int node) {
      if(nodeLeft > right || nodeRight < left) return -1987564321;
      if(left <= nodeLeft && nodeRight <= right) return rangeMax[node];
      int mid = (nodeLeft+nodeRight)/2;
      return max(RMQ(nodeLeft,mid,left,right,2*node),RMQ(mid+1,nodeRight,left,right,2*node+1));
  }
  int RMQ(int left, int right) {
      return RMQ(0, n-1, left, right, 1);
  }
};
 
int main() {
    vector<int> ma;
    vector<int> mi;
    int n,m;
    scanf("%d%d",&n,&m);
    FOR(i,n) {
        int tmp;
        scanf("%d",&tmp);
        ma.push_back(tmp);
        mi.push_back(-tmp);
    }
    RangeTree maxTree(ma);
    RangeTree minTree(mi);
     
    FOR(i,m) {
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d %d\n",-minTree.RMQ(a-1,b-1),maxTree.RMQ(a-1,b-1));
    }
    return 0;
}
#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<string.h>
#include<queue>
#define REP(i,a,b) for(int i=a;i<b;++i)
#define FOR(i,n) REP(i,0,n)
#define LONG long long
#define INF 987654321
using namespace std;

typedef pair<int, int> PairType;
int n;
int cache[100000];
vector<PairType> pair_v;
int lis(int start){ //O(n^2);
    if(cache[start] != -1) return cache[start];
    int ret = 1;
    int front = pair_v[start].second;
    REP(i,start+1,n){
        if(pair_v[i].second >= front) {
            if(cache[i] == -1) cache[i] = lis(i);
            ret = max(ret, 1+cache[i]);
        }
    }
    return ret;
}

int a[100002];
int pos[100002];
int from[100002];

void print(int n){
    if(from[n] == -1) return;
    print(from[n]);
    printf("(%d, %d)\n",pair_v[n-1].first, -pair_v[n-1].second);
}

int lis2(){ // O(nlogn)
    int lower;
    int size = 0;
    from[0] = -1;
    pos[0] = 0;
    REP(i,1,pair_v.size()+1){
        lower = upper_bound(a+1, a+1+size, pair_v[i-1].second) - a;
        if(lower > size) size = lower;
        a[lower] = pair_v[i-1].second;
        pos[lower] = i;
        from[i] = pos[lower-1];
    }
    //print(pos[size]);
    return size;
}

int main() {
    setbuf(stdout,NULL);
    int T;
    scanf("%d",&T);
    FOR(t,T){
        scanf("%d",&n);
        pair_v = vector<PairType>(n);
        memset(cache,-1,sizeof(int)*100000);
        FOR(i,n){
            int x,y;
            scanf("%d%d",&x,&y);
            pair_v[i].first = x;
            pair_v[i].second = -y;
            
        }
        sort(pair_v.begin(),pair_v.end());
        printf("Case #%d\n%d\n",t+1,lis(0)); 
    }
    return 0;
}

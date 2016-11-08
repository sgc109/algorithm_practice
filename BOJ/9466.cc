#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <stack>
#include <cstring>
#include <cstdlib>
#include <string>
#include <unordered_set>
#include <set>
#include <map>
#define REP(i,a,b) for(int i = a; i < b;++i) 
#define FOR(i,n) REP(i,0,n)
#define mp make_pair
#define pb push_back
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
 
using namespace std;
 
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
 
const int INF = 0x3a3a3a3a;
const long long INFL = 0x3a3a3a3a3a3a3a3a;
const int MAX_N = 1000000;
 
int n,m;
vi sccId;
vi findOrder;
int orderCnt, sccCnt;
stack<int> s;
vvi adj;
vvi sccMembers;
 
int scc(int here) {
    int ret = findOrder[here] = orderCnt++;
    s.push(here);
 
    FOR(i,adj[here].size()) {
        int there = adj[here][i];
        if(findOrder[there] == -1) {
            ret = min(ret, scc(there));
        }
        else if(sccId[there] == -1) {
            ret = min(ret, findOrder[there]);
        }
    }
 
    if(ret >= findOrder[here]) {
        int p=-1;
        while(p!=here){
            p=s.top();
            s.pop();
            sccId[p]=sccCnt;
            sccMembers[sccCnt].pb(p);
        }
        ++sccCnt;
    }
}
int main() {
    int t;
    inp1(t);
    while(t--) {
        inp1(n);
        adj = vvi(n,vi());
        findOrder = vi(n+1,-1);
        sccId = vi(n+1,-1);
        sccMembers = vvi(n+1,vi());
        FOR(i,n) {
            int b;
            inp1(b);
            --b;
            adj[i].pb(b);
        }
        sccCnt = orderCnt = 0;
        FOR(i,n) {
            if(findOrder[i] == -1) scc(i);
        }
        int ans=0;
        FOR(i,n) {
            if(sccId[i] != -1 && sccMembers[sccId[i]].size()==1) {
                if(adj[i][0] != i) ++ans;
            }
        }
        printf("%d\n",ans);
 
         
    }
    return 0;
}
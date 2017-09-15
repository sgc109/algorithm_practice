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
// #include <unordered_set>
#include <set>
// #include <map>
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

int start,finish;
int N,K;
vvi capacity, flow;
vvi adj;
int MAX;
 
int MASTER(int x) {
    return 2+x;
}

int TIME(int x){
    return 2+K+x;
}

int SHOES(int x) {
    return 2+K+101+x;
}

int ford() {
    int ret = 0;
    
    while(true) {
        queue<int> q;
        q.push(start);
        vi parent(MAX,-1);
        parent[start] = start;
        while(!q.empty() && parent[finish] == -1) {
            int here = q.front();
            q.pop();
            FOR(i, adj[here].size()) {
            	int there = adj[here][i];
                if(capacity[here][there] - flow[here][there] > 0 && parent[there] == -1) {
                    parent[there] = here;
                    q.push(there);
                }
            }
        }
        
        if(parent[finish] == -1) break;
        
        int maxFlow = INF;
        for(int p = finish; p != parent[p]; p = parent[p]) {
            maxFlow = min(maxFlow, capacity[parent[p]][p] - flow[parent[p]][p]);
        }
        for(int p = finish; p != parent[p]; p = parent[p]) {
            flow[parent[p]][p] += maxFlow;
            flow[p][parent[p]] -= maxFlow;
        }
        ret += maxFlow;
    }
    
    return ret;
}

int main() {
    int T;
    inp1(T);
    FOR(t,T) {
        inp2(N,K);
        start=0;finish=1;
        MAX=2+K+101+N;
        capacity = vvi(MAX,vi(MAX,0));
        flow = vvi(MAX,vi(MAX,0));
        adj = vvi(MAX,vi());
        int allDone = 0;
        FOR(i,N) {
            int a,b,c;
            inp3(a,b,c);
            REP(k,a,b) {
                capacity[TIME(k)][SHOES(i)]=1;
                adj[TIME(k)].pb(SHOES(i));
                adj[SHOES(i)].pb(TIME(k));
            }
            capacity[SHOES(i)][finish] = c;
            adj[SHOES(i)].pb(finish);
            adj[finish].pb(SHOES(i));

            allDone += c;
        }
        FOR(i,K) {
            int a,b;
            inp2(a,b);
            REP(k,a,b) {
                capacity[MASTER(i)][TIME(k)] = 1;
                adj[MASTER(i)].pb(TIME(k));
                adj[TIME(k)].pb(MASTER(i));
            }
            capacity[start][MASTER(i)] = INF;
            adj[start].pb(MASTER(i));
            adj[MASTER(i)].pb(start);
        }
        
        int ans = ford();
        printf("Case #%d\n",t+1);
        if(ans == allDone) printf("1\n");
        else printf("0\n");
    }
    return 0;
}
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

const int MAX_V = 1010;
const int SOURCE = 0;
const int SINK = 1;
int N, M;

int capacity[MAX_V][MAX_V], flow[MAX_V][MAX_V];

int cow(int n) {
    return 2 + n;
}

int house(int n) {
    return 2 + N + n;
}

int networkFlow(int source, int sink) {
    int totalFlow = 0;
    
    while(true) {
        vector<int> parent(2 + N + M, -1);
        
        queue<int> q;
        parent[source] = source;
        q.push(source);
        while(!q.empty() && parent[sink] == -1) {
            int here = q.front();
            q.pop();
            FOR(i,2+N+M) {
                int there = i;
                if(capacity[here][there] - flow[here][there] > 0 && parent[there] == -1) {
                    parent[there] = here;
                    q.push(there);
                }
            }
        }
        
        if(parent[sink] == -1) break;
        
        int minFlow = INF;
        for(int p = sink; parent[p] != p; p = parent[p]) {
            minFlow = min(minFlow, capacity[parent[p]][p] - flow[parent[p]][p]);
        }
        for(int p = sink; parent[p] != p; p = parent[p]) {
            flow[parent[p]][p] += minFlow;
            flow[p][parent[p]] -= minFlow;
        }
        totalFlow += minFlow;
    }
    
    return totalFlow;
}

int main() {
    scanf("%d%d",&N, &M);
    memset(flow,0,sizeof(flow));
    memset(capacity,0,sizeof(capacity));
    FOR(i,N) {
        capacity[SOURCE][cow(i)] = 1;
    }
    
    FOR(i,M) {
        capacity[house(i)][SINK] = 1;
    }
    
    FOR(i,N){
        int n;
        scanf("%d",&n);
        FOR(j,n) {
            int tmp;
            scanf("%d",&tmp);
            --tmp;
            capacity[cow(i)][house(tmp)] = 1;
        }
    }
    
    printf("%d", networkFlow(SOURCE, SINK));
    
    return 0;
}
#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<string.h>
#include<queue>

#define REP(i,a,b) for(int i=a;i<b;++i)
#define FOR(i,n) REP(i,0,n)

using namespace std;

const int MAX_V=100;

int V,E;

vector<int> adj[MAX_V];
int dist[MAX_V];
queue<int> q;

void bfs(int start, vector<int> &path) {
    dist[start] = 0;
    q.push(start);
    while(!q.empty()) {
        int here = q.front();
        path.push_back(here);
        q.pop();
        FOR(i,adj[here].size()) {
            int there = adj[here][i];
            if(dist[there] == -1) {
                dist[there] = dist[here] + 1;
                q.push(there);
            }
        }
    }
}

int main() {
    FOR(i,MAX_V) {
        dist[i] = -1;
    }
    
    scanf("%d%d",&V,&E);
    FOR(i,E) {
        int a,b;
        scanf("%d%d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    vector<int> path;
    bfs(0,path);
    
    FOR(i,path.size()){
        printf("%d ",dist[i]);
    }
    
    return 0;
}
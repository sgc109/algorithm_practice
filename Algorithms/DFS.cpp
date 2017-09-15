#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<string.h>

#define REP(i,a,b) for(int i=a;i<b;++i)
#define FOR(i,n) REP(i,0,n)

using namespace std;

const int MAX_V=100;

int V,E;

vector<int> adj[MAX_V];
int visited[MAX_V];

void dfs(int here, vector<int> &path) {
    visited[here] = 1;
    path.push_back(here);
    FOR(i,adj[here].size()) {
        int there = adj[here][i];
        if(!visited[there]) {
            visited[there] = 1;
            dfs(there,path);
        }
    }    
}

int main() {
    memset(visited,0,MAX_V);
    
    scanf("%d%d",&V,&E);
    FOR(i,E) {
        int a,b;
        scanf("%d%d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    vector<int> path;
    
    FOR(i,V) {
        if(!visited[i]){
            dfs(i,path);
        }
    }
    
    FOR(i,path.size()) {
        printf("%d ",path[i]);
    }
    
    return 0;
}
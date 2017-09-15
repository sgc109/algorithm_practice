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

int V,E;
vector<vector<pair<int,int>>> adj;
vector<int> parent;

vector<int> bellmanFord(int start) {
    vector<int> upper(V,INF);
    
    upper[start] = 0;
    bool updated;
    FOR(i,V){
        updated = false;
        FOR(here,V){
            FOR(j,adj[here].size()){
                int there = adj[here][j].first;
                int cost = adj[here][j].second;
                
                if(upper[there] > upper[here] + cost){
                    upper[there] = upper[here] + cost;
                    parent[there] = here;
                    updated = true;
                }
            }
        }
        if(!updated) break;
    }
    if(updated) upper.clear();
    
    return upper;
}

int main() {
    scanf("%d%d",&V,&E);
    adj = vector<vector<pair<int,int>>>(V);
    parent = vector<int>(V);
    FOR(i,V){
        parent[i] = i;
    }
    FOR(i,E){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        adj[a].push_back(make_pair(b,c));
        adj[b].push_back(make_pair(a,c));
    }
    
    vector<int> minDist;
    minDist = bellmanFord(0);
    
    /*
    FOR(i,V){
        printf("%d ",minDist[i]);
    }
    */
    
    int node = 5;
    vector<int> path;
    while(true){
        path.push_back(node);
        if(node == parent[node]) break;
        node = parent[node];
    }
    
    reverse(path.begin(),path.end());
    
    FOR(i,path.size()){
        printf("%c ",path[i]+'a');
    }
    
    return 0;
}
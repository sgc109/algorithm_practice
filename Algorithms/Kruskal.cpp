#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>
#include<stdio.h>

#define REP(i,a,b) for(int i=a;i<b;++i)
#define FOR(i,n) REP(i,0,n)

using namespace std;

const int MAX_V = 100;

vector<pair<int,int>> adj[MAX_V];
int V,E;

struct UnionFind{
    vector<int> parent, rank;
    
    UnionFind(int n) : parent(n), rank(n,1){
        FOR(i,n) {
            parent[i] = i;
        }
    }
    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void merge(int a, int b){
        a = find(a); b = find(b);
        if(a==b) return;
        if(rank[a] < rank[b]) swap(a,b);
        parent[b] = a;
        if(rank[a]==rank[b]) ++rank[a];
    }
};

int Kruskal(vector<pair<int,int>> &selected) {
    vector<pair<int,pair<int,int>>> edges;
    FOR(u,V) {
        FOR(i,adj[u].size()){
            int v = adj[u][i].first;
            int cost = adj[u][i].second;
            if(u>=v) continue;
            edges.push_back(make_pair(cost,make_pair(u,v)));
        }
    }
    sort(edges.begin(),edges.end());
    
    int ret = 0;
    selected.clear();
    
    UnionFind uf(V);
    FOR(i,edges.size()){
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        if(uf.find(u)==uf.find(v)) continue;
        int cost = edges[i].first;
        ret += cost;
        uf.merge(u,v);
        selected.push_back(make_pair(u,v));
    }
    
    
    return ret;
}

int main(){
    
    cin >> V;
    cin >> E;
    FOR(i,E) {
        int a,b,c;
        cin >> a >> b >> c;
        --a;
        --b;
        adj[a].push_back(make_pair(b,c));
        adj[b].push_back(make_pair(a,c));
    }
    
    vector<pair<int,int>> selected;
    cout << Kruskal(selected);
    
    
    return 0;
}
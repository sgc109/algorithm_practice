#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>
#include<stdio.h>

#define REP(i,a,b) for(int i=a;i<b;++i)
#define FOR(i,n) REP(i,0,n)

const int MAX_V=100;

using namespace std;

struct UnionFind{
    vector<int> parent, rank;
    
    UnionFind(int n) : parent(n), rank(n,1){
        FOR(i,n) {
            parent[i] = i;
        }
        
    }
    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(x);
    }
    void merge(int a, int b){
        a = find(a); b = find(b);
        if(a==b) return;
        if(rank[a] < rank[b]) swap(a,b);
        parent[b] = a;
        if(rank[a]==rank[b]) ++rank[a];
    }
};


int main(){
    UnionFind uf(5);
    uf.merge(1,2);
    uf.merge(3,4);
    uf.merge(3,5);
    uf.merge(4,5);
    uf.merge(1,5);
    FOR(i,5){
        cout << "hi";
        cout << uf.parent[i] << " ";
    }
    
    
    
    return 0;
}
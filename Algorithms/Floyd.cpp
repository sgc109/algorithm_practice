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

vector<vector<int>> adj;
vector<vector<int>> via;


void floyd(){
    FOR(k,V){
        FOR(i,V){
            FOR(j,V){
                if(adj[i][j] > adj[i][k] + adj[k][j]) {
                    adj[i][j] = adj[i][k] + adj[k][j];
                    via[i][j] = k;
                }
            }
        }
    }
}

void calcPath(int u, int v, vector<int> &path) {
    if(via[u][v] == -1) {
        path.push_back(u);
        if(u != v) path.push_back(v);
    }
    else {
        int k = via[u][v];
        calcPath(u,k,path);
        path.pop_back();
        calcPath(k,v,path);
    }
}

int main() {
    scanf("%d%d",&V,&E);
    adj = vector<vector<int>>(V,vector<int>(V,INF));
    via = vector<vector<int>>(V,vector<int>(V,-1));
    FOR(i,V){
        adj[i][i] = 0;
    }
    FOR(i,E){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        adj[a][b] = c;
        adj[b][a] = c;
    }
    
    
    floyd();
    
    vector<int> path;
    calcPath(0,6,path);// calc(u,v,vector) : u 부터 v 까지의 최단경로를 vector에 만들어준다(재귀적으로)
    
    FOR(i,path.size()){
        printf("%c ",path[i]+'a');
    }
    
    return 0;
}
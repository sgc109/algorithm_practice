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

vector<vector<int>> reachable;
vector<vector<int>> adj;

void floyd() {
    FOR(k,V){
        FOR(i,V){
            FOR(j,V){
                reachable[i][j] = reachable[i][j] || (reachable[i][k] && reachable[k][j]);
            }
        }
    }
}

int main() {
    scanf("%d%d",&V,&E);
    adj = vector<vector<int>>(V,vector<int>(V,INF));
    reachable = vector<vector<int>>(V,vector<int>(V,0));
    FOR(i,V){
        reachable[i][i] = 1;
    }
    FOR(i,E){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        --a;--b;
        adj[a][b] = c;
        adj[b][a] = c;
        reachable[a][b] = 1;
        reachable[b][a] = 1;
    }
    
    floyd();
    
    FOR(i,V){
        FOR(j,V){
            printf("%d ",reachable[i][j]);
        }
        printf("\n");
    }
    return 0;
}
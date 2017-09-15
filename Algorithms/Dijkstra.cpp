#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<string.h>
#include<queue>

using namespace std;

#define REP(i,a,b) for(int i=a;i<b;++i)
#define FOR(i,n) REP(i,0,n)
#define LONG long long
#define INF 987654321

const int MAX_V = 100;

priority_queue<pair<int,int>> pq;
vector<pair<int,int>> adj[MAX_V];
int parent[MAX_V];
int dist[MAX_V];

int V,E;

void dijkstra(int start){
    dist[start] = 0;
    pq.push(make_pair(0,start));
    parent[start] = start;
    while(!pq.empty()){
        int curDist = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        
        if(dist[here] < curDist) continue;
        
        FOR(i,adj[here].size()){
            int nextDist = curDist + adj[here][i].second;
            int there = adj[here][i].first;
            
            if(nextDist < dist[there]){            
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist,there));
                parent[there] = here;
            }
        }
    }
}

vector<char> shortestPath(int node, vector<char> &path){
    while(1){
        path.push_back(node+'a');
        if(parent[node] == node) break;
        node = parent[node];
    }
    
    return path;
}

int main() {
    FOR(i,MAX_V){
        parent[i] = i;
        dist[i] = INF;
    }
    
    scanf("%d%d",&V,&E);
    FOR(i,E){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        adj[a].push_back(make_pair(b,c));
        adj[b].push_back(make_pair(a,c));
    }
    
    dijkstra(6);
    
    FOR(i,V) {
        printf("%d ",dist[i]);
    }
    
    /* 특정 노드까지의 최단 경로 출력
    vector<char> path;
    shortestPath(6,path);
    
    reverse(path.begin(),path.end());
    
    FOR(i,path.size()){
        printf("%c ",path[i]);
    }
    */
    
    
    return 0;
}
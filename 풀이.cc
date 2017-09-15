#include <iostream>
#include <map>
#include <vector>
#include <queue>
#define mp make_pair
using namespace std;
int n,m;
struct edge{
    int d,to;
};
vector<edge> adj[600001];
int dist[600001];
map<pair<int,int>,int> MAP;
int last=0;
int getId(int u,int c){
    if(MAP[mp(u,c)]==0){
        adj[u].push_back(edge{1,last});
        adj[last].push_back(edge{0,u});
        MAP[mp(u,c)]=last;
        last++;
    }
    return MAP[mp(u,c)];
}
void addEdge(int u,int v,int c){
    adj[getId(u,c)].push_back(edge{0,getId(v,c)});
    adj[getId(v,c)].push_back(edge{0,getId(u,c)});
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    last=n+1;
    for(int i=0;i<m;i++){
        int u,v,c;
        cin>>u>>v>>c;
        addEdge(u,v,c);
    }
    priority_queue<pair<int,int> > pq;
    pq.push(mp(0,1));
    for(int i=0;i<600000;i++)dist[i]=1e9;
    dist[1]=0;
    while(!pq.empty()){
        int here=pq.top().second;
        int cost=-pq.top().first;
        pq.pop();
        if(dist[here]<cost)continue;
        if(here==n){
            cout<<dist[here];
            return 0;
        }
        for(auto node:adj[here]){
            int there=node.to;
            int d=node.d;
            if(dist[there]>d+cost){
                dist[there]=d+cost;
                pq.push(mp(-(d+cost),there));
            }
        }
    }
    cout<<-1;
    return 0;
}
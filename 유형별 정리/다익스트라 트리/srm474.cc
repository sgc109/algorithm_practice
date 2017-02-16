/*
https://community.topcoder.com/stat?c=problem_statement&pm=10805
최단경로 트리를 구성할수있는 모든 방향 간선들의 합집합으로 DAG를 구성할수있다!
*/

#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int,pair<int,int> > piii;
typedef vector<piii> viii;
const double EPSILON = 1e-9;
const double PI = acos(0.0)*2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int dist[53],dp[53];
int order[53],id[53];
// int check[53];
int cnt;
priority_queue<pii> pq;
int N;
vector<string> vs;
class TreesCount{
public:
    int dijkstra(int start){
        memset(dist,0x3c,sizeof(dist));
        memset(dp,0,sizeof(dp));
        memset(id,-1,sizeof(id));
        dist[start]=0;
        pq.push({0,start});
        while(!pq.empty()){
            int here = pq.top().second;
            int hereD = -pq.top().first;
            pq.pop();
            if(dist[here]<hereD) continue;
            if(id[here]!=-1) {
                (dp[here]+=dp[order[id[here]-1]])%=MOD;
                continue;
            }
            order[cnt]=here;
            id[here]=cnt++;
            (dp[here]+=(here==0?1:dp[order[id[here]-1]]))%=MOD;
            FOR(there,N){
                if(vs[here][there]=='0') continue;
                int thereD = hereD+vs[here][there]-'0';
                if(dist[there]>=thereD){
                    dist[there]=thereD;
                    pq.push({-dist[there],there});
                }
            }
        }
        return dp[order[cnt-1]];
    }
    int count(vector<string> graph){
        N=sz(graph);
        vs=graph;
        return dijkstra(0);
    }
};
int main() {
    TreesCount test;
    cout << test.count( 
	
	
{"073542",
 "705141",
 "350721",
 "517031",
 "442304",
 "211140"}
 );
    return 0;
}

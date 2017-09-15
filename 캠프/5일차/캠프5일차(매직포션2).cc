#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <stack>
#include <cstring>
#include <cstdlib>
#include <string>
#include <set>
#include <cmath>
#include <deque>
// #include <unordered_set>
// #include <map>
#define REP(i,a,b) for(int i = a; i <= b;++i)
#define FOR(i,n) REP(i,0,n-1)
#define mp make_pair
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
typedef queue<int> QU;

const double EPSILON = 1e-9;
const double PI = acos(0.0)*2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;
int N,K;
char input[53][53];
double C[53][53];
double dist[53][53];
int main() {
	inp2(N,K);
	FOR(i,N) scanf("%s",input[i]);
	FOR(i,N) FOR(j,N) C[i][j]=input[i][j]-'0';
	
	FOR(i,N) FOR(j,K+1) dist[i][j]=INF;
	priority_queue<pair<double,pii> > pq;
	pq.push({0,{0,0}});
	dist[0][0]=0.0;
	while(!pq.empty()){
		double hereDist = -pq.top().first;
		pii hereNode = pq.top().second;
		pq.pop();
		if(dist[hereNode.first][hereNode.second] < hereDist) continue;

		FOR(there,N){
			if(there==hereNode.first) continue;
			FOR(i,2){
				if(hereNode.second+i>K) continue;
				double nextDist = hereDist+(i?C[hereNode.first][there]/2:C[hereNode.first][there]);
				if(dist[there][hereNode.second+i] > nextDist) {
					dist[there][hereNode.second+i] = nextDist, pq.push({-nextDist,{there,hereNode.second+i}});
				}
			}
		}
	}
	double ans=INF;
	FOR(i,K+1) ans=min(ans,dist[1][i]);
	printf("%.10lf",ans);
	return 0;
}

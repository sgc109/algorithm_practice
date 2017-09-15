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
#define FOR(i,n) REP(i,0,n)
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


int n;
int start;
int A[100003];
int dist[100003];
vi adj[100003];
int main() {
	memset(dist,-1,sizeof(dist));
	inp1(n);
	FOR(i,n) inp1(A[i]);
	inp1(start);
	start--;
	FOR(i,n){
		if(0<=i-A[i]) adj[i].pb(i-A[i]);
		if(i+A[i]<n) adj[i].pb(i+A[i]);
	}
	queue<int> q;
	dist[start]=0;
	q.push(start);
	int ans=0;
	while(!q.empty()){
		int here = q.front();
		q.pop();
		for(int there : adj[here]){
			if(dist[there]!=-1) continue;
			dist[there]=dist[here]+1;
			ans=max(ans,dist[there]);
		}
	}
	printf("%d",ans+1);
	return 0;
}

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
const int MAX_N = 1002;

int A[MAX_N],B[MAX_N];
int N,S,T,M;
int adj[MAX_N][MAX_N];
ll gcd(ll a, ll b){
	if(!a||!b) return a+b;
	return gcd(b%a,a);
}
ll lcm(ll a, ll b){
	return a*b/gcd(a,b);
}
int arrive[MAX_N];
int dist[MAX_N];
int main() {
	memset(dist,-1,sizeof(dist));
	inp4(N,S,T,M);
	if(S==T) {printf("0");return 0;}
	REP(i,1,M) inp1(A[i]);
	REP(i,1,M) inp1(B[i]);
	REP(i,1,M) if(T%B[i]==0) arrive[i]=1;
	REP(i,1,M){
		REP(j,1,M){
			if(lcm(B[i],A[j])<=N) adj[i][j]=1;
		}
	}
	queue<int> q;
	REP(i,1,M) if(S%A[i]==0) q.push(i),dist[i]=0;
	int ans=-1;
	while(!q.empty()){
		int here = q.front();
		if(arrive[here]) {
			ans=dist[here]+1;
			break;
		}
		q.pop();
		REP(there,1,M){
			if(!adj[here][there] || dist[there]!=-1) continue;
			dist[there] = dist[here]+1;
			q.push(there);
		}
	}
	printf("%d",ans);


	return 0;
}

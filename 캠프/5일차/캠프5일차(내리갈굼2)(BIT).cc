// #include <bits/stdc++.h>
// #include <unordered_set>
// #include <unordered_map>
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <utility>
#include <string>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
#define inp5(a,b,c,d,e) scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)z
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
const double PI = acos(-1);
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int N,M,a,b,o;
vector<int> G[100003];
ll t[200003];
int l[100003],r[100003];
int cnt;
void dfs(int here){
	l[here]=cnt++;
	for(int there: G[here]) dfs(there);
	r[here]=cnt++;
}
ll query(int x){
	ll ret=0;
	for(;x>0;x-=-x&x) ret+=t[x];
	return ret;
}
void update(int x, int v){
	for(;x<=2*N;x+=-x&x) t[x]+=v;
}
int main() {
	ios::sync_with_stdio(false);
	cnt=1;
	cin >> N >> M;
	REP(i,1,N){
		cin >> a;
		if(a==-1) continue;
		G[a].pb(i);
	}
	dfs(1);
	FOR(i,M){
		cin >> o;
		if(o-1) cin >> a,printf("%lld\n",query(l[a]));
		else cin >> a >> b,update(r[a]+1,-b),update(l[a],b);
	}
	return 0;
}

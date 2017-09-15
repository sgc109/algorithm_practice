// #include <bits/stdc++.h>
// #include <unordered_set>
// #include <unordered_map>
// #include <iostream>
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

int N,M,a,o;
ll b;
vector<int> G[100003];
ll t[800003],d[800003];
int l[100003],r[100003];
int cnt;
void dfs(int here){
	l[here]=cnt++;
	for(int there: G[here]) dfs(there);
	r[here]=cnt++;
}
void update(int nl, int nr, int l, int r, int n, ll v){
	if(d[n]) t[n]+=(nr-nl+1)*d[n],(nl!=nr?d[2*n]+=d[n],d[2*n+1]+=d[n]:0),d[n]=0;
	if(l<=nl&&nr<=r) {t[n]+=(nr-nl+1)*v,(nl!=nr?d[2*n]+=v,d[2*n+1]+=v:0); return;}
	if(r<nl||nr<l) return;
	update(nl,(nl+nr)/2,l,r,2*n,v),update((nl+nr)/2+1,nr,l,r,2*n+1,v),t[n]=t[2*n]+t[2*n+1];
}
ll query(int nl, int nr, int l, int r, int n){
	if(d[n]) t[n]+=(nr-nl+1)*d[n],(nl!=nr?d[2*n]+=d[n],d[2*n+1]+=d[n]:0),d[n]=0;
	if(l<=nl&&nr<=r) return t[n];
	if(r<nl||nr<l) return 0;
	return query(nl,(nl+nr)/2,l,r,2*n)+query((nl+nr)/2+1,nr,l,r,2*n+1);
}
int main() {
	inp2(N,M);
	FOR(i,N){
		inp1(a),a--;
		if(a==-2) continue;
		G[a].pb(i);
	}
	dfs(0);
	FOR(i,M){
		inp1(o);
		if(o-1) inp1(a), a--, printf("%lld\n",query(0,2*N-1,l[a],l[a],1));
		else inp1(a), scanf("%lld",&b), a--, update(0,2*N-1,l[a],r[a],1,b);
	}
	return 0;
}

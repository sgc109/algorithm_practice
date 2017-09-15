// #include <bits/stdc++.h>
#include <unordered_set>
// #include <unordered_map>
#include <vector>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <set>
#include <map>
// #include <cmath>
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
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

struct Range{
	int l,r;
	bool operator<(Range& rhs){
		if(l==rhs.l) return r<rhs.r;
		return l<rhs.l;
	}
};
int N,M,a,b,E;
Range ranges[200003];
ll dp[3610003];
int lz[3610003];
ll pow2(ll x, int n){
	if(!n) return 1;
	ll memo;
	if(n%2) {
		memo = pow2(x,(n-1)/2);
		return x*memo%MOD*memo%MOD;
	}
	memo = pow2(x,n/2);
	return memo*memo%MOD;
}
unordered_set<int> us;
ll query(int nl, int nr, int l, int r, int nd){
	if(lz[nd]) (dp[nd]*=pow2(2,lz[nd]))%=MOD,(nl!=nr?lz[2*nd]+=lz[nd],lz[2*nd+1]+=lz[nd]:0),lz[nd]=0;
	if(l<=nl&&nr<=r) return dp[nd];
	if(r<nl||nr<l) return 0;
	return (query(nl,(nl+nr)/2,l,r,2*nd)+query((nl+nr)/2+1,nr,l,r,2*nd+1))%MOD;
} ll query(int l, int r){return query(0,E,l,r,1);}

void update(int nl, int nr, int l, int r, int nd){
	if(lz[nd]) (dp[nd]*=pow2(2,lz[nd]))%=MOD,(nl!=nr?lz[2*nd]+=lz[nd],lz[2*nd+1]+=lz[nd]:0),lz[nd]=0;
	if(l<=nl&&nr<=r) {(dp[nd]*=2)%=MOD,(nl!=nr?lz[2*nd]++,lz[2*nd+1]++:0);return;}
	if(r<nl||nr<l) return;
	update(nl,(nl+nr)/2,l,r,2*nd),update((nl+nr)/2+1,nr,l,r,2*nd+1),dp[nd]=(dp[2*nd]+dp[2*nd+1])%MOD;
} void update(int l, int r){update(0,E,l,r,1);}

void pUpdate(int nl, int nr, int nd, int pos, ll val){
	if(lz[nd]) (dp[nd]*=pow2(2,lz[nd]))%=MOD,(nl!=nr?lz[2*nd]+=lz[nd],lz[2*nd+1]+=lz[nd]:0),lz[nd]=0;
	if(nl==nr&&nl==pos) {dp[nd]=val;return;}
	if(nr<pos||pos<nl) return;
	pUpdate(nl,(nl+nr)/2,2*nd,pos,val),pUpdate((nl+nr)/2+1,nr,2*nd+1,pos,val),dp[nd]=(dp[2*nd]+dp[2*nd+1])%MOD;
} void pUpdate(int pos, ll val){pUpdate(0,E,1,pos,val);}

int main() {
	vi sorted;
	inp2(N,M);
	us.insert(1),sorted.pb(1);
	us.insert(N),sorted.pb(N);
	FOR(i,M){
		inp2(a,b);
		ranges[i]=Range{a,b};
		if(!us.count(a)) us.insert(a),sorted.pb(a);
		if(!us.count(b)) us.insert(b),sorted.pb(b);
	}
	sort(all(sorted));
	E=sz(sorted)-1;
	FOR(i,M) {
		ranges[i].l=lower_bound(all(sorted),ranges[i].l)-sorted.begin();
		ranges[i].r=lower_bound(all(sorted),ranges[i].r)-sorted.begin();
	}
	sort(ranges,ranges+M);
	// 좌표압축 + 정렬까지 완료

	pUpdate(0,1);
	FOR(i,M){
		pUpdate(ranges[i].r,(query(ranges[i].l,ranges[i].r)+query(ranges[i].r,ranges[i].r))%MOD);
		update(ranges[i].r+1,E);
	}
	printf("%lld",query(E,E));
	return 0;
}

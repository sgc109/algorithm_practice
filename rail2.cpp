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

int N,M,a,b,E;
ll dp[200003];
int l[200003],r[200003],t[200003];
unordered_set<int> us;

void update(int l, int r, ll v){
	for(l+=E,r+=E;l<=r;l>>=1,r>>=1){
		if(l&1) (t[l++]+=v)%=MOD;
		if(!(r&1)) (t[r--]+=v)%=MOD;
	}
}
ll query(int l, int r){
	ll ret=0;
	for(l+=E,r+=E;l<=r;l>>=1,r>>=1){
		if(l&1) (ret+=t[l++])%=MOD;
		if(!(r&1)) (ret+=t[r--])%=MOD;
	}
	return ret;
}
int main() {
	memset(dp,-1,sizeof(dp));
	vi sorted;
	inp2(N,M);
	us.insert(1),sorted.pb(1);
	us.insert(N),sorted.pb(N);
	FOR(i,M){
		inp2(a,b);
		l[i]=a,l[i]=b;
		if(!us.count(a)) us.insert(a),sorted.pb(a);
		if(!us.count(b)) us.insert(b),sorted.pb(b);
	}
	sort(all(sorted));
	E=sz(sorted);
	FOR(i,M) {
		l[i]=lower_bound(all(sorted),l[i])-sorted.begin();
		r[i]=lower_bound(all(sorted),r[i])-sorted.begin();
	}
	// 좌표압축 완료
	
	REP(i,1,E){

	}
	return 0;
}

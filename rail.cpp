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

struct Range{
	int l,r;
	bool operator<(Range& rhs){
		if(l==rhs.l) return r<rhs.r;
		return l<rhs.l;
	}
};
int N,M,a,b,E;
Range ranges[5003];
ll dp[5003][10003];
unordered_set<int> us;
ll solve(int pos, int last){
	if(pos==M) return last==E;
	if(ranges[pos].l!=0&&last<ranges[pos].l) return 0;
	ll& cache = dp[pos][last+1];
	if(cache!=-1) return cache;
	return cache = (solve(pos+1,max(last,ranges[pos].r))+solve(pos+1,last))%MOD;
}
int main() {
	memset(dp,-1,sizeof(dp));
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

	printf("%lld", solve(0,-1));
	return 0;
}

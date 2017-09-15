// #include <bits/stdc++.h>
// #include <iostream>
#include <unordered_set>
#include <unordered_map>
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
#define inp5(a,b,c,d,e) scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)
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
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;
map<ll, ll> um;
int N,K;
int A[100003];
ll pSum[100003];
unordered_set<ll> us;
vector<ll> cand;
int main() {
	inp2(N,K);
	FOR(i,N) inp1(A[i]), pSum[i+1]=pSum[i]+A[i];
	long long pusher=1;
	for(; abs(pusher) <= 1e16; pusher*=K) {
		if(us.count(pusher)) break;
		us.insert(pusher);
		cand.pb(pusher);
	}
	ll ans=0;
	um[0]=1;
	REP(i,1,N){
		for(auto kk : cand) ans+=um[pSum[i]-kk];
		um[pSum[i]]++;
	}
	printf("%lld",ans);
	return 0;
}

// #include <bits/stdc++.h>
#include <unordered_set>
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
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int t[200003];
int N,M,a,b,c;
vector<int> sorted;
unordered_set<int> us;
void init(){for(int i = N-1; i >= 0; i--) t[i]=min(t[i<<1],t[i<<1|1]);}
int query(int l, int r){
	int ret=INF;
	for(l+=N,r+=N;l<=r;l>>=1,r>>=1){
		if(l&1) ret=min(ret,t[l++]);
		if(!(r&1)) ret=min(ret,t[r--]);
	}
	return ret;
}
int main() {
	scanf("%d%d",&N,&M);
	for(int i = 0; i < N; i++){
		scanf("%d",t+N+i);
	}
	init();
	for(int i = 0; i < M; i++){
		scanf("%d%d",&a,&b), a--, b--;
		printf("%d\n",query(a,b));
	}
	return 0;
}

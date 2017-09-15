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
// #include <unordered_set>
// #include <map>
#define REP(i,a,b) for(int i = a; i < b;++i) 
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

const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 1000002;

ll d[2100000],t[2100000];
int n;

void build() {
	for(int i=n-1;i>0;i--) t[i]=t[i<<1]+t[i<<1|1];
}
ll query(int nl, int nr, int l, int r, int node){
	if(d[node]!=0){
		t[node]+=d[node]*(nr-nl+1);
		if(node<n) d[node<<1]+=d[node],d[node<<1|1]+=d[node];
		d[node]=0;
	}
	if(l <= nl && nr <= r) return t[node];
	if(nr < l || r < nl) return 0;
	int nm = (nl+nr)>>1;
	return query(nl,nm,l,r,node<<1)+query(nm+1,nr,l,r,node<<1|1);
} ll query(int l, int r) {return query(0,n-1,l,r,1);}

ll addRange(int nl, int nr, int l, int r, int node, ll adder){
	if(d[node]!=0){
		t[node]+=d[node]*(nr-nl+1);
		if(node<n) d[node<<1]+=d[node],d[node<<1|1]+=d[node];
		d[node]=0;
	}
	if(l <= nl && nr <= r) {
		if(node<n) d[node<<1]+=adder,d[node<<1|1]+=adder;
		return t[node]+=adder*(nr-nl+1);
	}
	if(nr < l || r < nl) return t[node];
	int nm = (nl+nr)>>1;
	return t[node] = addRange(nl,nm,l,r,node<<1,adder)+addRange(nm+1,nr,l,r,node<<1|1,adder);
} ll addRange(int l, int r, ll adder) {return addRange(0,n-1,l,r,1,adder);}

int main() {
	int N,M,K;
	inp3(N,M,K);
	n = 1<<(int)ceil(log2(N));
	FOR(i,N) scanf("%lld",t+n+i);
	build();
	FOR(i,M+K){
		int a,b,c,d;
		inp1(a);
		if(a==1){
			inp3(b,c,d);
			addRange(b-1,c-1,d);
		}
		else if(a==2){
			inp2(b,c);
			printf("%lld\n",query(b-1,c-1));
		}
	}
	return 0;
}
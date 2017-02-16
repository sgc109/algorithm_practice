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

struct Range{
	int s,e;
	bool operator<(const Range& rhs){
		return e<rhs.e;
	}
};
unordered_set<int> us;
vector<int> ordered;
vector<Range> ranges;
int t[300003],check[300003];
int N,a,b,c;
int input[100003][3];
int query(int x){
	int ret=0;
	for(;x>0;x-=x&-x) ret+=t[x];
	return ret;
}
void update(int x, int v){
	for(;x<=300000;x+=x&-x) t[x]+=v;
}
int main() {
	int ans=0;
	scanf("%d",&N);
	for(int i = 0; i < N; i++){
		for(int j = 0; j < 3; j++) {
			scanf("%d",&input[i][j]);
			if(!us.count(input[i][j])) us.insert(input[i][j]), ordered.push_back(input[i][j]);
		}
	}
	sort(all(ordered));
	for(int i = 0; i < N; i++){
		for(int j = 0; j < 3; j++){
			input[i][j] = lower_bound(all(ordered),input[i][j]) - ordered.begin() + 1;
		}
		if(!check[input[i][0]]) {
			check[input[i][0]]=1;
			update(input[i][0],1);
			ans++;
		}
	}
	for(int i = 0; i < N; i++){
		int tmp = query(input[i][2])-query(input[i][1]-1);
		if(!tmp||(tmp==1&&input[i][1]<=input[i][0]&&input[i][0]<=input[i][2])) ranges.push_back(Range{input[i][1],input[i][2]});
	}

	sort(all(ranges));
	Range last = Range{-1,-1};
	for(int i = 0; i < sz(ranges); i++){
		if(last.e>ranges[i].s) continue;
		last=ranges[i], ans++;
	}
	printf("%d",ans);
	return 0;
}

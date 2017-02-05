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
const int MAX_N = 102;

void NO(){
	printf("Impossible");
	exit(0);
}

int n;
int main() {
	int lo = -INF,hi = INF;
	inp1(n);
	FOR(i,n){
		int v,d;
		inp2(v,d);
		if(d==1){
			if(hi<1900) NO();
			lo = max(lo,1900);
		}
		else if(d==2){
			if(lo>=1900) NO();
			hi = min(hi,1899);
		}
		lo+=v;
		hi+=v;
	}
	if(hi>=500000000) printf("Infinity");
	else printf("%d",hi);
	return 0;
}

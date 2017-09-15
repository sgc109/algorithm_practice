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
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
typedef queue<int> QU;

const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 1000;

int n,m;
int len[MAX_N];
int solve(int pos){
	if(pos==n) return 0;
	int ret = INF;
	int charCnt = len[pos];
	for(int i = pos+1; i <=n, charCnt <=m ; ++i){
		ret = min(ret, (m-charCnt)*(m-charCnt)+solve(i));
		if(i==n) {
			ret=0;
			break;
		}
		charCnt += len[i]+1;
	}
	return ret;
}
int main() {
	inp2(n,m);
	FOR(i,n){
		inp1(len[i]);
	}
	printf("%d",solve(0));
	return 0;
}
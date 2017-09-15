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

int n;
vi ans[12];
void solve(int *pos, int depth){
	if(depth==n) return;
	int size = ((1<<(n-depth))-1)>>1;
	solve(pos,depth+1);
	ans[depth].pb(*(pos+size));
	solve(pos+size+1,depth+1);
}
int main() {
	inp1(n);
	int arr[1<<10];
	FOR(i,(1<<n)-1) {
		scanf("%d",arr+i);
	}
	solve(arr,0);
	FOR(i,n){
		FOR(j,ans[i].size()) printf("%d ",ans[i][j]);
		printf("\n");
	}
	return 0;
}
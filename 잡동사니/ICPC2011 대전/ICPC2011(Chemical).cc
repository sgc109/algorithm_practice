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

const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 1000000;

int a,b,c;
// int dp[1001][1001][1001];
int pa,pb,pc;
int tmp;
int biggest;
long long solve(int restA, int restB, int restC){
	if(restA<0 || restB<0 || restC<0) return -INFL;
	long long ret = 0;
	int smallest = min(restA,min(restB,restB));
	if(tmp && smallest>=2) {
		return (long long)(pa+pb+pc)*(smallest/2)+solve(restA-(smallest/2)*2,restB-(smallest/2)*2,restC-(smallest/2)*2);
	}
	else if(!tmp && )
	else {
		ret = max(ret,pa+solve(restA-1,restB-1,restC));
		ret = max(ret,pb+solve(restA,restB-1,restC-1));
		ret = max(ret,pc+solve(restA-1,restB,restC-1));
	}

	return ret;
}
int main() {
	int T;
	inp1(T);
	while(T--){
		// memset(dp,-1,sizeof(dp));
		inp3(a,b,c);
		inp3(pa,pb,pc);
		int biggest = max(pa,max(pb,pc));
		tmp = (pa+pb+pc > biggest*2);
		printf("%lld\n",solve(a,b,c));
	}
	return 0;
}
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

typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;

const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 100004;

int n;
char S[MAX_N];
int main() {
	inp1(n);
	scanf("%s",S);
	int ans = INF;
	int r2b=0,b2r=0;
	int bNow=1;
	FOR(i,n) {
		if(bNow){
			if(S[i]=='r') ++r2b;
		}
		else{
			if(S[i]=='b') ++b2r;
		}
		bNow ^= 1;
	}
	// printf("r2b:%d, b2r:%d\n",r2b,b2r);
	int tmp = r2b >= b2r ? b2r : r2b;
	tmp += abs(r2b-b2r);
	ans = min(ans,tmp);
	r2b=0;
	b2r=0;
	bNow=0;
	FOR(i,n) {
		if(bNow){
			if(S[i]=='r') ++r2b;
		}
		else{
			if(S[i]=='b') ++b2r;
		}
		bNow ^= 1;
	}
	// printf("r2b:%d, b2r:%d\n",r2b,b2r);
	tmp = r2b >= b2r ? b2r : r2b;
	tmp += abs(r2b-b2r);
	ans = min(ans,tmp);

	printf("%d",ans);
	return 0;
}
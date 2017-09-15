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
#include <unordered_set>
#include <set>
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

typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;

const int INF = 0x3a3a3a3a;
const long long INFL = 0x3a3a3a3a3a3a3a3a;
const int MAX_N = 1000000;

char str[100004];
int cnt[220]={0,};
int c[5]={'R','L','U','D'};
int main() {
	scanf("%s",str);
	int len = strlen(str);
	if(len%2 != 0) {
		printf("-1");
		return 0;
	}
	FOR(i,len) {
		++cnt[str[i]];
	}

	int sum = 0;
	FOR(i,4) {
		sum += cnt[c[i]];
	}
	int a = abs(cnt['L']-cnt['R']);
	int b = abs(cnt['U']-cnt['D']);

	int ans=0;
	if(a%2==1) {
		ans++;
		a--;
		b--;
	}
	ans+=a/2;
	ans+=b/2;
	
	printf("%d",ans);
	return 0;
}
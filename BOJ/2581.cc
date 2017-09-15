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

int notPrime[10002];
int n,m;
int main() {
	notPrime[1]=1;
	inp2(n,m);
	for(int i=2;i*i<=10000;i++){
		if(notPrime[i]) continue;
		for(int j=2*i;j<=10000;j+=i) notPrime[j]=1;
	}
	int ansMin=INF;
	int ansSum=0;
	for(int i = n; i <=m; i++) {
		if(notPrime[i]) continue;
		ansMin=min(ansMin,i), ansSum+=i;
	}
	if(!ansSum) printf("-1");
	else printf("%d\n%d",ansSum,ansMin);
	return 0;
}

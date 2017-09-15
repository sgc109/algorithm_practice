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


pii cnt2n5[502];
int main() {
	int n;
	inp1(n);
	for(int i=1;i<=n;i++) cnt2n5[i]=mp(0,0);
	for(int i=1;i<=n;i++){
		if(i%2==0) cnt2n5[i]=mp(cnt2n5[i/2].first+1,cnt2n5[i/2].second);
		if(i%5==0) cnt2n5[i]=mp(cnt2n5[i/5].first,cnt2n5[i/5].second+1);
	}
	int cnt2=0,cnt5=0;
	for(int i=1;i<=n;i++) cnt2+=cnt2n5[i].first, cnt5+=cnt2n5[i].second;
	printf("%d",min(cnt2,cnt5));
	return 0;
}
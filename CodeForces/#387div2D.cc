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
	printf("-1");
	exit(0);
}

int n,k;
int t[200002];
int main() {
	inp2(n,k);
	FOR(i,n) inp1(t[i]);
	int prev = -1;
	vi add2,add1;
	int cntMinus=0;
	int ans=0;
	FOR(i,n) {
		if(i>0) {
			if((t[i-1]>=0&&t[i]<0)||(t[i-1]<0&&t[i]>=0)) ans++;
		}
		else if(t[i]<0) ans++;
		if(t[i]<0) {
			cntMinus++;
			if(prev!=-1 && i-prev-1>0) add2.pb(i-prev-1);
			prev=i;
		}
	}
	if(prev!=-1 && n-prev-1>0) add1.pb(n-prev-1);
	if(cntMinus > k) NO();
	sort(add2.begin(),add2.end());
	k-=cntMinus;
	
	// printf("ans:%d\n",ans);
	for(int i = 0; i < add2.size(); i++){
		if(add2[i]>k) break;
		k-=add2[i];
		ans-=2;
	}
	if(add1.size()!=0 && k >= add1[0]) ans--;
	printf("%d",ans);
	return 0;
}
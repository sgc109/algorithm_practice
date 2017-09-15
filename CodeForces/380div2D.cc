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
// #define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
typedef queue<int> QU;
typedef pair<pair<int,int>,char> unit;

const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

vector<unit> dir[8];

bool cmpYD(const unit &a, const unit &b){
    return a.first.second > b.first.second;
}
bool cmpXI(const unit &a, const unit &b){
    return a.first.first < b.first.first;
}
bool cmpYI(const unit &a, const unit &b){
    return a.first.second < b.first.second;
}
bool cmpXD(const unit &a, const unit &b){
    return a.first.first > b.first.first;
}

int main() {
	int n;
	inp1(n);
	ll kx, ky;
	bool ans=false;
	scanf("%lld%lld",&ky,&kx);
	FOR(i,n){
		char type;
		scanf(" %c",&type);
		ll bx, by;
		scanf("%lld%lld",&by,&bx);
		unit u = mp(mp(bx,by),type);
		if(kx==bx) {
			if(ky>by) dir[0].pb(u);
			else dir[4].pb(u);
		}
		else if(kx+ky==bx+by) {
			if(ky>by) dir[1].pb(u);
			else dir[5].pb(u);
		}
		else if(ky==by){
			if(kx<bx) dir[2].pb(u);
			else dir[6].pb(u);
		}
		else if(kx-ky==bx-by){
			if(kx<bx) dir[3].pb(u);
			else dir[7].pb(u);
		}
	}
	sort(dir[0].begin(),dir[0].end(),cmpYD);
	sort(dir[1].begin(),dir[1].end(),cmpYD);
	sort(dir[2].begin(),dir[2].end(),cmpXI);
	sort(dir[3].begin(),dir[3].end(),cmpYI);
	sort(dir[4].begin(),dir[4].end(),cmpYI);
	sort(dir[5].begin(),dir[5].end(),cmpYI);
	sort(dir[6].begin(),dir[6].end(),cmpXD);
	sort(dir[7].begin(),dir[7].end(),cmpXD);
	FOR(i,8){
		if(dir[i].size()==0) continue;
		if(i==0||i==2||i==4||i==6){
			if(dir[i][0].second=='R'||dir[i][0].second=='Q') ans=true;
		}
		if(i==1||i==3||i==5||i==7){
			if(dir[i][0].second=='B'||dir[i][0].second=='Q') ans=true;
		}
	}
	if(ans) printf("YES");
	else printf("NO");
	return 0;
}
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
#include <deque>
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

const double EPSILON = 1e-9;
const double PI = acos(0.0)*2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int xx[MAX_N],yy[MAX_N];
int n;
bool isN2(ll len){
	FOR(i,n){
		int px=xx[i];
		FOR(j,n){
			int cnt=0;
			int py=yy[j];
			int hereX = px-1;
			int hereY = py+1;
			FOR(k,n){
				if(hereX < xx[k] && xx[k] < hereX+len && hereY-len < yy[k] && yy[k] < hereY) cnt++;
			}
			if(cnt>=n-2) return true;
		}
	}
	return false;
}
int main() {
	inp1(n);
	FOR(i,n){
		inp2(xx[i],yy[i]);
	}
	ll lo=0,hi=2e9+4;
	while(lo<hi){
		ll mid=(lo+hi)>>1;
		if(isN2(mid)) hi=mid;
		else lo=mid+1;
	}
	printf("%lld",lo*lo);
	return 0;
}

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
const int MAX_N = 12;

int pos[MAX_N];
double newPos[MAX_N];
int n,t;
int main() {
	inp1(n);
	FOR(i,n) inp1(pos[i]);
	sort(pos,pos+n);
	inp1(t);
	ll det = 1<<n;
	ll num = 0;
	FOR(i,1<<n){
		// printf("i:%d\n",i);
		FOR(j,n) newPos[j]=pos[j];
		int state=i;
		ll cnt=0;
		double newTime=0;
		while(1){
			double minD=9999999999999999;
			FOR(j,n-1){
				if((state&(1<<j))!=0&&(state&(1<<(j+1)))==0) minD=min(minD,newPos[j+1]-newPos[j]);
			}
			if(minD==9999999999999999) break;
			if(newTime+minD/2>t) break;
			// printf("minD:%lf\n",minD);
			newTime+=minD/2;
			FOR(j,n) newPos[j]+=(state&(1<<j)?minD/2:-minD/2);
			FOR(j,n-1) {
				if(newPos[j]==newPos[j+1]) state^=(1<<j),state^=(1<<(j+1)),cnt++;
			}
		}
		num+=cnt;
	}
	// printf("num:%lld, det:%lld\n",num,det);
	printf("%.2lf",(double)num/det);
	return 0;
}

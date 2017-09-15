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
#define REP(i,a,b) for(int i = a; i <= b;++i)
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

int t[500003],d[500003];
int n,m,o;
void update(int x, int add){
	while(x<=n){
		t[x]^=add;
		x+=x&-x;
	}
}
int query(int x){
	int ret=0;
	while(x>0){
		ret^=t[x];
		x-=x&-x;
	}
	return ret;
}
int main() {
	inp1(n);
	REP(i,1,n) inp1(d[i]);
	inp1(m);
	while(m--){
		inp1(o);
		o--;
		if(o){
			int a;
			inp1(a);
			a++;
			printf("%d\n",query(a)^d[a]);
		}
		else {
			int l,r,c;
			inp3(l,r,c);
			l++;r++;
			update(l,c);
			update(r+1,c);
		}
	}
	return 0;
}

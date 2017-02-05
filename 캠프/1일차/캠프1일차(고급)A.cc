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
const int MAX_N = 52;

int n,m;
int order[MAX_N];
vi v;
int a;
int arr[MAX_N];
void NO(){
	printf("0");
	exit(0);
}
int main() {
	inp2(n,m);
	FOR(i,n){
		v.clear();
		FOR(j,m){
			inp1(arr[j]);
			v.pb(arr[j]);
		}
		sort(v.begin(),v.end());
		if(v[0]%m!=1||v[v.size()-1]%m!=0) NO();
		FOR(j,m){
			int r = lower_bound(v.begin(),v.end(),arr[j])-v.begin();
			if(!i) order[j] = r;
			else if(order[j]^r) NO(); 
		}
	}
	printf("1");
	return 0;
}

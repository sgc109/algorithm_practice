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
#include <unordered_set>
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
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
typedef queue<int> QU;

const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 1000000;

unordered_set<int> us;
int n;
vi v;

int gcd(int a, int b){
	while(a&&b){
		if(a<b) swap(a,b);
		a%=b;
		gcd(a,b);
	}
	return a+b;
}
int main() {
	inp1(n);
	int g; 
	FOR(i,n){
		int tmp;
		inp1(tmp);
		if(!us.count(tmp)){
			v.pb(tmp);
			us.insert(tmp);
		}
		if(i==0) g=tmp;
		else g=gcd(g,tmp);
	}
	if(us.count(g)) printf("%d",g);
	else printf("-1");

	
	return 0;
}
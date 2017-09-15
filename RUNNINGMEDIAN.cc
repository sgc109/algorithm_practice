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

const int MOD = 20090711;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int main() {
	int T;
	inp1(T);
	while(T--){
		priority_queue<int> pqMin,pqMax;
		int n,a,b;
		inp3(n,a,b);
		ll random = 1983;
		ll ans=0;
		FOR(i,n){
			if(i%2==0) pqMax.push(random);
			else pqMin.push(-random);

			if(!pqMax.empty() && !pqMin.empty() && pqMax.top() > -pqMin.top()){
				int a = pqMax.top();
				pqMax.pop();
				int b = -pqMin.top();
				pqMin.pop();
				pqMax.push(b);
				pqMin.push(-a);
			}

			if(i%2==0) ans+=pqMax.top();
			else ans+=min(pqMax.top(),-pqMin.top());

			ans%=MOD;
			random = (random*a+b)%MOD;
		}
		printf("%lld\n",ans);
	}
	

	return 0;
}
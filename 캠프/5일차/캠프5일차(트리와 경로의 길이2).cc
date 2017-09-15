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
#define FOR(i,n) REP(i,0,n-1)
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

int S,N;
int ans1,ans2;
bool go(int p, int node1, int node2, int cnt){
	if(p==S) {
		N=cnt;
		ans1=node1;
		ans2=node2;
		return true;
	}
	if(p>S||cnt>500||node1>10) return false;
	// printf("p:%d, node1:%d, node2:%d, cnt:%d\n",p,node1,node2,cnt);
	if(go(p+node2,node1+1,node2,cnt+1)) return true; // 루트에
	if(node1>=1 && go(p+node1+node2-1,node1-1,node2+1,cnt+1)) return true; // 깊이 1노드에
	if(node2>=1 && go(p+1,node1,node2,cnt+1)) return true; // 깊이2이상 노드에

	return false;
}
int main() {
	inp1(S);
	go(0,0,0,1);
	int cnt=1;
	printf("%d\n",N);
	N--;
	while(ans1--){
		printf("%d %d\n",0,cnt++);
		N--;
	}
	while(ans2--){
		printf("%d %d\n",0,cnt++);
		int tmp=cnt-1;
		printf("%d %d\n",tmp,cnt++);
		N-=2;
	}
	int save=cnt-1;
	while(N--){
		printf("%d %d\n",save,cnt++);
	}
	return 0;
}

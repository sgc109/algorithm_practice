#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)
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
typedef vector<pair<int,int> > vii;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
const double EPSILON = 1e-9;
const double PI = acos(0.0)*2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 100002;

int indegree[MAX_N];
int N,T;
int sel[MAX_N];
int main() {
	for(inp1(T);T--;){
		memset(indegree,0,sizeof(indegree));
		queue<int> q;
		inp1(N);
		FOR(i,N) inp1(sel[i]),sel[i]--,indegree[sel[i]]++;
		FOR(i,N) if(!indegree[i]) q.push(i);
		int ans=0;
		while(!q.empty()){
			ans++;
			int here = q.front();
			q.pop();
			indegree[sel[here]]--;
			if(!indegree[sel[here]]) q.push(sel[here]);
		}
		printf("%d\n",ans);
	}
	return 0;
}

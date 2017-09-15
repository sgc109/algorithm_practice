#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int,pair<int,int> > piii;
const double EPSILON = 1e-9;
const double PI = acos(0.0)*2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int T,N;
int S,E;
int visited[10000];
int main() {
	for(scanf("%d",&T);T--;){
		memset(visited,0,sizeof(visited));
		scanf("%d%d",&S,&E);
		queue<pair<int, string> > q;
		q.push({S,""});
		visited[S]=1;
		while(!q.empty()){
			int cur = q.front().first;
			string ins = q.front().second;
			q.pop();
			if(cur==E){
				printf("%s\n",ins.c_str());
				break;
			}
			int next=2*cur%10000;
			if(!visited[next]) {
				visited[next]=1;
				q.push({next,ins+"D"});
			}
			next=(cur+9999)%10000;
			if(!visited[next]) {
				visited[next]=1;
				q.push({next,ins+"S"});
			}
			next=(cur*10+cur/1000)%10000;
			if(!visited[next]) {
				visited[next]=1;
				q.push({next,ins+"L"});
			}
			next=(cur/10+(cur%10)*1000)%10000;
			if(!visited[next]) {
				visited[next]=1;
				q.push({next,ins+"R"});
			}
		}
	}
	return 0;
}

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
typedef vector<pair<int,int> > vii;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
const double EPSILON = 1e-9;
const double PI = acos(0.0)*2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

string S,T;
int adj[13];
unordered_map<string> um;
int asterPos,startPos;
void connect(int a, int b){
	adj[a].pb(b);
	adj[b].pb(a);
}
int diff(string& A, string& B){
	int ret=0;
	FOR(i,sz(A)) if(A[i]!=B[i]) ret++;
	return ret;
}
void allConnect(){
	connect(1,2),connect(1,3),connect(2,3),connect(2,4),connect(2,5),connect(3,5);
	connect(3,6),connect(4,5),connect(5,6),connect(4,7),connect(4,8),connect(5,8);
	connect(5,9),connect(6,9),connect(6,10),connect(7,8),connect(8,9),connect(9,10);
}
int main() {
	int ans=INF;
	cin >> S >> T;
	FOR(i,sz(T)) if(T[i]=='*') asterPos=i;
	FOR(i,sz(S)) if(S[i]=='*') startPos=i;
	queue<pair<string,int> > q;
	q.push({S,startPos});
	um[S]=1;
	while(!q.empty()){
		string here = q.front().first;
		int asPos = q.front().second;
		q.pop();
		if(asterPos==asPos) ans=min(ans,diff(here,T));
		for(int asNext : adj[asPos]){
			swap(here[asPos],here[asNext]);
			if(um.count(here)==0) {
				um[here]=1;
				q.push({here,asNext});
			}
			swap(adj[asPos],adj[asNext]);
		}
	}
	printf("%d",ans);
	return 0;
}

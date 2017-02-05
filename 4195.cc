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
typedef vector<piii> viii;
const double EPSILON = 1e-9;
const double PI = acos(0.0)*2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int T,M,a,b,c;
int p[200003],h[200003],size[200003];
int find(int here){
	if(p[here]==here) return here;
	return p[here]=find(p[here]);
}
void merge(int a, int b){
	a=find(a),b=find(b);
	if(h[a]<h[b]) swap(a,b);
	p[b]=a;
	size[a]+=size[b];
	if(h[a]==h[b]) h[a]++;
}
int main() {
	for(inp1(T);T--;){
		int id=1;
		map<string,int> mp;
		inp1(M);
		REP(i,1,2*M) p[i]=i,h[i]=1,size[i]=1;
		while(M--){
			char As[22],Bs[22];
			scanf("%s%s",As,Bs);
			string A(As),B(Bs);
			if(!mp[A]) mp[A]=id++;
			if(!mp[B]) mp[B]=id++;
			int a=mp[A],b=mp[B];
			if(find(a)!=find(b)) merge(a,b);
			printf("%d\n",size[find(a)]);
		}
		
	}
	return 0;
}

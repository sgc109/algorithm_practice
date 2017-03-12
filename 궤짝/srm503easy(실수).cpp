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
#define inp5(a,b,c,d,e) scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)
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
const double PI = acos(-1);
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

class ToastXToast{
public:
	int aMached[53],bMatched[53];
	vi linkA[53],linkB[53];
	int visited[53];
	int N,M;
	int dfs(int a){
		if(visited[a]) return 0;
		visited[a] = 1;
		for(int b : linkA[a]){
			if(bMatched[b]==-1 || dfs(bMatched[b])){
				bMatched[b] = a;
				aMached[a] = b;
				return 1;
			}
		}
		return 0;
	}
	int bake(vector <int> undertoasted, vector <int> overtoasted){
		int N = sz(undertoasted);
		int M = sz(overtoasted);
		FOR(i,N){
			FOR(j,M){
				if(undertoasted[i]<overtoasted[j]) linkA[i].pb(j), linkB[j].pb(i);
			}
		}
		memset(aMached,-1,sizeof(aMached));
		memset(bMatched,-1,sizeof(bMatched));
		int matched=0;
		FOR(i,N){
			memset(visited,0,sizeof(visited));
			if(dfs(i)) matched++;
		}
		if(matched<N) return -1;
		FOR(i,M){
			if(bMatched[i]==-1 && linkB[i].size()==0) return -1;
		}
		return matched;
	}
};
int main() {
	ToastXToast obj;
	cout << obj.bake(

{1,2,3},
{5,6,7}

		);
	return 0;
}

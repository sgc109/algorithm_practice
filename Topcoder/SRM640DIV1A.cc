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
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
// #define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
typedef queue<int> QU;

const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 52;

class ChristmasTreeDecoration{
public:
	int n;
	vi adj[MAX_N];
	int parent[MAX_N];
	int size[MAX_N];
	int check[MAX_N];
	int find(int p){
		if(parent[p]==p) return p;
		return parent[p] = find(parent[p]);
	}
	void merge(int a, int b){
		a = find(a); b = find(b);
		if(a==b) return;
		if(size[a]<size[b]) swap(a,b);
		parent[b] = a;
		if(size[a]==size[b]) size[a]++;
	}
	int solve(vector <int> col, vector <int> x, vector <int> y){
		n = col.size();
		FOR(i,n){
			parent[i]=i;
			size[i]=1;
		}
		FOR(i,x.size()){
			int a = x[i]; int b = y[i];
			a--;b--;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		FOR(here,n){
			for(int there : adj[here]){
				if(col[here]==col[there]) continue;
				if(find(here)==find(there)) continue;
				merge(here,there);
			}
		}
		int ans=0;
		memset(check,0,sizeof(check));
		FOR(i,n){
			int p = find(i);
			if(check[p]==0) {
				check[p] = 1;
				ans++;
			}
		}
		return ans-1;
	}
};
int main() {
	ChristmasTreeDecoration obj;
	printf("%d",obj.solve(
		{1,1,2,2},
{1,2,3,4},
{2,3,4,1}));
	return 0;
}
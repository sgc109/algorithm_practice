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
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;

const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 1000004;
const int Hash[2] = {1000000007,1000000009};

int f[220];
long long g[2][27];
int main() {
	freopen("output.txt","w",stdout);
	FOR(i,26){
		f['a'+i] = i+1;
	}
	int T;
	inp1(T);
	while(T--){
		int n;
		inp1(n);
		// memset(g,0,sizeof(g));
		FOR(k,2){
			REP(i,1,27) {
				g[k][i] = i;
				FOR(j,n-1){
					g[k][i]=(g[k][i]*27)%Hash[k];
				}
			}
		}	
		char S1[MAX_N], S2[MAX_N];
		scanf("%s %s",S1,S2);
		FOR(i,n){
			S1[i+n] = S1[i];
		}
		S1[2*n] = '\0';
		long long h2[2] = {0,0};
		long long H2;
		FOR(k,2) {
			FOR(i,n){
				h2[k] = (h2[k]*27+f[S2[i]])%Hash[k];
			}
		}
		H2 = h2[0]*Hash[1]+h2[1];
		// printf("%d %d\n",h2[0],h2[1]);

		long long h1[2] = {0,0};
		long long H1;
		FOR(k,2) {
			FOR(i,n){
				h1[k] = (h1[k]*27+f[S1[i]])%Hash[k];
			}
		}
		// printf("%d %d\n",h1[0],h1[1]);
		int pos=-1;
		for(int i = 0; ; ++i) {
			H1 = h1[0]*Hash[1]+h1[1];
			if(H1 == H2) pos = i;
			if(i >= n) break;
			FOR(k,2){
				h1[k] = (h1[k] - g[k][f[S1[i]]] + Hash[k]) % Hash[k];
				h1[k] = (h1[k] * 27) % Hash[k];
				h1[k] = (h1[k] + f[S1[i+n]]) % Hash[k];
			}		
		}

		if(pos==-1) printf("-1\n");
		else if(pos==0) printf("0\n");
		else printf("%d\n",n-pos);
	}
	
	return 0;
}
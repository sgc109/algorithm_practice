#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <stack>
#include <cstring>
#include <cstdlib>
#define REP(i,a,b) for(int i = a; i < b;++i) 
#define FOR(i,n) REP(i,0,n)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> llll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int> > vvi;
typedef vector<ii> vii;
	
const int INF = 0x3a3a3a3a;
const int MAX_V = 1002;

const int Hash = 10007;
int f[220] , g[26];
char S[MAX_V][MAX_V];
int val[MAX_V];
vector<string> strs;

int main() {
	setbuf(stdout,NULL);
	FOR(i,26) 
		f['a'+i] = i;

	int r,c;
	scanf("%d%d",&r,&c);
	getchar();
	strs = vector<string>(c);

	FOR(i,r) 
		gets(S[i]);


	FOR(j,c) {
		val[j] = f[S[0][j]];
		strs[j] += S[0][j];
		REP(i,1,r) {
			val[j] = (val[j] * 26 + S[i][j]) % Hash;
			strs[j] += S[i][j];
		}
	}

	FOR(i,26) {
		g[i] = i;
		FOR(j,r-1) {
			g[i] = (g[i] * 26) % Hash;
		}
	}

	int i;
	bool sameExist = false;
	for(i = 0; i < r-1; ++i) {
		vector<string> h[Hash];
		FOR(j,c) {
			val[j] = (val[j] - g[f[S[i][j]]] + Hash) % Hash;
			strs[j] = strs[j].substr(1,strs[j].size());

			sameExist = false;
			FOR(k,h[val[j]].size()) {
				for(int l = 0; l < r-i-1; ++l) {
					if(strs[j][l] != h[val[j]][k][l]) break;
					if(l == r-i-2) {
						sameExist = true;
						break;
					}
				}
				if(sameExist) break;
			}
			if(sameExist) break;
			h[val[j]].push_back(strs[j]);
			val[j] = (val[j] * 26) % Hash;
		}
		if(sameExist) break;

	}
	printf("%d",i);

	return 0;
}
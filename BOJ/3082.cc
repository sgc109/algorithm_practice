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
#include <unordered_set>
#include <set>
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
const int MAX_N = 1000;

const long long Hash = 10000007;

int h[Hash];

int dx[4] = {-1,0,0,1};
int dy[4] = {0,1,-1,0};

int map[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
int water;

int r,c, nwI, nwJ;
long long val;

int f[MAX_N][2*MAX_N];

vector<int> not0s;

bool inRange(int i, int j) {
	return (0 <= i && i < r && 0<= j && j < c);
}

void dfs(int hereI, int hereJ) {
	// printf("(%d, %d)\n",hereI,hereJ);
	visited[hereI][hereJ] = 1;

	FOR(k,4) {
		int thereI = hereI + dy[k];
		int thereJ = hereJ + dx[k];
		if(inRange(thereI,thereJ) && !visited[thereI][thereJ] && map[thereI][thereJ] > water) {
			int a = thereI - nwI;
			int b = thereJ - nwJ + c;
			val = (val * 2*r*c + f[a][b]) % Hash;
			dfs(thereI, thereJ);
		}
	}
}


int main() {
	setbuf(stdout,NULL);
	scanf("%d%d",&r,&c);
	int cnt = 0;
	FOR(i,r) {
		FOR(j,2*c) {
			f[i][j] = cnt++;
		}
	}

	FOR(i,r) {
		FOR(j,c) {
			scanf("%d",&map[i][j]);
		}
	}
	int q;
	scanf("%d",&q);
	FOR(k,q) {
		not0s.clear();
		FOR(i,r) FOR(j,c) visited[i][j] = 0;
		FOR(i,Hash) h[i] = 0;
		scanf("%d",&water);
		FOR(i,r) {
			FOR(j,c) {
				if(!visited[i][j] && map[i][j] > water) {
					nwI = i; nwJ = j;
					val = 0;
					dfs(i,j);
					++h[val];
					if(h[val] == 1) not0s.pb(val);
				}
			}
		}
		long long ans = 0;
		FOR(i,not0s.size()) {
			long long cnt = h[not0s[i]];
			cnt = cnt * cnt - cnt;
			cnt /= 2;
			ans += cnt;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
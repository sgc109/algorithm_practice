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
// #include <map>
#define REP(i,a,b) for(int i = a; i < b;++i) 
#define FOR(i,n) REP(i,0,n)
#define mp make_pair
#define pb push_back
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)

using namespace std;

typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;

const int INF = 0x3a3a3a3a;
const long long INFL = 0x3a3a3a3a3a3a3a3a;
const int MAX_N = 1000000;


int dx[4] = {0,1,-1,0};
int dy[4] = {1,0,0,-1};
int map[101][101];
int n;
int cnt;

bool inRange(int i, int j) {
	if(0 <= i && i < n && 0 <= j && j < n) return true;
	return false;
}

int visited[101][101];
void dfs(int hereI, int hereJ) {
	visited[hereI][hereJ] = 1;
	map[hereI][hereJ] = cnt;


	FOR(k,4) {
		int thereI = hereI + dy[k];
		int thereJ = hereJ + dx[k];
		if(visited[thereI][thereJ] == 0 && map[thereI][thereJ] != 0) {
			dfs(thereI,thereJ);
		}
	}
}

int main() {
	memset(visited,0,sizeof(visited));
	inp1(n);
	FOR(i,n){
		FOR(j,n){
			inp1(map[i][j]);
		}
	}
	cnt=0;
	FOR(i,n){
		FOR(j,n){
			if(visited[i][j] == 0 && map[i][j] != 0) {
				++cnt;
				dfs(i,j);
			}
		}
	}

	for(int t = 0; ; ++t) {
		FOR(i,n){
			FOR(j,n){
				int hereTerr = map[i][j];
				if(hereTerr <= 0) continue;
				FOR(k,4) {
					int newI = i+dy[k];
					int newJ = j+dx[k];
					if(!inRange(newI,newJ)) continue;
					if(map[newI][newJ] != 0 && map[newI][newJ] != -hereTerr && map[newI][newJ] != hereTerr) {
						if(map[newI][newJ] > 0) printf("%d",2*t);
						else printf("%d",2*t+1);
						return 0;
					}
					if(map[newI][newJ] == 0) map[newI][newJ] = -hereTerr;
				}
			}
		}
		FOR(i,n){
			FOR(j,n){
				if(map[i][j]<0) map[i][j] = -map[i][j];
			}
		}
	}
	return 0;
}
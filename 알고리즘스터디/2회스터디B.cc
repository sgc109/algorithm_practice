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
typedef pair<int,int> pii;

const int INF = 0x3a3a3a3a;
const long long INFL = 0x3a3a3a3a3a3a3a3a;
const int MAX_N = 1000000;

int dx[8] = {-1, 0, 0, 1, 1, -1, -1, 1};
int dy[8] = {0, 1, -1, 0, -1, 1, -1, 1};

int startI,startJ;
int finishI,finishJ;
int t,O,m,n;
char map[101][101];
int dist[101][101];
priority_queue<pair<int,pair<int,int> > > pq;
bool inRange(int i, int j) {
	if(0<=i&&i<m&&0<=j&&j<n) return true;
	return false;
}
void dijkstra() {
	dist[startI][startJ] = 0;
	pq.push(mp(0,mp(startI,startJ)));
	while(!pq.empty()) {
		int hereI = pq.top().second.first;
		int hereJ = pq.top().second.second;
		int hereDist = -pq.top().first;
		pq.pop();

		if(hereDist > dist[hereI][hereJ]) continue;

		FOR(i,8) {
			int thereI = hereI+dy[i];
			int thereJ = hereJ+dx[i];
			if(inRange(thereI,thereJ) && map[thereI][thereJ] != '#' && dist[thereI][thereJ] > hereDist+1) {
				dist[thereI][thereJ] = hereDist+1;
				pq.push(mp(-dist[thereI][thereJ],mp(thereI,thereJ)));
			}
		}
	}
}
int main() {
	inp1(t);
	while(t--){
		inp3(O,m,n);
		getchar();
		FOR(i,m) {
			gets(map[i]);
			FOR(j,n){
				if(map[i][j] == 'T') {
					finishI=i;
					finishJ=j;
				}
				if(map[i][j] == 'S') {
					startI=i;
					startJ=j;
				}
			}
		}

		memset(dist,0x3a,sizeof(dist));

		dijkstra();

		// printf("%d %d ",dist[finishI][finishJ],O);
		if(dist[finishI][finishJ] <= O) printf("Possible\n");
		else printf("Impossible\n");
	}
	return 0;
}
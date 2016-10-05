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
typedef queue<int> QU;

const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 1000000;

vector<pair<int,pii> > lakes;
int r,c,k;
char map[52][52];
int visited[52][52];
int dx[4] = {0,-1,1,0};
int dy[4] = {-1,0,0,1};

int area;
bool adjSea;

bool inRange(int i, int j){
	if(0 <= i && i < r && 0 <= j && j < c) return true;
	return false;
}

bool isAdjSea(int i, int j){
	if(i == 0 || i == r-1 || j == 0 || j == c-1) return true;
	return false;
}
void dfs(int hereI, int hereJ){
	if(isAdjSea(hereI,hereJ)) adjSea=true;
	visited[hereI][hereJ] = 1;
	++area;
	FOR(i,4){
		int thereI = hereI + dy[i];
		int thereJ = hereJ + dx[i];
		if(inRange(thereI,thereJ) && visited[thereI][thereJ]==0 && map[thereI][thereJ] == '.') {
			dfs(thereI,thereJ);
		}
	}
}

void dfs2(int hereI, int hereJ){
	map[hereI][hereJ] = '*';
	FOR(i,4){
		int thereI = hereI + dy[i];
		int thereJ = hereJ + dx[i];
		if(inRange(thereI,thereJ) && map[thereI][thereJ] == '.') {
			dfs2(thereI,thereJ);
		}
	}
}
int main() {
	inp3(r,c,k);
	FOR(i,r){
		scanf("%s",map[i]);
	}

	FOR(i,r){
		FOR(j,c){
			if(map[i][j]=='.' && visited[i][j] == 0) {
				adjSea = false;
				dfs(i,j);
				if(!adjSea) lakes.pb(mp(area,mp(i,j)));
				area=0;
			}
		}
	}

	sort(lakes.begin(),lakes.end());
	int ans = 0;
	int curCnt = lakes.size();
	int i = 0;
	while(curCnt > k){
		ans += lakes[i].first;
		dfs2(lakes[i].second.first,lakes[i].second.second);
		++i;
		--curCnt;
	}
	printf("%d\n",ans);
	FOR(i,r){
		printf("%s\n",map[i]);
	}
	return 0;
}
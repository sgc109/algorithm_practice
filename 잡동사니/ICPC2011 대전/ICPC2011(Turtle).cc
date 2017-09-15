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
const int MAX_N = 1000000;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
char S[1000];

int main() {
	int T;
	inp1(T);
	while(T--){
		int maxX=0,minX=0;
		int maxY=0,minY=0;
		int curX=0,curY=0;
		int dir=0;
		scanf("%s",S);
		int len  = strlen(S);
		FOR(i,len){
			if(S[i]=='L') dir = (dir+3)%4;
			else if(S[i]=='R') dir = (dir+1)%4;
			else if(S[i]=='F') {
				curX+=dx[dir];
				curY+=dy[dir];
			}
			else if(S[i]=='B') {
				curX-=dx[dir];
				curY-=dy[dir];
			}
			maxX = max(maxX, curX);
			minX = min(minX, curX);
			maxY = max(maxY, curY);
			minY = min(minY, curY);
		}
		printf("%d\n",(maxX-minX)*(maxY-minY));
	}
	return 0;
}
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
#include <unordered_set>
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
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
typedef queue<int> QU;

const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 50002;

struct Dot{
	ll x,y;
} dots[MAX_N];
ll sortedX[MAX_N];
ll sortedY[MAX_N];

int n,k,w;

bool isPossible(ll x1, ll y1, ll x2, ll y2){
	int away=0;
	FOR(i,n){
		if(x1-w <= dots[i].x && dots[i].x <= x1 && y1-w <= dots[i].y && dots[i].y <= y2+w) continue;
		if(x2 <= dots[i].x && dots[i].x <= x2+w && y1-w <= dots[i].y && dots[i].y <= y2+w) continue;
		if(x1-w <= dots[i].x && dots[i].x <= x2+w){
			if(y2 <= dots[i].y && dots[i].y <= y2+w) continue;
			if(y1-w <= dots[i].y && dots[i].y <= y1) continue;
			++away;
			if(away>k) return false;
			continue;
		}
		return false;
	}
	return true;
}

int main() {
	// freopen("output.txt","w",stdout);
	FILE *fp = fopen("output.txt","wb");
	int T;
	inp1(T);
	printf("total test:%d\n",T);
	FOR(t,T){
		printf("%dth case...\n",t+1);
		unordered_set<ll> usX;
		unordered_set<ll> usY;
		int xCnt=0;
		int yCnt=0;
		inp3(n,k,w);
		FOR(i,n){
			ll x,y;
			scanf("%lld%lld",&x,&y);
			dots[i].x=x;
			dots[i].y=y;
			if(!usX.count(x)){
				sortedX[xCnt++] = x;
				usX.insert(x);
			}
			if(!usY.count(y)){
				sortedY[yCnt++] = y;
				usY.insert(y);
			}
		}
		sort(sortedX,sortedX+xCnt);
		sort(sortedY,sortedY+yCnt);
		bool poss=false;
		// printf("x:%lld~%lld, y:%lld~%lld, n:%d, k:%d, w:%d\n",sortedX[0],sortedX[xCnt-1],sortedY[0],sortedY[yCnt-1],n,k,w);
		FOR(ix,xCnt-1){
			if(sortedX[0] < sortedX[ix]-w) continue;
			REP(jx,ix+1,xCnt){
				if(sortedX[jx]+w < sortedX[xCnt-1]) continue;
				FOR(iy,yCnt-1){
					REP(jy,iy+1,yCnt){
						// printf("ix:%d, jx:%d, iy:%d, jy:%d\n",ix,jx,iy,jy);
						if(isPossible(sortedX[ix],sortedY[iy],sortedX[jx],sortedY[jy])) {
							// printf("x:%d~%d, y:%d~%d\n",sortedX[ix],sortedX[jx],sortedY[iy],sortedY[jy]);
							poss=true;
							goto hell;
						}
					}
				}
			}
		}
		hell:
		if(poss) fprintf(fp,"YES\n");
		else fprintf(fp,"NO\n");
	}
	return 0;
}
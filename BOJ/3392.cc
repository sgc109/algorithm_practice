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
const int MAX_CORD = 30010;
const int MAX_N = 10010;


struct Rect{
	int x1,y1,x2,y2;
};
pii nodes[4*MAX_CORD];
int size;
Rect rects[MAX_N];
pair<pii,int> Xs[2*MAX_N];
int n;
int ans;

void update(int nodeLeft, int nodeRight, int left, int right, int node, int isStart){
	if(left <= nodeLeft && nodeRight <= right) {
		nodes[node].second+=(isStart?1:-1);
		if(nodes[node].second == 0) {
			if(nodeLeft==nodeRight) nodes[node].first = 0;
			else nodes[node].first = nodes[2*node].first+nodes[2*node+1].first;
		}
		else {
			nodes[node].first = nodeRight-nodeLeft+1;
		}
		return;
	}	

	if(right < nodeLeft || nodeRight < left) return;
	int nodeMid = (nodeLeft+nodeRight) >> 1;
	update(nodeLeft, nodeMid, left, right, 2*node, isStart);
	update(nodeMid+1, nodeRight, left, right, 2*node+1, isStart);

	if(nodes[node].second == 0) {
		nodes[node].first = nodes[2*node].first+nodes[2*node+1].first;
	}
}

void update(int left, int right, int isStart){
	update(0,size-1,left,right,1,isStart);
}
int main() {
	inp1(n);
	size = MAX_CORD;
	FOR(i,n){
		int x1,y1,x2,y2;
		inp4(x1,y1,x2,y2);
		rects[i].x1 = x1;
		rects[i].y1 = y1;
		rects[i].x2 = x2;
		rects[i].y2 = y2;
		Xs[2*i] = mp(mp(x1,i),1);
		Xs[2*i+1] = mp(mp(x2,i),0);
	}
	sort(Xs,Xs+2*n);
	FOR(i,2*n){
		int l = rects[Xs[i].first.second].y1;
		int r = rects[Xs[i].first.second].y2;
		if(i!=0) ans+=(Xs[i].first.first-Xs[i-1].first.first)*nodes[1].first;
		update(l,r-1,Xs[i].second);
	}
	printf("%d",ans);

	return 0;
}
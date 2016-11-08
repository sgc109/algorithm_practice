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
#include <ctime>
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
const int MAX_N = 100002;
const int MAX_SIZE = 40040008;
struct Cord{
	int x,y;
};

pii rangeMaxXup[MAX_SIZE];
pii rangeMaxXdown[MAX_SIZE];
pii rangeMaxYleft[MAX_SIZE];
pii rangeMaxYright[MAX_SIZE];
vi adj[MAX_N];
int N,r,d;
int size;
int start;
pair<Cord,int> squares[MAX_N];

bool compX(const pair<Cord,int>& a, const pair<Cord,int>& b) {
	return a.first.x < b.first.x;
}
bool compY(const pair<Cord,int>& a, const pair<Cord,int>& b) {
	return a.first.y < b.first.y;
}
bool compI(const pair<Cord,int>& a, const pair<Cord,int>& b) {
	return a.second < b.second;
}

// void init(int nodeLeft, int nodeRight, int node, vector<pii>& v) {
// 	if(nodeLeft == nodeRight) {
// 		v[node] = mp(-1,-1);
// 		return;
// 	}
// 	int nodeMid=(nodeLeft+nodeRight)>>1;
// 	init(nodeLeft,nodeMid,2*node,v);
// 	init(nodeMid+1,nodeRight,2*node+1,v);
// 	v[node] = v[2*node].first >= v[2*node+1].first ? v[2*node] : v[2*node+1];
// }

pii query(int nodeLeft, int nodeRight, int left, int right, int node, pii (&v)[MAX_SIZE]) {
	if(left <= nodeLeft && nodeRight <= right) {
		return v[node];
	}
	if(right < nodeLeft || nodeRight < left) return mp(-1,-1);
	int nodeMid=(nodeLeft+nodeRight)>>1;
	pii leftRange = query(nodeLeft,nodeMid,left,right,2*node,v);
	pii rightRange = query(nodeMid+1,nodeRight,left,right,2*node+1,v);
	return leftRange.first >= rightRange.first ? leftRange : rightRange;
}

void update(int nodeLeft, int nodeRight, int node, int pos, int val, int id, pii (&v)[MAX_SIZE]) {
	if(nodeLeft == nodeRight && nodeRight == pos) {
		if(v[node].first <= val) v[node] = mp(val,id);
		return;
	}
	if(pos < nodeLeft || nodeRight < pos) return;
	int nodeMid=(nodeLeft+nodeRight)>>1;
	update(nodeLeft,nodeMid,2*node,pos,val,id,v);
	update(nodeMid+1,nodeRight,2*node+1,pos,val,id,v);
	v[node] = v[2*node].first >= v[2*node+1].first ? v[2*node] : v[2*node+1];
}

void update(int pos, int val, int id, pii (&v)[MAX_SIZE]){
	update(0,size-1,1,pos,val,id,v);
}

pii query(int left, int right, pii (&v)[MAX_SIZE]) {
	return query(0,size-1,left,right,1,v);
}

int ans;
int visited[MAX_N];
queue<int> q;
void bfs(int start) {
	q.push(start);
	visited[start]=1;
	while(!q.empty()) {
		int here = q.front();
		ans = max(ans,squares[here-1].first.x+squares[here-1].first.y+2*r);
		q.pop();
		for(auto& there : adj[here]){
			if(visited[there]) continue;
			q.push(there);
			visited[there]=1;
		}
	}
}

int main() {
	// clock_t before;
	// double result;
	// before = clock();

	inp2(N,r);
	size=10010002;
	FOR(i,N){
		int x,y;
		inp2(x,y);
		if(x==0&&y==0) start=i+1;
		squares[i] = mp(Cord({x,y}),i+1);
	}
	inp1(d);

	// init(0,size-1,1,rangeMaxXup);
	// init(0,size-1,1,rangeMaxXdown);
	// init(0,size-1,1,rangeMaxYleft);
	// init(0,size-1,1,rangeMaxYright);

	sort(squares,squares+N,compX);

	FOR(i,N) {
		// printf("i's x:%d, y:%d\n",squares[i].first.x,squares[i].first.y);
		auto nearestSqrUp = query(squares[i].first.y,squares[i].first.y+r,rangeMaxXup);
		// printf("i:%d, nearestSqrUpId:%d\n",i,nearestSqrUp.second);
		if(nearestSqrUp.second != 0) {
			int dist = squares[i].first.x - nearestSqrUp.first;
			if(dist <= d) {
				adj[nearestSqrUp.second].pb(squares[i].second);
				adj[squares[i].second].pb(nearestSqrUp.second);
			}
		} 
		auto nearestSqrDown = query(squares[i].first.y,squares[i].first.y+r,rangeMaxXdown);
		// printf("i:%d, nearestSqrDownId:%d\n",i,nearestSqrDown.second);
		if(nearestSqrDown.second != 0) {
			int dist = squares[i].first.x - nearestSqrDown.first;
			if(dist <= d) {
				adj[nearestSqrDown.second].pb(squares[i].second);
				adj[squares[i].second].pb(nearestSqrDown.second);
			}
		}
		update(squares[i].first.y+r,squares[i].first.x+r,squares[i].second,rangeMaxXup);
		update(squares[i].first.y,squares[i].first.x+r,squares[i].second,rangeMaxXdown);
	}

	sort(squares,squares+N,compY);

	FOR(i,N) {
		// printf("i's x:%d, y:%d\n",squares[i].first.x,squares[i].first.y);
		auto nearestSqrLeft = query(squares[i].first.x,squares[i].first.x+r,rangeMaxYleft);
		// printf("i:%d, nearestSqrUpId:%d\n",i,nearestSqrUp.second);
		if(nearestSqrLeft.second != 0) {
			int dist = squares[i].first.y - nearestSqrLeft.first;
			if(dist <= d) {
				adj[nearestSqrLeft.second].pb(squares[i].second);
				adj[squares[i].second].pb(nearestSqrLeft.second);
			}
		} 
		auto nearestSqrRight = query(squares[i].first.x,squares[i].first.x+r,rangeMaxYright);
		// printf("i:%d, nearestSqrDownId:%d\n",i,nearestSqrDown.second);
		if(nearestSqrRight.second != 0) {
			int dist = squares[i].first.y - nearestSqrRight.first;
			if(dist <= d) {
				adj[nearestSqrRight.second].pb(squares[i].second);
				adj[squares[i].second].pb(nearestSqrRight.second);
			}
		}
		update(squares[i].first.x,squares[i].first.y+r,squares[i].second,rangeMaxYleft);
		update(squares[i].first.x+r,squares[i].first.y+r,squares[i].second,rangeMaxYright);
	}

	sort(squares,squares+N,compI);

	bfs(start);

	printf("%d",ans);


	// result = (double)(clock() - before) / CLOCKS_PER_SEC;

	// printf("\n%5.2fs\n", result); 

	return 0;
}
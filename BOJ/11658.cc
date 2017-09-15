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
#define all(v) (v).begin(),(v).end()
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
typedef queue<int> QU;

const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int N,M;
int map[1<<10+1][1<<10+1];
int pSum[1<<10+1][1<<10+1];
int t[1<<10+1][1<<10+1];

void update(int y, int x, int c){
	while(x<=N){
		int y1= y;
		while(y1<=N){
			t[y1][x]+=c;
			y1+=y1&-y1;
		}
		x+=x&-x;
	}
}
int query(int y, int x){
	int ret=0;
	while(x>0){
		int y1=y;
		while(y1>0){
			ret+=t[y1][x];
			y1-=y1&-y1;
		}
		x-=x&-x;
	}
	return ret;
}
int query(int y1, int x1, int y2, int x2){
	return query(y2,x2)-query(y2,x1-1)-query(y1-1,x2)+query(y1-1,x1-1);
}
int main() {
	inp2(N,M);
	FOR(i,N) FOR(j,N) inp1(map[i+1][j+1]);
	//point update, range query인 2D 펜윅트리.
	//처음에 2D 펜윅 트리를 초기화 하는 방법이 내방법이 있고 doju님 방법이 있음

	// 내방법
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			pSum[i][j] = pSum[i-1][j]+pSum[i][j-1]-pSum[i-1][j-1]+map[i][j];
		}
	}
	for(int i=1; i <=N; i++){
		for(int j=1; j<=N; j++){
			t[i][j] = pSum[i][j]-pSum[i-(i&-i)][j]-pSum[i][j-(j&-j)]+pSum[i-(i&-i)][j-(j&-j)];
		}
	}

	//doju님 방법
	/*for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) t[i][j]=map[i][j];
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			int nj = j+(j&-j);
			if(nj<=N) t[i][nj]+=t[i][j];
		}
	}
	for(int j=1; j<=N; j++){
		for(int i=1; i<=N; i++){
			int ni = i+(i&-i);
			if(ni<=N) t[ni][j]+=t[i][j];
		}
	}*/
	while(M--){
		int op;
		inp1(op);
		if(op){
			int y1,x1,y2,x2;
			inp4(y1,x1,y2,x2);
			printf("%d\n",query(y1,x1,y2,x2));
		}
		else {
			int y,x,c;
			inp3(y,x,c);
			int now = query(y,x,y,x);
			update(y,x,c-now);
		}
	}
	return 0;
}

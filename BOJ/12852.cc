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
#include <map>
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

const int INF = 0x3a3a3a3a;
const long long INFL = 0x3a3a3a3a3a3a3a3a;
const int MAX_N = 1000002;

queue<int> q;
int depth[MAX_N];
int from[MAX_N];

void bfs(int start) {
	q.push(start);
	depth[start] = 0;
	while(!q.empty()) {
		int here = q.front();
		q.pop();
		if(here==1) break;
		if(here%3==0 && depth[here/3] == -1) {
			depth[here/3] = 1+depth[here];
			from[here/3] = here;
			q.push(here/3);
		}
		if(here%2==0 && depth[here/2] == -1) {
			depth[here/2] = 1+depth[here];
			from[here/2] = here;
			q.push(here/2);
		}
		if(depth[here-1] == -1) {
			depth[here-1] = 1+depth[here];
			from[here-1] = here;
			q.push(here-1);
		}
	}

}

int main() {
	memset(depth,-1,sizeof(depth));
	int n;
	inp1(n);
	if(n==1) {
		printf("0\n1");
		return 0;
	}
	bfs(n);
	printf("%d\n",depth[1]);
	vector<int> path;
	path.pb(1);
	int pos=1;
	while(pos!=n) {
		pos = from[pos];
		path.pb(pos);
	}
	for(int i = path.size()-1; i >=0; --i) {
		printf("%d ",path[i]);
	}

	return 0;
}
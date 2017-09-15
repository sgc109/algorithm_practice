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
#include <deque>
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

const double EPSILON = 1e-9;
const double PI = acos(0.0)*2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 2002;

int n;
int dist[MAX_N][MAX_N];
int main() {
	FOR(i,MAX_N) FOR(j,MAX_N) dist[i][j]=-1;
	inp1(n);
	queue<pii> q;
	q.push(mp(1,0));
	dist[1][0]=0;
	int ans;
	while(!q.empty()){
		int cnt = q.front().first;
		int clip = q.front().second;
		q.pop();
		if(cnt==n){
			ans=dist[cnt][clip];
			break;
		}
		if(cnt-1 >= 0 && dist[cnt-1][clip]==-1) dist[cnt-1][clip]=dist[cnt][clip]+1,q.push(mp(cnt-1,clip));
		if(dist[cnt][cnt]==-1) dist[cnt][cnt]=dist[cnt][clip]+1,q.push(mp(cnt,cnt));
		if(cnt+clip < MAX_N && dist[cnt+clip][clip]==-1) dist[cnt+clip][clip]=dist[cnt][clip]+1,q.push(mp(cnt+clip,clip));
	}
	printf("%d",ans);
	return 0;
}
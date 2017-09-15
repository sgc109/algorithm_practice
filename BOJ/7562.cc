#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int,pair<int,int> > piii;
const double EPSILON = 1e-9;
const double PI = acos(0.0)*2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int N,T;
int a,b,c,d;
int dy[]={-2,-2,-1,1,2,2,1,-1};
int dx[]={-1,1,2,2,1,-1,-2,-2};
int pane[303][303];
bool inRange(int i, int j){
	return 0 <= i && i < N && 0 <= j && j < N;
}
int main() {
	for(scanf("%d",&T);T--;){
		memset(pane,0,sizeof(pane));
		queue<pair<int,int> > q;
		scanf("%d",&N);
		scanf("%d%d%d%d",&a,&b,&c,&d);
		pane[a][b]=1;
		q.push({a,b});
		int ans;
		while(!q.empty()){
			int hereI=q.front().first, hereJ=q.front().second;
			int hereDist = pane[hereI][hereJ];
			q.pop();
			if(hereI==c&&hereJ==d) {
				ans=hereDist-1;
				break;
			}
			for(int i=0;i<8;i++){
				int thereI=hereI+dy[i],thereJ=hereJ+dx[i];
				if(!inRange(thereI,thereJ) || pane[thereI][thereJ]) continue;
				pane[thereI][thereJ] = hereDist+1;
				q.push({thereI,thereJ});
			}

		}
		printf("%d\n",ans);
	}
	return 0;
}

#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)
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
typedef vector<pair<int,int> > vii;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
const double EPSILON = 1e-9;
const double PI = acos(0.0)*2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int dy[]={-1,0,0,1};
int dx[]={0,-1,1,0};
int Map[103][103];
int visited[103][103];
int dist[103][103];
int N;
int landCnt;
bool inRange(int i, int j){
	return 0<=i&&i<N&&0<=j&&j<N;
}
void dfs(int hereI, int hereJ){
	visited[hereI][hereJ]=1;
	Map[hereI][hereJ]=landCnt;
	FOR(i,4){
		int thereI=hereI+dy[i];
		int thereJ=hereJ+dx[i];
		if(!inRange(thereI,thereJ)||visited[thereI][thereJ]||Map[thereI][thereJ]==0) continue;
		dfs(thereI,thereJ);
	}
}
int main() {
	landCnt=1;
	inp1(N);
	FOR(i,N) FOR(j,N) inp1(Map[i][j]);
	FOR(i,N){
		FOR(j,N) {
			if(visited[i][j]||Map[i][j]==0) continue;
			dfs(i,j);
			landCnt++;
		}
	}
	landCnt--;
	int ans=INF;
	memset(dist,-1,sizeof(dist));
	queue<piii> q;
	FOR(i,N){
		FOR(j,N){
			if(Map[i][j]==k) q.push({i,j}),dist[i][j]=0;
		}
	}
	while(!q.empty()){
		int hereI=q.front().first;
		int hereJ=q.front().second;
		q.pop();
		FOR(i,4){
			int thereI=hereI+dy[i];
			int thereJ=hereJ+dx[i];
			if(!inRange(thereI,thereJ)||dist[thereI][thereJ]!=-1)continue;
			dist[thereI][thereJ]=dist[hereI][hereJ]+1;
			q.push({thereI,thereJ});
			if(Map[thereI][thereJ]!=0&&Map[thereI][thereJ]!=k) {
				ans=min(ans,dist[thereI][thereJ]);
				break;
			}
		}
	}
	printf("%d",ans-1);
	return 0;
}

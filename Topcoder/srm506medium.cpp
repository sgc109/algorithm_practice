/*
https://community.topcoder.com/stat?c=problem_statement&pm=11334

처음엔 상태들을 잘 정의한뒤 그래프를 형성해서 다익스트라를 돌리는 식으로 풀 수가 있을 거라고 생각했는데
쉽지않았다. 아마 지금까지 그렇게 풀었던 문제들은 문제에서 주어진 경로대로 이동하는 것이 아니라
출발지와 도착지만 주어지고 출발지에서 도착지로 이동하는 가장 적은 비용을 묻는 문제였던것같고
이 문제는 경로가 주어지고 반드시 그 경로대로 이동해야 하면서 한정된 자원이 존재할 때에 최소 비용을 구하는 문제이다.
그래서 이 문제는 network flow graph 로 풀 수가 있고 최소 비용을 찾아야 하기 때문에 mcmf 로 풀 수가 있다.
우선 한가지 사실을 깨달아야 한다. 경로가 주어졌으니 k번째 도시가 출발지일때 k+1번째 도시는 도착지라고 볼 수가있다.
그렇다면 맨처음 0번도시에 있다는 것을 고려했을때 입력으로 주어진 도시들의 배열의 크기가 M 이라면
M개의 경로(출발지와 도착지 쌍으로 이루어진)를 결정해서 다 더해주면 되는 것인데 중요한것은 각각의 M개의 경로에서
아무리 많아야 차를 딱 한 대만 이용하는 것이 무조건 이득이라는 것이다. 왜냐하면 일단 차를 한번 타면 어디로든 갈 수가
있기 때문에 굳이 차를 하나 더 소모하면서 중간에 다른 차를 갈아탈 필요가 없는 것이다. 그렇기 때문에 각각의 M개의 경로에서는
이러한 선택을 하면된다. 차를 탈 것인지 안 탈 것인지, 만약 차를 탄다면 어떤 차를 탈 것인지. 이것만 결정 하면되는것이다.
(현재 있는 도시에 있지 않은 차를 탄다는 것은 그 차가 있는 도시까지 걸어간뒤 차를 탄다는 말을 함축한 것이라는 사실도 중요하다.)
플로우에서는 특정 자원이 한정되어 있기 때문에 이미 앞서 내린 결정을 무르면서 좀 더 최적의 선택으로 바꿀 수가 있는데
여기서도 만약 특정 차를 다른 경로를 이동할 때 이용했을 때 더 이득이라면 무를 수가 있는 것이다.
즉 유량 그래프의 source 와 sink 를 제외하고 내부의 노드들을 단계별로 그룹1과 그룹2로 나누었을 때
그룹1은 M개의 경로가 되는것이고 그룹2는 자동차들과 걷기에 해당하는 것이다. 처음에 같은 곳에 존재하는 자동차들을 하나로
합쳐야 한다고 생각했는데 그럴 필요가 없었다. 각각의 자동차는 딱 한번만 탈 수 있기 때문에 capacity는 1이고
걸어가는건 무제한이기 때문에 capacity 는 INF 이다. 그리고 그룹1과 그룹2 사이의 비용은 우선 모든 노드 쌍 사이의 최단경로를
구한뒤(플로이드) 문제에서 주어진 조건을 합쳐서 걸어갈 때와 자동차를 탈 때를 각각 잘 계산하여 넣어주면 된다.
*/

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
#define inp5(a,b,c,d,e) scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)
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
typedef vector<piii> viii;
const double EPSILON = 1e-9;
const double PI = acos(-1);
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;
const int MAX_V = 150;
class SlimeXGrandSlimeAuto{
public:
	int N,M,K,S,T;
	int D[53][53];
	int cap[MAX_V][MAX_V], cost[MAX_V][MAX_V];
	int inQ[MAX_V], parent[MAX_V], dist[MAX_V];
	vector<int> G[MAX_V];
	unordered_map<char,int> mp;
	inline int G1(int x){return 2+x;}
	inline int G2(int x){return 2+M+x;}
	void connect(int a, int b, int c, int d){
		G[a].push_back(b);
		G[b].push_back(a);
		cap[a][b]=c;
		cost[a][b]=d;
		cost[b][a]=-d;
	}
	void floyd(){
		FOR(k,N) FOR(i,N) FOR(j,N) D[i][j] = min(D[i][j],D[i][k]+D[k][j]);
	}
	int mcmf(){
		int ret=0;
		while(1){
			memset(inQ,0,sizeof(inQ));
			memset(parent,-1,sizeof(parent));
			memset(dist,0x3c,sizeof(dist));
			queue<int> q;
			q.push(S);
			dist[S]=0;
			inQ[S]=1;
			while(!q.empty()){
				int here = q.front();
				q.pop();
				inQ[here]=0;
				for(int there : G[here]){
					int thereD = dist[here]+cost[here][there];
					if(cap[here][there] <= 0 || dist[there] <= thereD) continue;
					dist[there] = thereD;
					parent[there] = here;
					inQ[there]=1;
					q.push(there);
				}
			}
			if(parent[T]==-1) break;
			int costSum=0;
			int minCap=INF;
			for(int p = T; p!=S; p=parent[p]){
				minCap = min(minCap,cap[parent[p]][p]);
				costSum+=cost[parent[p]][p];
			}
			for(int p = T; p!=S; p=parent[p]){
				cap[parent[p]][p]-=minCap;
				cap[p][parent[p]]+=minCap;
			}
			ret+=costSum*minCap;
		}
		return ret;
	}
	int travel(vector <int> cars, vector <int> districts, vector <string> roads, int inverseWalkSpeed, int inverseDriveSpeed){
		vector<int> tmp;
		tmp.push_back(0);
		FOR(i,districts.size()) tmp.push_back(districts[i]);
		districts = tmp;
		memset(cap,0,sizeof(cap));
		memset(cost,0,sizeof(cost));
		memset(D,0x3c,sizeof(D));
		S=0, T=1;
		N = roads.size();
		M = districts.size();
		K = cars.size();
		FOR(i,10) mp[i+'0']=i+1;
		FOR(i,26) mp[i+'a']=i+11;
		FOR(i,26) mp[i+'A']=i+37;
		mp['.']=INF;
		FOR(i,N) FOR(j,N) D[i][j] = mp[roads[i][j]];
		FOR(i,N) D[i][i] = 0;
		floyd();
		FOR(i,M-1) connect(S,G1(i),1,0);
		FOR(i,K) connect(G2(i),T,1,0);
		connect(G2(K),T,INF,0);
		FOR(i,M-1){
			FOR(j,K){
				int firstWalk = inverseWalkSpeed*D[districts[i]][cars[j]];
				int secondDrive = inverseDriveSpeed*D[cars[j]][districts[i+1]];
				connect(G1(i),G2(j),1,firstWalk+secondDrive);
			}
			connect(G1(i),G2(K),1,inverseWalkSpeed*D[districts[i]][districts[i+1]]);
		}
		return mcmf();
	}
};

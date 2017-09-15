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
#define fastio() ios_base::sync_with_stdio(false),cin.tie(NULL)
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
const int ADD = 32741;

ll h[129][129][129];
string qStr[129][129][129];
int isLeaf[129][129][129];
int pane[129][129];
int N, M;
int dy[] = {0, 0, 1, 1};
int dx[] = {0, 1, 0, 1};
map<ll, int> mp;
ll hashFunc(string str){
	ll ret = 0;
	for(int i = 0; i < str.size(); i++){
		ret = (ret * ADD + str[i]) % MOD;
	}	
	return ret;
}
int go(int posI, int posJ, int size){
	int start = pane[posI][posJ];
	bool allSame = true;
	for(int i = posI; i < posI + size; i++){
		for(int j = posJ; j < posJ + size; j++){
			if(start != pane[i][j]) allSame = false;
		}
	}
	string& here = qStr[posI][posJ][size];
	if(allSame){
		isLeaf[posI][posJ][size] = 1;
		here = (pane[posI][posJ] == 0 ? "W" : "B");
		return 1;
	}

	here = "X";
	int ret = 1;
	FOR(k,4){
		int s = size/2;
		string& next = qStr[posI + dy[k]*s][posJ + dx[k]*s][s];
		ret += go(posI + dy[k]*s, posJ + dx[k]*s, s);
		here += next;
	}
	return ret;
}

int dfs(int posI, int posJ, int size){
	if(isLeaf[posI][posJ][size]) return 1;
	if(mp[hashFunc(qStr[posI][posJ][size])]) return 0;
	mp[hashFunc(qStr[posI][posJ][size])] = 1;

	int ret = 1;
	FOR(k,4){
		int s = size/2;
		ret += dfs(posI + dy[k]*s, posJ + dx[k]*s, s);
	}
	return ret;
}
int main() {
	memset(pane,-1,sizeof(pane));
	memset(isLeaf,0,sizeof(isLeaf));
	inp2(N,M);
	FOR(i,N){
		FOR(j,M){
			scanf("%1d",&pane[i][j]);
		}
	}

	M = (1<<(int)(ceil(log2(M))));
	N = (1<<(int)(ceil(log2(N))));

	M = N = max(N,M);

	FOR(i,N){
		FOR(j,M){
			if(pane[i][j] == -1) pane[i][j] = 0;
		}
	}

	int ans1 = go(0,0,N);
	int ans2 = dfs(0,0,N);
	printf("%d %d\n",ans1,ans2);

	return 0;
}

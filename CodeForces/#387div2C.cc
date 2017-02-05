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

int n,q;
piii tasks[100002];
vector<piii> query;
vi occupying[100002];
int isOccu[102];
int main() {
	inp2(n,q);
	int cntAvail = n;
	FOR(i,q){
		int a,b,c;
		inp3(a,b,c);
		tasks[i] = mp(a,mp(b,c));
		query.pb(mp(a,mp(1,i)));
		query.pb(mp(a+c,mp(-1,i)));
	}
	sort(query.begin(),query.end());
	FOR(i,query.size()){
		piii q = query[i];
		int inOrOut = q.second.first;
		int id = q.second.second;
		if(inOrOut == -1){
			FOR(j,occupying[id].size()) isOccu[occupying[id][j]]=0;
			cntAvail+=occupying[id].size();
			occupying[id].clear();
		}
		else {
			if(cntAvail < tasks[id].second.first) {
				printf("-1\n");
				continue;
			}
			int ans=0;
			int it = tasks[id].second.first;
			FOR(j,n){
				if(isOccu[j]) continue;
				ans+=j+1;
				isOccu[j]=1;
				occupying[id].pb(j);
				it--;
				if(it<=0) break;
			}
			cntAvail-=tasks[id].second.first;
			printf("%d\n",ans);
		}
	}
	return 0;
}
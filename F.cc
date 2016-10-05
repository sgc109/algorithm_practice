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
const int MAX_N = 200002;

int parent[MAX_N];
int depth[MAX_N];
vi adj[MAX_N];
int n,m;
int s,t,ds,dt;
int connected[MAX_N][2];
vector<pii> ans;

int find(int a){
	if(parent[a]==a) return a;
	return parent[a] = find(parent[a]);//
}
int merge(int a, int b){
	int parentA = find(a);
	int parentB = find(b);
	if(parentA == parentB) return -1;
	if(depth[parentA] < depth[parentB]) swap(parentA,parentB);

	parent[parentB] = parentA;
	if(depth[parentA] == depth[parentB]) depth[parentA]++;

	return parentA;//
}
void isImpossible(){
	if(ds <0 || dt<0) {
		printf("No");
		exit(0);
	}
}
int main() {
	inp2(n,m);
	REP(i,1,n+1) {
		parent[i]=i;
		depth[i]=0;
	}
	FOR(i,m){
		int a,b;
		inp2(a,b);
		adj[a].pb(b);
		adj[b].pb(a);
	}
	inp4(s,t,ds,dt);
	REP(here,1,n+1){
		if(here==s||here==t) continue;
		for(int& there : adj[here]){
			if(there==s||there==t) continue;
			if(merge(here,there)!=-1){
				ans.pb(mp(here,there));
			}
		}
	}
	// printf("%d %d\n",parent[s],parent[t]);
	int ST[2] = {s,t};
	FOR(i,2){
		int here = ST[i];
		for(int& there : adj[here]){
			// printf("here:%d, there:%d\n",here,there);
			int p = find(there);
			connected[p][i]=there;
		}
	}
	// printf("connected[s][t]:%d\n",connected[s][t]);

	bool found=false;
	REP(here,1,n+1){
		if(here==s||here==t) continue;
		int p = find(here);
		if(connected[p][0] > 0 && connected[p][1] > 0) {
			ds--;
			dt--;
			ans.pb(mp(connected[p][0],s));
			ans.pb(mp(connected[p][1],t));
			connected[p][0]=0;
			connected[p][1]=0;
			found=true;
			break;
		}
	}
	queue<pii> hanged;
	if(found){
		REP(here,1,n+1){
			if(here==s||here==t) continue;
			int p = find(here);
			if(connected[p][0] > 0 && connected[p][1] > 0){
				hanged.push(mp(connected[p][0],connected[p][1]));
				connected[p][0] = 0;
				connected[p][1] = 0;
			}
			else {
				if(connected[p][0] > 0){
					ds--;
					ans.pb(mp(connected[p][0],s));
					connected[p][0] = 0;
				}
				else if(connected[p][1] > 0){
					dt--;
					ans.pb(mp(connected[p][1],t));
					connected[p][1] = 0;
				}
					// printf("1\n");
				isImpossible();
					// printf("2\n");
			}
		}
		//printf("7\n");
		if(ds+dt < hanged.size()) {
			printf("No");
			return 0;
		}
		//printf("8\n");
		while(ds > 0 && !hanged.empty()) {
			ans.pb(mp(hanged.front().first,s));
			hanged.pop();
			ds--;
		}
		while(dt > 0 && !hanged.empty()) {
			ans.pb(mp(hanged.front().second,t));
			hanged.pop();
			dt--;
		}
	}
	else {
		// printf("11\n");
		if(connected[s][1] == 0 && connected[t][0] == 0) {
			// printf("%d %d\n",s,t);
			printf("No");
			return 0;	
		}
		// printf("12\n");
		REP(here,1,n+1){
			if(here==s||here==t) continue;
			int p = find(here);
			if(connected[p][0] > 0){
				ds--;
				ans.pb(mp(connected[p][0],s));
				connected[p][0] = 0;
			}
			else if(connected[p][1] > 0){
				dt--;
				ans.pb(mp(connected[p][1],t));
				connected[p][1] = 0;
			}
			isImpossible();
		}
		ans.pb(mp(s,t));
		ds--;dt--;
		isImpossible();
	}
	if(ans.size() != n-1) {
		printf("No");
		return 0;
	}
	printf("Yes\n");
	FOR(i,ans.size()){
		printf("%d %d\n",ans[i].first,ans[i].second);
	}
	return 0;
}
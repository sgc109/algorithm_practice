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
#include <unordered_set>
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
const int MAX_N = 10000;

vector<ll> comp;
unordered_set<ll> compSet;
ll w1,h1,w2,h2;
pair<int,pll> dist1[MAX_N];
pair<int,pll> dist2[MAX_N];
int trans(ll x){
	return lower_bound(comp.begin(),comp.end(),x)-comp.begin();
}
void dfs1(ll here){
	if(!compSet.count(here)) {
		comp.pb(here);
		compSet.insert(here);
	}
	else return;
	if(here%2==0) dfs1(here/2);
	if(here%3==0) dfs1(here*2/3);
}
void bfs1(){
	queue<pair<int,pll> > q;
	q.push(mp(0,mp(w1,h1)));
	while(!q.empty()){
		int cost = q.front().first;
		ll hereW = q.front().second.first;
		ll hereH = q.front().second.second;
		q.pop();
		int here = trans(hereW*hereH);
		if(dist1[here].first!=-1) continue;
		dist1[here] = mp(cost,mp(hereW,hereH));
		if(hereW%2==0) {
			q.push(mp(cost+1,mp(hereW/2,hereH)));
		}
		if(hereW%3==0) {
			q.push(mp(cost+1,mp(hereW*2/3,hereH)));
		}
		if(hereH%2==0){
			q.push(mp(cost+1,mp(hereW,hereH/2)));
		}
		if(hereH%3==0){
			q.push(mp(cost+1,mp(hereW,hereH*2/3)));
		}
	}
}
void bfs2(){
	queue<pair<int,pll> > q;
	q.push(mp(0,mp(w2,h2)));
	while(!q.empty()){
		int cost = q.front().first;
		ll hereW = q.front().second.first;
		ll hereH = q.front().second.second;
		q.pop();
		int here = trans(hereW*hereH);
		if(dist2[here].first!=-1) continue;
		dist2[here] = mp(cost,mp(hereW,hereH));
		if(dist1[here].first!=-1) {
			printf("%d\n",dist1[here].first+dist2[here].first);
			printf("%I64d %I64d\n%I64d %I64d",dist1[here].second.first,dist1[here].second.second,dist2[here].second.first,dist2[here].second.second);
			exit(0);
		}
		if(hereW%2==0) {
			q.push(mp(cost+1,mp(hereW/2,hereH)));
		}
		if(hereW%3==0) {
			q.push(mp(cost+1,mp(hereW*2/3,hereH)));
		}
		if(hereH%2==0){
			q.push(mp(cost+1,mp(hereW,hereH/2)));
		}
		if(hereH%3==0){
			q.push(mp(cost+1,mp(hereW,hereH*2/3)));
		}
	}
}
int main() {
	FOR(i,MAX_N) dist1[i]=mp(-1,mp(0,0));
	FOR(i,MAX_N) dist2[i]=mp(-1,mp(0,0));
	scanf("%I64d%I64d%I64d%I64d",&w1,&h1,&w2,&h2);
	dfs1(w1*h1);
	dfs1(w2*h2);
	sort(comp.begin(),comp.end());
	bfs1();
	bfs2();
	printf("-1");

	return 0;
}
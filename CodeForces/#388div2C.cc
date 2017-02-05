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

int cant[200002];
char team[200003];
set<int> index[2];
int main() {
	int n;
	int cnt1=0;
	int cnt2=0;
	inp1(n);
	scanf("%s",team);
	FOR(i,n){
		if(team[i]=='R') {
			index[0].insert(i);
			cnt1++;
		}
		else {
			index[1].insert(i);
			cnt2++;
		}
	}
	while(1){
		FOR(i,n){
			// printf("i:%d\n",i);
			if(cnt1==0||cnt2==0) goto hell;
			if(cant[i]) continue;
			int turn = team[i]=='R'?0:1;
			set<int>::iterator idx;
			if(i < *index[turn^1].rbegin())	idx = index[turn^1].lower_bound(i);
			else idx = index[turn^1].begin();
			cant[*idx]=1;
			// printf("deleted:%d\n",*idx);
			index[turn^1].erase(idx);
			if(turn) cnt1--;
			else cnt2--;
		}
	}
	hell:
	if(cnt1) printf("R");
	else printf("D");


	
	return 0;
}
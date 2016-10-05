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
const int MAX_N = 1000000;

int change[2002][2002];
int changed;
pii arr[2002];
int firstOrder[2002];
int n,m;
int limit;
int main() {
	inp2(n,m);
	limit = n/m;
	FOR(i,m+1){
		arr[i].second = i;
	}
	FOR(i,n){
		int tmp;
		inp1(tmp);
		firstOrder[i] = tmp;
		if(tmp <= m) arr[tmp].first++;
		else arr[0].first++;
	}
	sort(arr+1,arr+1+m);

	while(arr[0].first > 0 && arr[1].first < limit) {
		arr[1].first++;
		arr[0].first--;
		++changed;
		change[0][arr[1].second]++;
		sort(arr+1,arr+1+m);
	}

	while(arr[1].first < limit){
		arr[1].first++;
		arr[m].first--;
		++changed;
		change[arr[m].second][arr[1].second]++;
		sort(arr+1,arr+1+m);
	}

	printf("%d %d\n",limit,changed);
	FOR(i,n){
		bool find = false;
		if(firstOrder[i] > m) {
			REP(j,1,m+1){
				if(change[0][j]) {
					printf("%d ",j);
					change[0][j]--;
					find=true;
					break;
				}
			}
		}
		else {
			REP(j,1,m+1){
				if(change[firstOrder[i]][j]) {
					printf("%d ",j);
					change[firstOrder[i]][j]--;
					find=true;
					break;
				}
			}
		}
		if(!find) printf("%d ",firstOrder[i]);
	}
	return 0;
}
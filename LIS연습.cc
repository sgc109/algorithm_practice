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
// #define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)

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

int arr[MAX_N];
int parent[MAX_N];
int index[MAX_N];
int C[MAX_N];
int n;

int main() {
	inp1(n);
	FOR(i,n){
		inp1(arr[i+1]);
	}
	int maxLen=0,maxI;
	REP(i,1,n+1){
		int tmp = lower_bound(C+1,C+maxLen+1,arr[i])-C;
		if(maxLen<tmp){
			maxLen=tmp;
			maxI=i;
		}
		C[tmp]=arr[i];
		index[tmp]=i;
		parent[i]=index[tmp-1];
	}
	vi ans;
	while(parent[maxI]!=maxI){
		ans.pb(arr[maxI]);
		maxI = parent[maxI];
	}
	reverse(ans.begin(),ans.end());
	FOR(i,ans.size()){
		printf("%d ",ans[i]);
	}
	return 0;
}
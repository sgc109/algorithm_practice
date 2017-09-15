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
const int MAX_N = 10002;

int n;
int arr[MAX_N];
int m;
int limitSum(int limit){
	int ret=0;
	for(int i = 0 ; i < n ; i ++) ret+=min(limit,arr[i]);
	return ret;
}
int main() {
	scanf("%d",&n);
	int sum=0;
	int maxx=0;
	for(int i = 0 ; i < n ; i++) {
		scanf("%d",arr+i);
		maxx=max(maxx,arr[i]);
		sum+=arr[i];
	}
	scanf("%d",&m);
	if(sum <= m) {
		printf("%d",maxx);
		return 0;
	}
	int lo=0,hi=1e9+1;
	while(lo<hi){
		int mid=(lo+hi)>>1;
		if(limitSum(mid)<=m) lo=mid+1;
		else hi=mid;
	}
	lo--;
	printf("%d",lo);

	return 0;
}

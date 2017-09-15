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
const int MAX_N = 100002;

int n,m;
int arr[MAX_N];
bool poss(int limit){
	int cnt=0;
	int sum=0;
	FOR(i,n){
		if(arr[i]>limit) return false;
		else if(sum+arr[i]>limit) cnt++,sum=arr[i];
		else sum+=arr[i];		
	}
	if(sum) cnt++;
	return cnt<=m;
}
int main() {
	inp2(n,m);
	FOR(i,n) inp1(arr[i]);
	int lo=1,hi=2e9;
	while(lo<hi){
		int mid=(lo+hi)>>1;
		if(poss(mid)) hi=mid;
		else lo=mid+1;
	}
	printf("%d",lo);
	return 0;
}

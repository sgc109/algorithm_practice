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

int arr[100002];
int main() {
	int n,a,b;
	int tmpA, tmpB;
	inp3(n,a,b);
	if(a>b) swap(a,b);
	tmpA=a;tmpB=b;
	FOR(i,n) inp1(arr[i]);
	sort(arr,arr+n);
	ll sumA=0,sumB=0;
	int pos=n-1;
	for(;a>0;a--,pos--) sumA+=arr[pos];
	for(;b>0;b--,pos--) sumB+=arr[pos];
	// printf("sumA:%d, sumB:%d\n",sumA,sumB);
	double ans = ((double)sumA/tmpA)+((double)sumB/tmpB);
	printf("%.8lf",ans);
	return 0;
}
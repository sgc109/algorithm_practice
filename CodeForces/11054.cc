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
const int MAX_N = 1002;

int fromLeft[MAX_N];
int fromRight[MAX_N];
int n;
int arr[MAX_N];
int main() {
	inp1(n);
	FOR(i,n){
		inp1(arr[i]);
	}
	FOR(i,n){
		fromLeft[i]=1;
		FOR(j,i){
			if(arr[j]<arr[i]) fromLeft[i]=max(fromLeft[i],fromLeft[j]+1);
		}
	}
	for(int i=n-1;i>=0;i--){
		fromRight[i]=1;
		for(int j=n-1;j>i;j--){
			if(arr[i]>arr[j]) fromRight[i]=max(fromRight[i],fromRight[j]+1);
		}
	}
	int ans=0;
	FOR(i,n){
		ans=max(ans,fromLeft[i]+fromRight[i]);
	}
	printf("%d",ans-1);
	return 0;
}
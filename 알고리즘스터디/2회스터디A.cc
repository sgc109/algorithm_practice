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
#include <unordered_set>
#include <set>
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

typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;

const int INF = 0x3a3a3a3a;
const long long INFL = 0x3a3a3a3a3a3a3a3a;
const int MAX_N = 1000000;
int n,k;
int maxLen;
int maxL,maxR;
int cnt[1000003];
int a[500002];
int kind;
int main() {
	inp2(n,k);
	FOR(i,n) {
		scanf("%d",a+i);
	}
	int l=0,r=0;
	while(l<n && r<n){
		if(cnt[a[r]] > 0) {
			++cnt[a[r]];
			++r;
			if(maxLen < r-l) {
				maxLen=r-l;
				maxL=l;
				maxR=r-1;
			}
			continue;
		}
		else if(cnt[a[r]] == 0){
			if(kind==k) {
				while(kind==k){
					if(cnt[a[l]]==1) {
						--kind;
					}
					--cnt[a[l]];
					++l;
				}
			}
			++kind;
			++cnt[a[r]];
			++r;
			if(maxLen < r-l) {
				maxLen=r-l;
				maxL=l;
				maxR=r-1;
			}
		}
	}
	printf("%d %d",maxL+1,maxR+1);
	
	return 0;
}
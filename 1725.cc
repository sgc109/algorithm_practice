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

typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;

const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 1000000;

int a[100002];
int main() {
		int n;
		long long ans=-1;
		inp1(n);
		FOR(i,n) scanf("%d",a+i);
		a[n] = -1;
		stack<int> s;
		FOR(i,n+1) {
			if(s.empty()) {
				s.push(i);
				continue;
			}
			if(a[s.top()] == a[i]) continue;
			if(a[s.top()] < a[i]) s.push(i);
			else {
				int start=i;
				while(!s.empty() && a[s.top()] > a[i]) {
					ans = max(ans, (long long)(i-s.top())*a[s.top()]);
					a[s.top()] = a[i];
					start = s.top();
					s.pop();
				}
				if(s.empty() || a[s.top()] < a[i]) s.push(start);
			}
		}
		printf("%lld\n",ans);
	return 0;
}
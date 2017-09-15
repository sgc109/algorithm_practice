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
#include <set
/>/ #include <unordered_set>
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

long long height;

long long ans=0;
char S[350005];
int depth;
int main() {
	int t;
	inp1(t);
	getchar();
	while(t--) {
		stack<int> s;
		height=1;
		ans=0;
		depth=0;
		getchar();
		gets(S);
		
		int len = strlen(S);
		FOR(i,len) {
			if(S[i] == '(') {
				s.push(i);
				height=1;
				++depth;
			}
			else {
				int p = s.top();
				s.pop();
				if(depth%2==1) {
					long long added = (long long)(i-p)*height;
					ans += added;
				}
				else {
					long long added = (long long)(i-p)*height;
					ans -= added;
				}
				++height;
				--depth;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
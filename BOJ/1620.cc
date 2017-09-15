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
#include <map>
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

const int INF = 0x3a3a3a3a;
const long long INFL = 0x3a3a3a3a3a3a3a3a;
const int MAX_N = 1000000;

long long Hash[2] = {1000000007, 1000000009};
int f[220];
int n,m;
map<long long, int> h;
char dogam[100002][22];

int main() {
	FOR(i,26) {
		f['a'+i]=i+1;
	}
	FOR(i,26) {
		f['A'+i]=27+i;
	}
	inp2(n,m);
	getchar();
	FOR(i,n) {
		gets(dogam[i]);
		int len = strlen(dogam[i]);
		long long val[2] = {0,0};
		FOR(j,len) {
			FOR(k,2) {
				val[k] = (val[k]*57+f[dogam[i][j]])%Hash[k];
			}
		}
		h.insert(make_pair(val[0]*Hash[1]+val[1], i));
	}
	FOR(i,m) {
		char input[22];
		gets(input);
		if('0' <= input[0] && input[0] <= '9') {
			printf("%s\n",dogam[atoi(input)-1]);
		}
		else {
			int len = strlen(input);
			long long val[2] = {0,0};
			FOR(j,len) {
				FOR(k,2) {
					val[k] = (val[k]*57+f[input[j]])%Hash[k];
				}
			}
			printf("%d\n",h[val[0]*Hash[1]+val[1]]+1);
		}
	}

	return 0;
}
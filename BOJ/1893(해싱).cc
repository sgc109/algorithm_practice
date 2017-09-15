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
#define REP(i,a,b) for(int i = a; i < b;++i) 
#define FOR(i,n) REP(i,0,n)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> llll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int> > vvi;
typedef vector<ii> vii;

const int INF = 0x3a3a3a3a;
const int MAX_W = 50001;
const int MAX_S = 500001;
const long long Hash[2] = {1000000007, 1000000009};

char A[63];
char W[MAX_W];
char S[MAX_S];
int aLen,wLen,sLen;
int N;
int f[220];
long long g[63][2];

int main() {
	scanf("%d ",&N);
	FOR(t,N) {
		gets(A);
		gets(W);
		gets(S);
		aLen = strlen(A);
		wLen = strlen(W);
		sLen = strlen(S);
		if(wLen > sLen) {
			printf("no solution\n");
			continue;
		}
		FOR(i,aLen) f[A[i]] = i;


		FOR(i,aLen) {
			g[i][0] = i; g[i][1] = i;
			FOR(j,wLen-1) {
				FOR(k,2) {
					g[i][k] = (g[i][k] * 257) % Hash[k];

				}
			}
		}

		long long valW[2] = {0,};
		long long valHashW;
		FOR(i,wLen) {
			FOR(k,2) {
				valW[k] = (valW[k] * 257 + f[W[i]]) % Hash[k];
			}
		}
		valHashW = valW[0] * Hash[1] + valW[1];
		//printf("valHashW: %lld\n",valHashW);

		vector<int> ans;
		FOR(shift,aLen) {
			//printf("shift%d\n",shift);
			long long val[2] = {0,};
			long long valHash;

			FOR(i,wLen) {
				FOR(k,2) {
					val[k] = (val[k] * 257 + (f[S[i]]-shift+aLen)%aLen) % Hash[k];
				}
			}

			int cnt = 0;
			FOR(i,sLen-wLen+1) {
				valHash = val[0] * Hash[1] + val[1];
				//printf("valHash: %lld\n",valHash);
				if(valHashW == valHash) ++cnt;
				if(cnt>1) break;
				if(i == sLen-wLen) {
					if(cnt==1) ans.pb(shift);
					break;
				}
				else {
					FOR(k,2) {
						val[k] = (val[k] - g[(f[S[i]]-shift+aLen)%aLen][k] + Hash[k]) % Hash[k];
						val[k] = (val[k] * 257) % Hash[k];
						val[k] = (val[k] + (f[S[i+wLen]]-shift+aLen)%aLen) % Hash[k];
					}
				}
			}
		}
		if(ans.size() == 0) {
			printf("no solution\n");
			continue;
		}
		if(ans.size() == 1) {
			printf("unique: %d\n", ans[0]);
			continue;
		}
		printf("ambiguous:");
		FOR(i,ans.size()) {
			printf(" %d",ans[i]);
		}
		printf("\n");


	}
	return 0;
}
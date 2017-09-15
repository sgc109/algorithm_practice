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
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)

using namespace std;

typedef pair<long long, long long> pll;

const int INF = 0x3a3a3a3a;
const long long INFL = 0x3a3a3a3a3a3a3a3a;
const int MAX_N = 1002;

int n;
int adj[MAX_N][MAX_N];
int degree[MAX_N];
int edgeCnt;

void getEulerCircuit(int here, vector<int>& circuit) {

	FOR(there,n) {
		if(adj[here][there]) {
			--adj[here][there];
			--adj[there][here];
			getEulerCircuit(there, circuit);
		}
	}

	circuit.push_back(here);
}

int main() {
	memset(degree,0,sizeof(degree));
	edgeCnt = 0;
	inp1(n);
	FOR(i,n) {
		FOR(j,n){
			inp1(adj[i][j]);
			if(i<=j) {
				degree[i]+=adj[i][j];
				degree[j]+=adj[i][j];
				edgeCnt += adj[i][j];
			}
		}
	}

	int oddDegree = 0;
	FOR(i,n) {
		if( degree[i] % 2 != 0) ++oddDegree;
	}

	if(oddDegree) {
		// printf("HI");
		printf("-1");
		return 0;
	}

	vector<int> circuit;
	bool noEdge = true;
	FOR(i,n) {
		if(degree[i]!=0) {
			getEulerCircuit(i,circuit);
			noEdge = false;
			break;
		}
	}
	if(noEdge) {
		// printf("HI");
		printf("-1");
		return 0;
	}
	reverse(circuit.begin(),circuit.end());

	if(circuit.size()-1 != edgeCnt) {
		// printf("%d %d\n",circuit.size(),edgeCnt);
		printf("-1");
		return 0;
	}

	FOR(i,circuit.size()) {
		printf("%d ",circuit[i]+1);
	}


	return 0;
}
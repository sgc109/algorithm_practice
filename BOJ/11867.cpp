#include <cstdio>
#include <set>
#include <cstring>
using namespace std;
int dp[103][103];
int go(int a, int b){
	if(a == 1 && b == 1) return 0;
	if(a > b) return go(b, a);
	int& cache = dp[a][b];
	if(cache != -1) return cache;
	set<int> st;
	for(int i = 1 ; i <= a / 2; i++) st.insert(go(i, a - i));
	for(int i = 1 ; i <= b / 2; i++) st.insert(go(i, b - i));
	int prev = -1;
	for(int p : st){
		if(prev + 1 != p) break;
		prev = p;
	}
	return cache = prev + 1;
}
int N, M;
int main() {
	memset(dp,-1,sizeof(dp));
	scanf("%d%d",&N,&M);
	int ret = go(N, M);
	if(ret) printf("A");
	else printf("B");
	return 0;
}
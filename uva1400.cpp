#include <bits/stdc++.h>

using namespace std;

int n, m;
int d[2000003];
int dp[2000003];
int a[500003];

void solve(int l, int r, int node){
	if(l == r) {
		dp[node] = d[node] = a[l];
		return;
	}
	int m = (l + r) / 2;
	solve(l, m, node*2);
	solve(m+1, r, node*2+1);
	d[node] = d[node*2] + d[node*2+1];
	dp[node] = max(dp[node*2], d[node*2] + dp[node*2+1]);
}

void query(int l, int r, int node){
	
}

int main(){
	while(scanf("%d %d\n", &n, &m) != EOF) {
		memset(d,0,sizeof(d));
		for(int i = 0 ; i < n; i++)
			scanf("%d", a + i);
		solve(0, n-1, 1);

		for(int i = 0 ; i < m; i++){
			int l, r;
			scanf("%d %d\n",&l, &r);

			printf("Case %d:\n",i);
		}
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

bool t[1<<20][2];
int dp[1000001][2];
int T,N,K,a,b,c;
int size;
bool query(int id, int l, int r){
	bool ret = 1;
	for(l += size, r += size; l <= r; l/=2, r/=2){
		if(l&1) ret &&= t[l++][id];
		if(~r&1) ret &&= t[r--][id];
	}
	return ret;
}
void update(int id, int pos, bool v){
	for(t[pos+=size][id] = v; pos > 1; pos/=2) t[pos/2] = t[pos] && t[pos^1];
}
int main() {
	scanf("%d",&T);
	for(int t = 1; t <= T; t++){
		scanf("%d%d%d",&a,&b,&c);
		for(int i = 0 ; i < c; i++){
			memset(dp)
		}
	}
	return 0;
}
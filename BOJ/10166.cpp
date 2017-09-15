#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int D1, D2;
map<int,int> mp1;
int gcd(int a, int b){
	return b ? gcd(b, a % b) : a;
}
int main() {
	scanf("%d%d",&D1,&D2);
	int ans = 0;
	for(int i = D1; i <= D2; i++){
		map<int,int> mp2;
		for(int j = 1; j < i; j++){
			int g = gcd(i, j);
			if(mp1[i / g]) continue;
			ans++;
			mp2[i / g] = 1;
		}
		for(auto p : mp2) mp1[p.first] = 1;
	}
	printf("%d", ans+1);
	return 0;
}

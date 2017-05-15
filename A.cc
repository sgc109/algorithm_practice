#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int N;
int go(int n){
	if(n==1) return 0;
	if(n%2) return 1+go(n+1);
	return 1+go(n/2);
}
int main() {
	scanf("%d",&N);
	printf("%d",go(N));
	return 0;
}

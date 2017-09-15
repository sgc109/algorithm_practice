#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define fastio() ios_base::sync_with_stdio(false),cin.tie(NULL)
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int N;
int notPrime[1000003];
int main() {
	scanf("%d", &N);
	for(int i = 2; i * i <= N; i++){
		if(notPrime[i]) continue;
		for(int j = i * i ; j <= N; j += i){
			notPrime[j] = 1;
		}
	}
	if(N & 1){
		if(N < 9) return printf("-1");
		printf("2 3 ");
		N -= 5;
	}
	else {
		if(N < 8) return printf("-1");
		printf("2 2 ");
		N -= 4;
	}
	for(int i = 2; i < N; i++){
		if(!notPrime[i] && !notPrime[N - i]){
			return !printf("%d %d", i, N - i);
		}
	}
	return 0;
}
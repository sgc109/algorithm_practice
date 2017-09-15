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

int N, K;
int A[13];
int gcd(int a, int b){
	return !b ? a : gcd(b, a % b);
}
int main() {
	fastio();
	cin >> N >> K;
	for(int i = 0 ; i < N; i++) cin >> A[i];
	int g = A[0];
	for(int i = 1; i < N; i++) g = gcd(g, A[i]);
	for(int i = 0 ; i < K; i++){
		int gak;
		cin >> gak;
		int ok = gak ? 0 : 1;
		if(g && gak % g == 0) ok = 1;
		if(ok) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
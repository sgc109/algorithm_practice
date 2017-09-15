#include <bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int N,M,K;
int main() {
	fastio();
	cin >> N >> M >> K;
	int r = K / M;
	int c = K % M;
	cout << r << " " << c;
	return 0;
}
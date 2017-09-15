#include <iostream>
#include <cstdio>
#include <vector>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define fastio() ios::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const ll infl = 0x3c3c3c3c3c3c3c3c;

int N;
int A[100003];
int bck[100003];
int main() {
	fastio();
	cin >> N;
	for(int i = 0 ; i < N; i++) {
		cin >> A[i];
		A[i]--;
		bck[i] = A[i];
	}
	int ans = 0;
	for(int i = 0 ; i < N - 1; i++){
		if(A[i] == i) swap(A[i], A[i + 1]), ans++;
	}
	if(A[N - 1] == N - 1) ans++;
	
	cout << ans;
	return 0;
}
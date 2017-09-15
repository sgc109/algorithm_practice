#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define fastio() ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
int A[1003];
int N, D;
queue<int> q;
int main() {
	fastio();
	while(1){
		cin >> D >> N;
		if(D == -1 && N == -1) break;
		for(int i = 0 ; i < N; i++) cin >> A[i];
		sort(A, A + N);
		int ans = 0;
		int pos = 0;
		while(pos < N){
			int mid = upper_bound(A, A + N, A[pos] + D) - A - 1;
			ans++;
			pos = upper_bound(A, A + N, A[mid] + D) - A;
		}
		cout << ans << endl;
	}
	return 0;
}
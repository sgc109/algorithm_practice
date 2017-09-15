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
int A[10003];
int main() {
	fastio();
	cin >> N;
	for(int i = 0 ; i < N; i++) cin >> A[i];
	sort(A, A + N);
	for(int i = N - 1; i >= 1 ; i--){
		if(A[i] > i || A[i] <= 0) return !printf("-1");
		int cnt = i - A[i];
		for(int j = i - 1; j > i - 1 - cnt; j--) {
			A[j]--;
		}
		int l = i - cnt - 1;
		while(A[l] > A[i - cnt] && l >= 0) l--;
		queue<int> q;
		for(int j = i - cnt; j <= i - 1; j++) q.push(A[j]);
		for(int j = l + 1; j <= i - cnt - 1; j++) A[j + cnt] = A[j];
		for(int j = l + 1; !q.empty(); j++) A[j] = q.front(), q.pop();
	}
	if(!A[0]) cout << 1;
	else cout << -1;
	return 0;
}
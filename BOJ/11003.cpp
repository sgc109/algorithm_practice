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

int N, L, a;
deque<int> dq;
int A[5000003];
int main() {
	fastio();
	cin >> N >> L;
	for(int i = 0 ; i < N; i++){
		cin >> A[i];
		while(!dq.empty() && dq.front() <= i - L) dq.pop_front();
		while(!dq.empty() && A[dq.back()] >= A[i]) dq.pop_back();
		dq.push_back(i);
		cout << A[dq.front()] << ' ';
	}
	return 0;
}
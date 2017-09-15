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
int A[10003];
int cnt[10];
void NO(){
	cout << "NO";
	exit(0);
}
priority_queue<int> pq;
int main() {
	fastio();
	cin >> N >> K;
	for(int i = 0 ; i < K; i++) cin >> A[i];
	cnt[1] = 0, cnt[2] = 2 * N, cnt[4] = N;
	for(int i = 0 ; i < K && cnt[4]; i++){
		if(A[i] / 4){
			int dec = min(cnt[4], A[i] / 4);
			cnt[4] -= dec;
			A[i] -= 4 * dec;
		}
	}
	for(int i = 0 ; i < K && cnt[2]; i++){
		if(A[i] / 2){
			int dec = min(cnt[2], A[i] / 2);
			cnt[2] -= dec;
			A[i] -= 2 * dec;
		}
	}

	

	cout << "YES";
	return 0;
}
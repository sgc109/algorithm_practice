#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int T,M,N,K,W;
ll t[1<<18];
int size;
int A[303][303];

void update(int pos, int v){
	for(t[pos += size] += v; pos > 1; pos/=2) t[pos/2] = t[pos] + t[pos^1];
}
int kth(ll k){
	int cur;
	for(cur = 1; cur < size;){
		if(t[cur*2] < k) k-=t[cur*2], cur=2*cur+1;
		else cur *= 2;
	}
	return cur - size;
}

int main() {
	// freopen("output.txt","w",stdout);
	size = 1<<17;
	cin >> T;
	for(int tc = 1; tc <= T; tc++){
		cout << "Case #" << tc << "\n";
		cin >> M >> N >> K >> W;
		for(int i = 0 ; i < M; i++) for(int j = 0 ; j < N; j++) cin >> A[i][j];
		for(int i = 0 ; i <= M-W; i++) {
			memset(t,0,sizeof(t));
			for(int ii = i; ii < i+W; ii++){
				for(int j = 0 ; j < W; j++){
					update(A[ii][j], 1);
				}
			}
			for(int j = 0 ; j <= N-W; j++){
				cout << kth((W*W)/2+1) << " ";
				if(j == N-W) break;
				for(int ii = i ; ii < i+W; ii++){
					update(A[ii][j], -1);
					update(A[ii][j+W], 1);
				}
			}
			cout << "\n";
		}
	}
	return 0;
}

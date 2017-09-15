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

int T, N;
int tree[100003];
int A[5003];
int query(int x){
	int ret = 0;
	while(x > 0){
		ret += tree[x];
		x -= x & -x;
	}
	return ret;
}
void update(int x, int val){
	while(x <= 100000){
		tree[x] += val;
		x += x & -x;
	}
}
int main() {
	fastio();
	cin >> T;
	while(T--){
		cin >> N;
		for(int i = 0 ; i < N; i++) cin >> A[i];
		int ok = 0;
		for(int k = 0 ; k < 2 & !ok; k++){
			memset(tree,0,sizeof(tree));
			for(int i = 0 ; i < N && !ok; i++){
				int maxx = 0;
				for(int j = i + 1; j < N && !ok; j++){
					if(A[i] < A[j] && A[j] < maxx) {
						int ret = query(maxx - 1) - query(A[j]);
						if(ret > 0) {
							ok = 1;
							break;
						}
					}
					maxx = max(maxx, A[j]);
				}
				update(A[i], 1);
			}

			reverse(A, A + N);
		}
		cout << (ok ? "Yes" : "No") << '\n';
	}
	return 0;
}
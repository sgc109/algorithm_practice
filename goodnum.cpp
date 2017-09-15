#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int T,N;
set<int> st;
int A[5003];
int main() {
	cin >> T;
	for(int t = 1 ; t <= T; t++){
		st.clear();
		cin >> N;
		st.insert(0);
		int ans = 0;
		for(int i = 0 ; i < N; i++) cin >> A[i];
		for(int i = 0 ; i < N; i++){
			if(st.count(A[i])) ans++;

			vector<int> add;
			for(int n : st) if(n + A[i] <= 5000) add.push_back(n + A[i]);
			for(int j = 0 ; j < add.size(); j++) st.insert(add[j]);
		}
		cout << "Case #" << t << endl;
		cout << ans << endl;
	}
	return 0;
}
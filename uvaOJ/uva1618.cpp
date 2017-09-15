#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int T,N;
int arr[5003];
set<int> st[5003];
int main() {
	cin >> T;
	while(T--){
		cin >> N;
		for(int i = 1 ; i <= N; i++) cin >> arr[i];
		int ans = 0;
		for(int k = 0 ; k < 2; k++){
			for(int i = N; i >= 1; i--) st[i] = st[i+1], st[i].insert(arr[i]);
			for(int i = 1; i < N; i++){
				int maxx = -1;
				for(int j = i+2; j <= N; j++){
					maxx = max(maxx, arr[j-1]);
					if(maxx < arr[i]) continue;
					if(arr[i] > arr[j]){
						auto it = st[j+1].lower_bound(arr[i]);
						if(it == st[j+1].end() || maxx < (*it)) continue;
						ans = 1;
						for(int i = 1 ; i <= N; i++) st[i].clear();			
						goto hell;
					}
				}
			}
			for(int i = 1 ; i <= N; i++) st[i].clear();
			reverse(arr+1, arr+1+N);
		}
		hell:
		if(ans) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
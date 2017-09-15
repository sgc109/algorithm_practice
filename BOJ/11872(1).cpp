#include <bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int f[10000];
set<int> st;
int main() {
	fastio();
	f[0] = 0;
	f[1] = 1;
	for(int i = 2; i < 10000; i++){
		st.clear();
		for(int j = 0; j <= i - 1; j++) st.insert(f[j]);
		for(int j = 1; j <= i / 2; j++){
			st.insert(f[j] ^ f[i - j]);
		}
		int prev = -1;
		for(int p : st){
			if(p != prev + 1) break;
			prev = p;
		}
		f[i] = prev + 1;
	}

	for(int i = 0 ; i < 10000; i++) cout << f[i] << " ";
	return 0;
}
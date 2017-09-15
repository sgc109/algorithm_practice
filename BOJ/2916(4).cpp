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

int N, M;
set<int> st;
int main() {
	fastio();
	cin >> N >> M;
	st.insert(0);
	for(int i = 0 ; i < N; i++) {
		int gak;
		cin >> gak;
		for(int j = -360; j <= 360; j++){
			for(auto num : st){
				int psh = num + j * gak;
				st.insert(psh);
			}
		}
	}
	for(int i = 0 ; i < M; i++){
		int gak;
		cin >> gak;
		if(st.count(gak)) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
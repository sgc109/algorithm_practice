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

struct node{
	string S;
	int turn, cnt;
};
int N;
node in[53];
int black[30];
int par[53];
int find(int u){
	if(u == par[u]) return u;
	return par[u] == u ? u : par[u] = find(par[u]);
}
void merge(int a, int b){
	a = find(a), b = find(b);
	if(a == b) return;
	par[a] = b;
}
bool same(int a, int b){
	return find(a) == find(b);
}
int main() {
	fastio();
	cin >> N;
	for(int i = 0 ; i < N; i++){
		string S;
		int turn, cnt;
		cin >> S >> turn >> cnt;
		in[i] = node{S, turn, cnt};
	}
	int ans = 0;
	for(int i = 0 ; i < 26; i++){
		for(int j = i + 1; j < 26; j++){
			for(int k = j + 1; k < 26; k++){
				black[i] = black[j] = black[k] = 1;
				int ok = 1;
				for(int i = 0 ; i < 52; i++) par[i] = i;
				for(int l = 0 ; l < N; l++){
					string s = in[l].S;
					int c1 = s[0] - 'A', c2 = s[1] - 'A';
					int turn = in[l].turn;
					int cnt = in[l].cnt;
					if(black[c1] + black[c2] > 2 - cnt){
						ok = 0;
						break;
					}
					vector<int> cand;
					if(!black[c1]) cand.pb(c1);
					if(!black[c2]) cand.pb(c2);
					if(sz(cand) == 2){
						int c1 = cand[0], c2 = cand[1];
						if(cnt == 1){
							merge(2 * c1 + turn - 1, 2 * c2 + 2 - turn);
							merge(2 * c1 + 2 - turn, 2 * c2 + turn - 1);
						}
					}
				}
				for(int i = 0 ; i < 26; i++) if(same(2 * i, 2 * i + 1)) ok = 0;
				if(ok) ans++;
				black[i] = black[j] = black[k] = 0;
			}
		}
	}	
	cout << ans;
	return 0;
}
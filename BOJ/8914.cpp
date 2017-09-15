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

int T, K;
char pane[2][6][6];
vector<string> vs[2];
void make(string s, int pos, int id){
	if(pos == 5){
		vs[id].pb(s);
		return;
	}
	for(int i = 0 ; i < 6; i++) {
		if(i < 5 && pane[id][pos][i] == pane[id][pos][i + 1]) continue;
		make(s + pane[id][pos][i], pos + 1, id);
	}
}
int main() {
	fastio();
	cin >> T;
	while(T--){
		vs[0].clear(), vs[1].clear();
		cin >> K;
		for(int k = 0 ; k < 2; k++){
			for(int i = 0 ; i < 6; i++){
				string s;
				cin >> s;
				for(int j = 0 ; j < 5; j++){
					pane[k][j][i] = s[j];
				}
			}
			for(int i = 0; i < 5; i++) sort(pane[k][i], pane[k][i] + 6);
		}
		make("", 0, 0), make("", 0, 1);
		for(int k = 0 ; k < 2; k++) vs[k].erase(unique(all(vs[k])), vs[k].end());
		int pos1 = 0, pos2 = 0;	
		int len1 = sz(vs[0]), len2 = sz(vs[1]);
		int cnt = 0;
		int ok = 0;
		while(pos1 < len1 && pos2 < len2){
			if(vs[0][pos1] == vs[1][pos2]) {
				cnt++;
				if(cnt == K){
					ok = 1;
					cout << vs[0][pos1] << '\n';
					break;
				}
				pos1++, pos2++;
			}
			else if(vs[0][pos1] < vs[1][pos2]) pos1++;
			else pos2++;
		}
		if(!ok) cout << "NO\n";
	}
	return 0;
}
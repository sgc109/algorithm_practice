#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int pane[23][23];
int stoi(string& s){
	int ret = 0;
	for(int i = 0 ; i < sz(s); i++){
		ret = 10 * ret + s[i] - '0';
	}
	return ret;
}
bool inRange(int i, int j){
	return 0 <= i && i < 20 && 0 <= j && j < 20;
}
int main() {
	for(int i = 0 ; i < 20; i++){
		for(int j = 0 ; j < 20; j++){
			string s;
			cin >> s;
			int num = stoi(s);
			pane[i][j] = num;
		}
	}

	int ans = 0;

	for(int i = 0 ; i < 20; i++){
		for(int j = 0 ; j < 20; j++){
			for(int k = 0 ; k < 8; k++){
				int di = "00122210"[k] - '1';
				int dj = "12221000"[k] - '1';
				int mult = 1;
				for(int l = 0; l < 4; l++){
					int ni = i + di * l;
					int nj = j + dj * l;
					if(!inRange(ni, nj)) break;
					mult *= pane[ni][nj];
				}
				ans = max(ans, mult);
			}
		}
	}

	cout << ans;
	return 0;
}
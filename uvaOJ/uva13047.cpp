#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int T;
string S;
int ans;
void update(int s, int e){
	if(s == -1 || e == -1) return;
	if(s > 0 && S[s-1] == '<') ans = max(ans, e-s+2);
	if(e < S.size()-1 && S[e+1] == '>') ans = max(ans, e-s+2);
}
int main() {
	cin >> T;
	for(int t = 1 ; t <= T; t++){
		cin >> S;
		int s = -1, e = -1;
		ans = -1;
		int isDoub = -1;
		for(int i = 0 ; i < S.size(); i++){
			if(S[i] == '<' || S[i] == '>') {
				update(s,e);
				isDoub = -1;
				s = e = -1;
				ans = max(ans, 1);
				continue;
			}
			if(S[i] == '-'){
				if(isDoub == 0) e++;
				else {
					update(s,e);
					isDoub = 0;
					s = e = i;
				}

			}
			else if(S[i] == '='){
				if(isDoub == 1) e++;
				else {
					update(s,e);
					isDoub = 1;
					s = e = i;
				}

			}
		}
		update(s,e);
		cout << "Case " << t << ": ";
		cout << ans << endl;
	}
	return 0;
}
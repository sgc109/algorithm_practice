#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

const int MAXL = 17003;
string S1, S2;
int dp[2][MAXL];
string cmds[2][MAXL];

int Ldp[MAXL];
string Lcmds[MAXL];

int main() {
	memset(dp,0x3c,sizeof(dp));
	cin >> S1 >> S2;
	int len1 = S1.size();
	int len2 = S2.size();
	for(int i = 0 ; i < MAXL; i++) Ldp[i] = dp[0][i] = i;
	for(int i = 1 ; i <= len1; i++){
		Lcmds[i] = Lcmds[i-1] + 'd';
	}
	for(int i = 1 ; i <= len2; i++){
		cmds[0][i] = cmds[0][i-1] + 'a';
	}
	for(int i = 1 ; i <= len1; i++){
		for(int j = 1 ; j <= len2; j++){
			if(S1[i-1] == S2[j-1]) {
				dp[i%2][j] = (j > 1 ? dp[(i+1)%2][j-1] : Ldp[i-1]);
				cmds[i%2][j] = (j > 1 ? cmds[(i+1)%2][j-1] : Lcmds[i-1]) + 'c';
			}
			else {
				dp[i%2][j] = min(dp[i%2][j], dp[(i+1)%2][j]);
				dp[i%2][j] = min(dp[i%2][j], (j > 1 ? dp[i%2][j-1] : Ldp[i]));
				dp[i%2][j] = min(dp[i%2][j], (j > 1 ? dp[(i+1)%2][j-1] : Ldp[i-1]));
				if(dp[i%2][j] == dp[(i+1)%2][j]) {
					cmds[i%2][j] = cmds[(i+1)%2][j] + 'd';
				}
				else if(dp[i%2][j] == (j > 1 ? dp[i%2][j-1] : Ldp[i])){
					cmds[i%2][j] = (j > 1 ? cmds[i%2][j-1] : Lcmds[i]) + 'a';
				}
				else {
					cmds[i%2][j] = (j > 1 ? cmds[(i+1)%2][j-1] : Lcmds[i-1]) + 'm';
				}
				dp[i%2][j]++;
			}
		}
	}
	for(int i = 0 ; i < max(len1, len2); i++){
		char cmd = cmds[len1%2][len2][i];
		cout << cmd << " ";
		// if(cmd != 'd') cout << op[len1%2][len2][i] << endl;
		else cout << endl;
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int T;
string S;
stack<pair<char,int> > s;
int closing[1000003];
bool isOpen(char c){
	if(c == '(') return true;
	if(c == '[') return true;
	if(c == '{') return true;
	return false;
}
bool sameKind(char c1, char c2){
	return abs((int)c1 - (int)c2) <= 2;
}
int main() {
	cin >> T;
	for(int t = 1 ; t <= T; t++){
		memset(closing,-1,sizeof(closing));
		while(!s.empty()) s.pop();
		cin >> S;
		for(int i = 0 ; i < (int)S.size(); i++){
			if(isOpen(S[i])) s.push({S[i],i});
			else{
				if(s.empty()) continue;
				char topc = s.top().first;
				int topidx = s.top().second;
				s.pop();
				if(!sameKind(topc, S[i])){
					while(!s.empty()) s.pop();
				}
				else closing[topidx] = i;
			}
		}
		int ans = 0;

		int len = 0;
		int pos = 0;
		while(pos < (int)S.size()){
			if(closing[pos] == -1) len = 0, pos++;
			else {
				len += closing[pos] - pos + 1;
				ans = max(ans, len);
				pos = closing[pos]+1;
			}
		}

		cout << "Case #" << t << endl;
		cout << ans << endl;
	}
	return 0;
}
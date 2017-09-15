#include <string>
#include <cstring>
#include <map>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int N;
int L[330], R[330];
string S;
map<char, int> mp;
bool inRange(int x){
	return 0 <= x && x < N;
}
bool isCap(char c){
	return 'A' <= c && c <= 'Z';
}

string check(int l, int r){ // 규칙1 이라는 것을 가정한다.
	if(!inRange(l) || !inRange(r)) return "";
	if(l > r) return "";
	int allCap = 1;
	string ret = "";
	for(int i = l ; i <= r; i++) {
		ret += S[i];
		if(!isCap(S[i])) allCap = 0;
	}
	if(allCap) return ret;
	ret = "";
	if(isCap(S[l + 1])) return "";
	char c = S[l + 1];
	int toggle = 0;
	for(int i = l ; i <= r; i++){
		if(toggle == isCap(S[i])) return "";
		if(!isCap(S[i]) && S[i] != c) return "";
		if(isCap(S[i])) ret += S[i];
		toggle ^= 1;
	}
	return ret;
}

string solution(string sentence) {
	memset(L,0x3c,sizeof(L));
	memset(R,-1,sizeof(R));
	mp.clear();
	S = sentence;
	N = (int)S.size();
	for(int i = 0 ; i < N; i++) if(S[i] == ' ') return "invalid";
	for(int i = 0 ; i < N; i++){
		char c = S[i];
		if(!isCap(c)) {
			mp[c]++;
			L[c] = min(L[c], i);
			R[c] = max(R[c], i);
		}
	}

	string ans = "";
	int pos = 0;
	while(pos < N){
		char c = S[pos];
		if(!isCap(S[pos])) {
			if(mp[c] != 2) return "invalid";
			string ret = check(pos + 1, R[S[pos]] - 1);
			if(ret.size() == 0) return "invalid";
			if(ans.size() != 0) ans += ' ';
			ans += ret;
			pos = R[S[pos]] + 1;
		}
		else {
			int i;
			for(i = pos; i < N && isCap(S[i]); i++);
			if(i == N){
				string tmp = "";
				for(int j = pos; j < N; j++) tmp += S[j];
				if(tmp.size() > 0){
					if(ans.size() != 0) ans += ' ';
					ans += tmp;
				}
				break;
			}
			
			for(int j = pos; j < i - 1; j++) {
				if(ans.size() != 0) ans += ' ';
				ans += S[j];
				
			}
			if(mp[S[i]] == 2) {
				if(ans.size() != 0) ans += ' ';
				ans += S[i - 1];
				pos = i;
				continue;
			}
			string ret = check(i - 1, R[S[i]] + 1);
			if(ret.size() == 0) return "invalid";
			if(ans.size() != 0) ans += ' ';
			ans += ret;
			pos = R[S[i]] + 2;
		}
	}

	return ans;
}

int main(){
	string s;
	cin >> s;
	cout << solution(s);
	return 0;
}
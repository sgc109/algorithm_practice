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

void NO(){
	cout << "ROCK";
	exit(0);
}
string remOutPar(string& S){
	int N = sz(S);
	stack<int> stk;
	vector<int> match = vector<int>(N);
	if(S[0] != '(' || S.back() != ')') return S;
	for(int i = 0 ; i < N; i++) {
		if(S[i] == '(') stk.push(i);
		else if(S[i] == ')') {
			if(stk.empty()) NO();
			match[i] = stk.top();
			stk.pop();
		}
	}
	if(!stk.empty()) NO();
	if(match[N - 1] == 0) return S.substr(1, N - 2);
	return S;
}
bool posCheck(vector<int>& pos){
	for(int i = 1 ; i < sz(pos); i++) {
		if(pos[i - 1] + 1 == pos[i]) return false;
	}
	return true;
}
ll go(string& S){
	int N = sz(S);
	vector<int> pos;
	for(int i = 0 ; i < N; i++) { // '+', '-' 기준으로 덩어리 나누기
		if(S[i] == '+' || S[i] == '-') pos.pb(i);
	}
	if(sz(pos) == 0) { // 만약 '+', '-'가 없다면
		for(int i = 0 ; i < N; i++) { // '*', '/' 기준으로 덩어리 나누기
			if(S[i] == '*' || S[i] == '/') pos.pb(i);
		}
		if(sz(pos) == 0){ // 만약 '*', '/' 도 없다면
			
		}
		if(!posCheck(pos)) NO();

	}
	else {
		if(!posCheck(pos)) NO();

	}
}
int main() {
	fastio();
	string S;
	cin >> S;
	cout << go(S);
	return 0;
}
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

int N;
string S[3003];
ll fact[33];
struct Node{
	Node* next[26];
	int isEnd;
	Node() : isEnd(0){
		for(int i = 0 ; i < 26; i++) next[i] = 0;
	}
	void add(const char *s){
		if(s[0] == 0) {
			isEnd = 1;
			return;
		}
		int nxt = s[0] - 'A';
		if(next[nxt] == 0) next[nxt] = new Node;
		next[nxt]->add(s + 1);
	}
};
ll dfs(Node *cur){
	ll ret = 1;
	int cnt = 0;
	for(int i = 0 ; i < 26; i++){
		if(cur->next[i]) {
			ret = (ret * dfs(cur->next[i])) % mod;
			cnt++;
		}
	}
	cnt += cur->isEnd;
	return (ret * fact[cnt]) % mod;
}
int main() {
	fastio();
	fact[0] = 1;
	for(int i = 1; i <= 30; i++) fact[i] = (i * fact[i - 1]) % mod;
	cin >> N;
	Node *root = new Node;
	for(int i = 0 ; i < N; i++) cin >> S[i];
	for(int i = 0 ; i < N; i++) root->add(S[i].c_str());
	ll ans = dfs(root);
	cout << ans;

	return 0;
}
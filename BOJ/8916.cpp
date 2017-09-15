#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define fastio() ios_base::sync_with_stdio(false),cin.tie(NULL)
using namespace std;
typedef long long ll;
const int mod = 9999991;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

struct Node{
	int val;
	Node *l, *r;
	Node(int v) : val(v), l(NULL), r(NULL){}
};
typedef Node* pNode;
int T, N, cnt;
int siz[23];
void insert(pNode& cur, int val){
	if(cur == NULL) {
		cur = new Node(val);
		return;
	}
	if(cur->val < val) insert(cur->r, val);
	else insert(cur->l, val);
}
ll nCr[23][23];
ll dfs(pNode cur){
	if(cur == NULL) return 1;
	ll ret = 1;
	ret = (ret * dfs(cur->l)) % mod;
	ret = (ret * dfs(cur->r)) % mod;
	int n = (cur->l ? siz[cur->l->val] : 0);
	int m = (cur->r ? siz[cur->r->val] : 0);
	ret = (ret * nCr[n + m][n]) % mod;
	siz[cur->val] = n + m + 1;
	return ret;
}
int main() {
	fastio();
	cin >> T;
	for(int i = 1; i <= 20; i++){
		nCr[i][0] = 1;
		for(int j = 1; j < i; j++){
			nCr[i][j] = (nCr[i - 1][j] + nCr[i - 1][j - 1]) % mod;
		}
		nCr[i][i] = 1;
	}
	while(T--){
		memset(siz,0,sizeof(siz));
		nCr[0][0] = 1;
		cin >> N;
		Node *root = NULL;
		for(int i = 0 ; i < N; i++) {
			int a;
			cin >> a;
			insert(root, a);
		}
		cout << dfs(root) << '\n';
	}
	return 0;
}
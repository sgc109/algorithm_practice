#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <stack>
#include <cstring>
#include <cstdlib>	
#include <string>
#include <set>
#include <cmath>
// #include <unordered_set>
// #include <map>
#define REP(i,a,b) for(int i = a; i < b;++i) 
#define FOR(i,n) REP(i,0,n)
#define mp make_pair
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int> > vvi;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef queue<int> QU;

const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

vi same[2002];
int pieceCnt[2002][2002];

int toNum(char ch) {
	if (ch == 'x') return 0;
	return 1;
}

struct TrieNode {
	TrieNode *child[2];
	TrieNode *fail;
	int term;
	TrieNode() :term(-1), fail(0) {
		memset(child, 0, sizeof(child));
	}
	~TrieNode() {
		FOR(i, 2) if (child[i]) delete child[i];
	}
	void insert(const char *key, int id) {
		if (*key == 0) {
			if (term == -1) term = id;
			same[term].pb(id);
			return;
		}
		int next = toNum(*key);
		if (child[next] == 0) child[next] = new TrieNode();
		child[next]->insert(key + 1, id);
	}
};
void computeFailFunc(TrieNode *root) {
	queue<TrieNode *> q;
	root->fail = root;
	q.push(root);
	while (!q.empty()) {
		TrieNode *cur = q.front();
		q.pop();
		FOR(i, 2) {
			TrieNode *nextNode = cur->child[i];
			if (nextNode == 0) continue;
			if (cur == root) nextNode->fail = root;
			else {
				TrieNode *p = cur->fail;
				while (p != p->fail && p->child[i] == 0) p = p->fail;
				if (p->child[i]) p = p->child[i];
				nextNode->fail = p;
			}
			q.push(nextNode);
		}
	}
}
int main() {
	int ans = 0;
	int h1, w1, h2, w2;
	scanf("%d %d %d %d ", &h1, &w1, &h2, &w2);
	char buf[2002];
	TrieNode *root = new TrieNode();
	FOR(i, h1) {
		scanf("%s", buf);
		root->insert(buf, i);
	}
	computeFailFunc(root);
	FOR(i, h2) {
		scanf("%s", buf);
		TrieNode *state = root;
		FOR(j, w2) {
			int next = toNum(buf[j]);
			while (state != root && state->child[next] == 0) state = state->fail;
			if (state->child[next]) state = state->child[next];
			if (state->term == -1) continue;
			for (int rowNum : same[state->term]) {
				if (i - rowNum<0) break;
				pieceCnt[i - rowNum][j - w1 + 1]++;
				if (pieceCnt[i - rowNum][j - w1 + 1] == h1) ans++;
			}
		}
	}
	printf("%d", ans);
	return 0;
}
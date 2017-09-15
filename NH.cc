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
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
typedef queue<int> QU;

const int MOD = 10007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;
const int ALPHABET = 26;

int n,m;
struct TrieNode{
public:
	int no;
	int term;
	TrieNode *child[ALPHABET];
	TrieNode *next[ALPHABET];
	TrieNode *fail;
	vi foundStr;
	TrieNode():term(-1){
		memset(child,0,sizeof(child));
		fail=0;
	}
	~TrieNode(){
		FOR(i,ALPHABET){
			if(child[i]) delete child[i];
		}
	}
	int toNum(char ch){
		return ch-'a';
	}
	TrieNode *find(const char *ch){
		if(*ch==0) return this;
		int next = toNum(*ch);
		if(child[next]==0) return 0;
		return child[next]->find(ch+1);
	}
	void insert(const char *ch, int id){
		if(*ch==0){
			term = id;
			return;
		}
		int next = toNum(*ch);
		if(child[next] == 0) child[next] = new TrieNode();
		child[next]->insert(ch+1,id);
	}
};

void computeFailFunc(TrieNode *root){
	int nodeCnt=0;
	queue<TrieNode *> q;
	q.push(root);
	root->fail=root;
	while(!q.empty()){
		TrieNode *cur = q.front();
		q.pop();
		cur->no = nodeCnt++;
		FOR(i,ALPHABET){
			TrieNode *next = cur->child[i];
			if(next==0) continue;
			if(cur==root) next->fail=root;
			else {
				TrieNode *p = cur->fail;
				while(p != root && p->child[i] == 0) p = p->fail;
				if(p->child[i]) p = p->child[i];
				next->fail = p;
			}
			next->foundStr = next->fail->foundStr;
			if(next->term != -1) next->foundStr.pb(next->term);
			q.push(next);
		}
	}
}

void preproc(TrieNode *here){
	FOR(i,ALPHABET){
		TrieNode *next = here->child[i];
		if(next == 0){
			TrieNode *p = here;
			while(p != p->fail && p->child[i] == 0) p = p->fail;
			if(p->child[i]) p = p->child[i];
			here->next[i] = p;
		}
		else {
			here->next[i] = next;
			preproc(next);
		}
	}
}

int dp[102][1002];
int solve(int len, TrieNode *state){ // state 상태일때 len 글자를 만드는 경우의수
	if(state->foundStr.size()) return 0;
	if(len==0) return 1;
	int& cache = dp[len][state->no];
	if(cache != -1) return cache;
	int ret = 0;
	FOR(i,ALPHABET){
		ret += solve(len-1,state->next[i]);
		ret %= MOD;
	}
	return cache = ret;
}

int main() {
	int T;
	inp1(T);
	while(T--){
		memset(dp,-1,sizeof(dp));
		TrieNode *root = new TrieNode();
		inp2(n,m);
		FOR(i,m){
			char buf[12];
			scanf("%s",buf);
			root->insert(buf,i);
		}
		computeFailFunc(root);
		preproc(root);
		printf("%d\n",solve(n,root));
		delete root;
	}	
	return 0;
}
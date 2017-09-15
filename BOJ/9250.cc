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
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
typedef queue<int> QU;

const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

const int ALPHABET = 26;
int toNum(char ch){
	return ch-'a';
}
struct TrieNode{
	TrieNode *child[ALPHABET];
	TrieNode *fail;
	int term;
	int cntOutput;
	TrieNode():term(-1),fail(0),cntOutput(0){
		memset(child,0,sizeof(child));
	}
	~TrieNode(){
		FOR(i,ALPHABET) if(child[i]) delete child[i];
	}
	void insert(const char *key, int id){
		if(*key==0){
			term=id;
			return;
		}
		int next = toNum(*key);
		if(child[next]==0) child[next] = new TrieNode();
		child[next]->insert(key+1,id);
	}
};
void computeFailFunc(TrieNode *root){
	queue<TrieNode *> q;
	root->fail = root;
	q.push(root);
	while(!q.empty()){
		TrieNode *cur = q.front();
		q.pop();
		FOR(i,ALPHABET){
			TrieNode *nextNode = cur->child[i];
			if(nextNode==0) continue;
			if(cur==root) nextNode->fail = root;
			else {
				TrieNode *p = cur->fail;
				while(p != root && p->child[i] == 0) p = p->fail;
				if(p->child[i]) p = p->child[i];
				nextNode->fail = p;
			}
			nextNode->cntOutput = nextNode->fail->cntOutput + (nextNode->term!=-1?1:0);
			q.push(nextNode);
		}
	}
}
char buf[10002];
int main() {
	TrieNode *root = new TrieNode();
	int n,m;
	inp1(n);
	FOR(i,n){
		scanf("%s",buf);
		root->insert(buf,i);
	}
	computeFailFunc(root);
	inp1(m);
	FOR(i,m){
		scanf("%s",buf);
		int len = strlen(buf);
		TrieNode *state = root;
		bool found = false;
		FOR(j,len){
			int next = toNum(buf[j]);
			while(state != root && state->child[next]==0) state = state->fail;
			if(state->child[next]) state = state->child[next];
			if(state->cntOutput>0) {
				found=true;
				break;
			}
		}
		if(found) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
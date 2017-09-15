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

const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int n,m;
int f[130];

int toNum(char ch){
	int cnt=0;
	return f[ch];
}

struct TrieNode{
public:
	TrieNode *children[4];
	TrieNode *fail;
	bool term;
	int foundCnt;
	TrieNode():term(false),foundCnt(0){
		memset(children,0,sizeof(children));
		fail=0;
	}
	~TrieNode(){
		FOR(i,4) if(children[i]) delete children[i];
	}
	void insert(const char *key){
		if(*key==0){
			term = true;
			return;
		}
		int next = toNum(*key);
		if(children[next]==0) children[next] = new TrieNode();
		children[next]->insert(key+1);
	}
};
void computeFailFunc(TrieNode *root){
	queue<TrieNode *> q;
	q.push(root);
	root->fail = root;
	while(!q.empty()){
		TrieNode *here = q.front();
		q.pop();
		FOR(next,4){
			TrieNode *nextNode = here->children[next];
			if(nextNode==0) continue;
			if(here==root) nextNode->fail = root;
			else{
				TrieNode *p = here->fail;
				while(p != root && p->children[next] == 0) p = p->fail;
				if(p->children[next]) p = p->children[next];
				nextNode->fail = p;
			}
			nextNode->foundCnt = nextNode->fail->foundCnt + (nextNode->term?1:0);
			q.push(nextNode);
		}
	}
}

int cntAppear(TrieNode *root, string &S){
	int ret = 0;
	TrieNode *state = root;
	FOR(i,S.size()){
		int next = toNum(S[i]);
		TrieNode *p = state;
		while(p != p->fail && p->children[next] == 0) p = p->fail;
		if(p->children[next]) p = p->children[next];
		state = p;
		ret += state->foundCnt;
	}
	return ret;
}
char SS[1000002];
char PP[102];
int main() {
	f['A']=0;f['T']=1;f['C']=2;f['G']=3;
	int T;
	inp1(T);
	while(T--){
		TrieNode *root = new TrieNode();
		inp2(n,m);
		scanf("%s %s",SS,PP);
		string S(SS),P(PP);
		root->insert(P.c_str());
		FOR(i,m-1){
			for(int j = i+1; j < m; j++){
				string A = P.substr(0,i);
				string B = P.substr(i,j-i+1);
				string C = P.substr(j+1,m-j-1);
				reverse(B.begin(),B.end());
				string newS = A+B+C;
				root->insert(newS.c_str());
			}
		}
		computeFailFunc(root);
		printf("%d\n",cntAppear(root,S));
		delete root;
	}
	return 0;
}
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

vector<pair<int,string>> v;
int n,m;
struct TrieNode{
public:
	TrieNode *child[26];
	int recom;
	int terminal;
	TrieNode():recom(-1),terminal(-1){
		memset(child,0,sizeof(child));
	}
	~TrieNode(){
		FOR(i,26){
			if(child[i]) delete child[i];
		}
	}
	int toNum(char c){
		return c-'A';
	}
	void insert(const char *S, int num){
		if(recom==-1) recom = num;
		if(*S==0) {
			terminal=num;
			return;
		}
		int next = toNum(*S);
		if(child[next]==0) child[next] = new TrieNode();
		child[next]->insert(S+1,num);
	}
	TrieNode *find(const char *S){
		if(*S==0) return this;
		int next = toNum(*S);
		if(child[next]==0) return 0;
		return child[next]->find(S+1);
	}
	int minTypeCnt(const char *S, int id){
		if(*S==0) return 0;
		if(recom == id) return 1;
		int next = toNum(*S);
		return 1+child[next]->minTypeCnt(S+1,id);
	}
};

int main() {
	int T;
	inp1(T);
	while(T--){
		v.clear();
		inp2(n,m);
		FOR(i,n){
			string S;
			int prior;
			cin >> S;
			inp1(prior);
			v.pb(mp(-prior,S));
		}
		sort(v.begin(),v.end());
		TrieNode *root = new TrieNode();
		FOR(i,n) root->insert(v[i].second.c_str(),i);
		root->recom=-1;
		int ans=0;
		FOR(i,m){
			string S;
			cin >> S;
			TrieNode *target = root->find(S.c_str());
			if(target == 0 || target->terminal==-1) {
				ans+=S.size();
				continue;
			}
			ans+=root->minTypeCnt(S.c_str(),target->terminal);
		}
		ans+=m-1;
		printf("%d\n",ans);
	}
	return 0;
}
#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int,pair<int,int> > piii;
const double EPSILON = 1e-9;
const double PI = acos(0.0)*2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int N;
struct TrieNode{
	TrieNode* child[2];
	int num;
	void add(int num, int pos){
		if(pos<0) return;
		int next = num&(1<<pos)?1:0;
		if(!child[next]) child[next] = new TrieNode();
		child[next]->add(num,pos-1);
	}
	int search(int num, int pos, int made){
		if(pos<0) return made;
		int next = num&(1<<pos)?1:0;
		if(child[next^1]) return child[next^1]->search(num,pos-1,made|(1<<pos));
		return child[next]->search(num,pos-1,made);
	}
};
int A[100003];
int main() {
	inp1(N);
	TrieNode* trie = new TrieNode();
	FOR(i,N) {
		inp1(A[i]);
		trie->add(A[i],30);
	}
	int ans=0;
	FOR(i,N){
		ans=max(ans,trie->search(A[i],30,0));
	}
	printf("%d",ans);
	return 0;
}

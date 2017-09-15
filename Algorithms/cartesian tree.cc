#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
#include <string>
#include <queue>
#include <cstdio>
#include <iostream>
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
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int, pair<int, int> > piii;
typedef vector<piii> viii;
const double EPSILON = 1e-9;
const double PI = acos(0.0) * 2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

struct Node {
	int key;
	ll prior;
	Node *l, *r;
	Node(int key, ll prior) : key(key), prior(prior), l(0), r(0) {}
	Node() {}
};
typedef Node* pNode;

void split(pNode it, int key, pNode& l, pNode& r) {
	if (!it) l = r = 0;
	else if (it->key>key) split(it->l, key, l, it->l), r = it;
	else split(it->r, key, it->r, r), l = it;
}
void merge(pNode& it, pNode l, pNode r) {
	if (!l || !r) it = !l ? r : l;
	else if (l->prior>r->prior) merge(l->r, l->r, r), it = l;
	else merge(r->l, r->l, l), it = r;;
}
void erase(pNode& it, int key) {
	if (!it) return;
	if (it->key == key) merge(it,it->l,it->r);
	else erase(it->key>key?it->l:it->r, key);
}
void insert(pNode& it, pNode add) {
	if (!it) it = add;
	else if (it->prior <= add->prior) split(it, add->key, add->l, add->r), it = add;
	else insert(it->key>add->key?it->l:it->r, add);
}
void inorder(pNode it) {
	if (!it) return;
	inorder(it->l);
	cout << it->key << " ";
	inorder(it->r);
}
int findMax(pNode it){
	if(it->r==0) return it->key;
	return findMax(it->r);
}
int findMin(pNode it){
	if(it->l==0) return it->key;
	return findMin(it->l);
}
struct RNG {
	ll store;
	RNG() :store(1000000007) {}
	ll nextRand() {
		ll ret = store;
		store = (store*(1000000007))%(1000000009);
		return ret;
	}
};
int N;
int main() {
	RNG rng;
	pNode root = 0;
	for(inp1(N);N--;){
		int a;
		inp1(a);
		if(a) insert(root,new Node(a, rng.nextRand()));
		else {
			if(root==0) printf("0\n");
			else {
				int ans=findMin(root);
				printf("%d\n",ans);
				erase(root,ans);
			}
		}
	}
	return 0;
}

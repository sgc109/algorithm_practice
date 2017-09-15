#include <iostream>

using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

template <typename T>
class set{
public:
	struct Node{
		T key;
		int prior;
		Node *l, *r;
		Node(T k, int p): key(k), prior(p), l(0), r(0){}
		Node(){}
	};
	typedef Node* pNode;
	struct RNG{
		ll seed;
		RNG() : seed(123141){}
		int next(){
			int ret = (int)seed;
			seed = (seed * 123124 + 12938) % MOD;
			return ret;
		}
	};
	RNG rng;
	pNode root;

	set(){
		root = Node(0,rng.next());
	}

	void merge(pNode& cur, pNode& l, pNode& r){
		if(!l || !r) return l ? l : r;
		else if(l->prior < r->prior) merge(r->l, l, r->l), cur = r;
		else merge(l->r, l->r, r), cur = l;
	}
	void split(){}
	void insert(pNode& cur, pNode target){
		if(cur == 0) cur = target;
		else if(prior)
	}
	void erase(pNode& cur, pNode target){
		if(cur == 0) return;
		else if(cur->key == target->key) merge(cur, cur->l, cur->r);
		else erase( cur->key < target->key ? cur->r : cur->l, target);
	}
	void insert(T val){
		insert(root, Node(val,rng.next()));
	}
	void erase(T val){
		erase(root, Node(val,rng.next()));
	}
};
int main(){

	return 0;
}
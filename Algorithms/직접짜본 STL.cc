#include <stdio.h>
template <class T> void swap(T& a, T& b) { T tmp = a; a = b; b = tmp; }
template <class T> class vector {
	int cap;
	int _size;
	T *arr;
public:
	vector() :_size(0), cap(32), arr(new T[32]) {}
	T& operator[](int idx) { return arr[idx]; }
	bool empty() { return _size == 0; }
	void reserve(int newCap) {
		T *newArr = new T[newCap];
		for (int i = 0; i < cap; i++) newArr[i] = arr[i];
		delete[] arr;
		arr = newArr;
		cap = newCap;
	}
	void push_back(T v) {
		if (_size == cap) reserve(cap << 1);
		arr[_size++] = v;
	}
	T back() { return arr[_size - 1]; }
	void pop_back() { --_size; }
	int size() { return _size; }
	T* begin() { return arr; }
	T* end() { return arr + _size; }
};
template <class T> class priority_queue {
	vector<T> tree;
public:
	T top() { return tree.size() ? tree[0] : T(); }
	bool empty() { return tree.empty(); }
	void push(T v) {
		tree.push_back(v);
		int cur = tree.size() - 1;
		while (cur > 0) {
			int next = (cur - 1) / 2;
			if (!(tree[next] < tree[cur])) break;
			swap(tree[next], tree[cur]);
			cur = next;
		}
	}
	void pop() {
		if (empty()) return;
		tree[0] = tree.back();
		tree.pop_back();
		int cur = 0;
		while (1) {
			int next1 = 2 * cur + 1;
			int next2 = 2 * cur + 2;
			int next;
			if (next1 >= tree.size()) break;
			if (next2 >= tree.size()) next = next1;
			else next = !(tree[next1] < tree[next2]) ? next1 : next2;
			if (!(tree[cur] < tree[next])) break;
			swap<T>(tree[cur], tree[next]);
			cur = next;
		}
	}
};
template <class T>
void sort(T* s, T* e) {
	priority_queue<T> pq;
	for (T* pos = s; pos != e; pos++) {
		pq.push(*pos);
	}
	for (T* pos = --e; pos >= s; pos--) {
		*pos = pq.top();
		pq.pop();
	}
}
struct RNG {
	long long seed;
	RNG() :seed(12387621) {}
	int next() {
		int ret = (int)seed;
		seed = (seed * 2123978 + 122178) % 1000000007;
		return ret;
	}
};
template <class T> class set {
	struct Node {
		Node *l, *r;
		T key;
		int prior;
		Node() {}
		Node(T ky, int pr) :l(0), r(0), key(ky), prior(pr) {}
	};
	typedef Node* pNode;
	pNode root;
	RNG rng;
public:
	set() : root(0),rng(RNG()) {}
	void merge(pNode& par, pNode l, pNode r) {
		if (l == 0 || r == 0) par = (l == 0 ? r : l);
		else if (l->prior < r->prior) merge(r->l, l, r->l), par = r;
		else merge(l->r, l->r, r), par = l;
	}
	void split(pNode cur, pNode breaker, pNode& l, pNode& r) {
		if (cur == 0) l = r = 0;
		else if (cur->key < breaker->key) split(cur->r, breaker, cur->r, r), l = cur;
		else split(cur->l, breaker, l, cur->l), r = cur;
	}
	void insert(pNode& cur, pNode target) {
		if (cur == 0) { cur = target; }
		else if (cur->prior < target->prior) split(cur, target, target->l, target->r), cur = target;
		else insert((cur->key < target->key ? cur->r : cur->l), target);
	}
	void erase(pNode &cur, pNode target) {
		if (cur == 0) return;
		else if (cur->key != target->key) erase((cur->key < target->key ? cur->r : cur->l), target);
		else merge(cur, cur->l, cur->r);
	}
	void inorder(pNode cur) {
		if (cur == 0) return;
		inorder(cur->l);
		printf("%d ", cur->key);
		inorder(cur->r);
	}
	void insert(T v) { insert(root, new Node(v, rng.next())); }
	void erase(T v) { erase(root, new Node(v,rng.next())); }
	void printAll() { inorder(root); }
};

int main() {
	set<int> st;
	for (int i = 0; i < 10; i++) {
		st.insert(i);
	}
	st.printAll();
	return 0;
}
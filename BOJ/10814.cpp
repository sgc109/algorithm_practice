#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define fastio() ios_base::sync_with_stdio(false),cin.tie(NULL)
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

struct node{
	int age;
	int ord;
	string name;
	bool operator<(const node& rhs) const{
		if(age == rhs.age) return ord < rhs.ord;
		return age < rhs.age;
	}
};
int N;
node nodes[100003];
int main() {
	fastio();
	cin >> N;
	for(int i = 0 ; i < N; i++){
		int a;
		string b;
		cin >> a >> b;
		nodes[i] = node{a, i, b};
	}
	sort(nodes, nodes + N);
	for(int i = 0 ; i < N; i++) cout << nodes[i].age << ' ' << nodes[i].name << '\n';
	return 0;
}
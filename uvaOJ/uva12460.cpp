#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int cnt;
unordered_map<string, int> id;
string front[200003], back[200003];
int par[200003];

int find(int u){
	return par[u] == u ? u : par[u] = find(par[u]);
}
int merge(int a, int b){
	a = find(a), b = find(b);
	if(a == b) return -1;
	par[a] = b;
	return b;
}
int main() {
	while(1){
		string s;
		cin >> s;
		
		if(s == "--") break;
		
		id[s] = ++cnt;
		par[id[s]] = id[s];

		front[0] = back[s.size()-1] = "";
		for(int i = 1 ; i < s.size(); i++) front[i] = front[i-1] + s[i-1];
		for(int i = s.size()-2; i >= 0; i--) back[i] = s[i+1] + back[i+1];
		for(int i = 0 ; i < s.size(); i++) {
			string sub = front[i] + back[i];
			if(id[sub] == 0) id[sub] = ++cnt, par[id[sub]] = id[sub];
			merge(id[s], id[sub]);
		}
	}

	string s1,s2;
	while(cin >> s1 >> s2){
		if(find(id[s1]) == find(id[s2])) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
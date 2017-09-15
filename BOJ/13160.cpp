#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

vector<pair<int,pair<int,int> > > seqs;
int N;
int main() {
	cin >> N;
	for(int i = 0 ; i < N; i++) {
		int l,r;
		cin >> l >> r;
		seqs.push_back({l,{-1, i+1}});
		seqs.push_back({r,{1, i+1}});
	}
	sort(seqs.begin(), seqs.end());

	int ans = 0;
	int cnt = 0;
	for(auto seq : seqs){
		cnt -= seq.second.first;
		ans = max(ans, cnt);
	}

	cnt = 0;
	set<int> st;
	for(auto seq : seqs){
		if(seq.second.first < 0) st.insert(seq.second.second);
		else st.erase(seq.second.second);
		cnt -= seq.second.first;
		if(cnt == ans) break;
	}
	cout << ans << endl;
	for(int a : st) cout << a << " ";
	return 0;
}
	
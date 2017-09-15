#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define fastio() ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

vector<int> t[140003];
int dp[35003][53];
int A[35003];
int size;
int N, K;
void init(int nodeL, int nodeR, int node){
	if(nodeL == nodeR) {
		vector<int> v;
		v.push_back(A[nodeL]);
		t[node] = v;
		return;
	}
	int nodeM = (nodeL + nodeR) / 2;
	init(nodeL, nodeM, 2*node);
	init(nodeM + 1, nodeR, 2*node + 1);
	vector<int> lv = t[2*node];
	vector<int> rv = t[2*node+1];
	int lpos = 0, rpos = 0;
	vector<int> ret;
	while(lpos < sz(lv) && rpos < sz(rv)){
		if(lv[lpos] < rv[rpos]) ret.pb(lv[lpos++]);
		else if(lv[lpos] == rv[rpos]) rpos++;
		else ret.pb(rv[rpos++]);
	}
	while(lpos < sz(lv)) ret.pb(lv[lpos++]);
	while(rpos < sz(rv)) ret.pb(rv[rpos++]);
	
	t[node] = ret;
}
vector<int> query(int s, int e, int nodeL, int nodeR, int node){
	if(s <= nodeL && nodeR <= e) return t[node];
	if(e < nodeL || nodeR < s) return vector<int>();
	int nodeM = (nodeL + nodeR) / 2;
	vector<int> lv = query(s, e, nodeL, nodeM, 2*node);
	vector<int> rv = query(s, e, nodeM + 1, nodeR, 2*node + 1);
	int lpos = 0, rpos = 0;
	vector<int> ret;
	while(lpos < sz(lv) && rpos < sz(rv)){
		if(lv[lpos] < rv[rpos]) ret.pb(lv[lpos++]);
		else if(lv[lpos] == rv[rpos]) rpos++;
		else ret.pb(rv[rpos++]);
	}
	while(lpos < sz(lv)) ret.pb(lv[lpos++]);
	while(rpos < sz(rv)) ret.pb(rv[rpos++]);
	return ret;
}
vector<int> query(int s, int e){
	return query(s, e, 0, size - 1, 1);
}

int go(int pos, int rest){
	if(pos == N) return rest ? -INF : 0;
	if(!rest) return -INF;
	int& cache = dp[pos][rest];
	if(cache != -1) return cache;
	int ret = -INF;
	for(int i = pos; i < N; i++){
		ret = max(ret, sz(query(pos, i)) + go(i + 1, rest - 1));
	}
	return cache = ret;
}
int main() {
	memset(dp,-1,sizeof(dp));
	fastio();
	cin >> N >> K;
	for(int i = 0 ; i < N; i++) cin >> A[i];
	for(size = 1; size <= N; size *= 2);
	init(0, size - 1, 1);
	cout << go(0, K);
	return 0;
}
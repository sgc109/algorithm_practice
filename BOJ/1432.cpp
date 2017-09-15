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

int N;
int in[303];
priority_queue<int> pq;
vector<int> G[303];
int after[303];
int cnt;
int main() {
	fastio();
	cin >> N;
	for(int i = 0 ; i < N; i++){
		string S;
		cin >> S;
		for(int j = 0 ; j < N; j++){
			if(S[j] == '1') in[i]++, G[j].pb(i);
		}
	}
	for(int i = 0 ; i < N; i++) if(!in[i]) pq.push(i);
	while(!pq.empty()){
		int cur = pq.top();
		pq.pop();
		after[cur] = N - cnt++;
		for(int nxt : G[cur]){
			in[nxt]--;
			if(!in[nxt]) pq.push(nxt);
		}
	}
	for(int i = 0 ; i < N; i++) cout << after[i] << ' ';
	return 0;
}
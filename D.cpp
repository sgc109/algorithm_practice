#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define fastio() ios::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const ll infl = 0x3c3c3c3c3c3c3c3c;

struct Node{
	int day, id, cost;
	bool operator<(const Node& rhs) const{
		return day < rhs.day;
	}
};
int N, M, K;
ll come[1000003], go[1000003];
int check[100003];
ll tikCst[100003];
vector<Node> comV, goV;
int main() {
	fastio();
	memset(come,0x3c,sizeof(come));
	memset(go,0x3c,sizeof(go));
	cin >> N >> M >> K;
	for(int i = 0 ; i < M; i++) {
		int d, s, e, c;
		cin >> d >> s >> e >> c;
		if(s) comV.pb(Node{d, s, c});
		else goV.pb(Node{-d, e, c});
	}
	sort(all(comV));
	sort(all(goV));
	int cnt = 0;
	int S = -1, E = -1;
	int ok = 0;
	ll sum = 0;
	memset(tikCst,0x3c,sizeof(tikCst));
	for(auto p : comV){
		if(!ok && !check[p.id]) check[p.id] = 1, cnt++;
		if(!ok && cnt == N) ok = 1;
		if(tikCst[p.id] == infl) tikCst[p.id] = p.cost, sum += p.cost;
		else if(tikCst[p.id] > p.cost) sum += -tikCst[p.id] + p.cost, tikCst[p.id] = p.cost;
		if(ok) come[p.day] = min(come[p.day], sum);
	}

	memset(tikCst,0x3c,sizeof(tikCst));
	memset(check,0,sizeof(check));
	sum = 0;
	cnt = 0;
	ok = 0;
	for(auto p : goV){
		if(!ok && !check[p.id]) check[p.id] = 1, cnt++;
		if(!ok && cnt == N) ok = 1;
		if(tikCst[p.id] == infl) tikCst[p.id] = p.cost, sum += p.cost;
		else if(tikCst[p.id] > p.cost) sum += -tikCst[p.id] + p.cost, tikCst[p.id] = p.cost;
		if(ok) go[-p.day] = min(go[-p.day], sum);
	}
	for(int i = 1; i <= 1000000; i++) come[i] = min(come[i - 1], come[i]);
	for(int i = 1000000; i >= 0; i--) go[i] = min(go[i + 1], go[i]);

	ll ans = infl;
	for(int i = 0 ; i <= 1000000 - K; i++) ans = min(ans, come[i] + go[i + K + 1]);
	if(ans == infl) ans = -1;
	cout << ans;

	return 0;
}
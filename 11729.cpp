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

int N;
vector<pair<int,int> > ans[23][3][3];
vector<pair<int,int> > go(int h, int from, int to){
    if(!h) return vector<pair<int,int> >();
    if(sz(ans[h][from][to])) return ans[h][from][to];
    int els = from ^ to;
    vector<pair<int,int> > ret;
    ret = go(h - 1, from, els);
    ret.pb({from, to});
    auto tmp = go(h - 1, els, to);
    ret.insert(ret.end(), all(tmp));
    return ans[h][from][to] = ret;
}
int main() {
	fastio();
    cin >> N;
    go(N, 1, 3);
    cout << sz(ans[N][1][3]) << '\n';
    for(auto p : ans[N][1][3]) cout << p.first << ' ' << p.second << '\n';
}

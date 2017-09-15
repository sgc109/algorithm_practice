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

int N, M;
int psum[100003];
int main() {
	fastio();
    cin >> N >> M;
    for(int i = 1; i <= N; i++) cin >> psum[i];
    for(int i = 1; i <= N; i++) psum[i] += psum[i - 1];
    while(M--){
        int l, r;
        cin >> l >> r;
        cout << psum[r] - psum[l - 1] << '\n';
    }
}

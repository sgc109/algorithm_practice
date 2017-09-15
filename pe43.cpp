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

vector<int> v;
int mods[13] = {2, 3, 5, 7, 11, 13, 17};
int main() {
	fastio();
    ll ans = 0;
    for(int i = 0; i < 10; i++) v.pb(i);
    do{
        int now = 100 * v[7] + 10 * v[8] + v[9];
        int ok = 1;
        for(int j = 6; j >= 0; j--) {
            if(now % mods[j]) {
                ok = 0;
                break;
            }
            now /= 10;
            now += 100 * v[j];
        }
        if(!ok) continue;
        ll num = 0;
        for(int j = 0; j < 10; j++) num = num * 10 + v[j];
        ans += num;
    }while(next_permutation(all(v)));
    cout << ans;
}

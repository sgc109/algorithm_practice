#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define fastio() ios::sync_with_stdio(0),cin.tie(0);
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int inf = 0x3c3c3c3c;
const ll infl = 0x3c3c3c3c3c3c3c3c;

ll s2l(string s){
    ll ret = 0;
    for(char c : s) ret = 10 * ret + c - '0';
    return ret;
}
int cmp(string a, string b){
    reverse(all(a));
    reverse(all(b));
    if(sz(a) > sz(b)) return 1;
    if(sz(a) < sz(b)) return -1;
    for(int i = sz(a) - 1; i >= 0; i--) {
        if(a[i] > b[i]) return 1;
        else if(a[i] < b[i]) return -1;
    }
    return 0;
}
ll b;
string base, in;
ll go(string num, ll bs){
    if(sz(num) == 0) return 0;
    vector<int> pos;
    for(int i = 0; i < sz(num); i++) if(num[i] != '0') pos.pb(i);
    for(int i = sz(pos) - 1; i >= 0; i--){
        int p = pos[i];
        string s = num.substr(p, sz(num) - p + 1);
        if(cmp(base, s) <= 0) {
            if(i == sz(pos) - 1){
                ll ret = go(num.substr(0, sz(num) - 1), bs * b);
                return ret;
            }
            else {
                string tmp = num.substr(pos[i + 1], sz(num) - pos[i + 1] + 1);
                ll ret = s2l(tmp) * bs + go(num.substr(0, pos[i + 1]), bs * b);
                return ret;
            }
        }
    }
    return s2l(num) * bs;
}
int main(){
    cin >> base >> in;
    b = s2l(base);
    ll ans = go(in, 1);
    cout << ans;
}

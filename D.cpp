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
    while(s.back() == '0') s.pop_back(); 
    reverse(all(s));
    ll ret = 0;
    for(char c : s) ret = 10 * ret + c - '0';
    return ret;
}

int cmp(string a, string b){
    while(a.back() == '0') a.pop_back();
    while(b.back() == '0') b.pop_back();
    if(sz(a) > sz(b)) return 1;
    if(sz(a) < sz(b)) return -1;
    for(int i = sz(a) - 1; i >= 0; i--) {
        if(a[i] > b[i]) return 1;
        else if(a[i] < b[i]) return -1;
    }
    return 0;
}

ll ans;
ll b;
string base, in;
int main(){
    cin >> base >> in;
    reverse(all(base));
    b = s2l(base);
    ll gob = 1;
    string bigyo;
    int cnt0 = 0;
    for(int i = sz(in) - 1; i >= 0; i--){
        cout << "gob : " << gob << endl;
        cout << "cnt0 : " << cnt0 << endl;
        string tmp = bigyo + in[i];
        cout << "ans : " << ans << ", bigyo : " << bigyo << ", tmp : " << tmp << endl;
        cout << "cmp : " << cmp(base, tmp) << endl;
        if(in[i] == '0') cnt0++;
        if(cmp(base, tmp) <= 0) {
            cout << "fuck\n";
            ans += s2l(bigyo) * gob;
            bigyo = in[i];
            gob *= b;
            while(cnt0--) gob *= b;
        }
        else {
            if(in[i] != '0') cnt0 = 0;
            bigyo = tmp;
        }
        cout << "ans : " << ans << endl;
    }
    ans += s2l(bigyo) * gob;   
    cout << ans;
}

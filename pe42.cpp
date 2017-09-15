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

string S;
int isTri[1000000];
int main() {
	fastio();
    for(int i = 1; i * i <= 1000000; i++) isTri[i * (i + 1) / 2] = 1;
    freopen("words.txt", "r", stdin);
    cin >> S;
    stringstream ss(S);
    string s;
    int ans = 0;
    while(getline(ss, s, ',')){
        int sum = 0;
        for(int i = 1; i < sz(s) - 1; i++) sum += s[i] - 'A' + 1;
        if(isTri[sum]) ans++;
    }
    cout << ans;
}

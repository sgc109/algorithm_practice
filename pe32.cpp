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
set<int> st;
int main() {
	fastio();
    for(int i = 1; i <= 9; i++) v.pb(i);
    ll ans = 0;
    do{
        for(int i = 0; i < 6; i++){
            for(int j = i + 1; j < 7; j++){
                int a = 0, b = 0, c = 0;
                for(int k = 0; k < i + 1; k++) a = a * 10 + v[k];
                for(int k = i + 1; k < j + 1; k++) b = b * 10 + v[k];
                for(int k = j + 1; k < 9; k++) c = c * 10 + v[k];
                if(a * b == c) st.insert(c);
            }
        }
    }while(next_permutation(all(v)));
    for(int num : st) ans += num;
    cout << ans;

	return 0;
}

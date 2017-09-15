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

int bino[103][103];
int main() {
	fastio();
    for(int i = 0; i <= 100; i++) bino[i][0] = 1;
    int ans = 0;
    for(int i = 1; i <= 100; i++){
        for(int j = 1; j <= i; j++){
            bino[i][j] = min(1000001, bino[i - 1][j] + bino[i - 1][j - 1]);
            if(bino[i][j] > 1000000) ans++;
        }
    }
    cout << ans;
}

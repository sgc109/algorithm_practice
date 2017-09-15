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

int mx, mxNum;
int main() {
	fastio();
    for(int p = 3; p <= 1000; p++){
        int cnt = 0;
        for(int a = 1; a <= p / 3; a++){
            for(int b = a; a + b <= 2 * p / 3; b++){
                int c = p - a - b;
                if(a * a + b * b == c * c) cnt++;
            }
        }
        if(mx < cnt) mx = cnt, mxNum = p;
    }
    cout << mx << ' ' << mxNum;

	return 0;
}

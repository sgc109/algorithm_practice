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

int main() {
	fastio();
    int ans = 0;
    for(int m2 = 0; m2 <= 100; m2++){
        int s2 = m2 * 2;
        if(s2 > 200) break;
        for(int m3 = 0; m3 <= 40; m3++){
            int s3 = s2 + m3 * 5;
            if(s3 > 200) break;
            for(int m4 = 0; m4 <= 20; m4++){
                int s4 = s3 + m4 * 10;
                if(s4 > 200) break;
                for(int m5 = 0; m5 <= 10; m5++){
                    int s5 = s4 + m5 * 20;
                    if(s5 > 200) break;
                    for(int m6 = 0; m6 <= 4; m6++){
                        int s6 = s5 + m6 * 50;
                        if(s6 > 200) break;
                        for(int m7 = 0; m7 <= 2; m7++){
                            int s7 = s6 + m7 * 100;
                            if(s7 > 200) break;
                            ans++;
                        }
                    }
                }
            }
        }
    }
    cout << ans + 1;

	return 0;
}

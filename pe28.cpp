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
int pane[1003][1003];
int main() {
	fastio();
    N = 1001;
    int curI = N / 2, curJ = N / 2;
    int now = 1;
    int len = 1;
    int dir = 0;
    while(now < N * N){
        for(int l = 0; l < 2; l++){
            int di = "1210"[dir] - '1';
            int dj = "2101"[dir] - '1';
            for(int k = 0; k < len; k++){
                pane[curI][curJ] = now++;
                curI += di, curJ += dj;
            }
            dir = (dir + 1) % 4;
        }
        len++;
    }
    ll ans = 0;
    for(int i = 0; i < N; i++){
        ans += pane[i][i];
        ans += pane[i][N - 1 - i];
    }

    ans -= pane[N / 2][N / 2];
    cout << ans;
    
	return 0;
}

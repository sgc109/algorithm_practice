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

int N;
string S[1003];
int main(){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> S[i];
    int ans = 0;
    for(int i = 0; i < 7; i++){
        int cnt = 0;
        for(int j = 0; j < N; j++){
            if(S[j][i] == '1') cnt++;
        }
        ans = max(ans, cnt);
    }
    cout << ans;
}

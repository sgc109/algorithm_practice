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
int A[1003];
int main(){
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> A[i];
    sort(A + 1, A + N + 1, greater<int>());
    int ans = 0;
    for(int i = 1; i <= N; i++) {
        if(A[i] < i) break;
        ans = i;
    }
    cout << ans;
}

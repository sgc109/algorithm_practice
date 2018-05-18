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
int A[103];
vector<int> diff;
int main(){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N - 1; i++) diff.pb(A[i] - A[i + 1]);
    int ok = 1;
    for(int i = 0; i < sz(diff) - 1; i++) if(diff[i] != diff[i + 1]) ok = 0;
    if(!ok) cout << A[N - 1];
    else cout << A[N - 1] - diff[0];
}

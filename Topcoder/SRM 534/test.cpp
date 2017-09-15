#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define fastio() ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int hsh(string s){
    int ret = 0;
    for(int i = 0 ; i < (int)s.size(); i++){
        ret = ret * 2 + (s[i] == 'o');
    }
    return ret;
}
int main() {
	fastio();
	cout << hsh("..o..o");
	return 0;
}
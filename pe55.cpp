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

struct Number{
    vector<int> v;
    Number(vector<int> init){
        v = init;
    }
    Number(int size){
        v = vector<int>(size, 0);
    }
    Number operator+(Number& rhs) {
        vector<int> retV;
        int szA = sz(v), szB = sz(rhs.v);
        for(int i = 0; i < max(szA, szB); i++){
            int l = (i < szA ? v[i] : 0);
            int r = (i < szB ? rhs.v[i] : 0);
            retV.pb(l + r);
        }
        retV.pb(0);
        for(int i = 0; i < sz(retV) - 1; i++) {
            retV[i + 1] += retV[i] / 10, retV[i] %= 10;
        }
        if(retV.back() == 0) retV.pop_back();
        Number ret(retV);
        return ret;
    }
    void print(){
        for(int i = sz(v) - 1; i >= 0; i--) cout << v[i];
        cout << '\n';
    }
};

Number i2v(int x){
    vector<int> v;
    while(x) v.pb(x % 10), x /= 10;
    return Number(v);
}
int isPalin(Number& s){
    for(int i = 0; i <= sz(s.v) / 2; i++) if(s.v[i] != s.v[sz(s.v) - 1 - i]) return 0;
    return 1;
}
int isLych(Number num){
    for(int i = 0; i < 49; i++) {
        if(isPalin(num)) return 0;
        vector<int> revV = num.v;
        reverse(all(revV));
        while(!revV.empty() && revV.back() == 0) revV.pop_back();
        Number rev(revV);
        num = num + rev;
        // num.print();
    }
    if(isPalin(num)) return 0;
    return 1;
}
int main() {
    fastio();
    int ans = 0;
    for(int i = 1; i <= 10000; i++){
        // cout << "i : " << i << endl;
        if(isLych(Number(i2v(i)))) ans++, cout << i << endl;
    }
    cout << ans;
}

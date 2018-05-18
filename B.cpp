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

string S;
int N;
int pos[330];
int main(){
    cin >> S;
    N = sz(S);
    for(int i = 0; i < N; i++) {
        char c = S[i];
        if(c == '!') continue;
        pos[c] = i;
    }
    string s = "RBYG";
    for(char col : s){
        int st = pos[col];
        while(st >= 0) st -= 4;
        int cnt = 0;
        for(st += 4; st < N; st += 4) if(S[st] == '!') cnt++;
        cout << cnt << ' ';
    }
}

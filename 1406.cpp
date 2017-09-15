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

list<char> lst;
int N;
int main() {
	fastio();
    string S;
    cin >> S;
    for(char ch : S) lst.pb(ch);
    auto cur = lst.end();
    cin >> N;
    while(N--){
        char op, c;
        cin >> op;
        if(op == 'P') {
            cin >> c;
            lst.insert(cur, c);
        }
        else if(op == 'L'){
            if(cur != lst.begin()) cur--;
        }
        else if(op == 'D'){
            if(cur != lst.end()) cur++;
        }
        else{
            if(cur != lst.begin()) cur = lst.erase(--cur);
        }
    }
    for(auto it = lst.begin(); it != lst.end(); it++){
        cout << *it;
    }
}

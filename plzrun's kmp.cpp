#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

vector<int> kmp_search(const string& a, const string& b) {
    int an = a.length(), bn = b.length();
    vector<int> pi(bn);
    int m = 0;
    for (int i = 1; i < bn; i++) {
        while (m > 0 && b[i] != b[m])
            m = pi[m - 1];
        if (b[i] == b[m]) ++m;
        pi[i] = m;
    }
    vector<int> ret;
    m = 0;
    for (int i = 0; i < an; i++) {
        while (m > 0 && a[i] != b[m])
            m = pi[m - 1];
        if (a[i] == b[m]) ++m;
        if (m == bn) ret.push_back(i - m + 1);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string t, p;
    getline(cin, t);
    getline(cin, p);

    vector<int> ret = kmp_search(t, p);
    cout << ret.size() << endl;
    for (int i = 0; i < (int) ret.size(); i++) {
        cout << ret[i] + 1 << ' '; 
    }
    return 0;
}

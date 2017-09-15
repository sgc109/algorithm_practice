#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

vector<string> vs;
vector<pair<int,int> > vp;
class DengklekMakingChains {
public:
    int maxBeauty(vector<string> chains) {
        vs.clear(), vp.clear();
        int ans = 0;
        for(int i = 0 ; i < (int)chains.size(); i++) {
            int ok = 1;
            int sum = 0;
            for(int j = 0 ; j < 3; j++){
                if(chains[i][j] == '.') ok = 0;
                else sum += chains[i][j] - '0';
            }
            if(!ok) vs.push_back(chains[i]);
            else ans += sum;
        }

        for(int i = 0 ; i < (int)vs.size(); i++){
            int l = 0, r = 0;
            for(int j = 0 ; vs[i][j] != '.'; j++) l += vs[i][j] - '0';
            for(int j = 2 ; vs[i][j] != '.'; j--) r += vs[i][j] - '0';
            vp.push_back({l, r});
        }
        int maxx = 0;
        for(int i = 0 ; i < (int)vp.size(); i++){
            maxx = max(maxx, max(vp[i].first, vp[i].second));
            for(int j = i + 1; j < (int)vp.size(); j++){
                maxx = max(maxx, max(vp[i].first + vp[j].second, vp[i].second + vp[j].first));
            }
        }

        ans += maxx;

        for(int i = 0 ; i < (int)vp.size(); i++) for(int j = 0 ; j < 3; j++) if(vs[i][j] != '.') ans = max(ans, vs[i][j] - '0');

        return ans;
    }
};

// CUT begin
ifstream data("DengklekMakingChains.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
stringstream ss(next_line());
ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T> void from_stream(vector<T> &ts) {
int len;
from_stream(len);
ts.clear();
for (int i = 0; i < len; ++i) {
    T t;
    from_stream(t);
    ts.push_back(t);
}
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(vector<string> chains, int __expected) {
    time_t startClock = clock();
    DengklekMakingChains *instance = new DengklekMakingChains();
    int __result = instance->maxBeauty(chains);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
        break;
        vector<string> chains;
        from_stream(chains);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
        continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(chains, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1500775136;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 300 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "DengklekMakingChains (300 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end

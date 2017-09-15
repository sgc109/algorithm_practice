#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

class PatrolRoute {
public:
    int X, Y;
    int count(int W, int H){
        ll ret = 6;
        ret = (ret * (X - W)) % mod;
        ret = (ret * (Y - H)) % mod;
        ret = (ret * (W - 1)) % mod;
        ret = (ret * (H - 1)) % mod;
        return (int)ret;
    }
    int countRoutes(int X, int Y, int minT, int maxT) {
        this->X = X, this->Y = Y;
        int lo = 8, hi = 2 * (X - 1) * (Y - 1);
        lo = max(lo, minT);
        hi = min(hi, maxT);
        if(lo > hi) return 0;
        int ans = 0;
        if(lo & 1) lo++;
        for(int L = lo; L <= hi; L += 2){
            if(L & 1) continue;
            int K = L / 2;
            for(int W = 2; W <= K - 2; W++){
                int H = K - W;
                if(W >= X || H >= Y) continue;
                ans = (ans + count(W, H)) % mod;
            }
        }
        return ans;
    }
};

// CUT begin
ifstream data("PatrolRoute.sample");

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

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(int X, int Y, int minT, int maxT, int __expected) {
    time_t startClock = clock();
    PatrolRoute *instance = new PatrolRoute();
    int __result = instance->countRoutes(X, Y, minT, maxT);
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
        int X;
        from_stream(X);
        int Y;
        from_stream(Y);
        int minT;
        from_stream(minT);
        int maxT;
        from_stream(maxT);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
        continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(X, Y, minT, maxT, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1502517127;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "PatrolRoute (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end

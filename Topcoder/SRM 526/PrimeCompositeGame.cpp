#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int dp[500003][2];
int notPrime[500003];
class PrimeCompositeGame {
public:
    int n, k;
    int go(int pos, int turn) { // turn = 1 -> opposite
        if (pos == 1) return turn ? 1 : -1;
        if (pos != n && notPrime[pos] == turn) return turn ? -1 : 1;
        int& cache = dp[pos][turn];
        if (cache != inf) return cache;
        int ans = 0;
        int opp = 0;
        for (int i = 1; i <= k && 1 <= pos - i; i++) {
            if (notPrime[pos - i] != turn) continue;
            int ret = go(pos - i, turn ^ 1);
            int winner = ret < 0;
            if (winner == turn) {
                if (!ans) ans = ret;
                else if (turn) ans = max(ans, ret);
                else ans = min(ans, ret);
            }
            else {
                if (!opp) opp = ret;
                else if (turn) opp = min(opp, ret);
                else opp = max(opp, ret);
            }
        }
        
        if (ans < 0) ans--;
        else if(ans > 0) ans++;
        else {
            if (opp) {
                if (opp < 0) opp--;
                else opp++;
                return cache = opp;
            }
            return turn ? 1 : -1;
        }

        return cache = ans;
    }
    int theOutcome(int N, int K) {
        n = N, k = K;
        memset(notPrime, 0, sizeof(notPrime));
        memset(dp, 0x3c, sizeof(dp));
        for (int i = 2; i * i <= 474747; i++) {
            if (notPrime[i]) continue;
            for (int j = 2 * i; j <= 474747; j += i) notPrime[j] = 1;
        }

        int ret = go(N, 0);
        if (ret < 0) ret++;
        else ret--;
        return ret;
    }
};

// CUT begin
ifstream data("PrimeCompositeGame.sample");

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

bool do_test(int N, int K, int __expected) {
    time_t startClock = clock();
    PrimeCompositeGame *instance = new PrimeCompositeGame();
    int __result = instance->theOutcome(N, K);
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
        int N;
        from_stream(N);
        int K;
        from_stream(K);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(N, K, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1500150155;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "PrimeCompositeGame (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end

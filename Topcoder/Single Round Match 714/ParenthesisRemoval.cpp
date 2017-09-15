#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

class ParenthesisRemoval {
    public:
    int countWays(string s);
};

map<long long, long long> dp;

long long hashing(string s){
    long long ret = 0;
    for(int i = 0 ; i < s.size(); i++){
        if(s[i] == '(') ret++;
        ret = (ret * 107) % 1000000000000000007;
    }
    return ret;
}

long long go(string s){
    if(s.size()==2) return 1;
    long long h = hashing(s);
    auto it = dp.find(h);
    if(it != dp.end()) return dp[h];

    string next;
    int st = 0;
    int i;
    for(i = 0 ; i < s.size(); i++){
        if(s[i] == '(') st++;
        else st--;
        if(!st) break;
    }
    int pos = i;

    long long ret = 0;
    for(int i = 1; i <= pos; i++){
        if(s[i] == '(') continue;
        string next;
        for(int j = 1; j < s.size(); j++) if(i!=j) next += s[j];
        ret = (ret + go(next)) % MOD;
    }

    return dp[h] = ret;
}

int ParenthesisRemoval::countWays(string s){
    return (int)go(s);
}

// CUT begin
ifstream data("ParenthesisRemoval.sample");

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

bool do_test(string s, int __expected) {
    time_t startClock = clock();
    ParenthesisRemoval *instance = new ParenthesisRemoval();
    int __result = instance->countWays(s);
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
        string s;
        from_stream(s);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(s, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1494154804;
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
        cout << "ParenthesisRemoval (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end

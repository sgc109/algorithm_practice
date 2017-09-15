#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

class ImportantSequence {
public:
    int getCount(vector<int> B, string operators) {
        int pos;
        int N = (int)B.size();
        for(pos = 0; pos < N && operators[pos] == '-'; pos++){

        }
        if(pos == N) return -1;
        ll lo = 1, hi = B[pos] - 1;
        for(int i = pos + 1; i < N; i++){
            if(lo > hi) return 0;
            char op = operators[i];
            if(op == '-'){
                lo -= B[i];
                hi -= B[i];
            }
            else {
                ll l = lo, h = hi;
                lo = B[i] - h;
                hi = B[i] - l;
            }
            lo = max(lo, 1ll);
        }

        reverse(B.begin(), B.end());
        reverse(operators.begin(), operators.end());
        for(int i = 0 ; i < N; i++){
            if(lo > hi) return 0;
            char op = operators[i];
            if(op == '-'){
                lo += B[i];
                hi += B[i];
            }
            else {
                ll l = lo, h = hi;
                lo = B[i] - h;
                hi = B[i] - l;
            }
            lo = max(lo, 1ll);
        }
        if(lo > hi) return 0;

        return hi - lo + 1;
    }
};

// CUT begin
ifstream data("ImportantSequence.sample");

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

bool do_test(vector<int> B, string operators, int __expected) {
    time_t startClock = clock();
    ImportantSequence *instance = new ImportantSequence();
    int __result = instance->getCount(B, operators);
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
        vector<int> B;
        from_stream(B);
        string operators;
        from_stream(operators);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
        continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(B, operators, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1502191985;
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
        cout << "ImportantSequence (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end

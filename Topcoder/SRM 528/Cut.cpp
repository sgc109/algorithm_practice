#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

bool cmp(int a, int b){
    int c1 = (a % 10) == 0;
    int c2 = (b % 10) == 0;
    if(c1 && c2) return a < b;
    if(!c1 && !c2) return b < a;
    return c1;
}
class Cut {
    public:
    int getMaximum(vector<int> eelLengths, int maxCuts) {
        sort(eelLengths.begin(), eelLengths.end(), cmp);
        int ans = 0;
        for(int i = 0 ; i < (int)eelLengths.size() && maxCuts; i++){
            int l = eelLengths[i];
            if(l % 10 == 0) {
                if(l / 10 - 1 <= maxCuts) {
                    ans += l / 10;
                    maxCuts -= l / 10 - 1;
                }
                else ans += maxCuts, maxCuts = 0;
            }
            else {
                int rest = l / 10;
                if(rest <= maxCuts) ans += rest, maxCuts -= rest;
                else ans += maxCuts, maxCuts = 0;
            }
        }
        return ans;
    }
};

// CUT begin
ifstream data("Cut.sample");

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

bool do_test(vector<int> eelLengths, int maxCuts, int __expected) {
    time_t startClock = clock();
    Cut *instance = new Cut();
    int __result = instance->getMaximum(eelLengths, maxCuts);
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
        vector<int> eelLengths;
        from_stream(eelLengths);
        int maxCuts;
        from_stream(maxCuts);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(eelLengths, maxCuts, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1500146785;
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
        cout << "Cut (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int hsh(string& s){
    int ret = 0;
    for(int i = 0 ; i < (int)s.size(); i++){
        ret = ret * 2 + (s[i] == 'o');
    }
    return ret;
}
bool inRange(int x){
    return x < n;
}
int dp[1<<20];
int n;
int go(string& state){
    int h = hsh(state);
    if(h == 1) return 0;
    int& cache = dp[h];
    if(cache != -1) return cache;
    int ret = 0;
    for(int i = 0 ; i < (int)state.size() - 1; i++){
        if(state[i] == '.') continue;
        if(inRange(i + 1) && state[i + 1] == 'o' && inRange(i + 2) && state[i + 2] == 'o' && inRange(i + 3) && (i + 3 == n - 1 || state[i + 3] == '.')){
            string next = state;
            next[i] = '.';
            next[i + 3] = 'o';
            ret |= !go(next);
        }
        if(inRange(i + 1) && (i + 1 == n - 1 || state[i + 1] == '.')) {
            string next = state;
            next[i] = '.';
            next[i + 1] = 'o';
            ret |= !go(next);
        }
    }
    return cache = ret;
}
class EllysCheckers {
    public:
    string getWinner(string board) {
        memset(dp,-1,sizeof(dp));
        n = (int)board.size();
        return go(board) ? "YES" : "NO";
    }
};

// CUT begin
ifstream data("EllysCheckers.sample");

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

bool do_test(string board, string __expected) {
    time_t startClock = clock();
    EllysCheckers *instance = new EllysCheckers();
    string __result = instance->getWinner(board);
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
        string board;
        from_stream(board);
        next_line();
        string __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(board, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1501210701;
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
        cout << "EllysCheckers (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end

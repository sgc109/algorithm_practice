#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

class RowAndCoins {
public:
    int N;
    int dp[1<<14][2];
    string pane;
    int canWin(int mask, int turn){
        if((mask&-mask) == mask) {
            int i;
            for(i = 0 ; i < N; i++) if((1<<i) == mask) break; 
            return (pane[i] == 'B') ^ turn;
        }
        int&cache = dp[mask][turn];
        if(cache != -1) return cache;
        cache = 0;
        for(int size = 1 ; size < N; size++){
            int mk = (1<<size)-1;
            for(int j = 0 ; j < N-size+1; j++, mk<<=1){
                if((mask & mk) != mk) continue;
                if(mask^mk) cache |= !canWin(mask^mk, turn^1);
            }
        }
        return cache;
    }
    string getWinner(string cells) {
        pane = cells;
        memset(dp,-1,sizeof(dp));
        N = cells.size();

        return canWin((1<<N)-1, 1) ? "Alice" : "Bob";
    }
};

// CUT begin
ifstream data("RowAndCoins.sample");

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

bool do_test(string cells, string __expected) {
    time_t startClock = clock();
    RowAndCoins *instance = new RowAndCoins();
    string __result = instance->getWinner(cells);
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
        string cells;
        from_stream(cells);
        next_line();
        string __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
        continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(cells, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1495170218;
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
        cout << "RowAndCoins (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end

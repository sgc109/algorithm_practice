#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
class MagicalGirlLevelTwoDivOne {
public:
    int theCount(vector<string> palette, int n, int m);
};

int N,M;
ll dp[13][1<<10];
int pane[53][53];
int correct[13][13];
int cnts[13][13];
ll pow4[2503], pow5[2503];
ll go(int row, int state){
    if(row == N) return state == ((1<<M)-1);
    ll& cache = dp[row][state];
    if(cache != -1) return cache;
    cache = 0;
    for(int i = 0 ; i < (1<<M); i++){
        int cnt= 0;
        for(int j = i; j ; j>>=1) cnt+=(j&1);
        if(cnt%2==0) continue;
        bool ok = true;
        ll mult = 1;
        for(int j = 0 ; j < M; j++){
            if(correct[row][j] != -1 && correct[row][j] != ((i&(1<<j))>>j)) {ok = false; break;}
            mult = (mult * (((i&(1<<j))>>j)?pow5[cnts[row][j]]:pow4[cnts[row][j]])) % MOD;
        }
        if(ok) cache = (cache + (mult * go(row+1, state^i)) % MOD) % MOD;
    }
    return cache;
}
int MagicalGirlLevelTwoDivOne::theCount(vector<string> palette, int n, int m) {
    pow4[0] = pow5[0] = 1;
    for(int i = 1 ; i < 2503; i++) pow4[i] = (pow4[i-1] * 4) % MOD, pow5[i] = (pow5[i-1] * 5) % MOD;
    memset(dp,-1,sizeof(dp));
    memset(correct,-1,sizeof(correct));
    memset(pane,-1,sizeof(pane));
    memset(cnts,0,sizeof(cnts));
    N = n, M = m;
    int nn = palette.size();
    int mm = palette[0].size();
    for(int i = 0 ; i < nn; i++) for(int j = 0 ; j < mm; j++) {if(palette[i][j]=='.') continue; pane[i][j] = (palette[i][j]-'0')%2;}
    for(int i = 0 ; i < nn; i++){
        for(int j = 0 ; j < mm; j++){
            if(pane[i][j] == -1) {cnts[i%N][j%M]++; continue;}
            if(correct[i%N][j%M] == -1) {correct[i%N][j%M] = pane[i][j]; continue;}
            if(correct[i%N][j%M] != pane[i][j]) return 0;
        }
    }
    return (int)go(0, 0);
}


// CUT begin
ifstream data("MagicalGirlLevelTwoDivOne.sample");

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

bool do_test(vector<string> palette, int n, int m, int __expected) {
    time_t startClock = clock();
    MagicalGirlLevelTwoDivOne *instance = new MagicalGirlLevelTwoDivOne();
    int __result = instance->theCount(palette, n, m);
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
        vector<string> palette;
        from_stream(palette);
        int n;
        from_stream(n);
        int m;
        from_stream(m);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
        continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(palette, n, m, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1494374221;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 600 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "MagicalGirlLevelTwoDivOne (600 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;


int dp[2][200002];
int way[21][2][200002];
int N;
class SRMIntermissionPhase {
public:
    int countWays(vector<int> points, vector<string> description) {
        memset(dp,0,sizeof(dp));
        memset(way,0,sizeof(way));
        N = description.size();
        for(int i = 0 ; i < N; i++){
            for(int j = 1 ; j <= 200001; j++) way[i][0][j] = 1;
            for(int k = 1 ; k <= 3; k++){
                way[i][k%2][0] = 0;
                for(int j = 1 ; j <= 200001; j++){
                    int lo, hi;
                    if(description[i][k-1] == 'N') lo = hi = 0;
                    else lo = 1, hi = min(points[k-1], j);
                    way[i][k%2][j] = ((ll)way[i][k%2][j-1] + (way[i][(k+1)%2][j-lo] - (hi < j ? way[i][(k+1)%2][j-hi-1] : 0)) + mod) % mod;
                }
            }
        }
        for(int i = 0 ; i <= 200001; i++) dp[0%2][i] = 1;
        for(int i = 1 ; i <= N; i++) {
            dp[i%2][0] = 0;
            for(int j = 1; j <= 200001; j++) {
                dp[i%2][j] = (dp[i%2][j-1] + ((ll)way[N-i][3%2][j] - way[N-i][3%2][j-1] + mod) % mod * dp[(i+1)%2][j-1] % mod) % mod;
            }
        }
        return dp[N%2][200001];
    }
};

// CUT begin
ifstream data("SRMIntermissionPhase.sample");

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

bool do_test(vector<int> points, vector<string> description, int __expected) {
    time_t startClock = clock();
    SRMIntermissionPhase *instance = new SRMIntermissionPhase();
    int __result = instance->countWays(points, description);
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
        vector<int> points;
        from_stream(points);
        vector<string> description;
        from_stream(description);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
        continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(points, description, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1495097523;
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
        cout << "SRMIntermissionPhase (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end

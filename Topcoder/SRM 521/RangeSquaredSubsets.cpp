#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;


set<ll> memo;
bool inRange(int x0, int y0, int x1, int y1, int x, int y){
    return x0 <= x && x <= x1 && y0 <= y && y <= y1;
}
class RangeSquaredSubsets {
    public:
    long long countSubsets(int nlow, int nhigh, vector<int> xs, vector<int> ys) {
        memo.clear();
        set<int> stx = set<int>(xs.begin(), xs.end());
        set<int> sty = set<int>(ys.begin(), ys.end());
        stx.insert(-inf);
        stx.insert(inf);
        sty.insert(-inf);
        sty.insert(inf);
        vector<int> x = vector<int>(stx.begin(),stx.end());
        vector<int> y = vector<int>(sty.begin(),sty.end());
        for(int xi = 1 ; xi < x.size()-1; xi++) for(int yi = 1 ; yi < y.size()-1; yi++)
        for(int xj = xi ; xj < x.size()-1; xj++) for(int yj = yi ; yj < y.size()-1; yj++){
            int lenx0 = x[xj] - x[xi];
            int leny0 = y[yj] - y[yi];

            int lenx1 = x[xj+1] - x[xi-1];
            int leny1 = y[yj+1] - y[yi-1];

            int lo = max(max(lenx0, leny0), nlow);
            int hi = min(min(lenx1, leny1)-1, nhigh);
            if(lo <= hi){
                ll mask = 0;
                for(int i = 0 ; i < xs.size(); i++){
                    if(inRange(x[xi],y[yi],x[xj],y[yj],xs[i],ys[i])) {
                        mask |= (1ll << i);
                    }
                }
                if(mask) memo.insert(mask);
            }
        }

        return memo.size();
    }
};

// CUT begin
ifstream data("RangeSquaredSubsets.sample");

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

bool do_test(int nlow, int nhigh, vector<int> x, vector<int> y, long long __expected) {
    time_t startClock = clock();
    RangeSquaredSubsets *instance = new RangeSquaredSubsets();
    long long __result = instance->countSubsets(nlow, nhigh, x, y);
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
        int nlow;
        from_stream(nlow);
        int nhigh;
        from_stream(nhigh);
        vector<int> x;
        from_stream(x);
        vector<int> y;
        from_stream(y);
        next_line();
        long long __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(nlow, nhigh, x, y, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1495154629;
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
        cout << "RangeSquaredSubsets (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end

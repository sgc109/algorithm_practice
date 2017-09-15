#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

vector<pair<int,int> > v;
class Over9000Rocks {
    public:
    int countPossibilities(vector<int> lowerBound, vector<int> upperBound) {
        v.clear();
        int N = (int)lowerBound.size();
        for(int bit = 0 ; bit < (1<<N); bit++){
            int lo = 0, hi = 0;
            for(int i = 0 ; i < N; i++){
                if(bit & (1 << i)){
                    lo += lowerBound[i], hi += upperBound[i];
                }
            }
            lo = max(lo, 9001);
            if(lo > hi) continue;
            v.push_back({lo, 0});
            v.push_back({hi, 1});
        }
        if((int)v.size() == 0) return 0;
        sort(v.begin(), v.end());
        int prv = v[0].first;
        int on = 0;
        int ans = 0;
        for(auto p : v){
            int cur = p.first;
            int end = p.second;
            if(!on && prv < cur) ans++;
            if(on) ans += cur - prv;
            on += (end ? -1 : 1);
            prv = cur;
        }
        ans++;
        return ans;
    }
};

// CUT begin
ifstream data("Over9000Rocks.sample");

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

bool do_test(vector<int> lowerBound, vector<int> upperBound, int __expected) {
    time_t startClock = clock();
    Over9000Rocks *instance = new Over9000Rocks();
    int __result = instance->countPossibilities(lowerBound, upperBound);
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
        vector<int> lowerBound;
        from_stream(lowerBound);
        vector<int> upperBound;
        from_stream(upperBound);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(lowerBound, upperBound, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1501983017;
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
        cout << "Over9000Rocks (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end

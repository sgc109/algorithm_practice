#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

class ElectionFraudDiv1 {
public:
    int N;
    vector<int> v;
    bool possi(int k){
        // printf("k ; %d\n", k);
        int s = 0, e = 0;
        for(int i = 0 ; i < N; i++){y
            int ts = 0, te = 0;
            int lo = 0, hi = k;
            while(lo < hi){
                int mid = (lo + hi) / 2;
                if(round((double)mid / k * 100) >= v[i]) hi = mid;
                else lo = mid + 1;
            }
            ts = lo;
            // printf("lo : %d\n", lo);
            if((int)round((double)lo * 100 / k) != v[i]) return false;
            // printf("%d %d\n", (int)round((double)lo / k * 100), v[i]);
            lo = 0, hi = k;
            while(lo < hi){
                int mid = (lo + hi) / 2;
                if(round((double)mid / k * 100) <= v[i]) lo = mid + 1;
                else hi = mid;
            }
            te = lo;
            s += ts, e += te - 1;
            // printf("s : %d, e : %d\n", s, e);
        }
        return s <= k && k <= e;
    }
    int MinimumVoters(vector<int> percentages) {
        v = percentages;
        N = (int)percentages.size();
        for(int i = 1 ; i < 100000; i++){
            if(possi(i)) return i;
        }        
        return -1;
    }
};

// CUT begin
ifstream data("ElectionFraudDiv1.sample");

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

bool do_test(vector<int> percentages, int __expected) {
    time_t startClock = clock();
    ElectionFraudDiv1 *instance = new ElectionFraudDiv1();
    int __result = instance->MinimumVoters(percentages);
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
        vector<int> percentages;
        from_stream(percentages);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
        continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(percentages, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1503064426;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 275 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "ElectionFraudDiv1 (275 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end

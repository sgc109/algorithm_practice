#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

class RotatedClock {
public:
    string getEarliest(int hourHand, int minuteHand);
};

string RotatedClock::getEarliest(int hourHand, int minuteHand){
    pair<int, int> ans = {INF, INF};
    for(int i = 0 ; i < 12; i++){
        if(minuteHand % 12 || (hourHand * 12) % 360 != minuteHand) 1;
        else ans = min(ans, {hourHand / 30, minuteHand / 6});
        hourHand = (hourHand + 30) % 360;
        minuteHand = (minuteHand + 30) % 360;
    }
    if(ans == make_pair(INF, INF)) return "";
    string ret;
    if(ans.first < 10) ret += '0', ret += '0'+ans.first;
    else ret += '0'+ans.first/10, ret += '0'+ans.first%10;
    ret += ":";
    if(ans.second < 10) ret += "0", ret += '0'+ans.second;
    else ret += '0'+ans.second/10, ret += '0'+ans.second%10;

    return ret;
}












// CUT begin
ifstream data("RotatedClock.sample");

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

bool do_test(int hourHand, int minuteHand, string __expected) {
    time_t startClock = clock();
    RotatedClock *instance = new RotatedClock();
    string __result = instance->getEarliest(hourHand, minuteHand);
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
        int hourHand;
        from_stream(hourHand);
        int minuteHand;
        from_stream(minuteHand);
        next_line();
        string __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
        continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(hourHand, minuteHand, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1493891805;
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
        cout << "RotatedClock (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

map<char,int> f;
int rome2int(string& s){
    int ret = 0;
    for(int i = 0 ; i < (int)s.size() - 1; i++){
        if(f[s[i]] < f[s[i+1]]) ret -= f[s[i]];
        else ret += f[s[i]];
    }
    ret += f[s.back()];
    return ret;
}
bool cmpp(const string& A, const string& B){
    int pos1 = A.find(" ");
    int pos2 = B.find(" ");
    string sa1 = A.substr(0, pos1);
    string sb1 = B.substr(0, pos2);
    if(sa1 != sb1) return sa1 < sb1;
    string sa2 = A.substr(pos1 + 1, (int)A.size() - pos1 - 1);
    string sb2 = B.substr(pos2 + 1, (int)B.size() - pos2 - 1);
    int num1 = rome2int(sa2);
    int num2 = rome2int(sb2);
    return num1 < num2;
}
class KingSort {
    public:
    vector<string> getSortedList(vector<string> kings) {
        f['I'] = 1;
        f['V'] = 5;
        f['X'] = 10;
        f['L'] = 50;
        sort(kings.begin(), kings.end(), cmpp);
        return kings;
    }
};

// CUT begin
ifstream data("KingSort.sample");

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

template <typename T> string to_string(vector<T> ts) {
    stringstream s;
    s << "[ ";
    for (int i = 0; i < (int)ts.size(); ++i) {
        if (i > 0) s << ", ";
        s << to_string(ts[i]);
    }
    s << " ]";
    return s.str();
}

bool do_test(vector<string> kings, vector<string> __expected) {
    time_t startClock = clock();
    KingSort *instance = new KingSort();
    vector<string> __result = instance->getSortedList(kings);
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
        vector<string> kings;
        from_stream(kings);
        next_line();
        vector<string> __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(kings, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1500275734;
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
        cout << "KingSort (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end

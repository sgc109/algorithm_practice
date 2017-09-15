#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int N;
int check[53];
int tim[53];
vector<int> X, Y;
string dir;
int take(int i, int j){
    if(X[i] == X[j]){
        if(Y[i] < Y[j]) swap(i, j);
        if(dir[i] == 'S' && dir[j] == 'N') return abs(Y[i] - Y[j]);
        return 0;
    }
    else if(Y[i] == Y[j]){
        if(X[i] > X[j]) swap(i, j);
        if(dir[i] == 'E' && dir[j] == 'W') return abs(X[i] - X[j]);
        return 0;
    }
    if(abs(X[i] - X[j]) != abs(Y[i] - Y[j])) return 0;
    if(X[i] > X[j]) swap(i, j);
    if(X[i] < X[j] && Y[i] < Y[j]){
        if((dir[i] == 'N' && dir[j] == 'W') || (dir[i] == 'E' && dir[j] == 'S')) return 2 * abs(X[i] - X[j]);
        return 0;
    }
    if((dir[i] == 'E' && dir[j] == 'N') || (dir[i] == 'S' && dir[j] == 'W')) return 2 * abs(X[i] - X[j]);
    return 0;
}
vector<pair<int, pair<int,int> > > v;
class AntsMeet {
    public:
    int countAnts(vector<int> x, vector<int> y, string direction) {
        X = x, Y = y, dir = direction;
        v.clear();
        memset(tim,0,sizeof(tim));
        memset(check,0,sizeof(check));
        N = (int)x.size();
        for(int i = 0 ; i < N; i++){
            for(int j = i + 1; j < N; j++){
                int t = take(i, j);
                if(!t) continue;
                v.push_back({t, {i, j}});
            }
        }
        sort(v.begin(), v.end());
        for(auto p : v){
            int i = p.second.first;
            int j = p.second.second;
            int cst = p.first;
            if(tim[i] && tim[i] < cst) continue;
            if(tim[j] && tim[j] < cst) continue;
            tim[i] = tim[j] = cst;
            check[i] = check[j] = 1;
        }
        int ans = 0;
        for(int i = 0 ; i < N; i++) ans += !check[i];

        return ans;
    }
};

// CUT begin
ifstream data("AntsMeet.sample");

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

bool do_test(vector<int> x, vector<int> y, string direction, int __expected) {
    time_t startClock = clock();
    AntsMeet *instance = new AntsMeet();
    int __result = instance->countAnts(x, y, direction);
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
        vector<int> x;
        from_stream(x);
        vector<int> y;
        from_stream(y);
        string direction;
        from_stream(direction);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(x, y, direction, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1502509828;
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
        cout << "AntsMeet (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end

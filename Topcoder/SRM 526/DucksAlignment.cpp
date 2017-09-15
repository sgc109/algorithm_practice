#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

class DucksAlignment {
public:
    int N,M;
    vector<int> cols, rows;
    int minimumTime(vector<string> grid) {
        N = (int)grid.size();
        M = (int)grid[0].size();
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < M; j++){
                if(grid[i][j] == 'o') rows.push_back(i);
            }
        }
        for(int j = 0 ; j < M; j++){
            for(int i = 0 ; i < N; i++){
                if(grid[i][j] == 'o') cols.push_back(j);
            }
        }
        int rowsMid = rows[(int)rows.size()/2];
        int colsMid = cols[(int)cols.size()/2];
        int rowsSum = 0, colsSum = 0;
        int colSize = (int)cols.size();
        int rowSize = (int)rows.size();
        for(int i = 0 ; i < colSize; i++) colsSum += abs(cols[i] - colsMid);
        for(int i = 0 ; i < rowSize; i++) rowsSum += abs(rows[i] - rowsMid);

        int colMin = inf, rowMin = inf;
        for(int i = 0 ; i <= M - colSize; i++){
            int sum = 0;
            for(int j = 0 ; j < colSize; j++) {
                sum += abs(i + j - cols[j]);
            }
            colMin = min(colMin, sum);
        }
        for(int i = 0 ; i <= N - rowSize; i++){
            int sum = 0;
            for(int j = 0 ; j < rowSize; j++) {
                sum += abs(i + j - rows[j]);
            }
            rowMin = min(rowMin, sum);
        }
        printf("%d %d %d %d\n",rowsSum, colMin, colsSum, rowMin);
        return min(rowsSum + colMin, colsSum + rowMin);
    }
};

// CUT begin
ifstream data("DucksAlignment.sample");

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

bool do_test(vector<string> grid, int __expected) {
    time_t startClock = clock();
    DucksAlignment *instance = new DucksAlignment();
    int __result = instance->minimumTime(grid);
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
        vector<string> grid;
        from_stream(grid);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
        continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(grid, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1499390120;
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
        cout << "DucksAlignment (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end

#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
#define inp5(a,b,c,d,e) scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;	
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int,pair<int,int> > piii;
typedef vector<piii> viii;
const double EPSILON = 1e-9;
const double PI = acos(-1);
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

class PerfectMemory {
public:
    int N,M;
    double dp[2503][2503];
    double case1(double rest, double known){
        double ret = rest-2*known;
        ret /= (rest-known);
        ret /= (rest-known-1);
        return ret;
    }
    double case2(double rest, double known){
        double ret = rest-2*known;
        ret /= (rest-known);
        ret *= (rest-2*known-2);
        ret /= (rest-known-1);
        return ret;
    }
    double case3(double rest, double known){
        double ret = rest-2*known;
        ret /= (rest-known);
        ret *= known;
        ret /= (rest-known-1);
        return ret;
    }
    double case4(double rest, double known){
        double ret = known;
        ret /= (rest-known);
        return ret;
    }

    double go(int rest, int known){
        if(rest==0) return 0;
        if(rest==2) return 1;
        double& cache = dp[rest][known];
        if(cache != -1) return cache;
        double ret = 0;
        if(rest/2 > known){
            ret += case1(rest, known) * (go(rest-2, known) + 1);
            ret += case2(rest, known) * (go(rest, known+2) + 1);
            ret += case3(rest, known) * (go(rest-2, known) + 2);
            ret += case4(rest ,known) * (go(rest-2, known-1) + 1);
        }
        else ret += (go(rest-2, known-1) + 1);
        return cache = ret;
    }

    double getExpectation(int N, int M) {
        for(int i = 0 ; i <= 2500; i++){
            for(int j = 0 ; j <= 2500; j++){
                dp[i][j] = -1;
            }
        }
        return go(N*M,0);
    }
};

// CUT begin
ifstream data("PerfectMemory.sample");

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

bool double_equal(const double &a, const double &b) { return b==b && a==a && fabs(b - a) <= 1e-9 * max(1.0, fabs(a) ); }

bool do_test(int N, int M, double __expected) {
    time_t startClock = clock();
    PerfectMemory *instance = new PerfectMemory();
    double __result = instance->getExpectation(N, M);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (double_equal(__expected, __result)) {
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
        int N;
        from_stream(N);
        int M;
        from_stream(M);
        next_line();
        double __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(N, M, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1491096405;
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
        cout << "PerfectMemory (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
